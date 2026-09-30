# 📚 TÀI LIỆU PHÂN TÍCH – THIẾT KẾ CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN C++

## 1. 📌 Giới thiệu

Đây là chương trình **Quản lý sinh viên** được xây dựng bằng ngôn ngữ **C++**, chạy trên môi trường Console.

Chương trình cho phép người dùng quản lý danh sách sinh viên thông qua hệ thống menu.

Mỗi sinh viên bao gồm các thông tin:

- Mã sinh viên
- Họ tên
- Lớp
- Điểm trung bình

Chương trình hỗ trợ các chức năng chính:

- ➕ Thêm sinh viên
- 📋 Hiển thị danh sách sinh viên
- ✏️ Sửa thông tin sinh viên
- 🗑️ Xóa sinh viên
- 🔎 Tìm kiếm sinh viên theo mã
- 🔎 Tìm kiếm sinh viên theo tên
- 📊 Sắp xếp sinh viên theo điểm
- 📊 Sắp xếp sinh viên theo tên
- 📝 Xếp loại học lực
- 📈 Thống kê học lực
- 🏆 Tìm sinh viên có điểm cao nhất

---

## 2. 🎯 Mục tiêu của chương trình

Project được xây dựng nhằm áp dụng các kiến thức C++ cơ bản vào một bài toán quản lý thực tế.

Các kiến thức được sử dụng:

- `struct`
- Mảng
- Hàm
- Chuỗi `string`
- Vòng lặp `for`
- Vòng lặp `do while`
- Câu lệnh `if else`
- `switch case`
- Tham chiếu `&`
- `const`
- Tìm kiếm tuần tự
- Thuật toán Bubble Sort
- Tìm giá trị lớn nhất
- Định dạng dữ liệu khi xuất

---

## 3. 🛠️ Thư viện sử dụng

Chương trình sử dụng 3 thư viện chính:

```cpp
#include <iostream>
#include <string>
#include <iomanip>
```

### 3.1. Thư viện `iostream`

Dùng để nhập và xuất dữ liệu.

Các lệnh thường sử dụng:

```cpp
cin
cout
```

Ví dụ:

```cpp
cout << "Nhap ma sinh vien: ";
cin >> ma;
```

Trong đó:

- `cout`: xuất dữ liệu ra màn hình.
- `cin`: nhập dữ liệu từ bàn phím.

### 3.2. Thư viện `string`

Dùng để làm việc với dữ liệu dạng chuỗi.

Ví dụ:

```cpp
string maSV;
string hoTen;
string lop;
```

Chương trình cũng sử dụng hàm:

```cpp
.find()
```

để tìm kiếm tên sinh viên.

Ví dụ:

```cpp
if (ds[i].hoTen.find(tuKhoa) != string::npos)
```

### 3.3. Thư viện `iomanip`

Dùng để định dạng dữ liệu khi xuất ra màn hình.

Các lệnh được sử dụng:

```cpp
setw()
left
fixed
setprecision()
```

Ví dụ:

```cpp
cout << left
     << setw(15) << sv.maSV
     << setw(25) << sv.hoTen
     << setw(12) << sv.lop
     << fixed << setprecision(2)
     << sv.diemTB
     << endl;
```

Trong đó:

- `left`: căn dữ liệu về bên trái.
- `setw(15)`: đặt độ rộng 15 ký tự.
- `fixed`: hiển thị số thực theo dạng cố định.
- `setprecision(2)`: hiển thị 2 chữ số sau dấu phẩy.
- `endl`: xuống dòng.

---

## 4. 🧱 Thiết kế dữ liệu

### 4.1. Struct `SinhVien`

Chương trình sử dụng `struct` để tạo kiểu dữ liệu sinh viên:

```cpp
struct SinhVien
{
    string maSV;
    string hoTen;
    string lop;
    double diemTB;
};
```

Struct `SinhVien` gồm 4 thuộc tính:

| Thuộc tính | Kiểu dữ liệu | Ý nghĩa |
|---|---|---|
| `maSV` | `string` | Mã sinh viên |
| `hoTen` | `string` | Họ và tên |
| `lop` | `string` | Lớp |
| `diemTB` | `double` | Điểm trung bình |

Có thể hình dung:

```text
SinhVien
│
├── maSV
├── hoTen
├── lop
└── diemTB
```

---

## 5. 💾 Lưu trữ danh sách sinh viên

Chương trình sử dụng mảng:

```cpp
SinhVien ds[100];
```

Mảng có thể lưu tối đa **100 sinh viên**.

Biến:

```cpp
int n = 0;
```

dùng để lưu **số lượng sinh viên hiện tại**.

Ví dụ:

```text
ds[0] → Sinh viên thứ 1
ds[1] → Sinh viên thứ 2
ds[2] → Sinh viên thứ 3
...
ds[n-1] → Sinh viên cuối cùng
```

Khi thêm một sinh viên:

```cpp
ds[n] = sv;
n++;
```

Trong đó:

- `ds[n] = sv`: đưa sinh viên mới vào vị trí cuối danh sách.
- `n++`: tăng số lượng sinh viên lên 1.

---

## 6. 📋 Danh sách các chức năng

Menu chính của chương trình:

```text
========================================
          QUAN LY SINH VIEN
========================================

1. Them sinh vien
2. Hien thi danh sach
3. Sua sinh vien
4. Xoa sinh vien
5. Tim kiem sinh vien
6. Sap xep sinh vien
7. Thong ke hoc luc
8. Tim sinh vien diem cao nhat
0. Thoat

========================================
```

---

## 7. ➕ Chức năng thêm sinh viên

Hàm:

```cpp
void themSinhVien(SinhVien ds[], int &n);
```

Chức năng này cho phép người dùng nhập một sinh viên mới.

### Quy trình thực hiện

```text
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
```

Trước khi thêm, chương trình kiểm tra mã sinh viên:

```cpp
if (kiemTraMaTonTai(ds, n, sv.maSV))
{
    cout << "Ma sinh vien da ton tai!";
    return;
}
```

Mục đích là đảm bảo mỗi sinh viên có một mã riêng.

---

## 8. 📋 Chức năng hiển thị danh sách

Hàm:

```cpp
void hienThiDanhSach(SinhVien ds[], int n);
```

Hàm sử dụng vòng lặp `for` để duyệt toàn bộ danh sách:

```cpp
for (int i = 0; i < n; i++)
{
    xuatSinhVien(ds[i]);
}
```

Mỗi sinh viên được xuất bằng hàm:

```cpp
xuatSinhVien(ds[i]);
```

Thông tin được trình bày thành các cột:

```text
Ma SV          Ho Ten                   Lop         Diem TB
------------------------------------------------------------
SV001          Nguyen Van An            CNTT01      8.50
SV002          Tran Van B               CNTT02      7.25
SV003          Le Van C                 CNTT03      9.00
```

---

## 9. 🔍 Kiểm tra mã sinh viên

Hàm:

```cpp
bool kiemTraMaTonTai(SinhVien ds[], int n, string ma);
```

Chức năng của hàm là kiểm tra xem mã sinh viên đã tồn tại trong danh sách hay chưa.

Hàm duyệt toàn bộ danh sách:

```cpp
for (int i = 0; i < n; i++)
{
    if (ds[i].maSV == ma)
    {
        return true;
    }
}

return false;
```

Nếu tìm thấy mã:

```cpp
return true;
```

Nếu không tìm thấy:

```cpp
return false;
```

---

## 10. 🔎 Tìm vị trí sinh viên theo mã

Hàm:

```cpp
int timViTriTheoMa(SinhVien ds[], int n, string ma);
```

Hàm tìm vị trí của sinh viên trong mảng dựa vào mã sinh viên.

Nếu tìm thấy:

```cpp
return i;
```

Nếu không tìm thấy:

```cpp
return -1;
```

Ví dụ:

```text
ds[0] → SV001
ds[1] → SV002
ds[2] → SV003
```

Nếu tìm `SV002`:

```text
SV002 → vị trí 1
```

Hàm này được sử dụng lại trong nhiều chức năng:

- Sửa sinh viên
- Xóa sinh viên
- Tìm kiếm theo mã

---

## 11. ✏️ Chức năng sửa sinh viên

Hàm:

```cpp
void suaSinhVien(SinhVien ds[], int n);
```

Người dùng nhập mã sinh viên cần sửa.

Chương trình gọi:

```cpp
timViTriTheoMa(ds, n, ma);
```

để tìm vị trí sinh viên.

### Quy trình

```text
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
```

Các thông tin được phép thay đổi:

- Họ tên
- Lớp
- Điểm trung bình

Mã sinh viên được giữ nguyên.

---

## 12. 🗑️ Chức năng xóa sinh viên

Hàm:

```cpp
void xoaSinhVien(SinhVien ds[], int &n);
```

Đầu tiên chương trình tìm vị trí sinh viên cần xóa.

Sau đó các phần tử phía sau được dịch lên một vị trí:

```cpp
for (int i = viTri; i < n - 1; i++)
{
    ds[i] = ds[i + 1];
}
```

Sau khi xóa:

```cpp
n--;
```

### Ví dụ

Trước khi xóa:

```text
[SV001] [SV002] [SV003] [SV004]
```

Xóa `SV002`:

```text
[SV001] [SV003] [SV004]
```

Sau đó số lượng sinh viên giảm đi 1.

---

## 13. 🔎 Tìm kiếm sinh viên theo mã

Hàm:

```cpp
void timTheoMa(SinhVien ds[], int n);
```

Người dùng nhập mã sinh viên cần tìm.

Chương trình sử dụng:

```cpp
timViTriTheoMa(ds, n, ma);
```

để tìm vị trí sinh viên.

Nếu tìm thấy sinh viên, chương trình hiển thị thông tin của sinh viên đó.

Nếu không tìm thấy:

```text
Khong tim thay sinh vien!
```

---

## 14. 🔎 Tìm kiếm sinh viên theo tên

Hàm:

```cpp
void timTheoTen(SinhVien ds[], int n);
```

Chương trình sử dụng hàm `find()` của `string`:

```cpp
if (ds[i].hoTen.find(tuKhoa) != string::npos)
```

Nếu từ khóa xuất hiện trong họ tên thì sinh viên đó được hiển thị.

Ví dụ nhập:

```text
Nguyen
```

Có thể tìm thấy:

```text
Nguyen Van An
Nguyen Van B
Tran Nguyen C
```

vì chuỗi `Nguyen` xuất hiện trong tên.

---

## 15. 📊 Sắp xếp theo điểm

Hàm:

```cpp
void sapXepTheoDiem(SinhVien ds[], int n);
```

Chương trình sử dụng thuật toán **Bubble Sort**.

Danh sách được sắp xếp điểm theo thứ tự giảm dần:

```text
9.50
8.75
8.00
7.25
6.50
```

Điều kiện đổi chỗ:

```cpp
if (ds[j].diemTB < ds[j + 1].diemTB)
```

Nếu điểm của sinh viên phía trước nhỏ hơn điểm của sinh viên phía sau thì hai sinh viên được đổi chỗ.

---

## 16. 📊 Sắp xếp theo tên

Hàm:

```cpp
void sapXepTheoTen(SinhVien ds[], int n);
```

Chương trình sử dụng thuật toán Bubble Sort.

Điều kiện so sánh:

```cpp
if (ds[j].hoTen > ds[j + 1].hoTen)
```

Nếu tên phía trước lớn hơn tên phía sau thì hai sinh viên được đổi chỗ.

---

## 17. 📝 Xếp loại học lực

Hàm:

```cpp
string xepLoai(double diem);
```

Chương trình dựa vào điểm trung bình để xếp loại học lực.

Quy tắc đang sử dụng:

| Điểm trung bình | Xếp loại |
|---:|---|
| `>= 8.0` | Giỏi |
| `>= 6.5` | Khá |
| `>= 5.0` | Trung bình |
| `< 5.0` | Yếu |

Ví dụ:

```text
8.5 → Giỏi
7.0 → Khá
5.5 → Trung bình
4.0 → Yếu
```

---

## 18. 📈 Thống kê học lực

Hàm:

```cpp
void thongKe(SinhVien ds[], int n);
```

Chương trình tạo các biến đếm:

```cpp
int soGioi = 0;
int soKha = 0;
int soTrungBinh = 0;
int soYeu = 0;
```

Sau đó duyệt toàn bộ danh sách:

```cpp
for (int i = 0; i < n; i++)
{
    string loai = xepLoai(ds[i].diemTB);

    if (loai == "Gioi")
    {
        soGioi++;
    }
    else if (loai == "Kha")
    {
        soKha++;
    }
    else if (loai == "Trung binh")
    {
        soTrungBinh++;
    }
    else
    {
        soYeu++;
    }
}
```

Kết quả có dạng:

```text
========== THONG KE ==========

Gioi       : 3
Kha        : 5
Trung binh : 2
Yeu        : 1
```

---

## 19. 🏆 Tìm sinh viên có điểm cao nhất

Hàm:

```cpp
void timDiemCaoNhat(SinhVien ds[], int n);
```

Ban đầu chương trình giả sử sinh viên đầu tiên có điểm cao nhất:

```cpp
int viTriMax = 0;
```

Sau đó duyệt các sinh viên còn lại:

```cpp
for (int i = 1; i < n; i++)
{
    if (ds[i].diemTB > ds[viTriMax].diemTB)
    {
        viTriMax = i;
    }
}
```

Nếu tìm thấy điểm lớn hơn thì cập nhật:

```cpp
viTriMax = i;
```

Sau khi kết thúc vòng lặp:

```cpp
ds[viTriMax]
```

là sinh viên có điểm trung bình cao nhất.

---

## 20. 🎮 Menu chương trình

Hàm:

```cpp
void menu();
```

có nhiệm vụ hiển thị các chức năng cho người dùng.

Trong `main()` sử dụng:

```cpp
switch (luaChon)
```

để xử lý lựa chọn.

Ví dụ:

```cpp
switch (luaChon)
{
    case 1:
        themSinhVien(ds, n);
        break;

    case 2:
        hienThiDanhSach(ds, n);
        break;

    case 3:
        suaSinhVien(ds, n);
        break;

    case 4:
        xoaSinhVien(ds, n);
        break;

    case 0:
        cout << "Thoat chuong trinh!";
        break;
}
```

---

## 21. 🧩 Cấu trúc tổng thể chương trình

```text
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
themSinhVien  hienThiDanhSach  suaSinhVien

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
             Tìm điểm cao nhất
```

---

## 22. 🧠 Các kiến thức C++ được áp dụng

### 22.1. Struct

```cpp
struct SinhVien
```

Dùng để tạo kiểu dữ liệu riêng cho sinh viên và gom các thông tin liên quan vào một cấu trúc.

---

### 22.2. Mảng

```cpp
SinhVien ds[100];
```

Dùng để lưu nhiều sinh viên.

---

### 22.3. Hàm

Ví dụ:

```cpp
void themSinhVien(...)
void suaSinhVien(...)
void xoaSinhVien(...)
```

Việc chia chương trình thành các hàm giúp chương trình dễ đọc, dễ kiểm tra và dễ quản lý.

---

### 22.4. Tham chiếu

Ví dụ:

```cpp
SinhVien &sv
```

và:

```cpp
int &n
```

Tham chiếu cho phép hàm làm việc trực tiếp với biến ban đầu.

Đặc biệt:

```cpp
int &n
```

được sử dụng khi hàm cần thay đổi số lượng sinh viên.

Ví dụ:

```cpp
n++;
```

hoặc:

```cpp
n--;
```

---

### 22.5. `const`

Ví dụ:

```cpp
const SinhVien &sv
```

Cho phép hàm sử dụng dữ liệu của sinh viên mà không thay đổi dữ liệu đó.

---

### 22.6. Vòng lặp

Chương trình sử dụng:

```cpp
for
```

để duyệt mảng.

Ví dụ:

```cpp
for (int i = 0; i < n; i++)
{
    // xử lý sinh viên
}
```

Ngoài ra sử dụng:

```cpp
do while
```

để lặp menu và kiểm tra dữ liệu nhập.

---

### 22.7. Câu lệnh điều kiện

Sử dụng:

```cpp
if
else if
else
```

để kiểm tra điều kiện.

Ví dụ:

```cpp
if (diem >= 8.0)
{
    return "Gioi";
}
else if (diem >= 6.5)
{
    return "Kha";
}
```

---

### 22.8. Switch Case

Sử dụng `switch case` để xây dựng menu:

```cpp
switch (luaChon)
{
    case 1:
        // Thêm sinh viên
        break;

    case 2:
        // Hiển thị danh sách
        break;

    case 0:
        // Thoát
        break;
}
```

---

## 23. 🔢 Các thuật toán được sử dụng

### 23.1. Tìm kiếm tuần tự

Chương trình duyệt lần lượt từng phần tử trong mảng:

```text
Sinh viên 1
    ↓
Sinh viên 2
    ↓
Sinh viên 3
    ↓
...
```

Được sử dụng trong:

- Tìm mã sinh viên
- Kiểm tra mã tồn tại
- Tìm sinh viên theo tên

---

### 23.2. Bubble Sort

Bubble Sort sử dụng hai vòng lặp:

```cpp
for (int i = 0; i < n - 1; i++)
{
    for (int j = 0; j < n - 1 - i; j++)
    {
        // So sánh và đổi chỗ
    }
}
```

Được sử dụng để:

- Sắp xếp theo điểm
- Sắp xếp theo tên

---

### 23.3. Tìm giá trị lớn nhất

Chương trình giả sử phần tử đầu tiên là lớn nhất:

```cpp
int viTriMax = 0;
```

Sau đó so sánh với các phần tử còn lại.

Mục đích là tìm:

```text
Sinh viên có điểm trung bình cao nhất
```

---

## 24. 📁 Cấu trúc Project

```text
Projectquanlysinhvien/
│
├── Projectsinhvien.cpp
│
└── README.md
```

Trong đó:

### `Projectsinhvien.cpp`

Là file chứa mã nguồn chương trình quản lý sinh viên.

### `README.md`

Là tài liệu mô tả project, bao gồm:

- Giới thiệu project
- Mục tiêu
- Thư viện sử dụng
- Cấu trúc dữ liệu
- Các chức năng
- Thuật toán
- Kiến thức C++ được sử dụng
- Hướng dẫn chạy chương trình

---

## 25. ▶️ Hướng dẫn chạy chương trình

### Bước 1: Mở project

Mở thư mục project bằng Visual Studio Code.

```text
Projectquanlysinhvien/
```

### Bước 2: Mở file C++

Mở:

```text
Projectsinhvien.cpp
```

### Bước 3: Biên dịch

Nếu sử dụng `g++`, mở Terminal và chạy:

```bash
g++ Projectsinhvien.cpp -o Projectsinhvien
```

### Bước 4: Chạy chương trình

Trên Windows:

```bash
.\Projectsinhvien
```

---

## 26. 🖥️ Ví dụ chương trình

Sau khi chạy chương trình, menu sẽ hiển thị:

```text
========================================
          QUAN LY SINH VIEN
========================================
1. Them sinh vien
2. Hien thi danh sach
3. Sua sinh vien
4. Xoa sinh vien
5. Tim kiem sinh vien
6. Sap xep sinh vien
7. Thong ke hoc luc
8. Tim sinh vien diem cao nhat
0. Thoat
========================================
Nhap lua chon:
```

Ví dụ danh sách sinh viên:

```text
Ma SV          Ho Ten                   Lop         Diem TB
------------------------------------------------------------
SV001          Nguyen Van An            CNTT01      8.50
SV002          Tran Van B               CNTT02      7.25
SV003          Le Van C                 CNTT03      9.00
```

---

## 27. 🔄 Luồng hoạt động của chương trình

```text
Bắt đầu
   ↓
Khởi tạo danh sách
   ↓
Hiển thị menu
   ↓
Người dùng nhập lựa chọn
   ↓
switch case
   ↓
Thực hiện chức năng
   ↓
Quay lại menu
   ↓
Người dùng chọn 0?
   ├── Không → tiếp tục chương trình
   │
   └── Có → Kết thúc
```

---

## 28. 📌 Danh sách các hàm chính

| Hàm | Chức năng |
|---|---|
| `nhapSinhVien()` | Nhập thông tin một sinh viên |
| `xuatSinhVien()` | Xuất thông tin một sinh viên |
| `hienThiDanhSach()` | Hiển thị toàn bộ danh sách |
| `kiemTraMaTonTai()` | Kiểm tra mã sinh viên |
| `timViTriTheoMa()` | Tìm vị trí theo mã |
| `themSinhVien()` | Thêm sinh viên |
| `suaSinhVien()` | Sửa sinh viên |
| `xoaSinhVien()` | Xóa sinh viên |
| `timTheoMa()` | Tìm kiếm theo mã |
| `timTheoTen()` | Tìm kiếm theo tên |
| `sapXepTheoDiem()` | Sắp xếp theo điểm |
| `sapXepTheoTen()` | Sắp xếp theo tên |
| `xepLoai()` | Xếp loại học lực |
| `thongKe()` | Thống kê học lực |
| `timDiemCaoNhat()` | Tìm sinh viên điểm cao nhất |
| `menu()` | Hiển thị menu |

---

## 29. 📖 Kiến thức cần nắm khi trình bày project

Khi trình bày project, cần hiểu các nội dung chính:

### `struct`

Dùng để tạo kiểu dữ liệu `SinhVien`.

### `ds[100]`

Là mảng dùng để lưu danh sách sinh viên.

### `n`

Là số lượng sinh viên hiện tại.

### `&n`

Dùng khi hàm cần thay đổi số lượng sinh viên.

### `SinhVien &sv`

Dùng để truyền sinh viên bằng tham chiếu, cho phép hàm thay đổi dữ liệu của sinh viên ban đầu.

### `const SinhVien &sv`

Dùng để truyền sinh viên bằng tham chiếu nhưng không cho phép hàm thay đổi dữ liệu.

### `timViTriTheoMa()`

Dùng để tìm vị trí sinh viên và được tái sử dụng trong nhiều chức năng.

### Bubble Sort

Dùng để sắp xếp danh sách theo điểm hoặc tên.

### `xepLoai()`

Dùng để xác định học lực dựa trên điểm trung bình.

### `switch case`

Dùng để xử lý lựa chọn trong menu.

---

## 30. 🚀 Hướng phát triển

Trong tương lai, chương trình có thể được mở rộng thêm:

- Lưu danh sách sinh viên vào file.
- Đọc danh sách sinh viên từ file.
- Quản lý nhiều môn học.
- Tính điểm trung bình từ nhiều môn.
- Thêm điểm từng môn.
- Thống kê điểm theo từng môn.
- Tìm kiếm nâng cao.
- Sắp xếp theo nhiều tiêu chí.
- Sử dụng `vector` để quản lý danh sách linh hoạt hơn.
- Xây dựng giao diện trực quan hơn.

---

## 31. ✅ Kết luận

Chương trình **Quản lý sinh viên** được xây dựng nhằm áp dụng các kiến thức C++ cơ bản vào một bài toán thực tế.

Chương trình sử dụng:

- `struct` để quản lý thông tin sinh viên.
- Mảng để lưu danh sách sinh viên.
- Hàm để chia chương trình thành các chức năng.
- `string` để xử lý dữ liệu dạng chuỗi.
- Vòng lặp để duyệt và xử lý danh sách.
- `if else` để kiểm tra điều kiện.
- `switch case` để xây dựng menu.
- Bubble Sort để sắp xếp.
- Tìm kiếm tuần tự để tìm sinh viên.
- Tham chiếu để thay đổi dữ liệu trực tiếp.
- `iomanip` để định dạng dữ liệu khi xuất.
