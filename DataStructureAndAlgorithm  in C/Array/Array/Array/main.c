#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "Array.h";
int main() {

	struct Array arr;
	//Initialize(&arr, 10);

	//Append(&arr,5);
	//Append(&arr, 6);
	//Append(&arr, 7);
	//Display(arr);


	/////////////////////////////////////////////
	//CustomInitialization(&arr);
	//EnterTheElements(&arr);
	////////////////////////////////////////////
	
	Initialize(&arr, 10);
	Append(&arr, 1);
	Append(&arr, 2);
	Append(&arr, 4);
	Append(&arr, 6);

	Insert(&arr, 2, 5);
	Display(arr);


	return 0;
}

