////////////////////////////////////////////////////////////////////////////////
// game.h
//
// Stores and manipulates game state.
//
// author: Michael Goldstein
//

#ifndef GAME__H
#define GAME__H

#include "types.h"

#define PIECE 0
#define LOCATION 1

typedef struct gamestate_t {
    // 2D static array of pieces followed by their locations,
    // indexes are replaces with PIECE_NONE after capture
    int white_pieces[16][2];
    int black_pieces[16][2];
} gamestate_t;

extern gamestate_t master_state;

void init_new_game(gamestate_t *state);
void move_piece(gamestate_t *state, square_t dest, square_t src);
piece_t get_piece_at(gamestate_t *state, square_t square);
gamestate_t *clone_state(gamestate_t *state);

#endif

