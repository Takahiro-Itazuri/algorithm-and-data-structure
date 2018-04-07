#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int sort[N];

void CombSort(void) {
	int i, temp, flag, gap;
	gap = N;

	do {
		gap = (gap * 10) / 13;
		if(gap == 0) {
			gap = 1;
		}

		flag = 1;
		for(i = 0; i < N - gap; i++) {
			if(sort[i] > sort[i + gap]) {
				flag = 0;
				temp = sort[i];
				sort[i] = sort[i + gap];
				sort[i + gap] = temp;
			}
		}
	} while((gap > 1) || (flag != 1));
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
	CombSort();

	printf("Finish sort\n");
	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}
	printf("\n");



	return 0;
}
