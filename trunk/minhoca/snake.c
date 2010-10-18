#include <stdlib.h>
#include "snake.h" // snake datatype

snake initsnake(int xpos, int ypos, int snakesize) {
	int i;
	snake retval;
	retval.data = (posxy *) malloc(sizeof(posxy)*snakesize);
	retval.size = snakesize;
	retval.hpos = 0;
	for(i = 0; i < snakesize; i++) {
		(retval.data+i)->x = xpos;
		(retval.data+i)->y = ypos;
	}
}

// helper functions
posxy *snaketail(snake *s) {
	return (s->data+((s->hpos+(s->size-1))%s->size));
}

posxy *snakehead(snake *s) {
	return (s->data+s->hpos);
}

posxy *snakeneck(snake *s) {
	return (s->data+((s->hpos+(s->size+1))%s->size));
}

