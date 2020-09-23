#include <stdio.h>
#include <stdlib.h>
#include "Employee Record.h"
#define SIZE 2

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	Payrecord payroll[SIZE];
	double gross, tax = 0;
	int n = 0;
	
	n = readRecords(payroll, SIZE);
	gross = calcRecords(payroll, n, &tax);
	printRecord(payroll, n);
	printSummary(gross, tax);
	
	return 0;
}
