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
int isOperand(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return 0;
	}
	else {
		return 1;
	}
}
int Pre(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else {
		return 0;
	}
}
char* InToPost(char* infix) {
	int i = 0, j = 0;
	int len = strlen(infix);
	struct Stack st;
	Intialization(&st, strlen(infix) + 1);
	char* postfix = (char*)malloc((len + 2) * sizeof(char));
	while (infix[i] != '\0')
	{
		if (isOperand(infix[i])) {
			postfix[j++] = infix[i++];
		}
		else {

			if (Pre(infix[i]) > Pre(StackTop(st))) {
				Push(&st,infix[i]);
				i++;
			}
			else {
				postfix[j++] = Pop(&st);

			}

		}
		
	}
	while (!IsEmpty(st))
	{
		postfix[j++] = Pop(&st);
	}
	postfix[j] = '\0';
	return postfix;

}
int main() {
	char* expression = "a+b*c";
	//printf("%d \n", isBalance(expression));
	char* data = InToPost(expression);
	printf("%s", data);

	return 0;
}