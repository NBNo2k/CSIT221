typedef struct Namerec
{
	char first[15];
	char middle[15];
	char last[15];
}Namerec;

typedef struct Payrecord
{
	int id;
	Namerec name;
	float hours, rate, regular, overtime, gross, tax_withheld, net;
}Payrecord;

void readName(Payrecord payroll[], int i);  //reads a single name 
void printName(Payrecord payroll[], int i);  //prints a single name
void printSummary(double gross, double tax);  //prints total tax gross pay and total tax withheld
int readRecords(Payrecord payroll[], int n);  //reads payroll input data records until n records have been read
void printRecords(Payrecord payroll[], int n);  //prints n payroll records
double calcRecords(Payrecord payroll[], int n, double *taxptr); 
//computes regular and overtime pay, and the tax to be withheld.
//also cumulatively sums total gross pay and total tax withheld.
//passes the address of tax initialized to 0 and returns the gross. 
