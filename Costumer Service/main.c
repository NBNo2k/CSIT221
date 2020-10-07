#include <stdio.h>
#include <stdlib.h>
#include "printqueque.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int choice, repeat;
	int item;
	char x;
	
	Queue q = createQueue();
	
	do
	{
		system("cls");
		printf("Print Menu\n");
		printf("[1] Caller\n");
		printf("[2] Pending Calls\n");
		printf("[3] Answer calls\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("\nPhone number: ");
				scanf("%d", &item);
				enqueue(q, item);
				break;
			case 2:
				if(isEmpty(q))
					printf("\nNo more callers");
				else
					display(q);
				break;
			case 3:
				if(isEmpty(q))
					printf("\nNo more callers");
				else
					printf("\nAnswering number: %d", dequeue(q));
				break;
			default:
				printf("\nInvalid input");
				getch(x);
		}
		printf("\nDo you wish to go back to menu(1/0)? ");
		scanf("%d", &repeat);
	}
	while(repeat == 1);
	
	return 0;
}
