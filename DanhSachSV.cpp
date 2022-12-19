#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 100

struct DSsinhVien
{
    char MSSV[9]; // mã số sinh viên
    char HoTen[31];
    double diemLT; // điểm lý thuyết
    double diemTH; // điểm thực hành
    double diemQT; // điểm quá trình
    double diemTK; // điểm tổng kết
};

// Nhap thong tin SV tru diem Ly Thuyet
void NhapSV(DSsinhVien &DS)
{
    do // Nhập hơn 8 kí tự yêu cầu nhập lại
    {
        cout << "Nhap MSSV (8 ki tu): ";
        cin >> DS.MSSV;
    } while (strlen(DS.MSSV) > 8);
    char temp[] = "";
    cin.getline(temp, 2);
    do // Nhập hơn 30 kí tự yêu cầu nhập lại
    {
        cout << "Nhap Ho va Ten: ";
        cin.getline(DS.HoTen, 256);
    } while (strlen(DS.HoTen) > 30);
    do
    {
        cout << "Nhap diem thuc hanh:";
        cin >> DS.diemTH;
    } while ((DS.diemTH < 0) || (DS.diemTH > 10));
    do
    {
        cout << "Nhap diem qua trinh: ";
        cin >> DS.diemQT;
    } while ((DS.diemQT < 0) || (DS.diemQT > 10));
}

// Nhap mang thong tin SV tru diem Ly Thuyet
void ArrNhapSV(DSsinhVien DS[], int &n)
{
    do
    {
        cout << "Nhap so sinh vien trong lop: ";
        cin >> n;
    } while (n < 0);
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        NhapSV(DS[i]);
    }
}

// Nhap thong tin diem Ly Thuyet
void NhapDiemLT(DSsinhVien &DS)
{
    do
    {
        cout << "Nhap diem ly thuyet: ";
        cin >> DS.diemLT;
    } while ((DS.diemLT < 0) || (DS.diemLT > 10));
}

// Nhap mang diem Ly Thuyet cua SV
void ArrNhapDiemLT(DSsinhVien DS[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap diem ly thuyet sinh vien " << DS[i].MSSV << ": \n";
        NhapDiemLT(DS[i]);
    }
}

// Tinh diem tong ket
double DiemTK(DSsinhVien &DS)
{
    DS.diemTK = ((DS.diemLT * 0.6) + (DS.diemTH * 0.3) + (DS.diemQT * 0.1));
    return DS.diemTK;
}

// Sap xep
void SapXep(DSsinhVien DS[], int n)
{
    for (int i = 0; i < n; i++)
    {
        DiemTK(DS[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (DS[i].diemTK < DS[j].diemTK)
            {
                swap(DS[i], DS[j]);
            }
        }
    }
}

// Xuat thong tin sinh vien
void xuatThongTin(DSsinhVien DS)
{
    cout << "MSSV: " << DS.MSSV << endl;
    cout << "Ho va ten: " << DS.HoTen << endl;
    cout << "Diem tong ket: " << DiemTK(DS) << endl;
    cout << "Diem ly thuyet: " << DS.diemLT << endl;
    cout << "Diem thuc hanh: " << DS.diemTH << endl;
    cout << "Diem qua trinh: " << DS.diemQT << endl;
}

// Xuat mang thong tin sinh vien
void ArrXuatTT(DSsinhVien DS[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        xuatThongTin(DS[i]);
    }
}

int main()
{
    DSsinhVien DS[MAX_SIZE];
    int n;
    ArrNhapSV(DS, n);
    ArrNhapDiemLT(DS, n);
    ArrXuatTT(DS, n);
    cout << "Sap xep lai danh sach sinh vien theo diem tong ket giam dan: \n";
    SapXep(DS, n);
    ArrXuatTT(DS, n);

    return 0;
}
