typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef struct
{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;


typedef QUEUE_HEAD* Queue;

typedef struct node					//Nodes for both stack and queue
{
	int data;
	Nodeptr next;
}NODE;

//Stack
Stack newStack();
void push(Stack s, int item);	
int pop(Stack s);					//Return the value before free 
void displayStack(Stack s);
int isEmptyStack(Stack s);	

//Queue
Queue newQueue();
void enqueue(Queue q, int item);
int dequeue(Queue q);				//Return the value before free 
void displayQueue(Queue q);
int isEmptyQueue(Queue q);			
