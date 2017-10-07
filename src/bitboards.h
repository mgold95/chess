////////////////////////////////////////////////////////////////////////////////
// bitboards.h
//
// Contains various bitboards used for computation in the engine
//
// author: Michael Goldstein
//

#ifndef BITBOARDS__H
#define BITBOARDS__H

#include "types.h"

// Macro to convert a square into a bitboard
#define __SQ_MASK(sq) (1 << (sq))

extern bitboard_t B_ATTACK_boardS   [N_PIECE_TYPES][N_SQUARES];
extern bitboard_t B_MOVE_boardS     [N_PIECE_TYPES][N_SQUARES];
extern bitboard_t BLOCK_B_boardS    [N_PIECE_TYPES][N_SQUARES];
extern bitboard_t W_ATTACK_boardS   [N_PIECE_TYPES][N_SQUARES];
extern bitboard_t W_MOVE_boardS     [N_PIECE_TYPES][N_SQUARES];
extern bitboard_t BLOCK_W_boardS    [N_PIECE_TYPES][N_SQUARES];

#endif

