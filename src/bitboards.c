#include "bitboards.h"

const bitboard_t W_ATTACK_boardS [N_PIECE_TYPES][N_SQUARES] = {
    { // Bitboards of squares white pawns on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        0x0000000000020000ull, 0x0000000000050000ull, 0x00000000000A0000ull, 0x0000000000140000ull, 0x0000000000280000ull, 0x0000000000500000ull, 0x0000000000A00000ull, 0x0000000000800000ull,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        0x0000000002000000ull, 0x0000000005000000ull, 0x000000000A000000ull, 0x0000000014000000ull, 0x0000000028000000ull, 0x0000000050000000ull, 0x00000000A0000000ull, 0x0000000080000000ull,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        0x0000000200000000ull, 0x0000000500000000ull, 0x0000000A00000000ull, 0x0000001400000000ull, 0x0000002800000000ull, 0x0000005000000000ull, 0x000000A000000000ull, 0x0000008000000000ull,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        0x0000020000000000ull, 0x0000050000000000ull, 0x00000A0000000000ull, 0x0000140000000000ull, 0x0000280000000000ull, 0x0000500000000000ull, 0x0000A00000000000ull, 0x0000800000000000ull,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        0x0002000000000000ull, 0x0005000000000000ull, 0x000A000000000000ull, 0x0014000000000000ull, 0x0028000000000000ull, 0x0050000000000000ull, 0x00A0000000000000ull, 0x0080000000000000ull,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        0x0200000000000000ull, 0x0500000000000000ull, 0x0A00000000000000ull, 0x1400000000000000ull, 0x2800000000000000ull, 0x5000000000000000ull, 0xA000000000000000ull, 0x8000000000000000ull,
        // A8, B8, C8, D8, E8, F8, G8, H8
        0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull
    },

    { // Bitboards of squares white knights on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        // A8, B8, C8, D8, E8, F8, G8, H8
    },

    { // Bitboards of squares white bishops on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        // A8, B8, C8, D8, E8, F8, G8, H8
    },

    { // Bitboards of squares white rooks on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        // A8, B8, C8, D8, E8, F8, G8, H8
    },

    { // Bitboards of squares white queens on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        // A8, B8, C8, D8, E8, F8, G8, H8
    },

    { // Bitboards of squares white kings on a given square can attack
        // A1, B1, C1, D1, E1, F1, G1, H1,
        // A2, B2, C2, D2, E2, F2, G2, H2,
        // A3, B3, C3, D3, E3, F3, G3, H3,
        // A4, B4, C4, D4, E4, F4, G4, H4,
        // A5, B5, C5, D5, E5, F5, G5, H5,
        // A6, B6, C6, D6, E6, F6, G6, H6,
        // A7, B7, C7, D7, E7, F7, G7, H7,
        // A8, B8, C8, D8, E8, F8, G8, H8
    }
};
