#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int main(void) {
	int buf, sum, count, n, size;
	int *array, *temp;

	size = 10;
	array = (int*)malloc(sizeof(int) * size);

	count = 0;
	do {
		printf("Input an integer number: ");
		scanf("%d", &buf);
		if(buf) {
			array[count] = buf;
			count++;
			if(count == size) {
				temp = (int*)malloc(sizeof(int) * size * 2);
				memcpy(temp, array, sizeof(int) * size);
				free(array);
				array = temp;
				size *= 2;
			}
		}
	} while(buf != 0);

	printf("Inputed numbers are following numbers.\n");
	for(sum = n = 0; n < count; n++) {
		printf("%d\t", array[n]);
		sum += array[n];
	}
	printf("\n----\nSum of these numbers is %d.\n", sum);

	free(array);
	return 0;
}
