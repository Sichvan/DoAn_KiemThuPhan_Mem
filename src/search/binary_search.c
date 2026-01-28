int BinarySearch(int a[], int N, int x) {
    int left = 0, right = N - 1, mid;
    do {
        mid = (left + right) / 2;
        if (x == a[mid]) return mid; // Tìm thấy
        else if (x < a[mid]) right = mid - 1;
        else left = mid + 1;
    } while (left <= right);
    return -1; // Không tìm thấy
}