#include "Queue.h"

typedef struct Floor {
	int level;
	int step;
} Floor;

void BFS(int *f_ptr, int *s_ptr, int *g_ptr, int *u_ptr, int *d_ptr);
Floor * ConstructFloor(int level, int step);
