#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
	int top;
	char* data;
	int size;

};
void Intialization(struct Stack* stack, int size) {
	
	stack->top = -1;
	stack->size = size;
	stack->data = (char*)malloc(sizeof(char) * size);
}
void Push(struct Stack * stack,char character) {
	if (stack->top == stack->size - 1) {
		printf("Stackover flow");
		return;
	}
	else {
		stack->top++;
		stack->data[stack->top] = character;

	}

}
char Pop(struct Stack* stack) {
	char character= '\0';
	if (stack->top == -1) {
		printf("Stack is Empty");
		return character;
	}
	else {
		character =	stack->data[stack->top--];
		return character;

	}

}
int IsEmpty(struct Stack stack) {
	return stack.top == -1;
}
char StackTop(struct Stack stack) {
	char ch = '\0';
	if (stack.top == -1) {

		printf("stack is empty \n");
	}
	else {
	 ch=stack.data[stack.top];
	}
	return ch;
}
int isBalance(char * expression) {

	struct Stack st ;
	Intialization(&st, strlen(expression) + 1);
	for (int i = 0;expression[i] != '\0';i++) {

		if (expression[i] == '(') {
			Push(&st, expression[i]);
		}
		else if(expression[i] == ')') {
			if (IsEmpty(st)) {
				return 0; //
			}
			else {
			  char x =	Pop(&st);

			}
		}

	}
	return IsEmpty(st);

}
int main() {
	char* expression = "(a+b))";
	printf("%d \n", isBalance(expression));

	return 0;
}