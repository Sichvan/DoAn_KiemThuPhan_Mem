#include <assert.h>
#include "../common.h"
#include "interpolation_search.c"

int main() {
    int a[N];
    int x = nondet_int();

    __CPROVER_assume(x >= 0 && x <= 50);

    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
        __CPROVER_assume(a[i] >= 0 && a[i] <= 50);
    }

    for (int i = 0; i < N - 1; i++) __CPROVER_assume(a[i] <= a[i+1]);
    if (N > 1) __CPROVER_assume(a[0] != a[N-1]);

    int result = InterpolationSearch(a, N, x);

    if (result != -1) {
        assert(a[result] == x);
    } else {
        for (int i = 0; i < N; i++) assert(a[i] != x);
    }
    return 0;
}