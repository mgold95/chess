#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "game.h"
#include "test_game.h"

static void fill_with_random(void* ptr, int nbytes);

const struct CMUnitTest test_game_tests[TEST_GAME_NUM_TESTS] = {
    cmocka_unit_test(test_init_new_game),
    cmocka_unit_test(test_move_piece),
    cmocka_unit_test(test_get_piece_at),
    cmocka_unit_test(test_clone_state)
};

void test_init_new_game(void **state)
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
    init_new_game(&master_state);
    assert_memory_equal(master_state.white_pieces, 
        initial_white_pieces, sizeof(int)*16*2);
    assert_memory_equal(master_state.black_pieces, 
        initial_black_pieces, sizeof(int)*16*2);
}

void test_move_piece(void **state)
{
    init_new_game(&master_state);

    move_piece(&master_state, D4, D2);
    assert_int_equal(master_state.white_pieces[3][LOCATION], D4);
    move_piece(&master_state, E5, E7);
    assert_int_equal(master_state.black_pieces[4][LOCATION], E5);

    move_piece(&master_state, D5, D4);
    assert_int_equal(master_state.white_pieces[3][LOCATION], D5);
    move_piece(&master_state, E4, E5);
    assert_int_equal(master_state.black_pieces[4][LOCATION], E4);

    move_piece(&master_state, D6, D5);
    assert_int_equal(master_state.white_pieces[3][LOCATION], D6);
    move_piece(&master_state, E3, E4);
    assert_int_equal(master_state.black_pieces[4][LOCATION], E3);

    move_piece(&master_state, D7, D6);
    assert_int_equal(master_state.white_pieces[3][LOCATION], D7);
    assert_int_equal(master_state.black_pieces[3][PIECE], PIECE_NONE);
}

void test_get_piece_at(void **state)
{
    init_new_game(&master_state);
    piece_t p = get_piece_at(&master_state, A2);
    assert_int_equal(p, W_PAWN);
    p = get_piece_at(&master_state, H7);
    assert_int_equal(p, B_PAWN);
    p = get_piece_at(&master_state, E8);
    assert_int_equal(p, B_KING);
}

void test_clone_state(void **state)
{
    gamestate_t *new_state = malloc(sizeof(gamestate_t));
    gamestate_t *clone;
    fill_with_random(new_state, sizeof(gamestate_t));
    clone = clone_state(new_state);
    assert_memory_equal(clone, new_state, sizeof(gamestate_t));
    free(new_state);
    free(clone);
}

static void fill_with_random(void* ptr, int nbytes)
{
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, ptr, nbytes);
    close(fd);
}

