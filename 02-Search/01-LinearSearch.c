#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NOT_FOUND (-1)
#define N (10)

int LinearSearch(int x, int *a, int num) {
	int n = 0;
	
	while(n < num && a[n] != x) {
		n++;
	}

	if (n < num) {
		return n;
	}

	return NOT_FOUND;
}

int main(int argc, char* argv[]) {
	int i, r, array[N];
	
	srand((unsigned int)time(NULL));

	printf("array ");
	for(i = 0; i < N; i++) {
		printf("[%d]:%d ", i, array[i] = rand() % 20);
	}

	printf("\nWhat do you want to search: ");
	scanf("%d", &i);

	r = LinearSearch(i, array, N);

	if(r == NOT_FOUND) {
		printf("%d is not found.\n", i);	
	}
	else {
		printf("%d is %d-th number.\n", i, r);
	}

	return 0;
}
