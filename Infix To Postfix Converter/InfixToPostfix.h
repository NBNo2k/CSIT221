typedef char stackItem;
typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
	Nodeptr array;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef struct node
{
	stackItem data;
	Nodeptr next;
}STACK_NODE;

Stack newStack();
void push(Stack s, stackItem item);
void pop(Stack s);
int isEmpty(Stack s);
stackItem stackTop(Stack s);

int order(char item);
void freeStack(Stack s);
int operand(char item);		//Check operands
int Operator(char item);	//Check operators
int InfixToPostfix(stackItem infix[], stackItem postfix[];);
