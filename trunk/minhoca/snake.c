#include <stdio.h>
#include <stdlib.h>
#include "snake.h" // snake datatype

void initsnake(snake *retval, int xpos, int ypos, int snakesize, int dir) {
	int i;
	retval->dir = dir;
	retval->data = (posxy *) malloc(sizeof(posxy)*snakesize);
	retval->size = snakesize;
	retval->hpos = 0;
	for(i = 0; i < snakesize; i++) {
		(retval->data+i)->x = xpos;
		(retval->data+i)->y = ypos;
	}
}

void growsnake(snake *dsnake, int n) {
	dsnake->size += 1;
	if ((dsnake->data = (posxy *) realloc(dsnake->data, sizeof(posxy)*dsnake->size)) == NULL) {
		printf("Error: Cannot grow snake --> Out of Memory!!!\n");
		exit(1);
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

