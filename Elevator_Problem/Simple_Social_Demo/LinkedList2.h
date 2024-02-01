// All code comes from CS 2050 provided Linked List Structs

#include <stdio.h>


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct Person Person;
typedef struct Node Node;

struct Node {
	Node *next;
	Person * data;
};

typedef struct {
	Node *head;
	int size;
} List;


struct Person {
	char * name;
	List * friendsList;
};

int isValidIndex(List *list, int index);
Node* makeNode(void *data, Node *next);
void* freeNode(Node *node);
void* nodeAtIndex(List *list, int index);
void clearList(List *list);
Node* setHead(List *list, Node *newHead);
int indexOf(List *list, void *object);
int insertAtIndex(List *list, void *object, int index);
void* removeAtIndex(List *list, int index);
List* initList();
int getSize(List *list);
void* getAtIndex(List *list, int index);
void freeList(List *list);

#endif
