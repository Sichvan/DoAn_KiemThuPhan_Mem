#ifndef COMMON_H
#define COMMON_H

// Khai báo các hàm của CBMC
int nondet_int();
void __CPROVER_assume(_Bool assumption);

// Kích thước mảng kiểm chứng
// Đây là nguyên nhân gây lỗi nếu bạn đặt tên biến là N ở file .c
#define N 5 

#endif