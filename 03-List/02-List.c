#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int buf, sum, count, n, i;
	int *array;

	printf("How many numbers do you input?: ");
	scanf("%d", &count);
	array = (int*)malloc(sizeof(int) * count);

	n = 0;
	do {
		printf("Input an integer number: ");
		scanf("%d", &buf);
		if(buf) {
			array[n++] = buf;
		}
	} while(buf != 0 && n != count);

	printf("Inputed numbers are following numbers.");
	for(sum = i = 0; i < n; i++) {
		printf("%d\t", array[i]);
		sum += array[i];
	}
	printf("\n----\nSum of these numbers is %d.", sum);

	free(array);
	return 0;
}
