#include "elevatorProblem.h"

int flag, count;

Queue * queue;
IntQueue * holdValQueue;

int graph [100];

// Breadth First Seach Function
void BFS(int *f_ptr, int *s_ptr, int *g_ptr, int *u_ptr, int *d_ptr)
{
	int f = *f_ptr;
	int s = *s_ptr;
	int g = *g_ptr;
	int u = *u_ptr;
	int d = *d_ptr;

	// printf("\nIn BFS\n");

	flag = 0;

	Floor * current = ConstructFloor(s, 0);
	Floor * next = ConstructFloor(s, 0);

	if (queue == NULL)
	{
		queue = ConstructQueue();
	}

	if (holdValQueue == NULL)
	{
		holdValQueue = IntConstructQueue();
	}

	while (isEmpty(queue) == FALSE)
	{
		Dequeue(queue);
	}

	Node * newNode = ConstructNode(NULL, current);

	Enqueue(queue, newNode);

	int i;

	for (i = 0; i < 100; i++)
	{
		graph[i] = 0;
	}

	graph[s - 1] = 1;


	while (isEmpty(queue) == FALSE)
	{
		// printf("Iteration\n");

		Node * currentNode = Dequeue(queue);

		current = currentNode->data;

		int curLevel = current->level;
		int curStep = current->step;

		// printf("\nCurrent Level = %d\n", curLevel);

		intNode * printNode = ConstructIntNode(NULL, next->level);

		IntEnqueue(holdValQueue, printNode);


		for(i = 1; i <= 2; i++) 
		{
			int nextLevel;

			if (i == 1)
			{
				// printf("Opt 1\n");

				nextLevel = curLevel + u;
			}
			else if (i == 2)
			{
				// printf("Opt 2\n");
				nextLevel = curLevel - d;
			}

			if ((nextLevel < 1) || (nextLevel > f))
			{
				// printf("Out of Range\n");
				continue;
			}

			if (graph[nextLevel - 1] == 0)
			{
				// printf("In graph[next->level] == 1\n");

				next->level = nextLevel;

				graph[nextLevel - 1] = 1;

				next->step = curStep + 1;

				Node * newNode2 = ConstructNode(NULL, next);

				Enqueue(queue, newNode2);


				if (nextLevel == g)
				{
					flag = 1;
					count = next->step;

					// printf("\nOut BFS 1\n");

					DestructQueue(queue);

					return;
				}
			}
		}
	}

	// printf("\nOut BFS 1\n");

	DestructQueue(queue);

	return;
}

Floor * ConstructFloor(int level, int step)
{
	// printf("\nIn ConstructFloor\n");

	Floor * floor = (Floor *)malloc(sizeof(Floor));

	if (!floor)
	{
		// printf("\nOut ConstructFloor\n");
		return floor;
	}

	floor->level = level;
	floor->step = step;

	// printf("\nOut ConstructFloor\n");

	return floor;
}

int main ()
{
	
	printf("\nEnter the following data separated by spaces: NumberOfFloors StartFloor GoalFloor NumberFloorUp NumberFloorDown\n1 <= start floor, goal floor <= number of floors <= 100 and 0 <= num floors up, num floors down <= 100. The floors are one-indexed, i.e. if there are 10 stories, start and goal be in [1; 10].\n");

	int check_condition = 0;

	int f, s, g, u, d;

	while(check_condition == 0)
	{
		scanf(" %d %d %d %d %d", &f, &s, &g, &u, &d);

		if (s >= 1 && s <= f && f <= 100 && f >= 1 && g <= f && g >= 1 && 0 <= u && u <= 100 && 0 <= d && d <= 100)
		{
			check_condition = 1;
		}
		else
		{
			printf("\nPlease Enter valid numbers. 1 <= start floor, goal floor <= number of floors <= 100 and 0 <= num floors up, num floors down <= 100. The floors are one-indexed, i.e. if there are 10 stories, start and goal be in [1; 10].\n");
		}
	}

	BFS(&f, &s, &g, &u, &d);

	if (flag == 1)
	{
		printf("\n\n");

		while (!IntisEmpty(holdValQueue))
		{
			intNode * itemNode = IntDequeue(holdValQueue);		 

			int printLevel = itemNode->data;

			printf("%d->", printLevel);
		}
		// printf("\n\nNumber of steps to get to goal floor: %d\n\n\n\n", count);

		printf("%d\n\n\n", g);
	}
	else
	{
		printf("\n\n\nUse the stairs\n");
	}

	IntDestructQueue(holdValQueue);
}

