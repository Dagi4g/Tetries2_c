#ifndef BOARD_H
#define BOARD_H

#include "../config.h"

typedef enum {
    EMPTY,
    BLOCK,
    WALL,
    FLOOR,
    CORNER,
} CellType;

typedef struct {
    CellType type;
    int color;
} Cell;

/* board API */
void board_init(void);
CellType board_get(int y, int x);
void board_set(int y, int x, CellType type, int color);
int get_color(int y,int x);


#endif
