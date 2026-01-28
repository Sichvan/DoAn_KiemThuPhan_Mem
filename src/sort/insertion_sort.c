void Hoanvi(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void InsertionSort(int a[], int N) {
    int pos, i;
    int x; // lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.
    for (i = 1; i < N; i++) { // đoạn a[0] đã sắp
        x = a[i]; 
        pos = i - 1;
        // tìm vị trí chèn x
        while ((pos >= 0) && (a[pos] > x)) {
            // kết hợp dời chỗ các phần tử sẽ đứng sau x trong dãy mới
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x; // chèn x vào dãy
    }
}