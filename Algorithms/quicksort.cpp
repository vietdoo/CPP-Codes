//Author: vietdoo
#include <iostream>
using namespace std;

const int N = 100009;

void quickSort(int a[], int l, int r) {
	if (l < r) {
		int pivot = a[(l + r) / 2];
		int i = l;
		int j = r;

		while (i <= j) {
			while (a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i <= j) {
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		quickSort(a, l, j);
		quickSort(a, i, r);
	}
}

int main () {
	int n = 9, a[N] = { 10, 3, 2, 8, 9, 11, 4, 1, 7};
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

	return 0;
}