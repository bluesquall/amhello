// bowling_game.c
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#include "bowling_game.h"

static int roll[MAX_ROLLS] = { 0 };
static int current_roll = 0;

void bowling_game_init (void)
{
    for (int i=0; i<MAX_ROLLS; i++)
        roll[i] = 0;
    current_roll = 0;
}

void bowling_game_roll (int pins)
{
    roll[current_roll++] = pins;
}

int bowling_game_score (void)
{
    int score = 0;
    int r = 0;
    for (int f=0; f<MAX_FRAMES; ++f) {
        int frame_score = 0;
        frame_score += roll[r++]; // add the first roll
        frame_score += roll[r++]; // add the second roll
        score += frame_score;
        if ( frame_score == 10 ) // check for spares
            score += roll[r]; // add the next roll bonus
    }
    printf("score: %d\n", score);
    return score;
}
