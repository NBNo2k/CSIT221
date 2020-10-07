#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	stackItem infix[100];
	int choice  = 1, retVal;
	stackItem postfix[100];
	
	do
	{
		Stack s = newStack();
		
		//Infix to Postfix Conversion
		printf("Infix string: ");
		scanf("%s", &infix);	
			 	
		InfixToPostfix(infix, postfix);
		printf("Postfix string: ");
		printf("%s", postfix);
		
		//Postfix Evaluation
		printf("\n\nPostfix string: ");
		scanf("%s", &postfix);
		printf("Result: %d", PostfixEvaluation(postfix, retVal));
		
		printf("\nDo you wish to continue(1/0)? ");
		scanf("%d", &choice);
		freeStack(s);
	}
	while(choice == 1);
	
	return 0;
}
