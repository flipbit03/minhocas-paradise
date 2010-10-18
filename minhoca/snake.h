#ifndef BASICDEFS_H
#include "basicdefs.h"
#endif

typedef struct {
	int size;
	int hpos;
	posxy * data;
} snake;

void initsnake(snake *retval, int xpos, int ypos, int snakesize);

void growsnake(snake *dsnake, int n);

// helper functions
posxy *snaketail(snake *s);
posxy *snakehead(snake *s);
posxy *snakeneck(snake *s);
