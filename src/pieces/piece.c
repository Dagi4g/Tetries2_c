#include <stdlib.h>
#include <time.h>
#include "piece.h"

// Helper function to create pieces
Piece create_o_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, BLOCK, BLOCK, EMPTY},
            {EMPTY, BLOCK, BLOCK, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_i_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {BLOCK, BLOCK, BLOCK, BLOCK},
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_t_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, BLOCK, EMPTY, EMPTY},
            {BLOCK, BLOCK, BLOCK, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_l_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, BLOCK, EMPTY},
            {BLOCK, BLOCK, BLOCK, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_j_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {BLOCK, EMPTY, EMPTY, EMPTY},
            {BLOCK, BLOCK, BLOCK, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_s_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {EMPTY, BLOCK, BLOCK, EMPTY},
            {BLOCK, BLOCK, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

Piece create_z_piece(void) {
    Piece p = {
        .x = BOARD_WIDTH / 2 - 2,
        .y = 1,
        .shape = {
            {EMPTY, EMPTY, EMPTY, EMPTY},
            {BLOCK, BLOCK, EMPTY, EMPTY},
            {EMPTY, BLOCK, BLOCK, EMPTY},
            {EMPTY, EMPTY, EMPTY, EMPTY}
        }
    };
    return p;
}

// Initialize RNG
void pieces_init_random(void) {
    srand(time(NULL));
}

// Spawn a random piece at runtime
Piece spawn_random_piece(void) {
    int index = rand() % 7;
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
