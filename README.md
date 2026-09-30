TÀI LIỆU PHÂN TÍCH – THIẾT KẾ CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN C++
1. Giới thiệu

Đây là chương trình Quản lý sinh viên được xây dựng bằng ngôn ngữ C++, chạy trên môi trường console.

Chương trình cho phép người dùng quản lý danh sách sinh viên thông qua menu. Mỗi sinh viên bao gồm các thông tin:

Mã sinh viên
Họ tên
Lớp
Điểm trung bình

Chương trình hỗ trợ các chức năng chính như thêm, sửa, xóa, tìm kiếm, sắp xếp và thống kê sinh viên.

Chương trình sử dụng các kiến thức C++ cơ bản như:

struct: xây dựng kiểu dữ liệu sinh viên.
array: lưu danh sách sinh viên.
function: chia chương trình thành các chức năng riêng.
string: xử lý mã sinh viên, họ tên và lớp.
for, do while: lặp và duyệt danh sách.
if else: kiểm tra điều kiện.
switch case: xây dựng menu.
Bubble Sort: sắp xếp danh sách.
Tham chiếu &: thay đổi dữ liệu trực tiếp trong hàm.
2. Thư viện sử dụng

Chương trình sử dụng các thư viện:

#include <iostream>
#include <string>
#include <iomanip>
iostream

Dùng để nhập và xuất dữ liệu:

cin
cout

Ví dụ:

cout << "Nhap ma sinh vien: ";
cin >> ma;
string

Dùng để xử lý dữ liệu dạng chuỗi:

string maSV;
string hoTen;
string lop;

Ngoài ra sử dụng:

.find()

để tìm kiếm tên sinh viên.

iomanip

Dùng để định dạng dữ liệu khi xuất ra màn hình:

setw()
left
fixed
setprecision()

Ví dụ:

cout << left
     << setw(15) << sv.maSV
     << setw(25) << sv.hoTen
     << fixed << setprecision(2)
     << sv.diemTB;
3. Thiết kế dữ liệu
3.1. Struct SinhVien

Chương trình sử dụng struct để lưu thông tin của một sinh viên:

struct SinhVien
{
    string maSV;
    string hoTen;
    string lop;
    double diemTB;
};

Trong đó:

Thuộc tính	Kiểu dữ liệu	Ý nghĩa
maSV	string	Mã sinh viên
hoTen	string	Họ và tên
lop	string	Lớp
diemTB	double	Điểm trung bình

Có thể hình dung:

SinhVien
│
├── maSV
├── hoTen
├── lop
└── diemTB
4. Lưu trữ danh sách sinh viên

Chương trình sử dụng mảng:

SinhVien ds[100];

Mảng có thể lưu tối đa 100 sinh viên.

Biến:

int n = 0;

dùng để lưu số lượng sinh viên hiện tại.

Ví dụ:

ds[0] → Sinh viên 1
ds[1] → Sinh viên 2
ds[2] → Sinh viên 3
...
ds[n-1] → Sinh viên cuối cùng

Khi thêm một sinh viên:

ds[n] = sv;
n++;
5. Các chức năng chính

Chương trình gồm các chức năng:

1. Thêm sinh viên
2. Hiển thị danh sách
3. Sửa sinh viên
4. Xóa sinh viên
5. Tìm kiếm sinh viên
6. Sắp xếp sinh viên
7. Thống kê học lực
8. Tìm sinh viên điểm cao nhất
0. Thoát
6. Chức năng thêm sinh viên

Hàm:

void themSinhVien(SinhVien ds[], int &n);

Chức năng này cho phép nhập một sinh viên mới vào danh sách.

Quy trình:

Nhập mã sinh viên
        ↓
Kiểm tra mã đã tồn tại chưa
        ↓
   ┌────┴────┐
   │         │
Đã tồn tại  Chưa tồn tại
   │         │
 Báo lỗi   Nhập thông tin
             │
             ↓
        Lưu vào mảng
             │
             ↓
           n++

Mã sinh viên được kiểm tra bằng:

kiemTraMaTonTai(ds, n, ma);

Mục đích là đảm bảo không có hai sinh viên trùng mã.

7. Chức năng hiển thị danh sách

Hàm:

void hienThiDanhSach(SinhVien ds[], int n);

Hàm sử dụng vòng lặp:

for (int i = 0; i < n; i++)
{
    xuatSinhVien(ds[i]);
}

để duyệt qua toàn bộ danh sách.

Thông tin được định dạng thành các cột bằng:

setw()
left
fixed
setprecision()

Ví dụ:

Ma SV          Ho Ten                   Lop         Diem TB
------------------------------------------------------------
SV001          Nguyen Van An            CNTT01      8.50
SV002          Tran Van B               CNTT02      7.25
8. Chức năng tìm vị trí sinh viên

Hàm:

int timViTriTheoMa(SinhVien ds[], int n, string ma);

Hàm duyệt mảng và tìm vị trí của sinh viên dựa vào mã.

Nếu tìm thấy:

return i;

Nếu không tìm thấy:

return -1;

Ví dụ:

ds[0] → SV001
ds[1] → SV002
ds[2] → SV003

Tìm SV002:

SV002 → vị trí 1

Hàm này được sử dụng lại trong nhiều chức năng:

Sửa sinh viên
Xóa sinh viên
Tìm kiếm theo mã
9. Chức năng sửa sinh viên

Hàm:

void suaSinhVien(SinhVien ds[], int n);

Quy trình:

Nhập mã sinh viên
        ↓
Tìm vị trí sinh viên
        ↓
Có tìm thấy?
   ┌────┴────┐
   │         │
  Không      Có
   │         │
 Báo lỗi    Nhập thông tin mới
             │
             ↓
        Cập nhật dữ liệu

Mã sinh viên được giữ nguyên, chương trình cho phép thay đổi:

Họ tên
Lớp
Điểm trung bình
10. Chức năng xóa sinh viên

Hàm:

void xoaSinhVien(SinhVien ds[], int &n);

Đầu tiên chương trình tìm vị trí sinh viên cần xóa.

Sau đó dịch các phần tử phía sau lên một vị trí:

for (int i = viTri; i < n - 1; i++)
{
    ds[i] = ds[i + 1];
}

Cuối cùng:

n--;

Ví dụ:

Trước khi xóa:

[SV001] [SV002] [SV003] [SV004]

Xóa SV002:

[SV001] [SV003] [SV004]

Sau đó n giảm đi 1.
11. Chức năng tìm kiếm theo mã

Hàm:

void timTheoMa(SinhVien ds[], int n);

Người dùng nhập mã sinh viên.

Chương trình sử dụng:

timViTriTheoMa()

để tìm vị trí.

Nếu tìm thấy, chương trình hiển thị thông tin sinh viên.

12. Chức năng tìm kiếm theo tên

Hàm:

void timTheoTen(SinhVien ds[], int n);

Chương trình sử dụng:

find()

của string.

Ví dụ:

if (ds[i].hoTen.find(tuKhoa) != string::npos)

Nếu tên chứa từ khóa cần tìm thì sinh viên đó được hiển thị.

Ví dụ người dùng nhập:

Nguyen

thì các tên như:

Nguyen Van An
Nguyen Van B
Tran Nguyen C

có thể được tìm thấy vì chuỗi "Nguyen" xuất hiện trong tên.

13. Chức năng sắp xếp theo điểm

Hàm:

void sapXepTheoDiem(SinhVien ds[], int n);

Chương trình sử dụng thuật toán Bubble Sort.

Điểm được sắp xếp theo thứ tự giảm dần:

9.50
8.75
8.00
7.25
6.50

Phần quan trọng:

if (ds[j].diemTB < ds[j + 1].diemTB)

Nếu sinh viên phía trước có điểm thấp hơn sinh viên phía sau thì đổi chỗ.

14. Chức năng sắp xếp theo tên

Hàm:

void sapXepTheoTen(SinhVien ds[], int n);

Chương trình cũng sử dụng Bubble Sort.

So sánh:

if (ds[j].hoTen > ds[j + 1].hoTen)

Nếu tên phía trước lớn hơn tên phía sau thì đổi chỗ.

15. Chức năng xếp loại học lực

Hàm:

string xepLoai(double diem);

Dựa vào điểm trung bình để xác định học lực.

Quy tắc đang sử dụng trong chương trình:

Điểm >= 8.0       → Giỏi
Điểm >= 6.5       → Khá
Điểm >= 5.0       → Trung bình
Điểm < 5.0        → Yếu

Ví dụ:

8.5  → Giỏi
7.0  → Khá
5.5  → Trung bình
4.0  → Yếu
16. Chức năng thống kê học lực

Hàm:

void thongKe(SinhVien ds[], int n);

Chương trình sử dụng các biến đếm:

int soGioi = 0;
int soKha = 0;
int soTrungBinh = 0;
int soYeu = 0;

Sau đó duyệt toàn bộ danh sách:

for (int i = 0; i < n; i++)

và sử dụng:

xepLoai(ds[i].diemTB);

để xác định loại học lực.

Kết quả có dạng:

========== THONG KE ==========

Gioi       : 3
Kha        : 5
Trung binh : 2
Yeu        : 1
17. Tìm sinh viên có điểm cao nhất

Hàm:

void timDiemCaoNhat(SinhVien ds[], int n);

Chương trình sử dụng phương pháp tìm giá trị lớn nhất.

Ban đầu giả sử sinh viên đầu tiên có điểm cao nhất:

int viTriMax = 0;

Sau đó duyệt từ sinh viên thứ hai:

for (int i = 1; i < n; i++)

Nếu tìm thấy điểm lớn hơn:

if (ds[i].diemTB > ds[viTriMax].diemTB)
{
    viTriMax = i;
}

thì cập nhật vị trí.

Cuối cùng:

ds[viTriMax]

là sinh viên có điểm cao nhất.

18. Menu chương trình

Hàm:

void menu();

có nhiệm vụ hiển thị các lựa chọn cho người dùng.

Trong main() sử dụng:

switch (luaChon)

để xử lý lựa chọn.

Có thể hình dung:

              MENU
                ↓
          Người dùng chọn
                ↓
          switch - case
                ↓
      ┌─────────┼─────────┐
      ↓         ↓         ↓
    Thêm      Hiển thị    Sửa
      ↓         ↓         ↓
   case 1     case 2     case 3
19. Cấu trúc tổng thể chương trình

Toàn bộ chương trình có thể hình dung như sau:

                    MAIN
                     │
                     ↓
                    MENU
                     │
             Người dùng lựa chọn
                     │
       ┌─────────────┼─────────────┐
       ↓             ↓             ↓
     Thêm          Hiển thị       Sửa
       │             │             │
       ↓             ↓             ↓
   themSinhVien  hienThiDanhSach suaSinhVien
       
       ┌─────────────┼─────────────┐
       ↓             ↓             ↓
      Xóa          Tìm kiếm      Sắp xếp
       │             │             │
       ↓             ↓             ↓
xoaSinhVien    timTheoMa/ten  sapXepTheo...
       
                     │
                     ↓
                  Thống kê
                     │
                     ↓
                  Tìm max
20. Các kiến thức C++ được áp dụng

Project này giúp áp dụng nhiều kiến thức cơ bản:

Cấu trúc dữ liệu
struct SinhVien
Mảng
SinhVien ds[100];
Hàm
void themSinhVien(...)
void xoaSinhVien(...)
Tham chiếu
SinhVien &sv
int &n
Chuỗi
string
find()
Vòng lặp
for
do while
Điều kiện
if
else if
else
Menu
switch case
Thuật toán
Bubble Sort
Tìm kiếm tuần tự
Tìm giá trị lớn nhất
Định dạng xuất
setw()
left
fixed
setprecision()
21. Cấu trúc file đề xuất

Nếu đưa lên GitHub, repository của bạn có thể trình bày như:

QuanLySinhVien/
│
├── README.md
│
└── QuanLySinhVien.cpp

Trong đó:

README.md
    ↓
Tài liệu phân tích + hướng dẫn project

QuanLySinhVien.cpp
    ↓
Code chương trình chính
22. Kết luận

Chương trình Quản lý sinh viên được xây dựng nhằm áp dụng các kiến thức C++ cơ bản vào một bài toán thực tế.

Chương trình sử dụng struct để quản lý thông tin sinh viên, mảng để lưu danh sách, hàm để chia nhỏ chương trình và các thuật toán cơ bản để tìm kiếm, sắp xếp và thống kê.

Thông qua project, các kiến thức về struct, array, function, string, vòng lặp, điều kiện, switch-case, Bubble Sort và tham chiếu được kết hợp thành một chương trình hoàn chỉnh.#   P r o j e c t q u a n l y s i n h v i e n  
 