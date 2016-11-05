// bowling_game.c
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#include "bowling_game.h"

enum { max_rolls = 21 };
static int roll[max_rolls] = { 0 };
static int current_roll = 0;

void bowling_game_init (void)
{
    for (int i=0; i<max_rolls; i++)
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
    for (int i=0; i<max_rolls; i++)
        score += roll[i];
    return score;
}
