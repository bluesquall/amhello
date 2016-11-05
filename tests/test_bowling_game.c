// test_bowling_game.c
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#include "src/bowling_game.h"

#include <assert.h>

static void roll_many(int n,  int pins)
{
    for (int i=0; i<20; i++)
        bowling_game_roll( pins );
}

static void test_gutter_game (void)
{
    bowling_game_init();
    roll_many( 20, 0 );
    assert( bowling_game_score() == 0 && "test_gutter_game()" );
}

static void test_all_ones (void)
{
    bowling_game_init();
    roll_many( 20, 1 );
    assert( bowling_game_score() == 20 && "test_all_ones()" );
}

static void test_one_spare (void)
{
    bowling_game_init();
    roll_many( 2, 0 );
    roll_many( 2, 5 );
    roll_many( 2, 3 );
    roll_many( 14, 0 );
    assert( bowling_game_score() == 19 && "test_all_ones()" );
}


int main (void)
{
    test_gutter_game();
    test_all_ones();
}
