#include<stdio.h>
#include<stdlib.h>

#define N 10
#define SEPARATOR 3

const int array[N] = {15, 3, 7, 6, 10, 4, 13, 2, 3, 6};

#define MAX(a, b) (((a) > (b))? (a): (b))

typedef struct{
	int sol;
	int num;
} cell;

int main(void) {
	cell solutions[N][SEPARATOR + 1];
	int i, j, s, sum;

	for(i = N - 1; i >= 0; i--) {
		for(j = 0; j < SEPARATOR + 1; j++) {
			solutions[i][j].num = 0;
			for(sum = 0, s = i; s < N; s++) {
				sum += array[s];
				if(j == 0 || i == N - 1 || solutions[i][j].num == 0 || (s != N - 1 && solutions[i][j].sol > MAX(sum, solutions[s + 1][j - 1].sol))) {
					if(j == 0 || i == N - 1) {
						solutions[i][j].sol = sum;
					}
					else {
						solutions[i][j].sol = MAX(sum, solutions[s + 1][j - 1].sol);
					}
					solutions[i][j].num = s - i + 1;
				}
			}
		}
	}

	for(j = 0; j < SEPARATOR + 1; j++) {
		for(i = 0; i < N; i++) {
			printf("%2d:%2d ", solutions[i][j].num, solutions[i][j].sol);
		}
		printf("\n");
	}

	printf("\nmax of sum:%d\ndivision:", solutions[0][SEPARATOR].sol);
	for(i = 0, j = SEPARATOR; j >= 0&& i != N; j--) {
		printf("[%d] ", solutions[i][j].num);
		i += solutions[i][j].num;
	}
	printf("\n");

	return 0;
}
