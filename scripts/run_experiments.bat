@echo off
setlocal

REM --- BƯỚC 1: KIỂM TRA MÔI TRƯỜNG ---
cbmc --version >nul 2>&1
if %errorlevel% neq 0 (
    echo [LOI] May tinh chua tim thay lenh 'cbmc'.
    echo Vui long cai dat CBMC va chon "Add to PATH" truoc khi chay.
    pause
    exit /b
)

REM --- BƯỚC 2: ĐỊNH VỊ THƯ MỤC GỐC ---
REM File bat dang o trong folder 'scripts', ta can lui ra ngoai 1 cap de ve root
cd /d "%~dp0.."

REM Tao thu muc results neu chua co
if not exist results mkdir results

echo ========================================================
echo        BAT DAU KIEM THU PHAN MEM VOI CBMC
echo ========================================================

REM Danh sach cac file can verify (Dung dau cach de ngan cach)
REM Luu y: Dung dau gach cheo nguoc (\) cho Windows
set FILES=sort\verify_bubble_sort sort\verify_insertion_sort sort\verify_interchange_sort sort\verify_selection_sort search\verify_linear_search search\verify_binary_search search\verify_interpolation_search search\verify_jump_search

REM --- BƯỚC 3: CHAY VONG LAP KIEM THU ---
for %%F in (%FILES%) do (
    call :run_test %%F
)

echo.
echo ========================================================
echo        HOAN TAT. KIEM TRA THU MUC 'results'
echo ========================================================
pause
exit /b

REM --- HAM CON DE CHAY TUNG FILE ---
:run_test
set FILE_PATH=%1
REM Lay ten file don thuan (bo phan duong dan) de dat ten file log
for %%I in ("%FILE_PATH%") do set NAME=%%~nI

echo.
echo [Dang chay] Kiem thu %NAME%...

REM Lenh CBMC: --unwind 6 (vi mang N=5), --trace (ghi vet loi)
REM 2>&1 la de bat ca loi bien dich (neu code C sai cu phap) vao file log
REM Lenh CBMC: them co --gcc de dung trinh bien dich GCC (MinGW)
cbmc "src\%FILE_PATH%.c" --gcc --unwind 6 --trace > "results\%NAME%.txt" 2>&1

REM Kiem tra ket qua trong file log vua tao
findstr /C:"VERIFICATION SUCCESSFUL" "results\%NAME%.txt" >nul
if %errorlevel% equ 0 (
    echo    Ket qua: [THANH CONG] - OK
) else (
    echo    Ket qua: [THAT BAI]   - Xem chi tiet tai results\%NAME%.txt
)
exit /b