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

static bool is_spare(int frame_start )
{
    return roll[frame_start] + roll[frame_start + 1] == 10;
}

static bool is_strike (int frame_start)
{
    return roll[frame_start] == 10;
}

static int plain_frame_score(int frame_start)
{
    return roll[frame_start] + roll[frame_start + 1];
}

static int spare_frame_score(int frame_start)
{
            puts("spare bonus!");
    return roll[frame_start] + roll[frame_start + 1] + roll[frame_start + 2];
}

static int strike_frame_score(int frame_start)
{
            puts("strike bonus!");
    return roll[frame_start] + roll[frame_start + 1] + roll[frame_start + 2];
}

int bowling_game_score (void)
{
    int score = 0;
    int frame_start_index = 0;
    for (int f=0; f<MAX_FRAMES; ++f) {
        if ( is_strike(frame_start_index) ) {
            score += strike_frame_score(frame_start_index);
            frame_start_index += 1;
        } else if ( is_spare(frame_start_index) ) {
            score += spare_frame_score(frame_start_index);
            frame_start_index += 2;
        } else {
            score += plain_frame_score(frame_start_index);
            frame_start_index += 2;
        }
    }
    printf("score: %d\n", score);
    return score;
}
