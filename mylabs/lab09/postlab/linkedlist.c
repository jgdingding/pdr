// Justin Gou
// jyg2qhc
// 4/8/2020
// linkedlist.c

#include <stdio.h>
#include <stdlib.h>

int main(){
	typedef struct node{
		struct node* prev;
		struct node* next;
		int value;
	} listnode;

	typedef struct linked_list{
		int size;
		listnode* head;
		listnode* tail;
	} llist;

	int n;

	printf("Enter how many values to input: ");
	scanf("%d",&n);

	llist* myList = (llist*) malloc(sizeof(llist));
	myList->size = n;

	listnode* prevNode = NULL;
	for(int i=0;i<myList->size;i++){
		int temp;

		printf("Enter value %d: ",i+1);
		scanf("%d",&temp);
		
		listnode* currNode = (listnode*) malloc(sizeof(listnode));
		currNode->value = temp;
		currNode->prev = prevNode;
		if (!(i==0)){
			prevNode->next = currNode;
		}

		if (i==0){
			myList->head = currNode;
		}
		if (i==myList->size-1){
			myList->tail = currNode;
		}
		
		prevNode = currNode;

	}
	prevNode->next = NULL;

	listnode* curel = myList->head;
	for(int i=0;i<myList->size;i++){
		printf("%d\n",curel->value);
		curel = curel->next;
		if (!(curel==NULL))
			free(curel->prev);
	}

	free(myList);

	return 0;
}
