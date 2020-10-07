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
void push(Stack s, stackItem item);
char pop(Stack s);
int isEmpty(Stack s);
stackItem stackTop(Stack s);

int order(char item);
void freeStack(Stack s);
int Operator(char item);	
int InfixToPostfix(stackItem infix[], stackItem postfix[]);
int PostfixEvaluation(stackItem postfix[], int retVal);
