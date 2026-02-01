int InterpolationSearch(int a[], int n, int x) { 
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= a[lo] && x <= a[hi]) {
        if (lo == hi) {
            if (a[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (a[hi] - a[lo])) * (x - a[lo]));
        if (a[pos] == x)
            return pos;
        if (a[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}