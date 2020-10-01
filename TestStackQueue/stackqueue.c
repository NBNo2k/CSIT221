#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

Stack newStack()
{
	Stack s;
	
	s = (Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top = NULL;
	
	return;
}

Nodeptr createNodeStack(int item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void push(Stack s, int item)
{
	Nodeptr temp = createNodeStack(item);
	temp->next = s->top;
	s->top = temp;
	s->count++;
}

int pop(Stack s)
{
	Nodeptr temp;
	int x = s->top->data;
	
	temp = s->top;
	s->top = temp->next;
	return x;
	temp->next = NULL;
	free(temp);
	s->count--;
}

int isEmptyStack(Stack s)
{
	if(s->count == 0)
		return 1;
	
	return 0;
}

void displayStack(Stack s)
{
	Nodeptr ptr = s->top;
	
	while(ptr != NULL)
	{
		printf("\nOutput Stack: ");
		printf("%d ", ptr->data);
	}
	printf("\n");
}

Queue createQueue()
{
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	
	q->front = q->rear = NULL;
	q->count = 0;
	
	return q;
}

Nodeptr createNodeQueue(int item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(QUEUE_NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void enqueue(Queue q, int item)
{
	Nodeptr temp;
	temp = createNodeQueue(item);
	
	if(isEmptyQueue(q))
		q->front = temp;
	else
		q->rear->next = temp;
		
	q->rear = temp;
	q->count++;
}

int dequeue(Queue q)
{
	Nodeptr temp;
	int x;
	
	temp = q->front;
	x = q->front->data;
	
	if(q->count == 1)
		q->front = q->rear = NULL;
		
	q->front = temp->next;
	return x;
	temp->next = NULL;
	free(temp);
	q->count--;
}

int isEmptyQueue(Queue q)
{
	return q->count == 0;
}

void displayQueue(Queue q)
{
	Nodeptr ptr = q->front;
	
	while(ptr != NULL)
	{
		printf("\nOutput Queue: ");
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

