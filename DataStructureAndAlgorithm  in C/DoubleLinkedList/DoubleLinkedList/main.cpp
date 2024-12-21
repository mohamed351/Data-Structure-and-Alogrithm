#include <stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
	struct Node* previous;

}*First;
void Create(int A[], int n) {

	struct Node* last , *temp;
	First = (struct Node*)malloc(sizeof(struct Node));
	First->data = A[0];
	First->previous = NULL;
	First->next = NULL;
	last = First;
	for (int i = 1;i < n;i++) {
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = A[i];
		last->next = temp;
		temp->previous = last;
		temp->next = NULL;
		last = temp;
	
	}
	

}
void Display(struct Node * ptr) {

	while (ptr != NULL)
	{
		printf("%d \n", ptr->data);
		ptr = ptr->next;

	}

}
int main() {

	int A[] = { 1,2,3,4,5,6,7 };
	Create(A, 7);
	Display(First);

	return 0;
}