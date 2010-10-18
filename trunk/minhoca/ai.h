#include "basicdefs.h"

typedef struct {
        unsigned int mode;
        posxy target;
} minhocabrain;

int ai_run(minhocabrain * brain, posxy * currpos, posxy * food, int hasfood, int dir);

