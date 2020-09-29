#include <stdio.h>
#include <math.h>

typedef struct
{
	int center;
}Point;

typedef struct
{
	Point center;
	float radius;
}Circle;

Point create()
{
	Point p;
	
	p.center = 0;

	return p;
}

Point initPoint(int center)
{
	Point p;
	
	p.center = center;
	
	return p;
}

typedef struct
{
	int x1;
	int x2;
	int y1;
	int y2;
}LINE;

LINE createLine()
{
	LINE l;
	
	l.x1 = 0;
	l.x2 = 0;
	l.y1 = 0;
	l.y2 = 0;
	
	return l;
}

LINE initLine(int x1, int x2, int y1, int y2)
{
	LINE l;
	
	l.x1 = x1;
	l.x2 = x2;
	l.y1 = y1;
	l.y2 = y2;
	
	
	return l;
}

float distance(LINE l)
{
	float distance = 0;
	int x1, x2, y1,y2;
	
	int x = l.x2-l.x1;
	int px = x*x;
	int y = l.y2-l.y1;
	int py = y*y;
	int temp = px+py;
	distance = sqrt(temp);
	
	return distance;
}

float diameter(Circle circ)
{
	float diameter = 0;
	
	diameter = circ.radius * 2;
	
	return diameter;
}

typedef struct
{
	int upperLeft;
	int lowerRight;
	float len;
	float wid;
}Rectangle;

Rectangle createRec()
{
	Rectangle rec;
	
	rec.upperLeft = 0;
	rec.lowerRight = 0;
	
	return rec;
}

float area(Rectangle rec)
{
	float area = 0;
	
	area = rec.len * rec.wid;
	
	return area;	
}

float length(Rectangle rec)
{
	float length = 0;
	
	if(rec.upperLeft < 0)
		length = rec.upperLeft*(-1) + rec.lowerRight;
	else if(rec.lowerRight < 0)
		length = rec.upperLeft + rec.lowerRight*(-1);
	else if(rec.lowerRight < 0 && rec.upperLeft < 0)
		length = rec.upperLeft*(-1) - rec.lowerRight*(-1);
	else
		length = rec.lowerRight - rec.upperLeft;
	
	return length;
}

Rectangle initRec(int upperLeft, int lowerRight, int len)
{
	Rectangle rec;
	
	rec.upperLeft = upperLeft;
	rec.lowerRight = lowerRight;

	
	return rec;
}



float width(Rectangle rec)
{
	float width = 0;
	
	if(rec.upperLeft < 0)
		width = rec.upperLeft*(-1) + rec.lowerRight;
	else if(rec.lowerRight < 0)
		width = rec.upperLeft + rec.lowerRight*(-1);
	else if(rec.lowerRight < 0 && rec.upperLeft < 0)
		width = rec.upperLeft*(-1) - rec.lowerRight*(-1);
	else
		width = rec.lowerRight - rec.upperLeft;
		
	area(rec);
	
	return width;
}

float perimeter(Rectangle rec)
{
	float perimeter = 0;
	
	perimeter = 2*rec.len + 2*rec.wid;
	
	return perimeter;
}

int main()
{
	Circle circ;
	
	printf("Enter value for center: ");
	scanf("%d", &circ.center);
	printf("Enter value for radius: ");
	scanf("%f", &circ.radius);
	
	LINE l;
	
	printf("Enter value for x1: ");
	scanf("%d", &l.x1);
	printf("Enter value for x2: ");
	scanf("%d", &l.x2);
	printf("Enter value for y1: ");
	scanf("%d", &l.y1);
	printf("Enter value for y2: ");
	scanf("%d", &l.y2);
	
	distance(l);
	printf("\nDistance: %.2f", distance(l));
	
	diameter(circ);
	printf("\nDiameter: %.2f\n\n", diameter(circ));
	
	Rectangle rec;
	
	rec.upperLeft = l.x1;
	rec.lowerRight = l.x2;
	
	length(rec);
	printf("Length: %.2f", length(rec));

	rec.len = length(rec);
	rec.upperLeft = l.y1;
	rec.lowerRight = l.y2;
	
	width(rec);
	printf("\nWidth: %.2f", width(rec));
	
	rec.wid = width(rec);
	area(rec);
	printf("\nArea: %.2f", area(rec));
	
	perimeter(rec);
	printf("\nPerimeter: %.2f", perimeter(rec));
	
	
}
