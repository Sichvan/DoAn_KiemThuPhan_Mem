void Hoanvi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                Hoanvi(&a[j], &a[j - 1]);
            }
        }
    }
}