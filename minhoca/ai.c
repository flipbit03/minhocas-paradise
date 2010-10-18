#include <stdlib.h>
#include <math.h>

#include "ai.h"
#include "snake.h"

// motor de estupidez
void ai_run(minhocabrain *brain, posxy *food, int hasfood, int fieldx, int fieldy) {
	int retval = 0;

	if(!hasfood) 
		brain->mode = M_ROAMING;
	else
		brain->mode = M_HUNTING;
		
	if (brain->mode == M_ROAMING)
		retval = brain->s->dir;
	
	if (brain->mode == M_HUNTING) {
		// calculate distance from target (food)
		int xdist, ydist;
		xdist = snakehead(brain->s)->x - food->x; // <0 right >0 left
		ydist = snakehead(brain->s)->y - food->y; // <0 bottom >0 up
			 
		retval = brain->s->dir;
		if (abs(xdist) == abs(ydist)) {
			if (ydist < 0)
				retval = DOWN;
			else
				retval = UP;
		}
	
		if (abs(xdist) < abs(ydist)) { // xdist is the nearest
			if ( ((xdist < 0) && (brain->s->dir == LEFT)) ||
			     ((xdist > 0) && (brain->s->dir == RIGHT)) ) {
				if ( ydist < 0 )
					retval = DOWN;
				else
					retval = UP;
			}

			if (xdist < 0 && brain->s->dir != LEFT)
				retval = RIGHT;
			if (xdist > 0 && brain->s->dir != RIGHT)
				retval = LEFT;

			if (xdist == 0 && ydist < 0 && brain->s->dir != UP)
				retval = DOWN;
			if (xdist == 0 && ydist > 0 && brain->s->dir != DOWN)
				retval = UP;


		}
		else { //ydist is the nearest
			if ( ((ydist < 0) && (brain->s->dir == UP)) ||
				     ((ydist > 0) && (brain->s->dir == DOWN)) ) {
				if ( xdist < 0 )
					retval = RIGHT;
				else
					retval = LEFT;
			}

			if (ydist < 0 && brain->s->dir != UP)
				retval = DOWN;
			if (ydist > 0 && brain->s->dir != DOWN)
				retval = UP;

			if (ydist == 0 && xdist < 0 && brain->s->dir != LEFT)
				retval = RIGHT;
			if (ydist == 0 && xdist > 0 && brain->s->dir != RIGHT)
				retval = LEFT;


		}
	
		// Calculate if it's easier/nearer to go through the borders (side flip)
		if(retval == LEFT) {
			if ((abs(xdist) > fieldx/2) && brain->s->dir != LEFT) retval *= -1;
		} 
		else if (retval == RIGHT) {
			if ((abs(xdist) > fieldx/2) && brain->s->dir != RIGHT) retval *= -1;
		} 
		else if(retval == UP) {
			if ((abs(ydist) > fieldy/2) && brain->s->dir != UP) retval *= -1;
		} 
		else if(retval == DOWN) {
			if ((abs(ydist) > fieldy/2) && brain->s->dir != DOWN) retval *= -1;
		} 

		//else {	
		//if (abs(ydist) > fieldy/2) retval *= -1;
		//}

	}

	brain->s->dir = retval;
}


			

 
		
