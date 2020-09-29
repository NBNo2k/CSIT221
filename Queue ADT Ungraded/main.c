#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q1 = createQueue();
	Queue q2 = createQueue();
	Queue q = createQueue();
	int item, choice, x = 1, z;
	char y;
	
	while(x == 1)
	{
		system("cls");
		printf("[1] Enqueue\n");
		printf("[2] Dequeue\n");
		printf("[3] Display\n");
		printf("[4] Check empty\n");
		printf("[5] Identical\n");
		printf("[6] Equal\n");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("[1] q1\n");
				printf("[2] q2\n");
				printf("Enter choice: ");
				scanf("%d", &z);
				
				if(z == 1)
				{
					printf("\nInput: ");
					scanf("%d", &item);
					enqueue(q1, item);
				}
				else
				{
					printf("\nInput: ");
					scanf("%d", &item);
					enqueue(q2, item);
				}
				break;
			case 2:
				printf("[1] q1\n");
				printf("[2] q2\n");
				printf("Enter choice: ");
				scanf("%d", &z);
				
				if(z == 1)
					dequeue(q1);
				else
					dequeue(q2);
				break;
			case 3:
				printf("[1] q1\n");
				printf("[2] q2\n");
				printf("Enter choice: ");
				scanf("%d", &z);
				
				if(z == 1)
					display(q1);
				else
					display(q2);
				break;
			case 4:
				if(isEmpty(q1))
					printf("\nEmpty");
				else
					printf("\nNot empty");
				break;
			case 5:
				if(!identical(q1, q2))
					printf("\nNot identical");
				else
					printf("\nIdentical");
				break;
			case 6:
				//sort(q);
				if(isEqual(q1, q2))
					printf("\nEqual");
				else
					printf("\nNot equal");
				break;
			default:
				printf("\nInvalid input");
				getch(x);
		}
		printf("\nDo you wish to continue(1/0)? ");
		scanf("%d", &x);
	}
	
	return 0;
}
