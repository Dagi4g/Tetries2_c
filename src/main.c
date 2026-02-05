#include <ncurses.h>
#include "board/board.h"
#include "renderer/board_render.h"

int main(void) {
    initscr();
    noecho();
    curs_set(0);

    board_init();
    renderer_draw_board();

    refresh();
    getch();    /* wait for key */

    endwin();
    return 0;
}
