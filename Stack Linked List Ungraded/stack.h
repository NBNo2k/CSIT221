typedef struct node* Nodeptr;

typedef struct{
	int count;	//Optional
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef  char dataItemType; 

typedef struct node{
	dataItemType data;
	Nodeptr next;
}STACK_NODE;

Stack createStack();//creates and initializes the stack
Stack push(Stack s1, dataItemType item);//inserts item in the stack
void pop(Stack s1);//deletes an element from the stack
void displayStack(Stack s1);//displays the elements of the stack
int isEmpty(Stack s1);//returns 1 if stack is empty; 0 if otherwise
void convertTo(int val, int base);	//Converts any value to a base
void convertToDec(int dec); 
void convertToOct(int dec); //Decimal to Octal
int isValid(char symbols[]);
int getTop(Stack s1);	//Returns the top value
