#ifndef PIECES_H
#define PIECES_H

#include "../board/board.h" // for CellType and BOARD_WIDTH

#define PIECE_SIZE 4

typedef struct {
    int x;
    int y;
    CellType shape[PIECE_SIZE][PIECE_SIZE];
} Piece;

// extern declarations
extern Piece o_piece;
extern Piece i_piece;
extern Piece t_piece;
extern Piece l_piece;
extern Piece j_piece;
extern Piece s_piece;
extern Piece z_piece;

// optional: array of all pieces
extern Piece all_pieces[7];
// initialize RNG for random pieces
void pieces_init_random(void);

// spawn a random piece
Piece spawn_random_piece(void);

#endif // PIECES_H
