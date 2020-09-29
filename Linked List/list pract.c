#include <stdio.h>
#include <stdlib.h>

typedef struct node* Nodeptr; //To clean the code of the *

typedef struct node
{
	int data;
	Nodeptr next;
}Node;	//To refer to the node

typedef Nodeptr List; //Use list when creating list
					//Use Nodeptr when referring to the individual node pointer
					
List createList()
{
	int i;
	
	List head; //Use list when referring to the entire list 
	Nodeptr ptr; //Use Nodeptr for the individual node pointer
	head = (Nodeptr) malloc(sizeof(Node));
	head->data = 10;
	ptr = head;
	
	for(i = 2; i <= 10; i++)
	{
		ptr->next = (Nodeptr) malloc(sizeof(Node));
		ptr->next->data = i * 10;
		ptr = ptr->next;
	}
	ptr->next = NULL;
	
	return head;
}

void display(List head)
{
	Nodeptr ptr=head;
	
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

int computeSum(List head)
{
	int sum = 0;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	
	return sum;
}
		
int count(List head)
{
	int count = 0;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	
	return count;
}

int countPos(List head)
{
	int pos = 0;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->data > 0)
		{
			pos++;
			ptr = ptr->next;
		}
	}
	
	return pos;
}

int countNeg(List head)
{
	int neg;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->data < 0)
		{
			neg++;
			ptr = ptr->next;
		}
		else
		{
			neg = 0;
			ptr = ptr->next;
		}
	}
	
	return neg;
}
	
int countEven(List head)
{
	int even = 0;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->data % 2 == 0)
		{
			even++;
			ptr = ptr->next;
		}
	}
	
	return even;
}

int countOdd(List head)
{
	int odd;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->data % 2 != 0)
		{
			odd++;
			ptr = ptr->next;
		}
		else
		{
			odd = 0;
			ptr = ptr->next;
		}
	}
	
	return odd;
}

int findItem(List head, int item)
{
	int found;
	Nodeptr ptr = head;
	
	while(ptr != NULL)
	{
		if(ptr->data == item)
		{
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	
	return found;
}

int findMin(List head)
{
	Nodeptr ptr = head;
	int min = ptr->data = 1 * 10;
	
	while(ptr != NULL)
	{
		
		int i;
		for(i = 2; i <= 10; i++)
		{
			if(min < ptr->data)
			{
				min = ptr->data;
				i++;
			}
		}
	}
	
	return min;
}
							
int main()
{
	int item;
	
	List head = createList();
	display(head);
	printf("\nSum: %d", computeSum(head));
	printf("\nCount: %d", count(head));
	printf("\nPositive: %d", countPos(head));
	printf("\nNegative: %d", countNeg(head));
	printf("\nCount: %d", count(head));
	printf("\nEven: %d", countEven(head));
	printf("\nOdd: %d", countOdd(head));
	
	printf("\nEnter item: ");
	scanf("%d", &item);
	printf("Item found: %d", findItem(head, item));
	
	printf("\nMinimun: %d", findMin(head));
	
	
	return 0;
}
