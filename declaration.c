#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//Inputs the array elements
void input(int num[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		printf("Enter array elements: ");
		scanf("%d", &num[i]);
	}
}

//Displays the array elements
int display(int num[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("\nArray[%d]: %d", i, num[i]);

}

//Getting the sum of the array elements
int computeSum(int num[], int size)
{
	int i, sum = 0;
	
	for(i = 0; i < size; i++)
		sum += num[i];		
	
	return sum;
}

//Counts the + ints
int countPos(int num[], int size)
{
	int i, count = 0;
	
	for(i = 0; i < size; i++)
		if(num[i] > 0)
			count++;
	
	return count;
}

//Counts the - ints
int countNeg(int num[], int size)
{
	int i, count = 0;
	
	for(i = 0; i < size; i++)
		if(num[i] < 0)
			count++;
			
	return count;
}

//Counts the even ints
int countEven(int num[], int size)
{
	int i, count = 0;
	
	for(i = 0; i < size; i++)
		if(num[i] % 2 == 0)
			count++;
			
	return count;
}

//Counts the odd ints
int countOdd(int num[], int size)
{
	int i, count = 0;
	
	for(i = 0; i < size; i++)
		if(num[i] % 2 != 0)
			count++;
			
	return count; 
}

//Finds the desired item
int findItem(int num[], int size, int item)
{
	int i;
	
	for(i = 0; i < size; i++)
		if(num[i] == item)
			return 1;
	
	return 0;
}

//Returns the index location if item is found
int findItemAt(int num[], int size, int item)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(num[i] == item)
		{
			return i;
			break;
		}
	}
	
	return -1;
}

//Finds the min element
int findMin(int num[], int size)
{
	int i, min = num[0];
	
	for (i = 0; i < size; i++)
	{
		if(min > num[i])
		{
			min = num[i];
			i++;
		}
	}
	
	return min;
}

//Finds the max element
int findMax(int num[], int size)
{
	int i, max = num[0];
	
	for (i = 0; i < size; i++)
	{
		if(max < num[i])
		{
			max = num[i];
			i++;
		}
	}
	
	return max;
}

//Insert item at the end
void add(int num[], int *count, int item)
{
	num[*count] = item;
	(*count)++;
}

void newD(int num[], int count)
{
	int i;

	printf("\n");
	for(i = 0; i < count; i++)
		printf("\nArray[%d]: %d", i, num[i]);
}

//Insert at index 0
void addFront(int num[], int *count, int x)
{
	int i; 
	
	for(i = *count; i > 0; i--)
		num[i] = num[i - 1];
	num[0] = x;	
	(*count)++;
}

//Insert item at Pos
void addAt(int num[], int *count, int item, int pos)
{
	int i;
	
	for(i =  *count; i >= pos; i--)
		num[i] = num[i - 1];
		
	num[pos - 1] = item;
	(*count)++;
}

void deleteEnd(int *count)
{
	(*count)--;
}

void deleteFront(int num[], int *count)
{
	int i;
	
	for(i = 0; i < (*count) - 1; i++)
		num[i] = num [i + 1];
		
	(*count)--;
}

void deleteAt(int num[], int *count, int pos)
{
	int i;
	
	for(i = pos - 1; i < *count; i++)
		num[i] = num[i + 1];
		
	(*count)--;
}
