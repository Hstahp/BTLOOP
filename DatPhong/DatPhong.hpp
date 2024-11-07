#pragma once
#include "../Phong/Phong.hpp"
#include "../KhachHang/KhachHang.hpp"

using namespace std;

class DatPhong : public Phong, public KhachHang {
private:
    string ngayDen; 
    string ngayDi; 


public:

    void nhapDatPhong(DatPhong vitri[], int count);
    void xuatDatPhong(); 
    bool kiemTrangay(string start,  string end);
    bool isValidDate(int day, int month, int year);
    bool isLeapYear(int year);
    bool kiemTraTrungPhong(DatPhong vitri[], int count);
    bool kiemTraTrungCCCD(DatPhong vitri[], int count, const string& cccd);
    // Thêm hàm tìm kiếm
    void searchByCCCD(DatPhong bookings[], int count, const string &cccd);
    void searchByName(DatPhong bookings[], int count, const string &name);
    static void xuatDanhSachDatPhong( DatPhong vitri[], int count);
    
};
void xoaKhachHang(DatPhong bookings[], int &count);


bool DatPhong::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool DatPhong::isValidDate(int day, int month, int year) {
    if (year < 0){
        cout << "Nam khong hop le! Moi nhap lai!" << endl;
        return false;
    }
    if (month < 1 || month > 12) {
        cout << "\033[31m";
        cout << "Thang khong hop le! Moi nhap lai!" << endl;
        cout << "\033[0m";
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if(day < 1 || day > 31) {
            cout << "\033[31m";
            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m";
            return false;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        if(day < 1 || day > 30) {
            cout << "\033[31m";
            cout << "Ngay khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m";
            return false;
        }
    } else if (month == 2){
        if(isLeapYear(year)) {
            if(day < 1 || day > 29){
                cout << "\033[31m";
                cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m";
                return false;
            }
        } else {
            if(day < 1 || day > 28){
                cout << "\033[31m";
                cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m";
                return false;
            }
        }
    }
    return true;
}

bool DatPhong::kiemTrangay(string start, string end) {
    // Tách ngày, tháng, năm từ chuỗi ngày theo định dạng "DD/MM/YYYY"
    //stoi chuyển kí tự string thành int
    int ngayStart = stoi(start.substr(0, 2));//lấy 2 ký tự đầu tiên từ start, tức là ngày.
    int thangStart = stoi(start.substr(3, 2));// lấy 2 ký tự tiếp theo từ vị trí thứ 3, tức là tháng.
    int namStart = stoi(start.substr(6, 4));//tương tự

    int ngayEnd = stoi(end.substr(0, 2));
    int thangEnd = stoi(end.substr(3, 2));
    int namEnd = stoi(end.substr(6, 4));

    // Kiểm tra tính hợp lệ của ngày
    if (!isValidDate(ngayStart, thangStart, namStart) || !isValidDate(ngayEnd, thangEnd, namEnd)) {
        return false;
    }

    // Kiểm tra năm trước
    if (namStart < namEnd && (thangStart < thangEnd || thangStart == thangEnd || thangStart > thangEnd)&& 
        (ngayStart < ngayEnd || ngayStart == ngayEnd || ngayStart > ngayEnd)) {
        return true;  // Nếu năm bắt đầu nhỏ hơn năm kết thúc, luôn hợp lệ
    } 
    
    if(namStart == namEnd){
    // Nếu cùng năm, kiểm tra tiếp tháng
    if (thangStart < thangEnd) 
        return true;
    }
    
    if(thangStart == thangEnd && namStart == namEnd){
    // Nếu cùng tháng, so sánh ngày
        if(ngayStart <= ngayEnd)
        return true;
    }
    return false;
}

bool DatPhong::kiemTraTrungPhong(DatPhong vitri[], int count) {
     
    for (int i = 0; i < count; ++i) {
        if (this->getSoPhong() == vitri[i].getSoPhong()) {
            // Kiểm tra xem có sự chồng chéo về thời gian không
            if (kiemTrangay(vitri[i].ngayDen, this->ngayDen) && kiemTrangay(this->ngayDen, vitri[i].ngayDi)) {
                return true; // Trùng lịch
            }
            if (kiemTrangay(this->ngayDen, vitri[i].ngayDen) && kiemTrangay(vitri[i].ngayDen, this->ngayDi)) {
                return true; // Trùng lịch
            }
        }
    }
    return false; // Không trùng
}

bool DatPhong::kiemTraTrungCCCD(DatPhong vitri[], int count, const string& cccd) {
    for (int i = 0; i < count; ++i) {
        if (vitri[i].getCCCD() == cccd) {
            return true; // CCCD đã tồn tại
        }
    }
    return false; // CCCD chưa tồn tại
}

void DatPhong::nhapDatPhong(DatPhong vitri[], int count) {
    bool dateTrung;
    do {
        dateTrung = false;
        Phong::nhapPhong();
        
        do {
            KhachHang::nhap(); 
            if (kiemTraTrungCCCD(vitri, count, this->getCCCD())) {
                cout << "\033[31m";
                cout << "CCCD da ton tai. Vui long nhap lai!" << endl;
                cout << "\033[0m";
            }
        } while (kiemTraTrungCCCD(vitri, count, this->getCCCD()));

        bool validDates;
        do {
            validDates = true;
            cout << "Nhap ngay den (DD/MM/YYYY): ";
            getline(cin, ngayDen);
            cout << "Nhap ngay di (DD/MM/YYYY): ";
            getline(cin, ngayDi);
            if (!kiemTrangay(ngayDen, ngayDi)) {
                validDates = false;
                cout << "\033[31m";
                cout << "Hay nhap ngay cho dung. Ngay den phai nho hon hoac bang ngay di. Vui long nhap lai!" << endl;
                cout << "\033[0m"; 
            } else {
                dateTrung = kiemTraTrungPhong(vitri, count);
                if (dateTrung) {
                    cout << "\033[31m";
                    cout << "Phong da duoc dat trong khoang thoi gian nay. Vui long chon phong khac hoac thay doi ngay!" << endl;
                    cout << "\033[0m";
                    validDates = false;
                }
            }
        } while (!validDates);
    } while (dateTrung);
}
void DatPhong::xuatDatPhong() {
    cout << "|" << left << setw(22) << hoTen 
         << "|" << setw(15) << cccd 
         << "|" << setw(12) << getSoPhong() 
         << "|" << setw(12) << ngayDen.substr(0,2) + "/" + ngayDen.substr(3,2) + "/" + ngayDen.substr(6,4)
         << "|" << setw(12) << ngayDi.substr(0,2) + "/" + ngayDi.substr(3,2) + "/" + ngayDi.substr(6,4)
         << "|" << setw(11) << gioiTinh 
         << "|" << setw(13) << sdt 
         << "|" << setw(27) << email 
         << "|" << setw(32) << diaChi << "|" << endl;
}

void DatPhong::xuatDanhSachDatPhong(DatPhong vitri[], int count) {
    cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";

    for (int i = 0; i < count; ++i) {
        vitri[i].xuatDatPhong();
        cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
}
void DatPhong::searchByCCCD(DatPhong bookings[], int count, const string &cccd) {
    bool found = false;
   cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    for (int i = 0; i < count; i++) {
        if (bookings[i].getCCCD() == cccd) {
            found = true;
            cout << "\033[1;32m"; // Green
            bookings[i].xuatDatPhong();
            cout << "\033[0m"; // Reset color
        } else {
            bookings[i].xuatDatPhong();
        }
         cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
    if (!found) {
        cout << "\033[31m"; // Red
        cout << "Khach hang voi CCCD " << cccd << " khong tim thay!" << endl;
        cout << "\033[0m"; // Reset color
    }
}

void DatPhong::searchByName(DatPhong bookings[], int count, const string &name) {
    bool found = false;
    cout << "\n+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    cout << "|        Ho ten        |     CCCD      | So phong   |  Ngay den  |   Ngay di  | Gioi tinh |     SDT     |          Email            |             Dia chi            |\n";
    cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";

    for (int i = 0; i < count; i++) {
        if (bookings[i].getHoTen() == name) {
            found = true;
            cout << "\033[1;32m"; // Green
            bookings[i].xuatDatPhong();
            cout << "\033[0m"; // Reset color
        } else {
            bookings[i].xuatDatPhong();
        }
                cout << "+----------------------+---------------+------------+------------+------------+-----------+-------------+---------------------------+--------------------------------+\n";
    }
    if (!found) {
        cout << "\033[31m"; // Red
        cout << "Khach hang voi ten " << name << " khong tim thay!" << endl;
        cout << "\033[0m"; // Reset color
    }
}

void xoaKhachHang(DatPhong bookings[], int &count) {
    if (count == 0) {   
        cout << "\033[31m";//red
        cout << "Khong co khach hang de xoa." << endl;
        cout << "\033[0m"; //reset 
        return;
    }
    
    int index;
    cout << "Nhap vi tri khach hang can xoa (0-" << count - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= count) {
        cout << "\033[31m";//red
        cout << "Vi tri khach hang khong hop le." << endl;
        cout << "\033[0m"; //reset 
        return;
    }

    // Chuyen cac vi tri sau vi tr xa ln m?t vi tr
    for (int i = index; i < count - 1; ++i) {
        bookings[i] = bookings[i + 1];
    }
    count--; // Giam so luong khach hang  
    cout << "\033[1;32m"; // Green
    cout << "Da xoa khach hang tai vi tri " << index << "." << endl;
    cout << "\033[0m"; // Reset color
}