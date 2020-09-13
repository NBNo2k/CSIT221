#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	Set s1, s2, s3, s, result;
	char x;
	int elem;
	
	s1 = initialize();
	s2 = initialize();
	s3 = initialize();
	
	while(1)
	{
		system("cls");
		
		//Menu
		printf("Set Menu\n\n");
		printf("[1] Add\n");
		printf("[2] Union\n");
		printf("[3] Intersection\n");
		printf("[4] Difference\n");
		printf("[5] Symmetric Difference\n");
		printf("[6] Subset\n");
		printf("[7] Disjoint\n");
		printf("[8] Equal");
		printf("\n\nEnter choice: ");
		int choice; scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				system("cls");
				printf("Add Menu\n\n");
				printf("[a] Set 1\n");
				printf("[b] Set 2");
				printf("\n\nEnter choice: ");
				char choicey; scanf("%s", &choicey);
				
				if(choicey == 'a')
				{
					printf("Enter element: ");
					scanf("%d", &elem);
					s1 = add(s1, elem);
					printf("Set 1: ");
					display(s1);
				}
				else if(choicey == 'b')
				{
					printf("Enter element: ");
					scanf("%d", &elem);
					s2 = add(s2, elem);
					printf("Set 2: ");
					display(s2);
				}
				else
					printf("Invalid choice");
				break; 
			case 2:
				printf("Union: ");
				getUnion(s1, s2);
				break;
			case 3:
				printf("Intersection: ");
				intersection(result, s1, s2);
				break;
			case 4:
				printf("Difference: ");
				difference(result, s1, s2);
				break;
			case 5:
				printf("Symmetric Difference: ");
				symmetricdifference(result, s1, s2);
				break;
			case 6:
				if(subset(s1, s2) == 1)
					printf("Set 1 is a subset of set 2");
				else
					printf("Set 1 is not a subset of set 2");
				printf("\n");
				break;
			case 7:
				if(disjoint(s1, s2) == 1)
					printf("Both sets are disjoint");
				else
					printf("Both sets are not disjoint");
				printf("\n");
				break;
			case 8:
				if(equal(s1, s2) == 1)
					printf("Both sets are equal");
				else
					printf("Both sets are not equal");
				printf("\n");
				break;
			default:
				printf("Invalid Input");
				getch(x);
		}
		printf("\n");
		system("pause");
	}
	
	return 0;
}
