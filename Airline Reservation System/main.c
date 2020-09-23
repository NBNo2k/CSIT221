#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#include "airline.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int seats[SIZE];
	int seatType, seat;
	
	initSeats(seats, SIZE);
	
	char x;
	while(1)
	{
		system("cls");
		printf("Welcome to MGM Airlines!\n\n");
		displaySeats(seats, SIZE);
		printf("\n\nPlease type 1 for first class");
		printf("\nPlease type 2 for economy: ");
		scanf("%d", &seatType);
		assignSeat(seats, seatType);
		seat = storage();
		getch(x);
	}
	
	return 0;
}
