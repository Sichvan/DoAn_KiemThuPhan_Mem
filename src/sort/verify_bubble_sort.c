#include <assert.h>
#include "../common.h"
#include "bubble_sort.c" // Include trực tiếp file thuật toán

// Hàm kiểm tra tính chất đã sắp xếp
void check_sorted(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Nếu phần tử trước lớn hơn phần tử sau -> LỖI
        assert(a[i] <= a[i+1]);
    }
}

int main() {
    int a[N];

    // 1. Sinh mảng ngẫu nhiên
    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
    }

    // 2. Gọi hàm sort cần kiểm tra
    BubleSort(a, N);

    // 3. Kiểm chứng kết quả
    check_sorted(a, N);

    return 0;
}