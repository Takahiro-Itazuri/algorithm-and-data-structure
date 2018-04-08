#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NOT_FOUND (-1)
#define N (10)

int SelfOrganizingSearch(int x, int *a, int num) {
	int n = 0, t;

	while(n < num && a[n] != x) {
		n++;
	}

	if (n < num) {
		if (n > 0) {
			t = a[n - 1];
			a[n - 1] = a[n];
			a[n] = t;
			return n - 1;
		}
		return n;
	}

	return NOT_FOUND;
}

int main(void) {
	int i, r, array[N];

	srand((unsigned int)time(NULL));

	for(i = 0; i < N; i++) {
		array[i] = rand() % 20;
	}

	for(;;) {
		printf("array ");
		for(i = 0; i < N; i++) {
			printf("[%d]:%d ", i, array[i]);
		}

		printf("\nWhat do you want to search? (-1: finish): ");
		scanf("%d", &i);

		if (i == -1) {
			break;
		}

		r = SelfOrganizingSearch(i, array, N);

		if (r == NOT_FOUND) {
			printf("%d is not found.\n", i);
		}
		else {
			printf("%d is %d-th number.\n", i, r);
		}
	}

	return 0;
}
