#include <stdio.h>
#include "Employee Record.h"

void readName(Payrecord payroll[], int i)
{
	printf("First Name: ");
	gets(payroll[i].name.first);
	printf("Middle Name: ");
	gets(payroll[i].name.middle);
	printf("Last Name: ");
	gets(payroll[i].name.last);	
}

void printName(Payrecord payroll[], int i)
{
	printf("\nEmployee Name: %s, %s %s", payroll[i].name.last, payroll[i].name.first, payroll[i].name.middle);
}

int readRecords(Payrecord payroll[], int n)
{
	int i, j, x;
	float z;
	
	for(i = 0; i < n; i++)
	{	
		printf("\nData Records");
		printf("\nID no: ");
		x = scanf("%d%*c", &j);
		if(j == EOF)
			return i;
		payroll[i].id = j;
		readName(payroll, i);
		printf("Hours: ");
		x = scanf("%f%*c", &z);
		payroll[i].hours = z;
		printf("Rate: ");
		x = scanf("%f%*c", &z);
		payroll[i].rate = z;	
	}
	return i;
}

double calcRecords(Payrecord payroll[], int n, double *taxptr)
{
	double gross = 0;
	*taxptr = 0;
	int o;

	
	for(o = 0; o < n; o++)
	{	
		if(payroll[o].hours > 40)
		{
			
			payroll[o].overtime = (payroll[o].hours - 40) * 1.5 * payroll[o].rate; 
			payroll[o].regular = 40 * payroll[o].rate;
		}
		else
		{
			payroll[o].regular = payroll[o].gross = payroll[o].hours * payroll[o].rate;
			payroll[o].overtime = 0;
		}
				
		payroll[o].gross = payroll[o].regular + payroll[o].overtime;
		
		if(payroll[o].gross < 500)
			payroll[o].tax_withheld = payroll[o].gross * 0.15;
		else if(payroll[o].gross < 1000)
			payroll[o].tax_withheld = payroll[o].gross * 0.28;
		else
			payroll[o].tax_withheld = payroll[o].gross * 0.33;
		
		gross += payroll[o].gross;
		*taxptr += payroll[o].tax_withheld;
		payroll[o].net = payroll[o].gross - payroll[o].tax_withheld;	 
	}
	
	return gross;
}

void printRecord(Payrecord payroll[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("\nData Records");
		printf("\n\nID no: %d", payroll[i].id);
		printName(payroll,  i);
		printf("\nHours: %.2f", payroll[i].hours);
		printf("\nRate: %.2f", payroll[i].rate);
		printf("\nRegular: %.2f", payroll[i].regular);
		printf("\nOvertime: %.2f", payroll[i].overtime);
		printf("\nGross: %.2f", payroll[i].gross);
		printf("\nNet: %.2f", payroll[i].net);
		printf("\nTax Withheald: %.2f\n", payroll[i].tax_withheld);
	}
}

void printSummary(double gross, double tax)
{ 	
	printf("\nSummary Report");
	printf("\nTotal Gross: %.2f", gross);
	printf("\nTotal Tax: %.2f", tax);	
}
