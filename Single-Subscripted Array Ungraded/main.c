#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int num[SIZE];
	int item;
	int count = 0;
	
	//Calling the input function
	input(num, SIZE);
	
	//To display the created array
	display(num, SIZE);
	
	//Display sum
	printf("\n\nThe sum of the array is %d", computeSum(num, SIZE));

	//Display counts of + ints
	printf("\nThe number of positive integers are/is %d", countPos(num, SIZE));
	
	//Display counts of - ints
	printf("\nThe number of negative integers are/is %d", countNeg(num, SIZE));
	
	//Display counts of even ints
	printf("\nThe number of even integers are/is %d", countEven(num, SIZE));
	
	//Display counts of odd ints
	printf("\nThe number of odd integers are/is %d", countOdd(num, SIZE));
	
	
	printf("\n\nInput desired item: ");
	scanf("%d", &item);
	
	//1 if item is found, otherwise 0	
	printf("\nReturn value is %d", findItem(num, SIZE, item));
	
	//Returns index if item is found, otherwise 0
	if (findItemAt(num, SIZE, item) > 0)
		printf("\nItem is at index %d", findItemAt(num, SIZE, item));
	else
		printf("\nReturn value is %d", findItemAt(num, SIZE, item));

	//Display min element
	printf("\nMinimun element is %d", findMin(num, SIZE));
	
	//Display max element
	printf("\nMaximum element is %d", findMax(num, SIZE));
	
	add(num, &count, 5);
	add(num, &count, 10);
	add(num, &count, 15);
	newD(num, count);
	
	printf("\n\nEnter item to index 0: ");
	scanf("%d", &item);

	addFront(num, &count, item);
	newD(num, count);
	
	int pos;
	printf("\n\nEnter item: "); scanf("%d", &item);
	printf("Enter position: "); scanf("%d", &pos);
	addAt(num, &count, item, pos);
	newD(num, count);
	
	deleteEnd(&count);
	printf("\n\nDeleted the end element of the array");
	newD(num, count);
	
	deleteFront(num, &count);
	printf("\n\nDeleted the front element of the array");
	newD(num, count);
	
	printf("\n\nEnter position: "); scanf("%d", &pos);
	deleteAt(num, &count, pos);
	newD(num, count);
	return 0;
}
