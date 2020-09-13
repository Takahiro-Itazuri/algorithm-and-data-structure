#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#define N 10

void BubbleSort(int* arr) {
	bool flag = true;

	while (flag) {
		flag = false;
		for (int i = 0; i < N - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
		}
	}
}

int main() {
	int sort[N];
	
	random_device rnd;
	cout << "Input : ";
	for (int i = 0; i < N; ++i) {
		sort[i] = rnd() % 100;
		cout << sort[i] << " ";
	}
	cout << endl;

	chrono::system_clock::time_point start = chrono::system_clock::now();

	BubbleSort(sort);

	chrono::system_clock::time_point end = chrono::system_clock::now();
	double msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

	cout << "Output: ";
	for (int i = 0; i < N; ++i) cout << sort[i] << " ";
	cout << endl;

	cout << "Time  : " << msec << " [ms]" << endl;

	return 0;
}
