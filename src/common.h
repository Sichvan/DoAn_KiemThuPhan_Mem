#ifndef COMMON_H
#define COMMON_H

// Khai báo các hàm của CBMC
int nondet_int();
void __CPROVER_assume(_Bool assumption);

#define N 5 // Kích thước mảng kiểm chứng (giữ nhỏ để chạy nhanh)

#endif