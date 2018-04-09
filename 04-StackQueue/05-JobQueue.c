#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX (5 + 1)
#define QUEUE_EMPTY (-1)

int queue[QUEUE_MAX];
int queue_first = 0, queue_last = 0;

void enqueue(int val) {
	if ((queue_last + 1) % QUEUE_MAX == queue_first) {
		printf("Jobs are filled.\n");
	}
	else {
		queue[queue_last] = val;
		queue_last = (queue_last + 1) % QUEUE_MAX;
	}
}

int dequeue(void) {
	int ret;

	if (queue_first == queue_last) {
		return QUEUE_EMPTY;
	}
	else {
		ret = queue[queue_first];
		queue_first = (queue_first + 1) % QUEUE_MAX;
		return ret;
	}
}

void queue_print(void) {
	int i;
	for(i = queue_first; i != queue_last; i = (i + 1) % QUEUE_MAX) {
		printf("%d ", queue[i]);
	}
}

int main(void) {
	int i, j;
	do {
		printf("Current queue: ");
		queue_print();
		printf("\nCommand 0: Finish, 1: Enqueue new job, 2: Execute an job\n>");
		scanf("%d", &i);

		switch(i) {
		case 1:
			 printf("Input job number: ");
			 scanf("%d", &j);
			 if (j >= 1 && j <= 1000) {
				 enqueue(j);
			 }
			 break;
		case 2:
			j = dequeue();
			if (j == QUEUE_EMPTY) {
				printf("No jobs.\n");
			}
			else {
				printf("Executing %d-th job...\n", j);
			}
			break;
		}
	} while(i != 0);
		
	return 0;
}
