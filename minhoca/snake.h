#include "basicdefs.h"

typedef struct {
	int size;
	int hpos;
	posxy * data;
} snake;

snake initsnake(int xpos, int ypos, int snakesize);

// helper functions
posxy *snaketail(snake *s);
posxy *snakehead(snake *s);
posxy *snakeneck(snake *s);
