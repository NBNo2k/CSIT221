#include <stdio.h>
#define ROW 3
#define COL 4

void input(int table[][COL])
{
	int row, col;
	
	for(row = 0; row < ROW; row++)
	{
		for(col = 0; col < COL; col++)
		{
			scanf("%d", &table[row][col]);
		}
	}
}

void display(int table[][COL])
{
	int row, col;
	
	for(row = 0; row < ROW; row++)
	{
		printf("\n");
		for(col = 0; col < COL; col++)
		{
			printf(" %d ", table[row][col]);
		}
	}
}

int getTotal(int table[][COL])
{
	int row, col;
	int sum = 0;
	
	for(row = 0; row < ROW; row++)
	{
		for(col = 0; col < COL; col++)
		{
			sum += table[row][col];
		}
	}
	
	return sum;
}

void pattern1(int table[][COL])
{
	int row, col;
	
	for(row = 0; row < ROW; row++)
	{
		for(col = 0; col < COL; col++)
		{
			if(row == col)
				table[row][col] = 0;
			else 
				table[row][col] = 1;
		}
	}
}

void pattern2(int table[][COL])
{
	int row, col;
	
	for(row = 0; row < ROW; row++)
	{
		for(col = 0; col < COL; col++)
		{
			if(row == col)
				table[row][col] = 0;
			else if(row > col)
				table[row][col] = 2;
			else
				table[row][col] = 1;
		}	
	}	
}

void multiplication(int table[][COL])
{
	int row, col;
	
	for(row = 1; row < ROW; row++)	
	{
		printf("\n");
		for(col = 1; col < COL; col++)
		{
			table[row][col] = row*col;
			printf("%d ", table[row][col]);
		}
	}
}

int main()
{
	int table[ROW][COL];
	
	input(table);
	display(table);
	
	printf("\n\nSum: %d", getTotal(table));
	printf("\n\n");
	
	printf("\nPatter Sample 1\n");
	pattern1(table);
	display(table);
	
	printf("\n\nPatter Sample 2\n");
	pattern2(table);
	display(table);
	
	printf("\n\nMultiplication Table\n");
	multiplication(table);
}
