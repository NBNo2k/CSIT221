#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

int input(int number)
{	
	while(number < 1 || number > 9)
	{
		scanf("%d", &number);
		
		//Checks if number is 1-9
		if(number < 1 || number > 9)
		{
			printf("Number must be 1-9\n");
		}
	}

	return number;
}

void add(Statistician answer, int *count, int *SIZE, int item)
{
	//Doubling the size	
	if((*count-1) > (*SIZE-1))
	{
		(*SIZE) *= 2;
		answer = (Statistician)realloc(answer, (*SIZE)*sizeof(int));
	}
	
	answer[(*count)] = item;
	(*count)++;
	
	int i;
	//Sorting
	for(i = 0; i < (*count)-1; i++)
	{
		int j;
		for(j = i + 1; j < (*count); j++)
		{
			if(answer[i] > answer[j])
			{
				int temp = answer[j];
				answer[j] = answer[i];
				answer[i] = temp;
			}
		}
	}
}

float mean(Statistician answer, int count)
{
	float mean = 0, temp;
	int i; 
		
	for(i = 0; i < count; i++)
	{
		temp += answer[i];
	}
	
	mean = (float)temp/count;

	return mean;
}

float median(Statistician answer, int count)
{
	float median = 0;
	int i;
	
	if(count % 2 == 0)
	{
		float temp = answer[(count / 2) - 1] + answer[((count + 2)/2) - 1];
		median = temp/2;
	}
	else
		median = answer[count/2];
		
	return median;
}

int max(Statistician answer, int count)
{
	int max = answer[count-1];
	
	return max;
}

int min(Statistician answer, int count)
{
	int min = answer[0];
	
	return min;
}

int range(Statistician answer, int count)
{
	int range = answer[count - 1] - answer[0];
		
	return range;
}

void mode(int freq[], int *freqsize, Statistician answer, int count)
{
	int i, j;
	*freqsize = 0;
	int tempSize = 9;
	
	int tempFreq[tempSize];

   for (i = 0; i < tempSize; i++) 
   {
      tempFreq[i] = 0;
	}	
    
	for (i = 0; i < tempSize; i++) 
	{
		for(j = 0; j < count; j++)
		{
			if(i + 1 == answer[j])
				tempFreq[i] += 1;
		}     
      }
    
	  int max = tempFreq[0];
	  for(i = 1; i < tempSize; i++)
	  {
	  	if(tempFreq[i] > max)
	  		max = tempFreq[i];
	  }
	  
	  for(i = 0; i < tempSize; i++)
	  {
	  	if(tempFreq[i] == max)
	  	{
	  		freq[*freqsize] = i + 1;
	  		(*freqsize)++;
	  		freq = (Statistician)realloc(freq, (*freqsize)*sizeof(int));
		}
	  }
}

void histogram(Statistician answer, int count)
{
	int i, j;
	int temp;
	
	printf("Histogram");
	for(i = 1; i < 10; i++)
	{        
		printf("\n%4d: ", i);
		
		for(j = 0; j < count; j++)
		{
			if(i == answer[j])
			printf("*");
		}
	}
}
