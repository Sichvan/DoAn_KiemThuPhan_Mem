#include <assert.h>
#include "../common.h"
#include "linear_search.c"

int main() {
    int a[N];
    int x = nondet_int(); // Giá trị cần tìm

    // 1. Sinh mảng ngẫu nhiên (Linear search không cần mảng sort)
    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
    }

    // 2. Gọi hàm
    int result = LinearSearch(a, N, x);

    // 3. Kiểm chứng
    if (result != -1) {
        // Tìm thấy: Tại vị trí trả về phải chứa x
        assert(a[result] == x);
    } else {
        // Không tìm thấy: Duyệt cả mảng để chắc chắn x không tồn tại
        for (int i = 0; i < N; i++) {
            assert(a[i] != x);
        }
    }
    return 0;
}