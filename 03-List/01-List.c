#include<stdio.h>
#include<stdlib.h>

#define NMAX 10

int main(void) {
	int buf, sum, count, n;
	int array[NMAX];

	count = 0;
	do {
		printf("Input an integer number: ");
		scanf("%d", &buf);
		if (buf) {
			array[count] = buf;
			count++;
		}
	} while(buf != 0 && count != NMAX);

	printf("--Inputed numbers are following numbers--\n");
	for(sum = n = 0; n < count; n++) {
		printf("%d\t", array[n]);
		sum += array[n];
	}
	printf("\n----\nSum of these numbers is %d.", sum);

	return 0;
}
