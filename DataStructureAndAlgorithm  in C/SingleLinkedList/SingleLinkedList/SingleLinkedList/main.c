#include <stdio.h>
#include <stdlib.h>
struct Node {
	int Data;
	struct Node* Next;
};
struct Node* CreateNode(int data);
void InsertAtFirst(struct Node** First, int data);
void Display(struct Node* node);
void InsertAtLast(struct Node* First, int data);

int main() {

	struct Node* First = NULL;
	InsertAtFirst(&First, 5);
	InsertAtFirst(&First, 6);
	InsertAtLast(First,4);
	InsertAtLast(First, 2);
	InsertAtLast(First, 1);

	Display(First);

	return 0;
}
struct Node* CreateNode(int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->Data = data;
	newNode->Next = NULL;
	return newNode;

}
void InsertAtFirst(struct Node** First, int data) {

	struct Node* newNode = CreateNode(data);

	if (*First == NULL) {
		*First = newNode;
	}
	else {

		newNode->Next = *First;
		*First = newNode;


	}
}
void Display(struct Node* node) {

	struct Node* temp = node;
	while (temp !=NULL)
	{
		printf("%d \n", temp->Data);
		temp = temp->Next;
	}
}
void InsertAtLast(struct Node* First, int data) {
	//get temp node
	struct Node* temp = First;
	//get the last node
	while (temp -> Next != NULL)
	{
		temp = temp->Next;
	}
	// create a new node
	struct Node * newNode =  CreateNode(data);
	temp->Next = newNode;

}