#include <stdio.h>
#include <string.h>

void display(char str1[])
{
	int i;
	
	printf("\n");
	for(i = 0; str1[i] != '\0'; i++)
		printf("%c ", str1[i]);
}

//Counts the number of chars in an array
int countAs(char str1[])
{
	int i, count = 0;
	
	for(i = 0; str1[i] != '\0'; i++)
		if(str1[i] == 'a' || str1[i] == 'A')
			count++;
			
	return count;
}

//Word that reads the same forward and backwards
int palindrome(char str1[])
{
	//Serves us the low variable
	int i;
	
	//Length of the string
	int length = strlen(str1) - 1;
	
	for(i = 0; str1[i] != '\0'; i++)
		if(str1[i] == str1[length--])
		{
			return 1;
			break;
		}
			
	
	return 0;
}
