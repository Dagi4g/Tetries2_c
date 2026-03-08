#include <ncurses.h>
#include <unistd.h>
#include "board/board.h"
#include "pieces/piece.h"
#include "renderer/board_render.h"
#include "config.h"


typedef enum {
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_DOWN
} Move;


int can_it_move(Piece *p,int dx,int dy) {
    for (int row = 0; row < PIECE_SIZE; row++) {
        for (int col = 0; col <= PIECE_SIZE-1; col++) {
            if (p->shape[row][col] == BLOCK) {
                int board_x = p->x + col + dx;
                int board_y = p->y + row + dy;
                if (board_x >= BOARD_WIDTH || board_get(board_y,board_x) != EMPTY)
                    return 0;
            }
        }
    }
    return 1;
}




int can_move(Piece *p, Move move) {
    switch (move) {
        case MOVE_LEFT:
            return can_it_move(p,-1,0);

        case MOVE_RIGHT:
            return can_it_move(p,1 ,0);

        case MOVE_DOWN:
            return can_it_move(p,0,-1);
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
    for (int x = 1; x < BOARD_WIDTH; x++)
	if (board_get(y,x) == BLOCK && board_get(y,x)!= WALL){
		board_set(y, x, EMPTY);
	}

}
void shift_rows_down(int from_y) {
    for (int y = from_y; y > 1; y--) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board_set(y, x, board_get(y - 1, x));
        }
    }

    // clear top row
    for (int x = 0; x < BOARD_WIDTH; x++)
        board_set(1, x, EMPTY);
}

void apply_move(Piece *p, Move move) {
    if (!can_move(p, move)) return;

    switch (move) {
        case MOVE_LEFT:
            p->x -= 1;
            break;

        case MOVE_RIGHT:
            p->x += 1;
            break;

        case MOVE_DOWN:
            p->y--;
            break;
    }
}

void draw_piece_temp(Piece *p) {
    clear(); // clear screen

    // Temporarily draw the piece on top of the board
    for (int row = 0; row < PIECE_SIZE; row++) {
        for (int col = 0; col < PIECE_SIZE; col++) {
            if (p->shape[row][col] == BLOCK) {
                int board_y = p->y + row;
                int board_x = p->x + col;

                // make sure we don't go out of bounds
                if (board_get(board_y,board_x) == EMPTY) {
                    board_set(board_y, board_x, BLOCK);
                }
            }
        }
    }

    // Draw the board with the temporary piece
    renderer_draw_board();

    // Remove the temporary piece
    for (int row = 0; row <PIECE_SIZE; row++) {
        for (int col = 0; col < PIECE_SIZE ; col++) {
            if (p->shape[row][col] != EMPTY) {
                int board_y = p->y + row;
                int board_x = p->x + col;

		mvprintw(BOARD_WIDTH+2,5,"block at (%d,%d) ",board_x,board_y);

		if (board_get(board_y,board_x) == BLOCK ) {
                    board_set(board_y, board_x, EMPTY);
                }
            }
        }
    }

    refresh(); // show frame
}

void lock_piece(Piece *p) {
    for (int row = 0; row < PIECE_SIZE; row++) {
        for (int col = 0; col < PIECE_SIZE; col++) {
            if (p->shape[row][col] == BLOCK) {
                int board_y = p->y + row;
                int board_x = p->x + col;

                // Make sure we stay inside the board
                if (board_y >= 0 && board_y < BOARD_HEIGHT &&
                    board_x >= 0 && board_x < BOARD_WIDTH) {
                    board_set(board_y, board_x, BLOCK);
                }
            }
        }
    }
}

int main(void) {
    initscr();
    start_color();
    use_default_colors();
    
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_GREEN, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    board_init();
    
    pieces_init_random();
    Piece block = spawn_random_piece();
    
    // Check if spawn was successful
    if (!can_move(&block,MOVE_DOWN)) {
        endwin();
        printf("Game Over - No space for new piece!\n");
        return 1;
    }
    
    int ch;
    int need_render = 1;
    
    while (1) {
        // INPUT HANDLING
        ch = getch();
        if (ch != ERR) {
            switch (ch) {
                case 'j':
                    apply_move(&block, MOVE_LEFT);
                    need_render = 1;
                    break;
                case 'k':
                    apply_move(&block, MOVE_RIGHT);
                    need_render = 1;
                    break;
                case 'n':
                    while (can_move(&block, MOVE_DOWN)) {
                        apply_move(&block, MOVE_DOWN);
                    }
                    need_render = 1;
                    break;
                case 'q':  // Add quit option
                    endwin();
                    return 0;
            }
        }
        
        // GRAVITY
        static int frame_counter = 0;
        frame_counter++;
        if (frame_counter >= 10) {  // Move down every 10 frames
            if (can_move(&block, MOVE_DOWN)) {
                apply_move(&block, MOVE_DOWN);
            } else {
                lock_piece(&block);
                
                // Clear rows
                for (int y = 1; y < BOARD_HEIGHT - 1; y++) {
                    while (row_is_full(y)) {
                        clear_row(y);
                        shift_rows_down(y);
                    }
                }
                
                block = spawn_random_piece();
                if (!can_move(&block,MOVE_DOWN)) {
                    break;  // Game over
                }
            }
            frame_counter = 0;
            need_render = 1;
        }
        
        // RENDER
        if (need_render) {
            draw_piece_temp(&block);
            need_render = 0;
        }
        
        usleep(50000);  // 50ms = 20 FPS (more responsive)
    }
    
    endwin();
    printf("Game Over!\n");
    return 0;
}
