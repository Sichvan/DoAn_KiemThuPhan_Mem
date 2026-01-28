int InterpolationSearch(int a[], int n, int x) {
    int lo = 0, hi = (n - 1);

    // Vòng lặp chạy khi x nằm trong khoảng giá trị của mảng [lo, hi]
    while (lo <= hi && x >= a[lo] && x <= a[hi]) {
        
        // Tránh chia cho 0 khi tất cả phần tử giống nhau
        if (lo == hi) {
            if (a[lo] == x) return lo;
            return -1;
        }

        // Công thức nội suy để ước lượng vị trí
        // pos = lo + (quãng đường giá trị * tỷ lệ phân bố)
        int pos = lo + (((double)(hi - lo) / (a[hi] - a[lo])) * (x - a[lo]));

        // Tìm thấy
        if (a[pos] == x)
            return pos;

        // Nếu x lớn hơn giá trị tại pos, x nằm ở nửa phải
        if (a[pos] < x)
            lo = pos + 1;
        // Nếu x nhỏ hơn giá trị tại pos, x nằm ở nửa trái
        else
            hi = pos - 1;
    }
    return -1; // Không tìm thấy
}