void Hoanvi(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int a[], int N) {
    int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
    for (int i = 0; i < N - 1; i++) {
        min = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min])
                min = j; // ghi nhận vị trí phần tử hiện nhỏ nhất
        }
        Hoanvi(a[min], a[i]);
    }
}