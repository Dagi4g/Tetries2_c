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
} Cell;

/* board API */
void board_init(void);
CellType board_get(int y, int x);
void board_set(int y, int x, CellType type);

#endif
