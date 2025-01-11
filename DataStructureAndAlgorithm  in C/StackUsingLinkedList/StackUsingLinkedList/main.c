#include <stdio.h>
#include <stdlib.h>
struct Node {

	int data;
	struct Node* next;

};

void Push(struct Node** stackNode , int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Stackover flow \n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (*stackNode == NULL) {

		*stackNode = newNode;
	}
	else {
		newNode->next = *stackNode;
		*stackNode = newNode;
	}

}
int Pop(struct Node ** stackNode) {
	int x = -1;
	if (*stackNode == NULL) {
		printf("stack is empty");
	    return -1;
	}
	else {
	 struct Node *temp =(*stackNode);
	 *stackNode = (*stackNode)->next;
	 x = temp->data;
	 free(temp);
	}
	return x;

}
int isEmpty(struct Node* stack) {

	return stack == NULL;
}
int peek(struct Node* stack, int index) {

	int x = -1;
	for (int i = 0;i < index && stack != NULL;i++) {
		stack = stack->next;
	}
	if (stack == NULL) {
		printf("Invalid Index \n");
		
	}
	else {
		x = stack->data;
	}
	return x;

}
int StackTop(struct Node* stack) {
	int x = -1;
	if (stack == NULL) {
		printf("Stack is Empty");
		return x;
	}
	else {
	 x=	stack->data;
	}
	return x;

}


int main() {

	struct Node* stack = NULL;
	Push(&stack, 5);
	Push(&stack, 6);
	Push(&stack, 7);
	Push(&stack, 8);
	Push(&stack, 9);
	printf("Stack top is %d \n", StackTop(stack));
	printf("Peek %d \n", peek(stack, 1));
	printf("---------Pop-------- \n");
	while (!isEmpty(stack))
	{
		printf("%d \n", Pop(&stack));
	}

	return 0;
}