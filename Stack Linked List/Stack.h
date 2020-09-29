typedef char stackItem;
typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef struct node{
	stackItem data;
	Nodeptr next;
}STACK_NODE;

Stack newStack();
void freeStack(Stack s);	
void push(Stack s, stackItem item);					//Insert at the top
void pop(Stack s);									//Deleting the top element
stackItem stackTop(Stack s);						//returns the top item
int isEmpty(Stack s);
void display(Stack s);
int parenthesesPair(char opening, char closing);	//Checks paired symbols
