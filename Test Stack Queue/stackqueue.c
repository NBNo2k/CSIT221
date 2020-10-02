#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

//Stack
Stack newStack()
{
	Stack s;
	
	s = (Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top = NULL;
	
	return s;
}

//For both stack and queue
Nodeptr createNode(int item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void push(Stack s, int item)
{
	Nodeptr temp = createNode(item);
	
	temp->next = s->top;
	s->top = temp;
	s->count++;
}

int pop(Stack s)
{
	Nodeptr temp;
	int x = temp->data;
	
	temp = s->top;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;
	
	return x;
}

void displayStack(Stack s)
{
	Nodeptr ptr = s->top;
	
	printf("\nOutput Stack: ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

int isEmptyStack(Stack s)
{
	return s->count == 0;
}

//Queue
Queue newQueue()
{
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	
	q->front = q->rear = NULL;
	q->count = 0;
	
	return q;
}

void enqueue(Queue q, int item)
{
	Nodeptr temp;
	temp = createNode(item);
	
	if(isEmptyQueue(q))
		q->front = temp;
	else
		q->rear->next = temp;
		
	q->rear = temp;
	q->count++;
}

int dequeue(Queue q)
{
	Nodeptr temp = q->front;
	int x = temp->data;;
	
	if(q->count == 1)
		q->rear = NULL;
		
	q->front = temp->next;
	temp->next = NULL;
	free(temp);
	q->count--;
	
	return x;
}

void displayQueue(Queue q)
{
	Nodeptr ptr = q->front;
	
	printf("\nOutput Queue: ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int isEmptyQueue(Queue q)
{
	return q->count == 0;
}
