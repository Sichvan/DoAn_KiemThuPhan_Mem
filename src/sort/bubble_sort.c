void Hoanvi(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubleSort(int a[], int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j > i; j--) {
            if (a[j] < a[j - 1]) // nếu sai vị trí thì đổi chỗ
                Hoanvi(a[j], a[j - 1]);
        }
    }
}