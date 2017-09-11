////////////////////////////////////////////////////////////////////////////////
// uci.c
//
// Provides general setup and command-line parsing.
//
// author: Michael Goldstein
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "info.h"
#include "types.h"

#include "uci.h"

#define CMD_SIZE 128

// main loop, should be the only thing running on the main thread
// parses UCI commands and dispatches functions to handle them
void uci_loop()
{
    char *str;
    char *token;
    uci_cmd_t command;

    // disable buffering because we want all io immediately availebl and posted
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    str = malloc(CMD_SIZE);
    if (!str) {
        printf("Failed to allocate memory.\n");
        exit(0);
    }
    while (1) {
        fgets(str, CMD_SIZE, stdin);
        if (str[0] == '\0' || str[0] == '\n') {
            continue;
        }
        token = strtok(str, " \n");
        command = parse_token(token);
        switch (command) {
            case UCI:
                uci_id();
                break;
            case ISREADY:
                uci_ready();
                break;
            case SETOPTION:
                break;
            case UCINEWGAME:
            case POSITION:
            case GO:
                uci_go();
                break;
            case QUIT:
                free(str);
                exit(0);
            default:
                printf("Unknown command: %s\n", token);
                break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Command functions
//

void uci_id()
{
    // print name and author
    printf("id name %s %s\n", NAME, VERSION);
    printf("id author %s\n", AUTHORS);
    // print options

    // send ok
    printf("uciok\n");
}

void uci_ready()
{
    printf("readyok\n");
}

void uci_option()
{
    char *token;
    token = strtok(NULL, " \n");
    printf("No such option: %s\n", token);
}

void uci_newgame()
{

}

void uci_position()
{

}

void uci_go()
{
    char sq[3];
    sqtoa(sq, C8);
    printf("%s", sq);
}

uci_cmd_t parse_token(char *token)
{
    if (!strncmp("uci", token, CMD_SIZE)) {
        return UCI;
    } else if (!strncmp("isready", token, CMD_SIZE)) {
        return ISREADY;
    } else if (!strncmp("setoption", token, CMD_SIZE)) {
        return SETOPTION;
    } else if (!strncmp("ucinewgame", token, CMD_SIZE)) {
        return UCINEWGAME;
    } else if (!strncmp("go", token, CMD_SIZE)) {
        return GO;
    } else if (!strncmp("stop", token, CMD_SIZE)) {
        return STOP;
    } else if (!strncmp("quit", token, CMD_SIZE)) {
        return QUIT;
    }

    return UNKNOWN;
}

#undef CMD_SIZE

