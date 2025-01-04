struct Node {
	int data;
	struct Node* next;
};
struct Node* Create(int data);
void InsertAtFirst(struct Node** ptr, int data);
void Display(struct Node* ptr);
void DisplayRecusion(struct Node* ptr);
void ConvertArrayToLinkedList(struct Node** ptr, int arr[], int size);
int Count(struct Node* ptr);
int CountUsingRecusion(struct Node* ptr);
void Insert(struct Node** ptr, int position, int data);
void InsertAtLast(struct Node** ptr, int data);
void InsertAtSortedPosition(struct Node** ptr, int data) {

	struct Node* newNode = Create(data);
	if (*ptr == NULL) {

		*ptr = newNode;
	}
	else {
		struct Node* p = *ptr;
		struct Node* q = NULL;
		while (p && p->data < data)
		{ 
			q = p;
			p = p->next;

		}
		if (p == *ptr) {
			newNode->next = *ptr;
			*ptr = newNode;
		}
		else {
			newNode->next = q->next; // or p
			q->next = newNode;

		}


	}

}
void Delete(struct Node** ptr, int index) {

	if (index == 0) {

		struct Node* temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);

	}
	else {

		struct Node* p = *ptr;
		struct Node* q = NULL;
		for (int i = 0;i < index ;i++) {
			q = p;
			p = p->next;
		
		}
		q->next = p->next;
		free(p);

	}
	

}

struct Node* Create(int data) {
	struct Node* ptr = (struct Node*)malloc(sizeof(struct  Node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}
void InsertAtFirst(struct Node** ptr, int data) {

	if (*ptr == NULL) {
		*ptr = Create(data);
	}
	else {
		struct Node* newNode = Create(data);
		newNode->next = *ptr;
		*ptr = newNode;


	}

}
void Display(struct Node* ptr) {

	while (ptr != NULL)
	{
		printf("%d \n", ptr->data);
		ptr = ptr->next;
	}
}
void ConvertArrayToLinkedList(struct Node** ptr, int arr[], int size) {

	*ptr = Create(arr[0]);
	struct Node* temp = *ptr;
	for (int i = 1;i < size;i++) {
		temp->next = Create(arr[i]);
		temp = temp->next;
	}
}

void DisplayRecusion(struct Node* ptr) {

	if (ptr != NULL) {

		printf("%d \n", ptr->data);
		DisplayRecusion(ptr->next);
	}
}
int Count(struct Node* ptr) {

	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}
int CountUsingRecusion(struct Node* ptr) {

	if (ptr == NULL) {
		return 0;
	}
	else {

		return CountUsingRecusion(ptr->next) +1;
	}

}
void Insert(struct Node** First, int position, int data) {
	if (position < 0) {

		printf("Kill yourself i hate you , you are idiot ! \n");
	}
	struct Node* newNode = Create(data);
	if (*First == NULL) {
		*First = newNode;
		return;
	}

	if (position == 0) {

	
		newNode->next = *First;
		*First = newNode;
		
	}
	else if(position > 0) {
		struct Node* temp = *First;
		for (int i = 0;i < position - 1 && temp != NULL;i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;

	}

}
void InsertAtLast(struct Node** ptr, int data) {

	struct Node* newNode = Create(data);
	if (*ptr == NULL) {
		*ptr = newNode;
	}
	else {
		struct Node* temp = *ptr;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		

	}

}