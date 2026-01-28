int LinearSearch(int a[], int N, int x) {
    int i = 0;
    while ((i < N) && (a[i] != x)) {
        i++;
    }
    if (i == N) return -1; // tìm hết mảng nhưng không có x
    return i; // tìm thấy tại vị trí i
}