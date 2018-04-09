#include<stdio.h>
#include<stdlib.h>

unsigned long power[10] = {0};

int number_using[10] = {0,0,0,0,0,0,0,0,0,0};

int NumOfDigit(unsigned long number, unsigned long digit) {
	int ret = 0;

	if (number == 0) return 0;

	if (number % 10 == digit) {
		ret = 1;
	}

	ret += NumOfDigit(number / 10, digit);

	return ret;
}

void CheckNumber(void) {
	int i;
	unsigned long result;
	result = 0;

	for(i = 1; i <= 9; i++) {
		result += power[i] * number_using[i];
	}

	for(i = 1; i <= 9; i++) {
		if(NumOfDigit(result, i) != number_using[i]) {
			return;
		}
	}

	printf("%lu \n", result);
	return;
}

void MakeNumbers(int start, int kosuu) {
	int i;

	if(kosuu > 10) {
		return;
	}

	for(i = start; i <= 9; i++) {
		number_using[i]++;
		CheckNumber();
		MakeNumbers(i, kosuu + 1);
		number_using[i]--;
	}
}

int main(void) {
	unsigned long i, j, k;
	for(i = 1; i <= 9; i++) {
		k = 1;
		for(j = 0; j < i; j++) {
			k *= i;
		}
		power[i] = k;
	}

	MakeNumbers(1, 1);

	return EXIT_SUCCESS;
}
