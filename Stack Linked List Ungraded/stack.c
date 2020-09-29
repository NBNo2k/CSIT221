#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack createStack(){
	Stack s;
	s = (Stack) malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top = NULL;
	return s;
}

Nodeptr createNode(int item){
	Nodeptr ptr;
	ptr=(Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data=item;
	ptr->next=NULL;
	return ptr;
}

Stack push(Stack s1, dataItemType item){
	Nodeptr temp = createNode(item);
	temp->next = s1->top;
	s1->top = temp;
	s1->count++;
}

void pop(Stack s1){
	Nodeptr temp;
	temp = s1->top;
	s1->top = temp->next;
	temp->next = NULL;
	free(temp);
	s1->count--;
}

void displayStack(Stack s1){
	Nodeptr ptr=s1->top;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int isEmpty(Stack s1){
	return s1->top==NULL;
	// or return s1->count==0;
}

void convertToBinary(int dec)
{
	Stack s = createStack();
	
	int val = dec;
	
	while(val!=0)
	{
		push(s, val%2);
		val/=2;
	}
	
	displayStack(s);
}

void convertToOct(int dec)
{
	Stack s = createStack();
	
	int val = dec;
	
	while(val != 0)
	{
		push(s, val % 8);
		val /= 8;
	}
	
	displayStack(s);
}

void convertTo(int val, int base)
{
	Stack s = createStack();
	
	while(val != 0)
	{
		push(s, val % base);
		val /= base;
	}
}

int isValid(char symbols[])
{
	Stack s1 = createStack();
	
	int i, ans = 1;
	
	for(i = 0; symbols[i] != '\0'; i++)
	{
		if(symbols[i]=='(')
			push(s1, '(');
		else
		{
			if(isEmpty(s1))
			{
				ans = 0;
				break;
			}
			else
				pop(s1);
		}
	}
	
	return isEmpty(s1) && ans==1;
}

int getTop(Stack s1)	//Returns the top
{
	return s1->top->data;
}
