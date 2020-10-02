typedef struct node* Nodeptr;

typedef struct node
{
	int item;
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
int dequeue(Queue q);
void display(Queue q);
int isEmpty(Queue q);


