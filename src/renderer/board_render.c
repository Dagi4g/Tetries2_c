#include <ncurses.h>
#include "../board/board.h"
#include "board_render.h"

static char glyph_for(CellType type) {
    switch (type) {
        case EMPTY:  return ' ';
        case BLOCK:  return '#';
        case WALL:   return '|';
        case FLOOR:  return '-';
        case CORNER: return '+';
        default:     return '?';
    }
}

void renderer_draw_board(void) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            mvaddch(y, x, glyph_for(board_get(y, x)));
        }
    }
}
