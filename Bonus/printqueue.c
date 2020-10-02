#include <stdio.h>
#include <stdlib.h>
#include "printqueque.h"

Queue createQueue()
{
	Queue print = (Queue)malloc(sizeof(QUEUE_HEAD));
	
	print->rear = print->rear = NULL;
	print->count = 0;
	
	return print;
}

Nodeptr createNode(int item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(QUEUE_NODE));
	ptr->item = item;
	ptr->next = NULL;
	
	return ptr;
}

void enqueue(Queue q, int item)
{
	Nodeptr temp = createNode(item);
	
	if(isEmpty(q))
		q->front = temp;
	else
		q->rear->next = temp;
		
	q->rear = temp;
	q->count++;
}

int dequeue(Queue q)
{
	Nodeptr temp = q->front;
	int x = temp->item;
	
	if(q->count == 1)
		q->rear = NULL;
		
	q->front = temp->next;
	temp->next = NULL;
	free(temp);
	q->count--;
	
	return x;
}

void display(Queue q)
{
	Nodeptr ptr = q->front;
	
	printf("\nPending call(s): ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->item);
		ptr = ptr->next;
	}
	printf("\n");
}

int isEmpty(Queue q)
{
	return q->count == 0;
}
