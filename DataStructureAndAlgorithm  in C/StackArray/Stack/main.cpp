#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int top;
	int* data;
	int size;
};
void Create(struct Stack* stack, int size);
void Push(struct Stack* stack, int value);
int Pop(struct Stack* stack);
void Display(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);

int main() {
	int size =2;
	Stack st;
	Create(&st, 5);
	printf("Is Full : %d \n", isFull(&st));
	printf("Is Empty : %d \n", isEmpty(&st));
	Push(&st,1);
	Push(&st, 2);
	Push(&st, 3);
	Push(&st, 4);
	Push(&st, 5);
	printf("\n ======================== \n");
	Display(&st);
	printf("\n ======================== \n");
	printf("Is Full : %d \n", isFull(&st));
	printf("Is Empty : %d \n", isEmpty(&st));
	printf("\n ======================== \n");
	printf("Pop Value %d \n", Pop(&st));
	printf("Pop Value %d \n", Pop(&st));
	printf("Pop Value %d \n", Pop(&st));
	printf("Pop Value %d \n", Pop(&st));
	printf("Pop Value %d \n", Pop(&st));
	printf("Pop Value %d \n", Pop(&st));

	return 0;

}
void Push(struct Stack* stack, int value) {

	if (stack->top == stack->size - 1) {
		printf("Stack overflow \n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = value;


}
int Pop(struct Stack* stack) {

	if (stack->top == -1) {
		printf("The Stack is underflow \n");
		return -1;
	}
	int data = stack->data[stack->top];
	stack->top--;
	return data;

}
void Display(struct Stack* stack) {

	for (int i = 0;i < stack->top+1;i++) {

		printf("%d \n", stack->data[i]);
	}

}
int isEmpty(struct Stack* stack) {

	if (stack->top == -1) {
		return 1;
	}
	else {
		return 0;
	}

}
int isFull(struct Stack* stack) {

	if (stack->top == stack->size - 1) {
		return 1;
	}
	else {
		return 0;
	}
}
void Create(struct Stack* stack, int size) {

	stack->data = (int*)malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = size;


}