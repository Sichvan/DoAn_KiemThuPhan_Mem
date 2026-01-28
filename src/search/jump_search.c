#include <math.h> // Cần thư viện này để dùng hàm sqrt

int JumpSearch(int a[], int n, int x) {
    // Kích thước bước nhảy tối ưu là căn bậc 2 của n
    int step = sqrt(n);
    int prev = 0;

    // Tìm khối (block) mà x có thể nằm trong đó
    // Nhảy các bước 'step' cho đến khi giá trị tại bước nhảy lớn hơn hoặc bằng x
    // hoặc đi hết mảng
    while (a[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1; // Đã vượt quá kích thước mảng
    }

    // Tìm kiếm tuyến tính trong khối vừa xác định [prev, step]
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