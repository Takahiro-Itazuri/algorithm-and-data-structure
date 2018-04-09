#define QUEUE_MAX (5 + 1)
#define QUEUE_EMPTY -1

int queue[QUEUE_MAX];
int queue_first = 0;
int queue_last = 0;

void enqueue(int val) {
	if ((queue_last + 1) % QUEUE_MAX == queue_first) {
		printf("Jobs are filled\n");
	}
	else {
		queue[queue_last] = val;
		queue_last = (queue_last + 1) % QUEUE_MAX;
	}
}

int dequeue(void) {
	int ret;

	if(queue_first == queue_last) {
		return QUEUE_EMPTY;
	}
	else {
		ret = queue[queue_first];
		queue_first = (queue_first + 1) % QUEUE_MAX;
		return ret;
	}
}
