#include <stdio.h>
#include <string.h>

typedef struct
{
	int x; 
	int y;
}Point;

Point create()
{
	Point p;
	p.x = 0;
	p.y = 0;
	
	return p;
}

Point initPoint(int x, int y)
{
	Point p;
	p.x = x;
	p.y = y;
	
	return p;
}

void displayPoint(Point p)
{
	printf("\n\(%d,%d)", p.x, p.y);
}

int atQuadrant(Point p)
{
	int quad;
	
	if(p.x > 0 && p.y > 0)
		quad = 1;
	else if(p.x < 0 && p.y > 0)
		quad = 2;
	else if(p.x < 0 && p.y < 0)
		quad = 3;
	else
		quad = 4;
		
	return quad;
}

typedef struct
{
	char firstname[15];
	char middlename[15];
	char lastname[15];
}Name;

typedef struct Student
{
	int idnumber;
	Name name;
	int age;
	float tuitionfee;
}Stude;

typedef struct
{
	Point beg;
	Point end;
}Line;

Line createLine()
{
	Point p1 = create(), p2 = create();
	Line l;
	
	l.beg = p1;
	l.end = p2;
	
	return l;
}

Line initLine(Point p1, Point p2)
{
	Line l;
	
	l.beg = p1;
	l.end = p2;
	
	return l;
}

void displayLine(Line l1)
{
	printf("\nBeg: %d\nEnd: %d", l1.beg, l1.end);
}

int lineType(Line l1)
{
	int type;
	
	if(l1.beg.y == l1.end.y)
		type = 1;
	else if(l1.beg.x == l1.end.x)
		type = 2;
	else 
		type = 3;
		
	return type;
}

int main(int argc, int *argv[])
{
	Stude s;
	
	printf("ID no: ");
	scanf("%d", &s.idnumber);
	fflush(stdin); //Clear the output buffer
	printf("First Name: ");
	gets(s.name.firstname);
	printf("Middle Name: ");
	gets(s.name.middlename);
	printf("Last Name: ");
	gets(s.name.lastname);
	printf("Age: ");
	scanf("%d", &s.age);
	printf("Tuition Fee: ");
	scanf("%f", &s.tuitionfee);
	
	printf("\n\nResult\n");
	
	printf("\nID no: %d", s.idnumber);
	printf("\nFirst Name: %s", s.name.firstname);
	printf("\nMiddle Name: %s", s.name.middlename);
	printf("\nLast Name: %s", s.name.lastname);
	printf("\nAge: %d", s.age);
	printf("\nTuition Fee: %.2f", s.tuitionfee);

	Point p = create();
	p = initPoint(-5,-7);
	displayPoint(p);
	printf(" is at quadrant %d", atQuadrant(p));
	
	Line l1 = createLine();
	Point p1 = initPoint(3,10);
	Point p2 = initPoint(2,6);
	l1 = initLine(p1, p2);
	displayLine(l1);
	printf(" = %d", lineType(l1));
	
	return 0;
}

void input(Stude s[], int size);
void display(Stude s[], int size);
