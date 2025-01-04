#include <stdio.h>
#include <stdlib.h>

struct Node {

	int col;
	int data;
	struct Node* next;

};
struct Node* createNode(int value, int col) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->col = col;
	temp->next = NULL;
	return temp;
}
void DisplayMatix(int rows , int cols,struct Node* matrix[5]) {
	
	for (int i = 0;i < rows;i++) {
	   struct Node * a = matrix[i];

		for (int j = 0;j < cols;j++) {

			if (a != NULL) {
				if (a->col == j) {

					printf(" %d ", a->data);
					a = a->next;
				}
				else {

					printf(" 0 ");
				}
			}
			else {
				printf(" 0 ");
			}
		}
		printf("\n");
	}

}
void fillTheMatrix(int rows , int cols, int  arr[][6] , struct Node ** node ) {
	for (int i = 0;i < rows; i++) {
		node[i] = NULL;
		struct Node* last = NULL;
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] != 0) {
				struct Node* temp = createNode(arr[i][j], j);
				if (node[i] == NULL) {
					
					node[i] = last = temp;
				}
				else {
					last->next = temp;
					last = temp;
				}
				
				
				
			}
			

			
		}
		
	}
}


int main() {

	struct Node* matrix[5] = { NULL };
	// Fill the matrix 
   
	int arra[5][6] = { {0,0,0,0,8,0},
					   {0,0,0,7,0,0},
					   {5,0,0,0,9,0},
					   {0,0,0,0,0,3},
					   {6,0,0,4,0,0}
	};
	fillTheMatrix(5, 6, arra, matrix);
	DisplayMatix(5, 6, matrix);



	return 0;
}