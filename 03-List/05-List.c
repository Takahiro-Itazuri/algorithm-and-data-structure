#include<stdio.h>
#include<stdlib.h>

typedef struct tagListNode {
	struct tagListNode *next;
	struct tagListNode *prev;
	int data;
} ListNode;

int main(void) {
	int buf;
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

	do {
		printf("Input a query: ");
		scanf("%d", &buf);
		if(buf) {
			for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
				if (thisnode->data == buf) {
					printf("%d is found.\n", buf);
					if (thisnode->prev != NULL) {
						thisnode->prev->next = thisnode->next;
					}
					else {
						firstnode = thisnode->next;
					}

					if (thisnode->next != NULL) {
						thisnode->next->prev = thisnode->prev;
					}
					else {
						lastnode = thisnode->prev;
					}

					free(thisnode);
					break;
				}
			}
			if (thisnode == NULL) {
				printf("%d is not found or deleted.\n", buf);
			}
		}
	} while(buf != 0);

	for(thisnode = firstnode; thisnode != NULL;) {
		removenode = thisnode;
		thisnode = thisnode->next;
		free(removenode);
	}

	return 0;
}
