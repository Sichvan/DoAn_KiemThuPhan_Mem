int JumpSearch(int a[], int n, int x) { // Đã đổi N thành n
    int step = 2; 
    int prev = 0;
    while (a[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += 2; // Tăng bước nhảy thêm 2
        if (prev >= n)
            return -1; // Đã vượt quá kích thước mảng
    }

    // Tìm kiếm tuyến tính trong khối vừa xác định
    while (a[prev] < x) {
        prev++;
        // Nếu chạy đến bước nhảy tiếp theo hoặc hết mảng mà chưa thấy
        if (prev == (step < n ? step : n))
            return -1;
    }

    // Kiểm tra xem phần tử tìm được có đúng là x không
    if (a[prev] == x)
        return prev;

    return -1;
}