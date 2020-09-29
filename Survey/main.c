#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	Statistician answer;
	int count = 0, item, i, freqsize = 0, number;
	char x;
	int SIZE = 10;
	
	answer = (Statistician)malloc(SIZE * sizeof(int));
	int *freq = (int*)malloc(freqsize * sizeof(int));
	
	while(1) 
	{
		system("cls");
		
		while(count < 10)
		{
			printf("Answer: ", count+1);
			item = input(number);
			add(answer, &count, &SIZE, item);
			system("cls");
		}
		printf("Responds: %d", count);
		printf("\nResponses:\n");
		
		for(i = 0; i < count; i++)
		{
			if(i == count - 1)
				printf("%d\n", answer[i]);
			else
				printf("%d\n", answer[i]);
		}
		
		printf("Statistician Menu\n\n");
		printf("[1] Add\n");
		printf("[2] Mean\n");
		printf("[3] Median\n");
		printf("[4] Max\n");
		printf("[5] Min\n");                
		printf("[6] Range\n");
		printf("[7] Mode\n");
		printf("[8] Histogram\n\n");
		printf("Enter choice: ");
		int choice;	scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter additional response: ");
				item = input(number);
				add(answer, &count, &SIZE, item);
				break;
			case 2:
				printf("Mean: %.2f", mean(answer, count));
				getch(x);
				break;
			case 3:
				printf("Median: %.2f", median(answer, count));
				getch(x);
				break;
			case 4:
				printf("Max: %d", max(answer, count));
				getch(x);
				break;
				getch(x);
			case 5:
				printf("Min: %d", min(answer, count));
				getch(x);
				break;
			case 6:
				printf("Range: %d", range(answer, count));
				getch(x);
				break;
			case 7:
				mode(freq, &freqsize, answer, count);
				printf("Mode: ");
				for(i = 0; i < freqsize; i++)
					printf("%d ", freq[i]);
				printf("\n");
				break;
				getch(x);
			case 8:
				histogram(answer, count);
				getch(x);
				break;
			default:
				printf("Invalid Input");
				getch(x);
		}
		printf("\n");
		system("pause");
	}
	free(answer);
	
	return 0;
}
