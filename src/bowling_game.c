// bowling_game.c
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#include "bowling_game.h"

static int score = 0;

void bowling_game_init (void)
{
    score = 0;
}

void bowling_game_roll (int pins)
{}

int bowling_game_score (void)
{
    return score;
}
