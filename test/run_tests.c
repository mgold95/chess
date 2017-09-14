#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "test_game.h"

int main(int argc, char **argv)
{
    void *ptr;
    int retval;
    int counter;
    int byte_count = 0;
    int all_tests_size = sizeof(test_game_tests);
    ptr = malloc(all_tests_size);
    if (!ptr) {
        printf("Error: memory allocation failed.\n");
        return -EINVAL;
    }
    memset(ptr, 0, all_tests_size);
    if (argc == 1) {
        // if the user provided no args, run all tests
        memcpy((ptr+byte_count), test_game_tests, sizeof(test_game_tests));
    } else {
        // otherwise, parse args to see which tests to run
        while (++counter < argc) {
            if (!strcmp(argv[counter], "game")) {
                if ((byte_count += sizeof(test_game_tests)) > all_tests_size) {
                    printf("Error: set of tests to run is invalid.\n");
                    free(ptr);
                    return -EINVAL;
                }
                memcpy((ptr+byte_count), test_game_tests, sizeof(test_game_tests));
                byte_count += sizeof(test_game_tests);
            } else {
                printf("Error: `%s' is not a valid test.\n", argv[counter]);
                free(ptr);
                return -EINVAL;
            }
        }
    }
    retval = cmocka_run_group_tests(ptr, NULL, NULL);
    free(ptr);
    return retval;
}

