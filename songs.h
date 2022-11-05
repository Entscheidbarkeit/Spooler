/**
 * Spotify playlist: https://open.spotify.com/playlist/77S2PAAxqry5fvqO7rhnq4?si=4h0jLM8tRSqRUJ2u4VAySQ
 * Bitconnect: https://www.youtube.com/watch?v=e5nyQmaq4k4
 * Operating System Song: https://www.youtube.com/watch?v=FGwevyxoycw
 **/

#pragma once

#include <stdlib.h>

#define NUM_SONGS 32

struct song {
    const char* title;
    const char** lyrics;
    const size_t lines;
};

extern const char* NEVER_GONNA_GIVE_YOU_UP[56];
extern const char* WHO_LET_THE_DOGS_OUT[79];
extern const char* WHAT_IS_LOVE[69];
extern const char* MAJOR_TOM[61];
extern const char* LOOKING_FOR_FREEDOM[52];
extern const char* SKANDAL_IM_SPERRBEZIRK[56];
extern const char* DANGER_ZONE[34];
extern const char* SCATMAN[98];
extern const char* I_LIKE_TO_MOVE_IT[81];
extern const char* TEQUILA[3];
extern const char* BARBIE_GIRL[58];
extern const char* DISCO_POGO[51];
extern const char* CHERI_CHERI_LADY[69];
extern const char* BOOMERANG[61];
extern const char* NEUNUNDNEUNZIG_LUFTBALLONS[41];
extern const char* BLUE_DA_BA_DEE[43];
extern const char* OCEAN_MAN[18];
extern const char* SHOUT[102];
extern const char* I_M_GONNA_BE_500_MILES[59];
extern const char* VERLIEBEN_VERLOREN_VERGESSEN_VERZEIHN[45];
extern const char* BIG_ENOUGH[63];
extern const char* BITCONNECT[77];
extern const char* NYAN_CAT[80];
extern const char* OPERATING_SYSTEM_SONG[45];
extern const char* SCHICKERIA[55];
extern const char* DER_KOMMISAR[83];
extern const char* STILL_ALIVE[49];
extern const char* WANT_YOU_GONE[39];
extern const char* LOL_INTERNET[41];
extern const char* COMPUTER_ICH_BEFEHLE_DIR[67];
extern const char* SURFIN_BIRD[90];
extern const char* O_TANNENBAUM[20];  // In Anlehnung an "Modern Operating Systems" von Andrew S. Tanenbaum
extern const struct song SONGS[NUM_SONGS];
