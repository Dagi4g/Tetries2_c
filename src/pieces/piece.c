#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "piece.h"

// Helper: sets default position for any piece
static void piece_set_position(Piece *p) {
    p->x = BOARD_WIDTH / 2 - 2;
    p->y = BOARD_HEIGHT - 4;
}

// O-piece
Piece create_o_piece(void) {
    Piece p = {0};
    p.color = 1;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},

    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// I-piece
Piece create_i_piece(void) {
    Piece p = {0};
    p.color = 2;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, BLOCK},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// T-piece
Piece create_t_piece(void) {
    Piece p = {0};
    p.color = 3;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {EMPTY, BLOCK, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// L-piece
Piece create_l_piece(void) {
    Piece p = {0};
    p.color = 4;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCK, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// J-piece
Piece create_j_piece(void) {
    Piece p = {0};
    p.color = 5;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {BLOCK, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// S-piece
Piece create_s_piece(void) {
    Piece p = {0};
    p.color = 6;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {BLOCK, BLOCK, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}

// Z-piece
Piece create_z_piece(void) {
    Piece p = {0};
    p.color = 7;
    piece_set_position(&p);
    CellType s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    //memcpy(p.color, color, sizeof(color));
    return p;
}



// Initialize RNG
void pieces_init_random(void) {
    srand(time(NULL));
}

// Spawn a random piece at runtime
Piece spawn_random_piece(void) {
    int index = rand()%7 + 0;
    switch(index) {
        case 0: return create_o_piece();
        case 1: return create_i_piece();
        case 2: return create_t_piece();
        case 3: return create_l_piece();
        case 4: return create_j_piece();
        case 5: return create_s_piece();
        case 6: return create_z_piece();
    }
    return create_o_piece(); // fallback
}


void rotate(Piece *p) {
    int temp[PIECE_SIZE][PIECE_SIZE];

    // Your exact logic: "column = 3-row and row = column"
    // Which translates to: temp[row][col] = old[3-col][row]
    for (int row = 0; row < PIECE_SIZE; row++) {
        for (int col = 0; col < PIECE_SIZE; col++) {
            // This is the direct translation of your description
            temp[row][col] = p->shape[PIECE_SIZE - 1 - col][row];
        }
    }

    // Copy back
    for (int i = 0; i < PIECE_SIZE; i++) {
        for (int j = 0; j < PIECE_SIZE; j++) {
            p->shape[i][j] = temp[i][j];
        }
    }
}
