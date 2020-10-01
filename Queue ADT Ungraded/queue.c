#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue createQueue()
{
	Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
	
	q->front = q->rear = NULL;
	q->count = 0;
	
	return q;
}

Nodeptr createNode(int item)
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
	temp = createNode(item);
	
	
	if(isEmpty(q))
		q->front = temp;
	else
		q->rear->next = temp;
	
	q->rear = temp;
	q->count++;
}

void dequeue(Queue q)
{
	Nodeptr temp;
	temp = q->front;
	
	if(q->count == 1)
		temp = q->rear = NULL;
	
	q->front = temp->next;
	temp->next = NULL;
	free(temp);
	q->count--;
}

void display(Queue q)
{
	Nodeptr ptr = q->front;
	
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int isEmpty(Queue q)
{
	return q->count==0;	
}

int identical(Queue q1, Queue q2)
{
	Nodeptr ptr1 = q1->front;
	Nodeptr ptr2 = q2->front;
	int flag;
	
	if(ptr1 == NULL && ptr2 == NULL)
		flag = 1;
	
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->data == ptr2->data)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	if(flag == 1)
		return 1;
	else
		return 0;
}

void sort(Queue q)
{
	int swapped;
	Nodeptr ptr;
	Nodeptr temp = NULL;
	
	//if list is empty
	if(q->front == NULL)
		return;
		
	do
	{
		swapped = 0;
		ptr = q->front;
		
		while(ptr->next != temp)
		{
			if(ptr->data > ptr->next->data)
			{
				int temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
				
				swapped = 1;
			}
			ptr = ptr->next;
		}
		temp = ptr;
	}
	while(swapped);
}

int isEqual(Queue q1, Queue q2)
{
	Nodeptr ptr1 = q1->front;
	Nodeptr ptr2 = q2->front;
	int flag;
	
	sort(q1);
	sort(q2);
	
	if(ptr1 == NULL && ptr2 == NULL)
		flag = 1;
		
	if(ptr1 == NULL && ptr2 != NULL || ptr1 != NULL && ptr2 == NULL)
		flag = 0;
	
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->data == ptr2->data)
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	if(flag == 1)
		return 1;
	else
		return 0;
}
