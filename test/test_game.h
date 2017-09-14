#ifndef TEST_GAME__H
#define TEST_GAME__H

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#define TEST_GAME_NUM_TESTS 4

void test_init_new_game(void **state);
void test_move_piece(void **state);
void test_get_piece_at(void **state);
void test_clone_state(void **state);

extern const struct CMUnitTest test_game_tests[TEST_GAME_NUM_TESTS];

#endif

