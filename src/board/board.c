#include "board.h"

static Cell board[BOARD_HEIGHT][BOARD_WIDTH];

void board_init(void) {
    /* clear board */
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x].type = EMPTY;
        }
    }
    for (int x = 0; x < BOARD_WIDTH; x++){
	    board[0][x].type = FLOOR; // the roof the board.
    }

    /* walls */
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        board[y][0].type = WALL;
        board[y][BOARD_WIDTH - 1].type = WALL;
    }

    /* floor */
    for (int x = 0; x < BOARD_WIDTH; x++) {
        board[BOARD_HEIGHT - 1][x].type = FLOOR;
    }

    /* corners */
    board[0][0].type = CORNER;
    board[0][BOARD_WIDTH - 1].type = CORNER;
    board[BOARD_HEIGHT - 1][0].type = CORNER;
    board[BOARD_HEIGHT - 1][BOARD_WIDTH - 1].type = CORNER;
}

CellType board_get(int y, int x) {
    return board[y][x].type;
}
