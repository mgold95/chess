////////////////////////////////////////////////////////////////////////////////
// game.c
//
// Stores game state
//
// author: Michael Goldstein
//

#include <stdlib.h>
#include <string.h>

#include "game.h"

gamestate_t master_state;

// sets the internal game state to a new game
void init_new_game(gamestate_t *state)
{
    const int initial_white_pieces[16][2] = {
        { W_PAWN,   A2 },
        { W_PAWN,   B2 },
        { W_PAWN,   C2 },
        { W_PAWN,   D2 },
        { W_PAWN,   E2 },
        { W_PAWN,   F2 },
        { W_PAWN,   G2 },
        { W_PAWN,   H2 },
        { W_ROOK,   A1 },
        { W_KNIGHT, B1 },
        { W_BISHOP, C1 },
        { W_QUEEN,  D1 },
        { W_KING,   E1 },
        { W_BISHOP, F1 },
        { W_KNIGHT, G1 },
        { W_ROOK,   H1 }
    };
    const int initial_black_pieces[16][2] = {
        { B_PAWN,   A7 },
        { B_PAWN,   B7 },
        { B_PAWN,   C7 },
        { B_PAWN,   D7 },
        { B_PAWN,   E7 },
        { B_PAWN,   F7 },
        { B_PAWN,   G7 },
        { B_PAWN,   H7 },
        { B_ROOK,   A8 },
        { B_KNIGHT, B8 },
        { B_BISHOP, C8 },
        { B_QUEEN,  D8 },
        { B_KING,   E8 },
        { B_BISHOP, F8 },
        { B_KNIGHT, G8 },
        { B_ROOK,   H8 }
    };
    memcpy(state->white_pieces, initial_white_pieces, sizeof(int)*16*2);
    memcpy(state->black_pieces, initial_black_pieces, sizeof(int)*16*2);
}

void move_piece(gamestate_t *state, square_t dest, square_t src)
{
    // kill any captured pieces
    for (int i = 0; i < 16; i++) {
        if (state->white_pieces[i][LOCATION] == dest) {
            state->white_pieces[i][PIECE] = PIECE_NONE;
            break;
        }
        if (state->black_pieces[i][LOCATION] == dest) {
            state->black_pieces[i][PIECE] = PIECE_NONE;
            break;
        }
    }
    // move the piece
    for (int i = 0; i < 16; i++) {
        if (state->white_pieces[i][LOCATION] == src) {
            state->white_pieces[i][LOCATION] = dest;
            break;
        }
        if (state->black_pieces[i][LOCATION] == src) {
            state->black_pieces[i][LOCATION] = dest;
            break;
        }
    }
}

// returns the piece located on a given square
piece_t get_piece_at(gamestate_t *state, square_t square)
{
    for (int i = 0; i < 16; i++) {
        if (state->white_pieces[i][LOCATION] == square) {
            return state->white_pieces[i][PIECE];
        }
        if (state->black_pieces[i][LOCATION] == square) {
            return state->black_pieces[i][PIECE];
        }
    }
    return PIECE_NONE;
}

gamestate_t *clone_state(gamestate_t *state)
{
    gamestate_t *ptr;
    ptr = malloc(sizeof(gamestate_t));
    memcpy(ptr, state, sizeof(gamestate_t));
    return ptr;
}

