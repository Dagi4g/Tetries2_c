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
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},

    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// I-piece
Piece create_i_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, BLOCK},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// T-piece
Piece create_t_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {EMPTY, BLOCK, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// L-piece
Piece create_l_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCK, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// J-piece
Piece create_j_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, BLOCK, EMPTY},
        {BLOCK, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// S-piece
Piece create_s_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {BLOCK, BLOCK, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
    return p;
}

// Z-piece
Piece create_z_piece(void) {
    Piece p = {0};
    piece_set_position(&p);
    Cell s[4][4] = {
        {EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCK, BLOCK, EMPTY, EMPTY},
        {EMPTY, BLOCK, BLOCK, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY}
    };
    memcpy(p.shape, s, sizeof(s));
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
