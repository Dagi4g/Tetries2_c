#ifndef PIECES_H
#define PIECES_H

#include "../board/board.h" // for CellType and BOARD_WIDTH

#define PIECE_SIZE 4

typedef struct {
    int x;
    int y;
    int color;
    CellType shape[PIECE_SIZE][PIECE_SIZE];
} Piece;
void pieces_init_random(void);
void rotate(Piece *p);
Piece spawn_random_piece(void);

// Functions to create each piece
static void piece_set_position(Piece *p);
Piece create_o_piece(void);
Piece create_i_piece(void);
Piece create_t_piece(void);
Piece create_l_piece(void);
Piece create_j_piece(void);
Piece create_s_piece(void);
Piece create_z_piece(void);

#endif

