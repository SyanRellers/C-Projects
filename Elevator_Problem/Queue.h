#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct Node Node;

struct Node {
	Node *next;
	void * data;
};

typedef struct intNode intNode;

struct intNode {
	intNode *next;
	int data;
};

typedef struct {
	Node *head;
	Node *tail;
	int size;
} Queue;

typedef struct {
	intNode *head;
	intNode *tail;
	int size;
} IntQueue;


Queue *ConstructQueue();
void DestructQueue(Queue *queue);
int Enqueue(Queue *queue, Node *item);
Node * Dequeue(Queue *queue);
int isEmpty(Queue* queue);
Node *ConstructNode(Node * next, void * data);
void * getNodeData(Node * node);
void setNodeData(Node * node, void * data);

IntQueue *IntConstructQueue();
void IntDestructQueue(IntQueue *queue);
int IntEnqueue(IntQueue *queue, intNode *item);
intNode * IntDequeue(IntQueue *queue);
int IntisEmpty(IntQueue* queue);
intNode *ConstructIntNode(intNode * next, int data);
int getIntNodeData(intNode * node);
void setIntNodeData(intNode * node, int data);