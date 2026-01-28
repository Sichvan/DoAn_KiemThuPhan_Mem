#include <assert.h>
#include "../common.h"
#include "binary_search.c" 

int main() {
    int a[N];
    int x = nondet_int();

    // 1. Sinh mảng ngẫu nhiên
    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
    }

    // 2. RÀNG BUỘC QUAN TRỌNG: Mảng đầu vào bắt buộc phải tăng dần
    // Nếu không có dòng này, Binary Search sẽ chạy sai và báo lỗi oan.
    for (int i = 0; i < N - 1; i++) {
        __CPROVER_assume(a[i] <= a[i+1]);
    }

    // 3. Gọi hàm
    int result = BinarySearch(a, N, x);

    // 4. Kiểm chứng (giống Linear)
    if (result != -1) {
        assert(a[result] == x);
    } else {
        for (int i = 0; i < N; i++) {
            assert(a[i] != x);
        }
    }
    return 0;
}