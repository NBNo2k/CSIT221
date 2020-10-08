typedef char stackItem;
typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef struct node
{
	stackItem data;
	Nodeptr next;
}STACK_NODE;

Stack newStack();
stackItem stackTop(Stack s);
stackItem pop(Stack s);
void push(Stack s, stackItem item);
void display(Stack s);
void freeStack(Stack s);
int isEmpty(Stack s);

//Helper functions
int order(char item);
int Operator(char item);	
float evaluatePostfixString(float a, float b, int postfix);
