//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;


int biSearch(int a[], int l, int r, int value) {
	if (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == value) 
			return mid;
		if (a[mid] > value)
			return biSearch(a, l, mid - 1, value);
		return biSearch(a, mid + 1, r, value);
	}
	return -1;
}

signed main () {
	int n = 9, a[10] = { 10, 3, 2, 8, 9, 11, 4, 1, 7};
	sort(a , a + n);
	cout << biSearch(a, 0, n - 1, 7);

	return 0;
}