#include <iostream>
using namespace std;

int main(void) {
	int N, M;
	cout << "Enter number of Rows and Columns" << endl;
	cin >> N >> M;

	int* arr2 = new int[N * M];
	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] arr2;
	return 0;
}
