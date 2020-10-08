#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"

Stack newStack()
{
	Stack s;
	
	s = (Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0;
	s->top = NULL;
	
	return s;
}

Nodeptr createNode(char item)
{
	Nodeptr ptr;
	
	ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
} 

stackItem stackTop(Stack s)
{
	return s->top->data;
}

stackItem pop(Stack s)
{
	Nodeptr temp;
	stackItem item;
	
	temp = s->top;
	item = temp->data;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;
	
	return item;
}

void push(Stack s, stackItem item)
{
	Nodeptr temp = createNode(item);
	
	temp->next = s->top;
	s->top = temp;
	s->count++;
}

void display(Stack s)
{
    Nodeptr ptr = s->top;
    
	if (!isEmpty(s))
    {
        printf("\nResult: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
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

int isEmpty(Stack s)
{
	return s->count == 0;
}

int order(char item)
{
	int flag = 0;
	
	//Rank from left to right matters
	switch(item)
	{
		case '*':
		case '/':
		case '%':
			flag = 4;
			break;
		case '+':
		case '-':
			flag = 3;
			break;
		case '<':
		case '>':
			flag = 2;
			break;
		case '!':
			flag = 1;
			break;
	}
	
	return flag;
}


int Operator(char item)
{
	return (item == '*' ) || (item == '/') || (item == '%') || (item == '+') || (item == '-') || (item == '<') || (item == '>') || (item == '!');
}

float evaluatePostfixString(float a, float b, int postfix)
{
	float retVal = 0;
	
	switch(postfix)
	{
		case '+':
			retVal = a + b;
			break;
		case '-':
			retVal = a - b;
			break;
		case '*':
			retVal = a * b;
			break;
		case '/':
			retVal = a / b;
			break;
	}
	
	return retVal;
}
