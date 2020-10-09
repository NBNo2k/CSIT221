#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	stackItem infix[100];
	int choice  = 1, retVal, i, j;
	char postfix[100];
	Stack postfixString = newStack();
	Stack evaluatePostfix = newStack();
	float a, b;
	
	do
	{
		system("cls");

		printf("Infix to Postfix Conversion\n");
		printf("Infix string: ");
		scanf("%s", &infix);	
			 	
		//Traverse [Converter]
		for(i = 0, j = 0; infix[i]; i++)
		{
			//Directly add to Postfix if operand
			if(isdigit(infix[i]))
				postfix[j++] = infix[i];
			else
			{
				if(Operator(infix[i]))
				{
					//Add to postfix if stack is empty
					if(isEmpty(postfixString))
						push(postfixString, infix[i]);
					else
					{
						//Push higher precedence
						if(order(infix[i]) > order(stackTop(postfixString)))
							push(postfixString, infix[i]);
						else
						{
							//Pop if lower precedence
							while(!isEmpty(postfixString) && order(infix[i]) <= order(stackTop(postfixString)))
							{
								postfix[j++] = stackTop(postfixString);
								pop(postfixString);
							}
							push(postfixString, infix[i]);
						}	
					}
				}
			}
		}
			
		while(!isEmpty(postfixString))
		{
			postfix[j++] = stackTop(postfixString);
			pop(postfixString);
		}
			
		postfix[j++] = '\0';	
		printf("Postfix string: %s", postfix); 	
		
		//Evaluate postfix string	
		for(i = 0; postfix[i] != '\0'; i++)
		{
			if(isdigit(postfix[i]))
				push(evaluatePostfix, postfix[i] - '0');
				
			else
			{
				int b = pop(evaluatePostfix);
				int a = pop(evaluatePostfix);
				
				retVal = evaluatePostfixString(a, b, postfix[i]);
				push(evaluatePostfix, retVal);
			}
		}
		
		printf("\n\nPostfix Evaluation");
		display(evaluatePostfix);
		
		freeStack(evaluatePostfix);
		
		printf("\nDo you wish to continue(1/0)? ");
		scanf("%d", &choice);
	}
	while(choice == 1);
	
	return 0;
}
