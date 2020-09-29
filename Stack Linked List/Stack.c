#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

Stack newStack()
{
	Stack s;
	
	s = (Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top = NULL;
	
	return;
}

Nodeptr createNode(char item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void freeStack(Stack s)
{
	Nodeptr temp = NULL;
	Nodeptr top_ref = s->top;
	
	while(top_ref != NULL)
	{
		temp = top_ref;
        top_ref = top_ref->next;
        temp->next = NULL;
        free(temp);
	}
	s->top = top_ref;
	s->count = 0;
}

void push(Stack s, stackItem item)
{               
	Nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	s->count++;
}

int parenthesesPair(char opening, char closing)
{
	if(opening == '(' && closing == ')')
		return 1;
	else if(opening == '{' && closing == '}')
		return 1;
	else if(opening == '[' && closing == ']')
		return 1;
	else
		return 0;
}

stackItem stackTop(Stack s)
{
	return s->top->data;
}

void pop(Stack s)
{             	
	Nodeptr temp;
	
	temp = s->top;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;
}

int isEmpty(Stack s)
{
	if (s->count == 0)
        return 1;
    return 0;
};

void display(Stack s)
{
	Nodeptr ptr = s->top;
	
	if(isEmpty(s) == 1)
		printf("Stack is empty.\n");
	else
	{
		printf("Remaining symbols: ");
		while(ptr != NULL)
		{
			printf("%c ", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
