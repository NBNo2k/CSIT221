#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	List head = NULL;
	head = addFront(head,5);
	head = addFront(head,10);
	head = addFront(head,15);
	head = add(head,20);
	head = addAt(head,30,4);
	display(head);
	
	head = deleteFront(head);
	display(head);
	head = deleteEnd(head);
	display(head);
	
	int pos;
	printf("Delete position: ");
	scanf("%d", &pos);
	head = deleteAt(head, pos);
	display(head);
	
	/*List head = createList();
	display(head);
	int item;
		
	printf("Sum = %d\n",computeSum(head));
	printf("Count = %d\n",count(head));
	printf("Positive = %d\n",countPos(head));
	printf("Negative = %d\n",countNeg(head));
	printf("Even = %d\n",countEven(head));
	printf("Odd = %d\n",countOdd(head));
	printf("Enter item: ");
	scanf("%d", &item);
	printf("Item found = %d", findItem(head, item));
	printf("\nMinumum = %d", findMin(head));
	printf("\nMaximum = %d", findMax(head));*/
	
	
	return 0;
}


