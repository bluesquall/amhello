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
    for (int f=0; f<MAX_FRAMES; ++f)
        score += roll[r] + roll[r+1];
        r += 2;
    return score;
}
