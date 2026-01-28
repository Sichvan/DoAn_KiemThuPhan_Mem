#!/bin/bash

# Tạo thư mục results nếu chưa có
mkdir -p results

echo "---- STARTING VERIFICATION ----"

# Danh sách các file cần verify
FILES=("sort/verify_bubble_sort" "sort/verify_insertion_sort" "sort/verify_interchange_sort" "sort/verify_selection_sort" "search/verify_linear_search" "search/verify_binary_search" "search/verify_interpolation_search" "search/verify_jump_search")

for f in "${FILES[@]}"; do
    NAME=$(basename $f)
    echo "Running verification for: $NAME..."
    
    # Chạy CBMC, unwind 6 lần (vì N=5), xuất kết quả ra file txt
    cbmc src/$f.c --unwind 6 > results/$NAME.txt
    
    # Kiểm tra nhanh kết quả và in màu
    if grep -q "VERIFICATION SUCCESSFUL" results/$NAME.txt; then
        echo -e "Result: \033[0;32mSUCCESS\033[0m" # Màu xanh
    else
        echo -e "Result: \033[0;31mFAILED\033[0m"  # Màu đỏ
    fi
done

echo "---- DONE. Check folder 'results' for details ----"