#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int* data;
	int top;
	int size;
};
void Initialization(struct Stack* stack , int size) {
	stack->data = malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = size;
	
}
void Push(struct Stack* stack, int data) {
	if (stack->top == stack->size - 1) {
		printf("Stackover flow \n");
		return;
	}
	else {
		stack->top++;
		stack->data[stack->top] = data;
	}
}
int Pop(struct Stack* stack) {
	int x = -1;
	if (stack->top == -1) {
		printf("Stack is Empty");
		return x;
	}
	else {

		x=	stack->data[stack->top--];
		return x;


	}
}
void Display(struct Stack stack) {
	for (int i = 0;i <= stack.top;i++) {
		printf("%d => %d \n", i, stack.data[i]);
	}
}
int isEmpty(struct Stack stack) {

	return stack.top == -1;
}
int isFull(struct Stack stack) {
	return stack.top == stack.size - 1;
}
int Peek(struct Stack stack, int index) {

	int x = -1;
	if ((stack.top - index ) < 0) {
		printf("Invalid Index");
		return x;
	}
	x = stack.data[stack.top - index  ];
	return x;
	
}
int stackTop(struct Stack stack) {
	int x = -1;
	if (stack.top == -1) {
		return x;
	}
	return stack.data[stack.top];
}
int main() {
	struct Stack st;
	Initialization(&st, 10);
	Push(&st, 5);
	Push(&st, 6);
	Push(&st, 8);
	Push(&st, 9);
	Push(&st, 10);
	Push(&st, 11);
	Push(&st, 13);
	Push(&st, 14);
	Push(&st, 15);
	Push(&st, 16);
	printf("%d", stackTop(st));
	//Push(&st, 17);
	//Push(&st, 18);
	//Push(&st, 19);
	//Push(&st, 20);
	/*Display(st);*/
	/*printf("\n----------------------------\n");
	while (!isEmpty(st))
	{
		printf("%d \n", Pop(&st));
	}*/



	return 0;
}