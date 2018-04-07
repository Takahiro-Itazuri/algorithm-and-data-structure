#include<stdio.h>
#include<stdlib.h>
#include<time.h>

# define N 10

int sort[N];
int buffer[N];

void MergeSort(int n, int* x) {
	int i, j, k, m;	

	if (n <= 1) {
		return;	
	}
	m = n / 2;
	
	MergeSort(m, x);
	MergeSort(n - m, x + m);

	for(i = 0; i < m; i++) {
		buffer[i] = x[i];
	} 

	i = k = 0;
	j = m;

	while(i < m && j < n) {
		if(buffer[i] <= x[j]) {
			x[k++] = buffer[i++];
		}
		else {
			x[k++] = x[j++];
		}
	}

	while (i < m) {
		x[k++] = x[i++];
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
	MergeSort(N, sort);

	printf("Finish sort\n");
	for(i = 0; i < N; i++) {
		printf("%d ", sort[i]);
	}
	printf("\n");


	return 0;
}
