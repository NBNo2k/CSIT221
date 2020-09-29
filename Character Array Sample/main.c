#include <stdio.h>
#define SIZE 10
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char str1[SIZE];
	
	//Gets the char of your choice
	gets(str1);
	display(str1);
	printf("\nNumber of A's: %d", countAs(str1));
	strlen(str1);
	printf("\nLength of the string: %d", strlen(str1));
	printf("\nReturn value: %d", palindrome(str1));
	
	return 0;
}
