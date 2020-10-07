#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include <string.h>

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
	return s->count == 0;
}

stackItem stackTop(Stack s)
{
	return s->top->data;
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

int operand(char item)
{
	return (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z');
}

int Operator(char item)
{
	return (item == '*' ) || (item == '/') || (item == '%') || (item == '+') || (item == '-') || (item == '<') || (item == '>') || (item == '!');
}

void InfixToPostfix(stackItem infix[], stackItem postfix[])
{
	int i, j;
	infix[100];
	postfix[100];
	Stack s = newStack();
	
	//Traverse
	for(i = 0, j = 0; infix[i]; i++)
	{
		//Directly add to Postfix if operand
		if(operand(infix[i]))
			postfix[j++] = infix[i];
		else
		{
			if(Operator(infix[i]))
			{
				//Addto postfix if stack is empty
				if(isEmpty(s))
					push(s, infix[i]);
				else
				{
					//Push higher precedence
					if(order(infix[i]) > order(stackTop(s)))
						push(s, infix[i]);
					else
					{
						//Pop if lower precedence
						while(!isEmpty(s) && order(infix[i]) <= order(stackTop(s)))
						{
							postfix[j++] = stackTop(s);
							pop(s);
						}
						push(s, infix[i]);
					}	
				}
			}
		}
	}
		
	while(!isEmpty(s))
	{
		postfix[j++] = stackTop(s);
		pop(s);
	}
		
	postfix[j++] = '\0';
}
