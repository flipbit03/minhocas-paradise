#ifndef SNAKE_H
#define SNAKE_H

#include "basicdefs.h"

typedef struct {
	int size;
	int hpos;
	int dir;
	posxy * data;
} snake;

void initsnake(snake *retval, int xpos, int ypos, int snakesize, int dir);

void growsnake(snake *dsnake, int n);

// helper functions
posxy *snaketail(snake *s);
posxy *snakehead(snake *s);
posxy *snakeneck(snake *s);

#endif /* SNAKE_H */
