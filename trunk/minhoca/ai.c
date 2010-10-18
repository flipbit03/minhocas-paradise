#include <stdlib.h>
#include <math.h>
#include <SDL.h>

// Minhoca's AI modes
#define M_ROAMING 128
#define M_HUNTING 64

#include "ai.h"

typedef struct {
        unsigned int mode;
        posxy target;
} minhocabrain;

// motor de demencia
int ai_run(minhocabrain *brain, posxy *currpos, posxy *food, int hasfood, int dir) {
	int retval = 0;

	if(!hasfood) 
		brain->mode = M_ROAMING;
	else
		brain->mode = M_HUNTING;
		
	if (brain->mode == M_ROAMING)
		retval = dir;
	
	if (brain->mode == M_HUNTING) {
		// calculate distance from target (food)
		int xdist, ydist;
		xdist = currpos->x - food->x; // <0 right >0 left
		ydist = currpos->y - food->y; // <0 bottom >0 up
		retval = dir;
		if (abs(xdist) == abs(ydist)) {
			if (ydist < 0)
				retval = DOWN;
			else
				retval = UP;
		}
	
		if (abs(xdist) < abs(ydist)) { // xdist is the nearest
			if ( ((xdist < 0) && (dir == LEFT)) ||
			     ((xdist > 0) && (dir == RIGHT)) ) {
				if ( ydist < 0 )
					retval = DOWN;
				else
					retval = UP;
			}

			if (xdist < 0 && dir != LEFT)
				retval = RIGHT;
			if (xdist > 0 && dir != RIGHT)
				retval = LEFT;

			if (xdist == 0 && ydist < 0 && dir != UP)
				retval = DOWN;
			if (xdist == 0 && ydist > 0 && dir != DOWN)
				retval = UP;


		}
		else { //ydist is the nearest
			if ( ((ydist < 0) && (dir == UP)) ||
				     ((ydist > 0) && (dir == DOWN)) ) {
				if ( xdist < 0 )
					retval = RIGHT;
				else
					retval = LEFT;
			}

			if (ydist < 0 && dir != UP)
				retval = DOWN;
			if (ydist > 0 && dir != DOWN)
				retval = UP;

			if (ydist == 0 && xdist < 0 && dir != LEFT)
				retval = RIGHT;
			if (ydist == 0 && xdist > 0 && dir != RIGHT)
				retval = LEFT;


		}
	}
	return retval;
}


			

 
		
