#ifndef BASICDEFS_H
#include "basicdefs.h"
#endif

typedef struct {
        unsigned int mode;
        posxy target;
} minhocabrain;

int ai_run(minhocabrain * brain, posxy * currpos, posxy * food, int hasfood, int dir);

