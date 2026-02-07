#include <ncurses.h>
#include <unistd.h>
#include "board/board.h"
#include "renderer/board_render.h"
#include "config.h"

typedef struct {
	int x ;
	int y ;
}Piece;

void piece_init(Piece *p){
	p->x = BOARD_WIDTH/ 2;
	p->y = 1;
}

int animate_board(Piece *p){
        board_set(p->y, p->x, BLOCK);   // draw new

        clear();
        renderer_draw_board();
        refresh();

        usleep(200000);  // 200 ms
        board_set(p->y, p->x, EMPTY);   // erase old
        p->y++;
   
	return 0;
}


int main(void) {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);   // non-blocking input
    keypad(stdscr, TRUE);

    board_init();
    Piece block;
    piece_init(&block);


    while (1){
	    while (block.y < BOARD_HEIGHT-1){
		    char ch = getch();
		    if (ch == 'j'){
			    if (block.x > 1){
			    block.x --;
		    }
		    }
		    if (ch == 'k'){
			    if (block.x < BOARD_WIDTH - 2){
				    block.x ++;
			    }
		    }
		    if (ch == 'n'){
			    block.y = BOARD_HEIGHT-2;
		    }

		    animate_board(&block);
	    }
	    piece_init(&block);

    }

    getch();
    endwin();
    return 0;
}
