#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h";

int main() {
   
	struct Node* Head = NULL;
	int A[] = { 1,3,4,5 };
	ConvertArrayToLinkedList(&Head, A, 4);

	/*Insert(&Head, 0, -1);
	Insert(&Head, 2, 2);
	Insert(&Head, 4, 5);*/
	/*InsertAtFirst(&Head, 5);
	InsertAtFirst(&Head, 6);
	InsertAtFirst(&Head, 7);*/
	/*DisplayRecusion(Head);
	printf("\nCounte Elements \n");
	printf("%d \n", Count(Head));*/

	//InsertAtLast(&Head, 9);
	/*InsertAtSortedPosition(&Head, 2);
	InsertAtSortedPosition(&Head, 6);*/

	Delete(&Head, 3);
	Display(Head);


	return 0;
}
