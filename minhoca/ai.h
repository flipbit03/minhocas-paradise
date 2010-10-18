#ifndef AI_H
#define AI_H

#include "basicdefs.h"
#include "snake.h"

// Minhoca's AI modes
#define M_ROAMING 128
#define M_HUNTING 64

typedef struct {
        unsigned int mode;
        posxy target;
	snake *s;
} minhocabrain;

void ai_run(minhocabrain *brain, posxy *food, int hasfood, int fieldx, int fieldy);

#endif /* AI_H */
