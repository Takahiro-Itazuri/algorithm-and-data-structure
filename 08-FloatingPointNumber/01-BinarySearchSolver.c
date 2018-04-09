#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double x) {
	return x * x * x * x * x - 10.0 * x * x * x * x + 25.0 * x * x * x + 40.0 * x * x + 200.0 * x - 500.0;
}

double BinarySearch(void) {
	double left, mid, right, epsilon;

	epsilon = 0.00001;

	left = 1.0;
	right = 3.0;

	while(fabs(right - left) > epsilon && fabs(func(left)) > epsilon) {
		mid = (left + right) / 2.0;

		if(func(left) * func(mid) >= 0.0) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	return left;
}

int main(void) {
	double d;
	d = BinarySearch();
	printf("x = %lf, func(x) = %lf.\n", d, func(d));
	return EXIT_SUCCESS;
}
