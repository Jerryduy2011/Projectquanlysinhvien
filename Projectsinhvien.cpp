#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien
{
    string maSV;
    string hoTen;
    string lop;
    double diemTB;
};

void nhapSinhVien(SinhVien &sv);

void xuatSinhVien(const SinhVien &sv);

void hienThiDanhSach(SinhVien ds[], int n);

bool kiemTraMaTonTai(SinhVien ds[], int n, string ma);

int timViTriTheoMa(SinhVien ds[], int n, string ma);

void themSinhVien(SinhVien ds[], int &n);

void suaSinhVien(SinhVien ds[], int n);

void xoaSinhVien(SinhVien ds[], int &n);

void timTheoMa(SinhVien ds[], int n);

void timTheoTen(SinhVien ds[], int n);

void sapXepTheoDiem(SinhVien ds[], int n);

void sapXepTheoTen(SinhVien ds[], int n);

string xepLoai(double diem);

void thongKe(SinhVien ds[], int n);

void timDiemCaoNhat(SinhVien ds[], int n);

void menu();

void nhapSinhVien(SinhVien &sv)
{
    cout << "Nhap ma sinh vien: ";
    getline(cin >> ws, sv.maSV);

    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);

    cout << "Nhap lop: ";
    getline(cin, sv.lop);

    do
    {
        cout << "Nhap diem trung binh (0 - 10): ";
        cin >> sv.diemTB;

        if (sv.diemTB < 0 || sv.diemTB > 10)
        {
            cout << "Diem khong hop le! Vui long nhap lai.\n";
        }

    } while (sv.diemTB < 0 || sv.diemTB > 10);
}

void xuatSinhVien(const SinhVien &sv)
{
    cout << left
         << setw(15) << sv.maSV
         << setw(25) << sv.hoTen
         << setw(12) << sv.lop
         << fixed << setprecision(2)
         << sv.diemTB
         << endl;
}

void hienThiDanhSach(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    cout << "\n================ DANH SACH SINH VIEN ================\n";

    cout << left
         << setw(15) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Lop"
         << setw(10) << "Diem TB"
         << endl;

    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        xuatSinhVien(ds[i]);
    }

    cout << "=======================================================\n";
}

bool kiemTraMaTonTai(SinhVien ds[], int n, string ma)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].maSV == ma)
        {
            return true;
        }
    }

    return false;
}

int timViTriTheoMa(SinhVien ds[], int n, string ma)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].maSV == ma)
        {
            return i;
        }
    }

    return -1;
}

void themSinhVien(SinhVien ds[], int &n)
{
    if (n >= 100)
    {
        cout << "Danh sach da day!\n";
        return;
    }

    SinhVien sv;

    cout << "\n========== THEM SINH VIEN ==========\n";

    cout << "Nhap ma sinh vien: ";
    getline(cin >> ws, sv.maSV);

    if (kiemTraMaTonTai(ds, n, sv.maSV))
    {
        cout << "Ma sinh vien da ton tai!\n";
        return;
    }

    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);

    cout << "Nhap lop: ";
    getline(cin, sv.lop);

    do
    {
        cout << "Nhap diem trung binh (0 - 10): ";
        cin >> sv.diemTB;

        if (sv.diemTB < 0 || sv.diemTB > 10)
        {
            cout << "Diem khong hop le! Vui long nhap lai.\n";
        }

    } while (sv.diemTB < 0 || sv.diemTB > 10);

    ds[n] = sv;

    n++;

    cout << "Them sinh vien thanh cong!\n";
}

void suaSinhVien(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    string ma;

    cout << "Nhap ma sinh vien can sua: ";
    getline(cin >> ws, ma);

    int viTri = timViTriTheoMa(ds, n, ma);

    if (viTri == -1)
    {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    cout << "\nNhap thong tin moi:\n";

    cout << "Nhap ho ten: ";
    getline(cin, ds[viTri].hoTen);

    cout << "Nhap lop: ";
    getline(cin, ds[viTri].lop);

    do
    {
        cout << "Nhap diem trung binh (0 - 10): ";
        cin >> ds[viTri].diemTB;

        if (ds[viTri].diemTB < 0 || ds[viTri].diemTB > 10)
        {
            cout << "Diem khong hop le! Vui long nhap lai.\n";
        }

    } while (ds[viTri].diemTB < 0 || ds[viTri].diemTB > 10);

    cout << "Sua sinh vien thanh cong!\n";
}

void xoaSinhVien(SinhVien ds[], int &n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    string ma;

    cout << "Nhap ma sinh vien can xoa: ";
    getline(cin >> ws, ma);

    int viTri = timViTriTheoMa(ds, n, ma);

    if (viTri == -1)
    {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    for (int i = viTri; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];
    }

    n--;

    cout << "Xoa sinh vien thanh cong!\n";
}

void timTheoMa(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    string ma;

    cout << "Nhap ma sinh vien can tim: ";
    getline(cin >> ws, ma);

    int viTri = timViTriTheoMa(ds, n, ma);

    if (viTri == -1)
    {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    cout << "\nSinh vien tim thay:\n";

    cout << left
         << setw(15) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Lop"
         << setw(10) << "Diem TB"
         << endl;

    cout << "-------------------------------------------------------\n";

    xuatSinhVien(ds[viTri]);
}

void timTheoTen(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    string tuKhoa;

    cout << "Nhap ten can tim: ";
    getline(cin >> ws, tuKhoa);

    bool timThay = false;

    cout << "\nKet qua tim kiem:\n";

    cout << left
         << setw(15) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Lop"
         << setw(10) << "Diem TB"
         << endl;

    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        if (ds[i].hoTen.find(tuKhoa) != string::npos)
        {
            xuatSinhVien(ds[i]);

            timThay = true;
        }
    }

    if (!timThay)
    {
        cout << "Khong tim thay sinh vien!\n";
    }
}

void sapXepTheoDiem(SinhVien ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ds[j].diemTB < ds[j + 1].diemTB)
            {
                SinhVien temp = ds[j];

                ds[j] = ds[j + 1];

                ds[j + 1] = temp;
            }
        }
    }

    cout << "Da sap xep theo diem giam dan!\n";
}

void sapXepTheoTen(SinhVien ds[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ds[j].hoTen > ds[j + 1].hoTen)
            {
                SinhVien temp = ds[j];

                ds[j] = ds[j + 1];

                ds[j + 1] = temp;
            }
        }
    }

    cout << "Da sap xep theo ten!\n";
}

string xepLoai(double diem)
{
    if (diem >= 8.0)
    {
        return "Gioi";
    }
    else if (diem >= 6.5)
    {
        return "Kha";
    }
    else if (diem >= 5.0)
    {
        return "Trung binh";
    }
    else
    {
        return "Yeu";
    }
}

void thongKe(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    int soGioi = 0;
    int soKha = 0;
    int soTrungBinh = 0;
    int soYeu = 0;

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

    cout << "\n========== THONG KE ==========\n";

    cout << "Gioi       : " << soGioi << endl;
    cout << "Kha        : " << soKha << endl;
    cout << "Trung binh : " << soTrungBinh << endl;
    cout << "Yeu        : " << soYeu << endl;
}

void timDiemCaoNhat(SinhVien ds[], int n)
{
    if (n == 0)
    {
        cout << "Danh sach dang rong!\n";
        return;
    }

    int viTriMax = 0;

    for (int i = 1; i < n; i++)
    {
        if (ds[i].diemTB > ds[viTriMax].diemTB)
        {
            viTriMax = i;
        }
    }

    cout << "\n========== SINH VIEN DIEM CAO NHAT ==========\n";

    cout << left
         << setw(15) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Lop"
         << setw(10) << "Diem TB"
         << endl;

    cout << "-------------------------------------------------------\n";

    xuatSinhVien(ds[viTriMax]);
}

void menu()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "          QUAN LY SINH VIEN             \n";
    cout << "========================================\n";

    cout << "1. Them sinh vien\n";
    cout << "2. Hien thi danh sach\n";
    cout << "3. Sua sinh vien\n";
    cout << "4. Xoa sinh vien\n";
    cout << "5. Tim kiem sinh vien\n";
    cout << "6. Sap xep sinh vien\n";
    cout << "7. Thong ke hoc luc\n";
    cout << "8. Tim sinh vien diem cao nhat\n";
    cout << "0. Thoat\n";

    cout << "========================================\n";
}

int main()
{
    SinhVien ds[100];

    int n = 0;
    int luaChon;

    do
    {
        menu();

        cout << "Nhap lua chon: ";
        cin >> luaChon;

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

            case 5:
            {
                int luaChonTim;

                cout << "\n";
                cout << "1. Tim theo ma\n";
                cout << "2. Tim theo ten\n";
                cout << "Nhap lua chon: ";
                cin >> luaChonTim;

                if (luaChonTim == 1)
                {
                    timTheoMa(ds, n);
                }
                else if (luaChonTim == 2)
                {
                    timTheoTen(ds, n);
                }
                else
                {
                    cout << "Lua chon khong hop le!\n";
                }

                break;
            }

            case 6:
            {
                int luaChonSapXep;

                cout << "\n";
                cout << "1. Sap xep theo diem\n";
                cout << "2. Sap xep theo ten\n";
                cout << "Nhap lua chon: ";
                cin >> luaChonSapXep;

                if (luaChonSapXep == 1)
                {
                    sapXepTheoDiem(ds, n);
                }
                else if (luaChonSapXep == 2)
                {
                    sapXepTheoTen(ds, n);
                }
                else
                {
                    cout << "Lua chon khong hop le!\n";
                }

                break;
            }

            case 7:
                thongKe(ds, n);
                break;

            case 8:
                timDiemCaoNhat(ds, n);
                break;

            case 0:
                cout << "Thoat chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 0);

    return 0;
}