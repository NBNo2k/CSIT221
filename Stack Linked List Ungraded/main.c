#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//printf("%d",isValid("()"));
	
	//convert(29);
	
	Stack s1 = createStack();

//	printf("%d\n", s1->count);	

	int item;
	printf("Item: ");
	scanf("%d", &item);
	s1 = push(s1, item);
	displayStack(s1);
/*	push(s1, 5);
	push(s1,10);
	push(s1,15);
	displayStack(s1);
	pop(s1);
	displayStack(s1);
	
	convertToBinary(123);
	convertToOct(394);*/
	
	/*int dec;
	printf("Decimal: ");
	scanf("&dec");
	DectoOct(dec);*/ 
	
	return 0;
}


