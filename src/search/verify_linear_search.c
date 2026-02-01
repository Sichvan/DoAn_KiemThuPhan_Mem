#include <assert.h>
#include "../common.h"
#include "linear_search.c"

int main() {
    int a[N];
    int x = nondet_int(); 

    for (int i = 0; i < N; i++) {
        a[i] = nondet_int();
    }

    int result = LinearSearch(a, N, x);

    if (result != -1) {
        assert(a[result] == x);
    } else {
        for (int i = 0; i < N; i++) {
            assert(a[i] != x);
        }
    }
    return 0;
}