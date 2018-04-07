#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int sort[N];

void BubbleSort() {
	int i, temp, flag;

	do {
		flag = 0;
		for (i = 0; i < N - 1; i++) {
			if (sort[i] > sort[i + 1]) {
				flag = 1;
				temp = sort[i];
				sort[i] = sort[i + 1];
				sort[i + 1] = temp;		
			}
		}
	} while(flag == 1);
}

int main(int argc, char* argv[]) {
	int i;

	srand((unsigned int)time(NULL));

	printf("Prepare for sort\n");
	for (i = 0; i < N; i++) {
		sort[i] = rand() % 100;
		printf("%d ", sort[i]);
	}
	printf("\n");

	printf("Start sort\n");
	BubbleSort();

	printf("Finish sort\n");
	for (i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}
	printf("\n");



	return 0;
}
