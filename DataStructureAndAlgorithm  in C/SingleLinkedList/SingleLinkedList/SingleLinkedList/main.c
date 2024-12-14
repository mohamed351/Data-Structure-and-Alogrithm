#include <stdio.h>
#include <stdlib.h>
struct Node {
	int Data;
	struct Node* Next;
};
struct Node* CreateNode(int data);
void InsertAtFirst(struct Node** First, int data);
void Display(struct Node* node);
void RecursiveDisplay(struct Node* node);
void InsertAtLast(struct Node** First, int data);
int SumElements(struct Node* ptr);
int RecusionSumElements(struct Node* ptr);
int CountElements(struct Node* ptr);
int GetMaxNumber(struct Node* ptr);
void InsertAtPosition(struct Node** ptr, int data, int position);
int DeleteElement(struct Node** ptr, int index);
struct Node* Search(struct Node* ptr, int key);
struct Node* ImporvedSearch(struct Node** ptr, int key);
int main() {

	struct Node* First = NULL;
	//InsertAtLast(&First, 1); // 0
	//InsertAtLast(&First, 2); // 1 
	//InsertAtLast(&First, 3); // 2
	//InsertAtLast(&First, 4); // 3
	/*InsertAtFirst(&First, 5);
	InsertAtFirst(&First, 6);

	InsertAtFirst(&First, 60);
	InsertAtFirst(&First, 50);
	InsertAtLast(First,4);
	InsertAtLast(First, 2);
	InsertAtLast(First, 1);

	Display(First);
	printf("\n===============Recursive Display==============\n");
	RecursiveDisplay(First);
	printf("\n===============Get Sum=================== \n");
	printf("The Total Sum is %d \n", SumElements(First));
	printf("===============Get Sum Recursion ================== \n");
	printf("The sum of Recursion Sum  is : %d", RecusionSumElements(First));
	printf("\n===============Count ================== \n");
	printf("The Count : %d", CountElements(First));
	printf("\n===============Count Elements Recursion ================== \n");
	printf("Reursion Count %d", CountElementsRecursion(First));
	printf("\n===============Max Number  ================== \n");
	printf("The Max number is %d", GetMaxNumber(First));*/
	
	/*Insert at position 3*/
	InsertAtLast(&First, 1); // 0
	InsertAtLast(&First, 2); // 1 
	InsertAtLast(&First, 3); // 2
	InsertAtLast(&First, 4); // 3

	InsertAtPosition(&First, 90, 0);

	//struct Node* searchItem = Search(First, 9);
	//if (searchItem != NULL) {

	//	printf("Search for element is %d \n", searchItem->Data);
	//}
	//else {
	//	printf("Element is not found \n");
	//}

	//struct Node * searchElementImproved =  ImporvedSearch(&First, 3);
	//if (searchElementImproved != NULL) {
	//	printf("Search for element is %d", searchElementImproved->Data);
	//	printf("The Node and the head changed to %d", First->Data);
	//}

	InsertAtPosition(&First, 5, 0);
	InsertAtPosition(&First, 9, 1);
	DeleteElement(&First, 0);
	DeleteElement(&First, 0);
	DeleteElement(&First, 2);
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
void InsertAtLast(struct Node** First, int data) {
	//get temp node

	if (*First == NULL) {
		*First = CreateNode(data);
		
	}
	else {


		struct Node* temp = *First;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		// create a new node
		struct Node* newNode = CreateNode(data);
		temp->Next = newNode;
	}

}
void RecursiveDisplay(struct Node* node) {

	if (node != NULL) {
		printf("%d ", node->Data);
		RecursiveDisplay(node->Next);

	}
}
int SumElements(struct Node* ptr) {
	int sum = 0;

	while (ptr != NULL)
	{
		sum += ptr->Data;
		ptr = ptr->Next;
	}

	return sum;
}
int RecusionSumElements(struct Node* ptr) {

	if (ptr == NULL) {
		return 0;
	}
	else {
		return RecusionSumElements(ptr->Next) + ptr->Data;
	}
}
int CountElements(struct Node* ptr) {
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->Next;
	}
	return count;
}
int CountElementsRecursion(struct Node* ptr) {
	
	if (ptr == NULL) {
		return 0;
	}
	else {

		return CountElementsRecursion(ptr->Next) + 1;
	}
}
int GetMaxNumber(struct Node* ptr) {

	
	int number = ptr->Data;
	while (ptr != NULL)
	{
		if (ptr->Data > number) {
			number = ptr->Data;
		}
		ptr = ptr->Next;
	}
	return number;
}
void InsertAtPosition(struct Node ** ptr,int data, int position) {

	struct Node* newNode = CreateNode(data);
	if (position == 0) {
		newNode->Next = *ptr;
		*ptr = newNode;

	}
	else {
		struct Node* temp = *ptr;
		for (int i = 0;i < position-1 && temp != NULL;i++) {
			temp = temp->Next;
		}

		newNode->Next = temp->Next;
		temp->Next = newNode;


	}

}
int DeleteElement(struct Node** ptr, int index) {

	struct Node* temp = NULL;
	if (index < 0 || index > CountElements(*ptr)) {
		return -1;
	}
	if (index == 0) {
		temp = *ptr;
		*ptr = (*ptr)->Next;
		int data = (*ptr)->Data;
		free(temp);
		return data;
	}
	else {
		struct Node* p = *ptr;
		struct Node* q = (*ptr)->Next;
		for (int i = 0; i < index; i++)
		{
			q = p;
			p = p->Next;
		}
		q->Next = p->Next;
		int data = p->Data;
		free(p);

		return  data;
	}

}
struct Node* Search(struct Node* ptr, int key) {

	while (ptr != NULL)
	{
		if (ptr->Data == key) {
			return ptr;
		}
		ptr = ptr->Next;
	}
	return NULL;
}
struct Node* ImporvedSearch(struct Node** ptr, int key) {

	struct Node* q = NULL;
	struct Node* temp = *ptr;

	while (temp != NULL)
	{
		if (temp->Data == key) {

			q->Next = temp->Next;
			temp->Next = *ptr;
			*ptr = temp;
			return *ptr;
		}
		q = temp;
		temp = temp->Next;
	}

	return NULL;

}