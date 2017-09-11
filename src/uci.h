#ifndef UCI__H
#define UCI__H

typedef enum uci_cmd_t {
    UCI = 0,
    ISREADY,
    SETOPTION,
    UCINEWGAME,
    POSITION,
    GO,
    STOP,
    QUIT,

    UNKNOWN = -1
} uci_cmd_t;

// Main command parsing loop
void uci_loop(void);

// Command functions
void uci_id(void);
void uci_ready(void);
void uci_go(void);

// Various helper functions
uci_cmd_t parse_token(char* token);

#endif

