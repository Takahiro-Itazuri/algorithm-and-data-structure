#include<stdio.h>
#include<stdlib.h>

#define N 5
int size[N] = {2, 3, 5, 6, 9};
int value[N] = {2, 4, 7, 10, 14};

#define KNAP_SIZE 16

int main(void) {
	int knap_value[KNAP_SIZE + 1] = {0};
	int i, j, new_value;

	printf("knapsack size  :");
	for(i = 1; i < KNAP_SIZE; i++) {
		printf("%2d ", i);
	}
	printf("\n\n");

	for(i = 0; i < N; i++) {
		for(j = size[i]; j < KNAP_SIZE + 1; j++) {
			new_value = knap_value[j - size[i]] + value[i];

			if(new_value > knap_value[j]) knap_value[j] = new_value;
		}

		printf("num of item = %d:", i + 1);
		for(j = 1; j < KNAP_SIZE + 1; j++) {
			printf("%2d ", knap_value[j]);
		}
		printf("\n");
	}
	
	return EXIT_SUCCESS;
}
