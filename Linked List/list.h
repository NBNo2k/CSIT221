typedef struct node* Nodeptr;//to clean the code of the *
								//use this when referring to the node pointer

typedef struct node{
	int data;
	Nodeptr next;
}Node;//use this name to refer to the node

typedef Nodeptr List;//use List when creating the list
					//use Nodeptr when referring to the individual node pointers

List createList();
void display(List head);

int computeSum(List head);
int count(List head);
int countPos(List head);
int countNeg(List head);
int countEven(List head);
int countOdd(List head);

int findItem(List head, int item);
int findMin(List head);
int findMax(List head);

Nodeptr createNode(int item);
List addFront(List head, int item);
List add(List head, int item);
List addAt(List head, int item, int pos);

List deleteFront(List head);
List deleteEnd(List head);
List deleteAt(List head, int pos);
