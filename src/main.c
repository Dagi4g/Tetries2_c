#include <ncurses.h>
#include <unistd.h>
#include "board/board.h"
#include "renderer/board_render.h"
#include "config.h"


int main(void) {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);   // non-blocking input
    keypad(stdscr, TRUE);

    board_init();

    int x = BOARD_WIDTH / 2;
    int y = 1;

    while (y < BOARD_HEIGHT - 1) {
        board_set(y, x, EMPTY);   // erase old
        y++;
        board_set(y, x, BLOCK);   // draw new

        clear();
        renderer_draw_board();
        refresh();

        usleep(200000);  // 200 ms
    }

    getch();
    endwin();
    return 0;
}
