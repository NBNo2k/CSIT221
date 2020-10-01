typedef int stackItem;
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
int pop(Stack s);					//Return the value before free 
void displayStack(Stack s);
int isEmptyStack(Stack s);

typedef struct 
{
	int data;
	Nodeptr next;
}QUEUE_NODE;

typedef struct
{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef QUEUE_HEAD* Queue;

Queue createQueue();
void enqueue(Queue q, int item);
int dequeue(Queue q);				//Return the value before free 
void displayQueue(Queue q);
int isEmptyQueue(Queue q);
