#include <stdio.h>
#include <stdlib.h>
#include "stackqueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	stackItem data;
	int choice, repeat;
	char x;
	
	Stack s = newStack();
	Queue q = createQueue();
	
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
				push(s, data);
				enqueue(q, data);
				break;
			case 2:
				if(pop(s));
					enqueue(q, data);
				if(dequeue(q));
					push(s, data);
				break;
			default:
				printf("\nInvalid input");
				getch(x);
		}
		if(isEmptyStack(s) && isEmptyQueue(q))
		{
			displayStack(s);
			displayQueue(q);
		}
		
		printf("\nDo you wish to continue (1/0)? ");
		scanf("%d", &repeat);
	}
	while(repeat == 1);
	
	return 0;
}
