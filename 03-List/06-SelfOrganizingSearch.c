#include<stdio.h>
#include<stdlib.h>

typedef struct tagListNode {
	struct tagListNode *next;
	int data;
} ListNode;

int main(void) {
	int buf;
	ListNode *firstnode, *lastnode, *newnode, *thisnode, *tmpnode;

	firstnode = lastnode = NULL;

	do {
		printf("Input an integer number: ");
		scanf("%d", &buf);
		if(buf) {
			newnode = (ListNode*)malloc(sizeof(ListNode));
			newnode->data = buf;
			newnode->next = NULL;
			if (lastnode != NULL) {
				lastnode->next = newnode;
				lastnode = newnode;
			}
			else {
				firstnode = lastnode = newnode;
			}
		}
	} while(buf != 0);

	do {
		printf("array ");
		for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
			printf("%d\t", thisnode->data);
		}

		printf("\nInput a query: ");
		scanf("%d", &buf);
		if(buf) {
			for(thisnode = firstnode; thisnode != NULL; tmpnode = thisnode, thisnode = thisnode->next) {
				if (thisnode->data == buf) {
					printf("%d is found.\n", buf);
					if (thisnode != firstnode) {
						tmpnode->next = thisnode->next;

						if (lastnode == thisnode) {
							lastnode = tmpnode;
						}

						thisnode->next = firstnode;
						firstnode = thisnode;
					}
					break;
				}
			}
		}
	} while(buf != 0);

	thisnode = firstnode;
	while(thisnode != NULL) {
		tmpnode = thisnode->next;
		free(thisnode);
		thisnode = tmpnode;
	}

	return 0;
}
