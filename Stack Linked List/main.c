#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	stackItem parentheses[100];
	int choice = 1, i, flag;
	
	Stack s = newStack();
	
	do
	{
		printf("Symbols: ");
		scanf("%s", &parentheses);
		
		for(i = 0; parentheses[i] != '\0'; i++)
		{
			if(parentheses[i] == '(' || parentheses[i] == '[' || parentheses[i] == '{')
				push(s, parentheses[i]);
			else if(parentheses[i] == ')' || parentheses[i] == ']' || parentheses[i] == '}')
			{
				if(parenthesesPair(stackTop(s), parentheses[i]))
					pop(s);
				else
				{
					flag = 1;	
					break;
				}
			}
		}
		
		if(flag != 1 && isEmpty(s) == 1)
			printf("Balanced\n");
		else
			printf("Mismatched\n");
		
		display(s);
			
		printf("Do you wish to continue(1/0)? ");
		scanf("%d", &choice);
		freeStack(s);
	}
	while(choice == 1);
	
	return 0;
}
