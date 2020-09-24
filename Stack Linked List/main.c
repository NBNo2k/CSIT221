#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char symbols[100];
	
	Stack s = newStack();
	

	if(balancedParentheses(symbols))
		printf("Balanced");
	else
		printf("Not balanced\n");

	return 0;
}
