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
    if ( pins == 10 )
        current_roll++;
}

static bool is_spare(int frame )
{
    return roll[2*frame] + roll[2*frame + 1]== 10;
}

static bool is_strike (int frame)
{
    return roll[2*frame] == 10;
}

int bowling_game_score (void)
{
    int score = 0;
    int r = 0;
    for (int f=0; f<MAX_FRAMES; ++f) {
//        printf("frame %d: %d, %d\n", f, roll[2*f], roll[2*f + 1]);
        int frame_score = 0;
        frame_score += roll[r++]; // add the first roll
        frame_score += roll[r++]; // add the second roll
        score += frame_score;
        if ( is_strike(f) ) {
//            puts("strike!");
            score += roll[r] + roll[r+1]; // add the next two rolls as bonus
        } else if ( is_spare(f) ) {
//            puts("spare!");
            score += roll[r]; // add the next roll bonus
        }
    }
//    printf("score: %d\n", score);
    return score;
}
