#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ai.h"
#include "snake.h"

// motor de burrice
void ai_run(minhocabrain *brain, posxy *food, int hasfood, int fieldx, int fieldy) {
	int retval = 0;

	if(!hasfood) 
		brain->mode = M_ROAMING;
	else
		brain->mode = M_HUNTING;
		
	if (brain->mode == M_ROAMING)
		retval = brain->s->dir;
	
	if (brain->mode == M_HUNTING) {
		// would be head (body collision calculations)
		posxy ficthead;

		// calculate distance from target (food)
		int xdist, ydist, nxdist, nydist, ixdist, iydist;

		// check hit var
		int i, diroptions[5], ficthit = 0, foundbest = 0;
		int checkgo;

		nxdist = snakehead(brain->s)->x - food->x; // <0 right >0 left
		nydist = snakehead(brain->s)->y - food->y; // <0 bottom >0 up
	 	ixdist = fieldx-abs(nxdist);
		iydist = fieldy-abs(nydist);

		if(nxdist > 0) ixdist *= -1;
		if(nydist > 0) iydist *= -1;

		if (abs(nxdist) <= abs(ixdist))
			xdist = nxdist;
		else
			xdist = ixdist;

		if (abs(nydist) <= abs (iydist)) 
			ydist = nydist;
		else
			ydist = iydist;

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
	// we have the answer "retval"

// FIXME
	diroptions[0] = retval;
	if (retval == UP || retval == DOWN)
		diroptions[2] = RIGHT;
	else
		diroptions[2] = DOWN;
	diroptions[1] = retval*-1;
	if (retval == UP || retval == DOWN)
		diroptions[3] = LEFT;
	else
		diroptions[3] = UP;
	diroptions[4] = brain->s->dir;
	
	for ( i = 0 ; i < 5 ; i++ ) {
		ficthit = 0;
		ficthead.x = snakehead(brain->s)->x;
		ficthead.y = snakehead(brain->s)->y;

		switch(diroptions[i]) {
			case UP:
				ficthead.y = (snakehead(brain->s)->y + (fieldy-1))%fieldy;
				break;
			case DOWN:
				ficthead.y = (snakehead(brain->s)->y + 1)%fieldy;
				break;
			case LEFT:
				ficthead.x = (snakehead(brain->s)->x + (fieldx-1))%fieldx;
				break;
			case RIGHT:
				ficthead.x = (snakehead(brain->s)->x + 1)%fieldx;
				break;
		}
	
        	/* Detect hit/unavailable direction */
	        for ( checkgo = 1; checkgo < (brain->s->size) ; checkgo++) {
        	        if ((ficthead.x == (brain->s->data+((brain->s->hpos+checkgo)%brain->s->size))->x) &&
                	        (ficthead.y == (brain->s->data+((brain->s->hpos+checkgo)%brain->s->size))->y)) {
					ficthit = 1;	
					foundbest = 0;
			}		
		}

		if (!ficthit)
			foundbest = 1;

		if(foundbest) {
			retval = diroptions[i];
			break;
		}
	}
	
	brain->s->dir = retval;
	}

}


			

 
		
