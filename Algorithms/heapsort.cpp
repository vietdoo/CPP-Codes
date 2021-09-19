//Author: vietdoo
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100009;

void heapify2(int a[], int n, int i) {

    while (i < n / 2) {
        int child = 2 * i + 1;
        if (child < n - 1) {
            if (a[child] < a[child + 1]) {
                child++;
            }
        }
        if (a[i] >= a[child]) {
            break;
        }
        
        swap(a[i], a[child]);
        i = child;
    }
}

void heapify(int a[], int n, int i) {
  
    int l = 2 * i + 1;
    int r = l + 1;

    int child = i;
    if (l < n && a[l] > a[child])
        child = l; 
    if (r < n && a[r] > a[child])
        child = r;

    if (child != i) {
        swap(a[child], a[i]);
        heapify(a, n, child);
    }
}

void buildHeap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n) {
    buildHeap(a, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, --n, 0);
    }
}

int main () {
    int n = 9, a[N] = {10, 3, 2, 8, 9, 11, 4, 1, 7};

    heapSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << "\ndone";
    return 0;
}