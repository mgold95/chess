////////////////////////////////////////////////////////////////////////////////
// types.h
//
// Defines various types used throughout the program
//
// author: Michael Goldstein
//

#ifndef TYPES__H
#define TYPES__H

#include <stdint.h>

#define N_PIECE_TYPES   6
#define N_SQUARES       64

typedef enum square_t {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
} square_t;

typedef uint64_t bitboard_t;

typedef enum color_t {
    WHITE = 0,
    BLACK = (1 << 31)
} color_t;

typedef enum piece_t {
    PIECE_NONE  = -1,

    PAWN        = 0,
    KNIGHT      = 1,
    BISHOP      = 2,
    ROOK        = 3,
    QUEEN       = 4,
    KING        = 5,

    W_PAWN      = WHITE | PAWN,
    W_KNIGHT    = WHITE | KNIGHT,
    W_BISHOP    = WHITE | BISHOP,
    W_ROOK      = WHITE | ROOK,
    W_QUEEN     = WHITE | QUEEN,
    W_KING      = WHITE | KING,

    B_PAWN      = BLACK | PAWN,
    B_KNIGHT    = BLACK | KNIGHT,
    B_BISHOP    = BLACK | BISHOP,
    B_ROOK      = BLACK | ROOK,
    B_QUEEN     = BLACK | QUEEN,
    B_KING      = BLACK | KING
} piece_t;

typedef enum phase_t {
    OPENING,
    MIDGAME,
    ENDGAME
} phase_t;

// Helper functions
void sqtoa(char *buf, square_t sq);

#endif

