#include "Queue.h"

Queue *ConstructQueue()
{
	// printf("In ConstructQueue\n");

	Queue *queue = (Queue*) malloc(sizeof(Queue));
	
	if (!queue)
	{
		return NULL;
	}

	queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    // printf("Out ConstructQueue\n");

    return queue;
}

Node *ConstructNode(Node * next, void * data)
{
	// printf("In ConstructNode\n");

	Node *node = (Node*) malloc(sizeof(Node));
	
	if (!node)
	{
		return NULL;
	}

	node->next = next;
    node->data = data;

    // printf("Out ConstructNode\n");

    return node;
}

void * getNodeData(Node * node)
{
	// printf("In getNodeData\n");

	if (!node)
	{
		// printf("Out getNodeData\n");
		return (node->data);
	}
	else
	{
		// printf("Out getNodeData\n");
		return NULL;
	}
}

void setNodeData(Node * node, void * data)
{
	// printf("In setNodeData\n");

	if (!node && !data)
	{
		node->data = data;
	}

	// printf("Out setNodeData\n");
}



void DestructQueue(Queue *queue)
{
	// printf("In DesctructQueue\n");

	Node * node;

	while (!isEmpty(queue))
	{
		node = Dequeue(queue);

		free(node);
	}

	free(queue);

	// printf("Out DestructQueue\n");
}


int Enqueue(Queue *queue, Node *item)
{
	// printf("In Eneueue\n");

	if ((queue == NULL) || (item == NULL)) 
	{
		// printf("Leave Enqueue\n");
        return FALSE;
    }

    item->next = NULL;

    if (queue->size == 0) 
    {
        queue->head = item;
        queue->tail = item;
    } 
    else 
    {
        queue->tail->next = item;
        queue->tail = item;
    }

    (queue->size)++;
    // printf("Leave Enqueue\n");
    return TRUE;
}


Node * Dequeue(Queue *queue)
{
	// printf("In Dequeue\n");

	Node *item;
    
    if (isEmpty(queue))
    {
    	// printf("Out Dequeue\n");

        return NULL;
    }

    item = queue->head;
    queue->head = (queue->head)->next;
    queue->size--;

    // printf("Out Dequeue\n");
    return item;    
}

int isEmpty(Queue* queue)
{
	// printf("In isEmpty\n");

	if (queue == NULL) 
	{
		// printf("Out isEmpty\n");
        return FALSE;
    }

    if (queue->size == 0) 
    {
    	// printf("Out isEmpty\n");
        return TRUE;
    } 
    else 
    {
    	// printf("Out isEmpty\n");
        return FALSE;
    }

}

IntQueue *IntConstructQueue()
{
	// printf("In ConstructQueue\n");

	IntQueue *queue = (IntQueue*) malloc(sizeof(Queue));
	
	if (!queue)
	{
		return NULL;
	}

	queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    // printf("Out ConstructQueue\n");

    return queue;
}

intNode *ConstructIntNode(intNode * next, int data)
{
	// printf("In ConstructNode\n");

	intNode *node = (intNode*) malloc(sizeof(intNode));
	
	if (!node)
	{
		return NULL;
	}

	node->next = next;
    node->data = data;

    // printf("Out ConstructNode\n");

    return node;
}

int getIntNodeData(intNode * node)
{
	// printf("In getNodeData\n");

	if (!node)
	{
		// printf("Out getNodeData\n");
		return (node->data);
	}
	else
	{
		// printf("Out getNodeData\n");
		return 0;
	}
}

void setIntNodeData(intNode * node, int data)
{
	// printf("In setNodeData\n");

	if (!node)
	{
		node->data = data;
	}

	// printf("Out setNodeData\n");
}



void IntDestructQueue(IntQueue *queue)
{
	// printf("In DesctructQueue\n");

	intNode * node;

	while (!IntisEmpty(queue))
	{
		node = IntDequeue(queue);
		free(node);
	}

	free(queue);

	// printf("Out DestructQueue\n");
}


int IntEnqueue(IntQueue *queue, intNode *item)
{
	// printf("In Eneueue\n");

	if ((queue == NULL) || (item == NULL)) 
	{
		// printf("Leave Enqueue\n");
        return FALSE;
    }

    item->next = NULL;

    if (queue->size == 0) 
    {
        queue->head = item;
        queue->tail = item;
    } 
    else 
    {
        queue->tail->next = item;
        queue->tail = item;
    }

    (queue->size)++;
    // printf("Leave Enqueue\n");
    return TRUE;
}


intNode * IntDequeue(IntQueue *queue)
{
	// printf("In Dequeue\n");

	intNode *item;
    
    if (IntisEmpty(queue))
    {
    	// printf("Out Dequeue\n");

        return NULL;
    }

    item = queue->head;
    queue->head = (queue->head)->next;
    queue->size--;

    // printf("Out Dequeue\n");
    return item;    
}

int IntisEmpty(IntQueue* queue)
{
	// printf("In isEmpty\n");

	if (queue == NULL) 
	{
		// printf("Out isEmpty\n");
        return FALSE;
    }

    if (queue->size == 0) 
    {
    	// printf("Out isEmpty\n");
        return TRUE;
    } 
    else 
    {
    	// printf("Out isEmpty\n");
        return FALSE;
    }

}





