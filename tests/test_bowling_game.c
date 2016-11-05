// test_bowling_game.c
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#include "src/bowling_game.h"

#include <assert.h>

static void test_gutter_game (void)
{
    bowling_game_init();
    for (int i=0; i<20; i++)
        bowling_game_roll(0);
    assert( bowling_game_score() == 0 && "test_gutter_game()" );
}

int main (void)
{
    test_gutter_game();
}
