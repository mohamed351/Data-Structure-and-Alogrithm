struct Array {
	int* data;
	int length;
	int size;
};
void Initialize(struct Array* arr, int size);
void Append(struct Array* arr, int data);
void Display(struct Array arr);


void Initialize(struct Array* arr, int size) {
	arr->data = (int*)malloc(size * sizeof(int));
	arr->size = size;
	arr->length = 0;
}
void Append(struct Array* arr, int data) {

	// if the length is greater or equal that size exist
	if (arr->length >= arr->size) {
		return;
	}
	//adding the array in array then append the length i used post increment after execute that line 
	// increment 
	arr->data[arr->length++] = data;


}
void Display(struct Array arr) {

	//start from zero till the length 
	for (int i = 0;i < arr.length;i++) {
		printf("[%d] : %d \n", i,arr.data[i]);
	}
}
/// <summary>
/// Create a custom array 
/// </summary>
/// <param name="arr"> the array that passed as a reference  </param>
void CustomInitialization(struct Array *arr) {
	printf("please enter the size of array : ");
	scanf("%d", &arr->size);
	arr->data = (int *) malloc(arr->size * sizeof(int));
	arr->length = 0;
}
void EnterTheElements(struct Array* arr) {

	for (int i = 0;i < arr->size;i++) {
		printf("Enter the Element of %d : ", i);
		scanf("%d", &arr->data[i]);
		arr->length++;
	}

}
void Insert(struct Array* array, int index, int value) {

	if ( index >= 0 && index < array->length) {

		int i = 0;
		for (i = array->length; i > index;i--) {
			array->data[i] = array->data[i - 1];
		}
		array->data[i] = value;
		array->length++;
	}

}
int Delete(struct Array* arr, int index) {
	if (index >= 0 && index < arr->length) {
		int i = 0;
		int selectedData = arr->data[index];
		for (i = index;i < arr->length - 1;i++) {
			arr->data[i] = arr->data[i + 1];
		}
		arr->length--;
		return selectedData;
	
	}
	return 0;
}