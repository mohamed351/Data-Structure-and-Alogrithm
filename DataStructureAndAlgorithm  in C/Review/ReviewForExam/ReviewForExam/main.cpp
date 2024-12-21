#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void Create(struct Node*& First, int A[], int n) {

	First = (struct Node*)malloc(sizeof(struct Node));
	First->data = A[0];
	First->next = NULL;
	struct Node* temp = First;
	for (int i = 1;i < n;i++) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = A[i];
		newNode->next = NULL;
		temp->next = newNode;
		temp = newNode;
	}

}
void Display(struct Node* ptr) {

	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
int countNodes(struct Node* ptr) {

	int count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}
int sum(struct Node* ptr) {
	int sumResult = 0;
	while (ptr)
	{
		sumResult+=ptr->data;
		ptr = ptr->next;
	}
	return sumResult;
}
struct Node* Search(struct Node* ptr, int key) {
	
	while (ptr)
	{
		if (ptr->data == key) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return  NULL;
}
void Insert(struct Node*& First, int position, int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (position == 0) {
		
		if (First == NULL)
		{
			First = newNode;
		}
		else {

			newNode->next = First;
			First = newNode;
		}


	}
	else if(position > 0) {

		struct Node* temp = First;
		for (int i = 0;i < position - 1;i++) {	
			temp = temp->next;
		}
		if (temp) {

			newNode->next = temp->next;
			temp->next = newNode;
		}

	}

}

void InsertSorted(struct Node*& First, int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = NULL;
	if (First == NULL) {

		First = newNode;
	}
	else {
		struct Node* q = NULL;
		struct Node* temp = First;
		while (temp && temp->data < data)
		{
			q = temp;
			temp = temp->next;
		}
		if (temp == First) {

			newNode->next = First;
			First = newNode;

		}
		else {

			newNode->next = q->next;
			q->next = newNode;
		}
	}
	


}

int DeleteNode(struct Node*& First, int index) {

	int x = -1;
	if (index == 0) {
		struct Node* p = First;
		First = First->next;
		x = p->data;
		free(p);
		return x;
	}
	else {

		struct Node* p = First;
		struct Node* q = NULL;
		for (int i = 0;i < index;i++) {
			q = p;
			p = p->next;
		}
	
		q->next = p->next;
		x = q->data;
		//free(q);
		return x;

	}


}
int main() {

	int A[] = { 2,4,6,8 };
	struct Node* First = NULL;
	Create(First, A, 4);
	Display(First);
	printf("\n");
	printf("count the Nodes : %d \n", countNodes(First));
	printf("Sum All Nodes : %d \n", sum(First));
	printf("Search For Value : %d \n", Search(First,6)->data);
	/*Insert(First, 0, 999);
	Insert(First, 1, 8888);*/
	//Insert(First, 7,999);
	//InsertSorted(First, 1);
	//InsertSorted(First, 7);
	//InsertSorted(First, 9);
	printf("Deleting Element at index %d \n", DeleteNode(First, 3));
	Display(First);




	return 0;
}
