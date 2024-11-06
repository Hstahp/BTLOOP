#pragma once
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;


using namespace std;

class Phong {
private:
    string loaiPhong;  // Loai phong ("VIP" hoac "Binh thuong")
    string phanLoai;   // Phan loai phong ("Phong don" hoac "Phong doi")
    string trangThai;  // Trang thai phong
    double gia;        // Gia phong
    int soPhong;      // So phong

public:
    Phong();  // Constructor mac dinh
    Phong(string loai, string phanLoai, double gia, int soPhong);  // Constructor co tham so
    Phong(const Phong &phong);  // Constructor sao chep
    ~Phong();
    void nhapPhong();
    void xuatPhong();
    int getSoPhong() const;
    double getGia();  // Lay gia phong
    void setGia(double g);  // Thiet lap gia phong
    void capNhatPhong(string trangThaiMoi);  // Cap nhat trang thai phong
    void sapXepPhong(Phong ds[], int n);  // Sap xep phong
};
Phong::~Phong(){}

Phong::Phong() {
    this->soPhong = 0;
    this->loaiPhong = "";
    this->phanLoai = "";
    this->gia = 0.0;
    this->trangThai = "Trong";  // Khoi tao trang thai la "Trong"
}

Phong::Phong(string loai, string phanLoai, double gia, int soPhong) {
    this->soPhong = soPhong;
    this->loaiPhong = loai;
    this->phanLoai = phanLoai;
    this->gia = gia;
    this->trangThai = "Trong";  // Khoi tao trang thai la "Trong"
}

// Constructor sao chep
Phong::Phong(const Phong &phong) {
    this->soPhong = phong.soPhong;
    this->loaiPhong = phong.loaiPhong;
    this->phanLoai = phong.phanLoai;
    this->gia = phong.gia;
    this->trangThai = phong.trangThai;
}

void Phong::nhapPhong() {
    cout << "Nhap so phong: ";
    cin >> soPhong;

    cin.ignore();
    while (true) {
        cout << "Nhap loai phong (VIP, Thuong): ";
        getline(cin, loaiPhong);
        if (loaiPhong == "VIP" || loaiPhong == "vip" ||
            loaiPhong == "Thuong" || loaiPhong == "thuong") {
            break; 
        } else {
            cout << "\033[31m";//red
            cout << "Phong khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }

   
    while (true) {
        cout << "Nhap phan loai phong (Don, Doi): ";
        getline(cin, phanLoai);
        if (phanLoai == "don" || phanLoai == "Don" ||
            phanLoai == "doi" || phanLoai == "Doi") {
            break; 
        } else {
            cout << "\033[31m";//red
            cout << "Phong khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }
    
    

    do {
        cout << "Nhap gia phong (>= 0): ";
        cin >> gia;
        if (gia < 0) {
            cout << "\033[31m";//red
            cout << "Gia phong phai lon hon hoac bang 0. Vui long nhap lai!" << endl;
            cout << "\033[0m"; //reset 
        }
    } while (gia < 0);

    trangThai = "Trong"; 
}

void Phong::xuatPhong() {
    cout << soPhong<<" " << loaiPhong <<" "<< phanLoai <<" "  << trangThai << endl; // Xuat trang thai
}

int Phong::getSoPhong() const {
    return soPhong; 
}

double Phong::getGia() {
    return gia;  // Tra ve gia phong
}

void Phong::setGia(double g) {
    gia = g;  // Thiet lap gia phong
}

void Phong::capNhatPhong(string trangThaiMoi) {
    trangThai = trangThaiMoi;
    cout << "\033[1;32m"; // Green
    cout << "Phong " << soPhong << " da duoc cap nhat." << endl;
    cout << "\033[0m"; // Reset color
}

void Phong::sapXepPhong(Phong ds[], int n) {
    cout << "Danh sach phong sau khi sap xep theo so phong:" << endl;
    int pos;
    Phong x;
    for (int i = 1; i < n; i++) {
        x = ds[i]; 
        pos = i - 1;
        while (pos >= 0 && ds[pos].getSoPhong() > x.getSoPhong()) {
            ds[pos + 1] = ds[pos];
            pos--;
        }
        ds[pos + 1] = x;
    }

    // Xuat danh sach phong sau khi sap xep
    for (int i = 0; i < n; i++) {
        ds[i].xuatPhong();
    }
}