#include<stdio.h>
#include<stdlib.h>

typedef struct tagListNode {
	struct tagListNode* prev;
	struct tagListNode* next;
	int data;
} ListNode;

int main(void) {
	int buf, sum;
	ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;

	firstnode = lastnode = NULL;

	do {
		printf("Input an integer number: ");
		scanf("%d", &buf);
		if (buf) {
			newnode = (ListNode*)malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;

			if (lastnode != NULL) {
				lastnode->next = newnode;
				newnode->prev = lastnode;
				lastnode = newnode;
			}
			else {
				firstnode = lastnode = newnode;
				newnode->prev = NULL;
			}
		}
	} while(buf != 0);


	printf("Inputed numbers are following numbers.\n");
	for(thisnode = firstnode, sum = 0; thisnode != NULL; thisnode = thisnode->next) {
		printf("%d\t", thisnode->data);
		sum += thisnode->data;
	}
	printf("\n----\nSum of these numbers is %d.\n", sum);

	for (thisnode = firstnode; thisnode != NULL;) {
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}

	return 0;
}
