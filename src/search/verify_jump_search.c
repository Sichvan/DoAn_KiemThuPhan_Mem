#include <assert.h>
#include "../common.h"
#include "jump_search.c" 
// Lưu ý: Code gốc của bạn có #include <math.h>, khi chạy cbmc có thể cần flag đặc biệt
// Nếu CBMC báo lỗi hàm sqrt, hãy thử thay sqrt(n) bằng số cố định (ví dụ 2) trong code nguồn để test.

int main() {
    int a[N];
    int x = nondet_int();

    // Sinh mảng và assume sorted (Bắt buộc)
    for (int i = 0; i < N; i++) a[i] = nondet_int();
    for (int i = 0; i < N - 1; i++) __CPROVER_assume(a[i] <= a[i+1]);

    int result = JumpSearch(a, N, x);

    if (result != -1) {
        assert(a[result] == x);
    } else {
        for (int i = 0; i < N; i++) assert(a[i] != x);
    }
    return 0;
}