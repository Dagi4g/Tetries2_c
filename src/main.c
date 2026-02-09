#include <ncurses.h>
#include <unistd.h>
#include "board/board.h"
#include "renderer/board_render.h"
#include "config.h"

typedef struct {
    int x;
    int y;
} Piece;

typedef enum {
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_DOWN
} Move;

void piece_init(Piece *p) {
    p->x = BOARD_WIDTH / 2;
    p->y = 1;
}

int can_move(Piece *p, Move move) {
    switch (move) {
        case MOVE_LEFT:
            return board_get(p->y, p->x - 1) == EMPTY;

        case MOVE_RIGHT:
            return board_get(p->y, p->x + 1) == EMPTY;

        case MOVE_DOWN:
            return board_get(p->y + 1, p->x) == EMPTY;
    }
    return 0;
}

bool row_is_full(int y) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        if (board_get(y, x) == EMPTY)
            return false;
    }
    return true;
}

void clear_row(int y) {
    for (int x = 0; x < BOARD_WIDTH; x++)
        board_set(y, x, EMPTY);
}
void shift_rows_down(int from_y) {
    for (int y = from_y; y > 0; y--) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board_set(y, x, board_get(y - 1, x));
        }
    }

    // clear top row
    for (int x = 0; x < BOARD_WIDTH; x++)
        board_set(0, x, EMPTY);
}

void apply_move(Piece *p, Move move) {
    if (!can_move(p, move)) return;

    switch (move) {
        case MOVE_LEFT:
            p->x--;
            break;

        case MOVE_RIGHT:
            p->x++;
            break;

        case MOVE_DOWN:
            p->y++;
            break;
    }
}
void draw_frame(Piece *p) {
    clear();
    board_set(p->y, p->x, BLOCK);
    renderer_draw_board();
    board_set(p->y, p->x, EMPTY); // remove temp draw
    refresh();
}

void lock_piece(Piece *p) {
    board_set(p->y, p->x, BLOCK);
}

int main(void) {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    board_init();

    Piece block;
    piece_init(&block);

    while (1) {
        /* ---------- INPUT ---------- */
	int ch = getch();
	if (ch == 'j') apply_move(&block, MOVE_LEFT);
	if (ch == 'k') apply_move(&block, MOVE_RIGHT);

	if (ch == 'n') {
	    while (can_move(&block, MOVE_DOWN)) {
		apply_move(&block, MOVE_DOWN);
	    }
	}
        /* ---------- GRAVITY ---------- */

	if (can_move(&block, MOVE_DOWN)) {
	    apply_move(&block, MOVE_DOWN);
	} else {
	    lock_piece(&block);
	    for (int y = BOARD_HEIGHT - 2; y >= 1; y--) {
		    if (row_is_full(y)) {
			clear_row(y);
			shift_rows_down(y);
			y++; // re-check same row index
		    }
		}
	    piece_init(&block);
	}
        /* ---------- RENDER ---------- */
        draw_frame(&block);

        usleep(200000); // 200 ms per frame
    }

    endwin();
    return 0;
}
