#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int data;
	int choice, repeat;
	char x;
	
	Stack stackInput = newStack();
	Stack stackOutput = newStack();
	
	Queue queueInput = newQueue();
	Queue queueOutput = newQueue();
	
	do
	{
		system("cls");
		printf("Test Driver Menu\n");
		printf("[1] Insert\n");
		printf("[2] Delete\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Item: ");
				scanf("%d", &data);
				push(stackInput, data);
				enqueue(queueInput, data);
				break;
			case 2:
				if(isEmptyStack(stackInput) && isEmptyQueue(queueInput))
				{
					displayStack(stackOutput);
					displayQueue(queueOutput);
				}	
				else
				{
					//Queue to stack
					push(stackOutput, dequeue(queueInput));
					
					//Stack to queue
					enqueue(queueOutput, pop(stackInput));
				}
				break;
			default:
				printf("\nInvalid input");
				getch(x);
		}	
		printf("\nDo you wish to continue (1/0)? ");
		scanf("%d", &repeat);
	}
	while(repeat == 1);
	
	return 0;
}
