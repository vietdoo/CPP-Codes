//Author: vietdoo
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100009;

void merge(int a[], int l, int mid, int r)
{
    int n = mid - l + 1;
    int m =  r - mid;
 
    int aLeft[n], aRight[m];
 
    for (int i = 0; i < n; i++)
        aLeft[i] = a[l + i];
    for (int i = 0; i < m; i++)
        aRight[i] = a[mid + 1 + i];

    int i = 0,  j = 0, k = l;

    while (i < n && j < m)
    {
        if (aLeft[i] <= aRight[j])
        	a[k++] = aLeft[i++];
        else
	        a[k++] = aRight[j++];
    }
 
    while (i < n)
        a[k++] = aLeft[i++];
    while (j < m)
        a[k++] = aRight[j++];
}

void mergeSort(int a[], int l, int r) {
	if (l < r) {
		int mid = (l + r) /2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

int main () {
    int n = 9, a[N] = {10, 3, 2, 8, 9, 11, 4, 1, 7};

    mergeSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << "\ndone";
    return 0;
}