#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int sort[N];

void BinaryInsertionSort() {
	int sorted, insert, idx, temp;
	int left, mid, right;

	for(sorted = 1; sorted < N; sorted++) {
		insert = sort[sorted];
		
		left = 0;
		right = sorted;
		while (left < right) {
			mid = (left + right) / 2;
			
			if(sort[mid] < insert) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}

		idx = left;

		while(idx <= sorted) {
			temp = sort[idx];
			sort[idx] = insert;
			insert = temp;
			idx++;
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
	BinaryInsertionSort();

	printf("Finish sort\n");
	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]); 
	}
	printf("\n");

	return 0;
}
