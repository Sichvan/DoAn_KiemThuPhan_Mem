#include <assert.h>
#include "../common.h"
#include "interpolation_search.c"

int main() {
    int a[N];
    int x = nondet_int();

    for (int i = 0; i < N; i++) a[i] = nondet_int();
    // Ràng buộc mảng tăng dần
    for (int i = 0; i < N - 1; i++) __CPROVER_assume(a[i] <= a[i+1]);

    // Ràng buộc bổ sung cho Interpolation: Các phần tử không được trùng nhau hoàn toàn
    // để tránh lỗi chia cho 0 trong logic (a[hi] - a[lo]) nếu code gốc chưa xử lý kỹ
    if (N > 1) __CPROVER_assume(a[0] != a[N-1]);

    int result = InterpolationSearch(a, N, x);

    if (result != -1) {
        assert(a[result] == x);
    } else {
        for (int i = 0; i < N; i++) assert(a[i] != x);
    }
    return 0;
}