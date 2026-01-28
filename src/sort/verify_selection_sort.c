#include <assert.h>
#include "../common.h"
#include "selection_sort.c"

void check_sorted(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        assert(a[i] <= a[i+1]);
    }
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) a[i] = nondet_int();

    SelectionSort(a, N);
    check_sorted(a, N);
    return 0;
}