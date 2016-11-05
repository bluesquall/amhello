// bowling_game.h
// A test-driven development example
// see http://www.slideshare.net/amritayan/test-driven-development-in-c

#define MAX_FRAMES 10
#define MAX_ROLLS 21

#include <stdbool.h>

void bowling_game_init (void);
void bowling_game_roll (int pins);
int bowling_game_score (void);

