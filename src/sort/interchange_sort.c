void Hoanvi(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void InterchangeSort(int a[], int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (a[j] < a[i]) 
                Hoanvi(a[min], a[i]);                                                                                                               
        }
    }
}