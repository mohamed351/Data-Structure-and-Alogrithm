#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
}*Head;

void CreateCircularLinkList(int A[], int n);
void Display(struct Node* ptr);
int main() {

	int A[]{ 1,2,3,4,5,6,7 };
	CreateCircularLinkList(A, 7);
	Display(Head);
	return 0;
}
void CreateCircularLinkList(int A[], int n) {

	struct Node* newNode = (struct Node *) malloc(sizeof(struct Node*));
	struct Node* last;
	newNode->data = A[0];
	newNode->next = Head;
	Head = newNode;
	last = Head;
	for (int i = 1;i < n;i++) {
		
		struct Node * temp = (struct Node*)malloc(sizeof(struct Node*));
		temp->data = A[i];
		temp->next = Head;
		last->next = temp;
		last = temp;
	   

	}


}
void Display(struct Node* ptr) {

	do {

		printf("%d", ptr->data);
		ptr = ptr->next;

	} while (ptr != Head);
}