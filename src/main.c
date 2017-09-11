////////////////////////////////////////////////////////////////////////////////
// main.c
//
// Provides general setup and command-line parsing.
//
// author: Michael Goldstein
//

// library includes
#include <stdio.h>

// project includes
#include "uci.h"
#include "info.h"

int main(void)
{
    printf("%s version %s by %s.\n", NAME, VERSION, AUTHORS);
    uci_loop();
    return 0;
}
