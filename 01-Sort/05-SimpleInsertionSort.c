#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int sort[N];

void SimpleInsertionSort(void) {
	int i, search, insert, temp;

	for(i = 0; i < N - 1; i++) {
		insert = sort[i + 1];
		
		for(search = 0; search <= i; search++) {
			if (sort[search] > insert) {
				break;
			}
		}

		while(search <= i + 1) {
			temp = sort[search];
			sort[search] = insert;
			insert = temp;
			search++;
		}
	}
}

int main(int argc, char* argv[]) {
	int i;

	srand((unsigned int)time(NULL));
	
	printf("Prepare for sort\n");
	for(i = 0; i < N; i++) {
		sort[i] = rand() % 100;
		printf("%d ", sort[i]);
	}
	printf("\n");

	printf("Start sort\n");
	SimpleInsertionSort();

	printf("Finish sort\n");
	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}
	printf("\n");


	return 0;
}
