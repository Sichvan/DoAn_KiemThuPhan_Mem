#include <assert.h>
#include "../common.h"
#include "bubble_sort.c" 

void check_sorted(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        assert(a[i] <= a[i+1]);
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
    }
    BubbleSort(a, N); 
    check_sorted(a, N);
    return 0;
}