typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}QUEUE_NODE;

typedef struct{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef QUEUE_HEAD* Queue;

Queue createQueue();//creates an empty queue
void enqueue(Queue q, int item);//inserts an element at the rear of the queue list
void dequeue(Queue q);//deletes and element from the front of the queue list
void display(Queue q);//displays the elements of the queue list
int isEmpty(Queue q);//determines whether the queue list is empty or not

int isIdentical(Queue q1, Queue q2);
	//returns 1 if the two queues have exactly the same elements, in the same order; 
	//0 if otherwise

int isEqual(Queue q1, Queue q2);
	//returns 1 if the two queues have equal elements, in any order; 
	//0 if otherwise
	
void sort(Queue q);
