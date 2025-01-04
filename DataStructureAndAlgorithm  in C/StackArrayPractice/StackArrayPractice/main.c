#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int* data;
	int top;
	int size;
};
void createStack(struct Stack* st , int size) {
	
	st->data = (int*)malloc(size * sizeof(int));
	st->size = size;
	st->top =-1;
}
void Push(struct Stack* st, int value) {
	if (st->top == st->size - 1) {
		printf("Stackover flow \n");
	}
	else {
		st->top++;
		st->data[st->top] = value;
	}
}
int Pop(struct Stack* st) {

	int x = -1;
	if (st->top == -1) {

		printf("Stack underflow \n");
	}
	else {
		x = st->data[st->top];
		st->top--;
	}
	return x;
}
int Peek(struct Stack st, int index) {
	int x = -1;
	if ((st.top - index) < 0) {
		printf("The Invalid Index");
	}
	else {

		x = st.data[st.top - index ];
		return x;
	}

}
void Display(struct Stack st) {

	for (int i = 0;i <= st.top ;i++) {
		printf("%d ", st.data[i]);
	}
}
int StackTop(struct Stack st) {

	if (st.top == -1) {
		return -1;
	}
	else {
		return st.data[st.top];
	}
}
int isEmpty(struct Stack st) {

	return st.top == -1;
}
int isFull(struct Stack st) {
	return st.top == st.size - 1;
}
int main() {
	struct Stack st;
	createStack(&st, 5);
	Push(&st, 1);
	Push(&st, 2);
	Push(&st, 3);
	Push(&st, 4);
	Push(&st, 5);
	//Push(&st, 6);
	/*Display(st);*/
	//printf("%d", Peek(st, 4));

	printf("Stack top : %d ", StackTop(st));


	return 0;
}