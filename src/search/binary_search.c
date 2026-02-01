int BinarySearch(int a[], int n, int x) { 
    int left = 0, right = n - 1, mid;
    do {
        mid = (left + right) / 2;
        if (x == a[mid]) return mid; 
        else if (x < a[mid]) right = mid - 1;
        else left = mid + 1;
    } while (left <= right);
    return -1; 
}