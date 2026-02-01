void Hoanvi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InterchangeSort(int a[], int n) { 
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                Hoanvi(&a[j], &a[i]); 
            }
        }
    }
}