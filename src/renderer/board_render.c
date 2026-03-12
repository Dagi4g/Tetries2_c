#include <ncurses.h>
#include "../board/board.h"
#include "board_render.h"



// Map CellType to glyph
static char glyph_for(CellType type) {
    switch(type) {
        case EMPTY:  return '.';
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

            int color = get_color(y,x);
	    CellType type = board_get(y,x);
            attron(COLOR_PAIR(color)); // enable color
            mvaddch(y, x, glyph_for(type));
            attroff(COLOR_PAIR(color)); // disable color
        }
    }
}
