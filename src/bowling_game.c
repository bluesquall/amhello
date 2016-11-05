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

static int normal_frame_score(int frame)
{
    int start_of_frame = 2 * frame;
    return roll[start_of_frame] + roll[start_of_frame + 1];
}

static int spare_bonus(int frame)
{
//            puts("spare bonus!");
    int start_of_bonus = 2 * (frame + 1);
    return roll[start_of_bonus];
}

static int strike_bonus(int frame)
{
//            puts("strike bonus!");
    int start_of_bonus = 2 * (frame + 1);
    return roll[start_of_bonus] + roll[start_of_bonus + 1];
}

int bowling_game_score (void)
{
    int score = 0;
    for (int f=0; f<MAX_FRAMES; ++f) {
//        printf("frame %d: %d, %d\n", f, roll[2*f], roll[2*f + 1]);
        score += normal_frame_score(f);
        if ( is_strike(f) ) {
            score += strike_bonus(f);
        } else if ( is_spare(f) ) {
            score += spare_bonus(f);
        }
    }
//    printf("score: %d\n", score);
    return score;
}
