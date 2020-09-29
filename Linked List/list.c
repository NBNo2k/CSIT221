#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List createList(){
	int i;
	List head;//use List when referring to the entire list 
	Nodeptr ptr; //use Nodeptr for the individual node pointer
	head = (Nodeptr) malloc(sizeof(Node));
	head->data = 10;
	ptr = head;
	for(i=2;i<=10;i++){
		ptr->next = (Nodeptr) malloc(sizeof(Node));
		ptr->next->data = i*10;
		ptr = ptr->next;
		
	}
	ptr->next = NULL;
	
	return head;
}

void display(List head){
	Nodeptr ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

//computes the total of the elements
int computeSum(List head){
	int sum = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		sum+=ptr->data;
		ptr = ptr->next;
	}
	return sum;
}

//counts the number of elements in the list
int count(List head){
	int ctr = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		ctr++;
		ptr = ptr->next;
	}
	return ctr;
}

//counts the number of positive elements
int countPos(List head){
	int ctr = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		if(ptr->data>=0)
			ctr++;
		ptr = ptr->next;
	}
	return ctr;
}

//counts the number of negative elements
int countNeg(List head){
	int ctr = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		if(ptr->data<0)
			ctr++;
		ptr = ptr->next;
	}
	return ctr;
}

//counts the number of even elements
int countEven(List head){
	int ctr = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		if(ptr->data%2==0)
			ctr++;
		ptr = ptr->next;
	}
	return ctr;
}

//counts the number of odd elements
int countOdd(List head){
	int ctr = 0;
	Nodeptr ptr=head;	
	while(ptr!=NULL){
		if(ptr->data%2!=0)
			ctr++;
		ptr = ptr->next;
	}
	return ctr;
}

//returns 1 if item is in the list; 0 if otherwise
int findItem(List head, int item){
	int found=0;
	Nodeptr ptr=head;
	while(ptr!=NULL){
		if(ptr->data==item){
			found=1;
			break;
		}
		ptr = ptr->next;
	}
	return found;
}

int findMax(List head)
{
	Nodeptr ptr = head;
	int max = INT_MIN;
	
	while(ptr != NULL)
	{
		if(max < ptr->data)
			max = ptr->data;
			
		ptr = ptr->next;
	}
	
	return max;
}

int findMin(List head)
{
	Nodeptr ptr = head;
	int min = INT_MAX;
	
	while(ptr != NULL)
	{
		if(min > ptr->data)
			min = ptr->data;
			
		ptr = ptr->next;
	}
	
	return min;
}

//Steps 1 and 2 of the algorithm
Nodeptr createNode(int item)
{
	Nodeptr ptr;
	ptr=(Nodeptr)malloc(sizeof(Node));
	ptr->data=item;
	ptr->next=NULL;
	
	return ptr;
}

//Adds item at the front of the list
List addFront(List head, int item){
	Nodeptr temp = createNode(item);//Steps 1 and 2
	//Skip step 3 - new node's predecessor is head
	temp->next = head;//Step 4
	head = temp;//Step 5
	return head;
}

//Adds item at the end of the list
List add(List head, int item){
	Nodeptr ptr;
	Nodeptr temp = createNode(item);//Steps 1 and 2
	//Step 3
	ptr=head;
	while(ptr->next!=NULL){//Just traverse the list until it stops at the last node
		ptr=ptr->next;
	}
	//Skip step 4 since the successor is NULL
	// temp->next already points to NULL as done already in createNode()
	//temp->next = ptr->next;//or do this
	ptr->next = temp;//Step 5
	return head;
}

//Adds item at the given position
//generic insert algorithm
//Assuming pos is within the bounds of the list
List addAt(List head, int item, int pos){
	int i;
	Nodeptr ptr;
	Nodeptr temp = createNode(item);//Steps 1 and 2
	if(pos==1){
		temp->next=head;//Step 4
		head = temp;//Step 5
	}
	else{//Step 3
		ptr=head; i=1;
		while(i<pos-1){
			ptr = ptr->next;
			i++;
		}
		temp->next = ptr->next;//Step 4
		ptr->next=temp;//Step 5
	}
	return head;
}

//deletes the first element
List deleteFront(List head){
	//Skip step 1 since the predecessor is head
	Nodeptr temp = head;//Step 2
	head = head->next; // or head = temp->next; //Step 3
	temp->next = NULL;//Step 4
	free(temp);//Step 5 
	return head;	
}

List deleteEnd(List head){
	Nodeptr temp, ptr;
	//Step 1, loops until ptr is at second to the last node
	ptr = head;
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	temp = ptr->next;//Step 2
	ptr->next = NULL; //or ptr->next=temp->next; //Step3
	temp->next=NULL;//Step 4
	free(temp);//Step 5
	return head;
}

List deleteAt(List head, int pos)	//Ungraded Excercise
{
	Nodeptr temp = head;
	Nodeptr ptr;
	Nodeptr nextnode;
	int i;
	
	for(i = 1; i < pos - 1; i++)
		temp = temp->next;
	
	nextnode = temp->next;
	temp->next = nextnode->next;
	free(nextnode);

	return head;
}


