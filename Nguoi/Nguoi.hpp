// Nguoi.h
#pragma once
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;


class Nguoi {
public:
    string hoTen;
    string gioiTinh;
    int ngaySinh;
    int thangSinh;
    int namSinh;
    string diaChi;
    string cccd;
    string sdt;
    string email;

    static string dsCCCD[200];
    static int soLuongCCCD;
    static string dsSDT[200];
    static int soLuongSDT;

public:
 
    void nhap();
    void xuat();
    bool namNhuan(int nam);
    static bool kiemTraCCCD(const string &cccd);
    static bool kiemTraSDT(const string &sdt);
    
};
string Nguoi::dsCCCD[200];
int Nguoi::soLuongCCCD = 0;
string Nguoi::dsSDT[200];
int Nguoi::soLuongSDT = 0;

//kiem tra nam nhuan
bool Nguoi::namNhuan(int nam){
    return(nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
//kiem tra CCCD co bi trung khong
bool Nguoi::kiemTraCCCD(const string& cccd){
    for(int i = 0; i < soLuongCCCD; i++){
        if(dsCCCD[i] == cccd){
            return true; 
        }
    }
    return false; 
}
//kiem tra  SDT co bi trung khong
bool Nguoi::kiemTraSDT(const string& sdt){
    for(int i = 0; i < soLuongSDT; i++){
        if (dsSDT[i] == sdt) {
            return true; 
        }
    }
    return false; 
}
void Nguoi::nhap(){
	cout<<"Nhap ho ten: ";
    cin.ignore();
	getline(cin,hoTen);
	//nhap va kiem tra ngay thang nam sinh 
    bool valid = false; 
    do{
        valid = true;  
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        if (namSinh < 0){
            cout << "\033[31m";//red
            cout << "Nam khong hop le! Moi nhap lai!" << endl;
            cout << "\033[0m"; //reset 
            valid = false;
        }
        if(valid){
            cout << "Nhap thang sinh: ";
            cin >> thangSinh;
            if (thangSinh < 1 || thangSinh > 12) {
                cout << "\033[31m";//red
                cout << "Thang khong hop le! Moi nhap lai!" << endl;
                cout << "\033[0m"; //reset 
                valid = false;
                }
        }
        if (valid){
            cout << "Nhap ngay sinh: ";
            cin >> ngaySinh;
            if(thangSinh == 1 || thangSinh == 3 || thangSinh == 5 || thangSinh == 7 || thangSinh == 8 || thangSinh == 10 || thangSinh == 12) {
                if(ngaySinh < 1 || ngaySinh > 31) {
                    cout << "\033[31m";//red
                    cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                    cout << "\033[0m"; //reset 
                    valid = false;
                    }
            }else if(thangSinh == 4 || thangSinh == 6 || thangSinh == 9 || thangSinh == 11) {
                if(ngaySinh < 1 || ngaySinh > 30) {
                    cout << "\033[31m";//red
                    cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                    cout << "\033[0m"; //reset 
                    valid = false;
                }
            }else if (thangSinh == 2){
                if(namNhuan(namSinh)) {
                    if(ngaySinh < 1 || ngaySinh > 29){
                        cout << "\033[31m";//red
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        cout << "\033[0m"; //reset 
                        valid = false;
                    }
                }else{
                    if(ngaySinh < 1 || ngaySinh > 28){
                        cout << "\033[31m";//red
                        cout << "Ngay khong hop le! Moi nhap lai!" << endl;
                        cout << "\033[0m"; //reset 
                        valid = false;
                    }
                }
            }
        }
    }
	while (!valid);

   // Nhap va kiem tra gioi tinh
    cin.ignore(); 
    while (true) {
        cout << "Gioi tinh cua khach hang (Nam/Nu/Khac): ";
        getline(cin, gioiTinh);
        if (gioiTinh == "Nam" || gioiTinh == "nam" ||
            gioiTinh == "Nu" || gioiTinh == "nu" ||
            gioiTinh == "Khac" || gioiTinh == "khac") {
            break; 
        } else {
        	cout << "\033[31m";//red
            cout << "Gioi tinh khong hop le. Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }

    // Nhap va kiem tra SDT
    while (true){
        cout << "Nhap so dien thoai (Phai lon hon 2 va be hon 11 so): ";
        getline(cin, sdt);
        if(sdt.length() < 11 && sdt.length() > 2) {
            bool validSDT = true;
            for(int i = 0; i < sdt.length(); i++){
            	char c = sdt[i];
                if(!isdigit(c)){
                    validSDT = false;
                    break;
                }
            }
	        if(validSDT && !kiemTraSDT(sdt)){
                dsSDT[soLuongSDT++] = sdt;
                break;
            }
        }
        cout << "\033[31m";//red
        cout<<"So SDT khong hop le hoac da ton tai! Vui long nhap lai."<<endl;
        cout << "\033[0m"; //reset 
    }

    // Nhap va kiem tra so CCCD
    while (true){
        cout << "Nhap so CCCD (Phai du 12 so): ";
        getline(cin, cccd);
        if(cccd.length() == 12){
            bool validCCCD = true;
            for(int i = 0; i < cccd.length(); i++){
            	char c = cccd[i];
                if (!isdigit(c)){//isdigit de kiem tra ki tu co phai la so hay khong
                    validCCCD = false;
                    break;
                }
            }
	       	if(validCCCD && !kiemTraCCCD(cccd)){
                dsCCCD[soLuongCCCD++] = cccd;
                break;
            }
        }
        cout << "\033[31m";//red
        cout<<"So CCCD khong hop le hoac da ton tai! Vui long nhap lai."<<endl;
        cout << "\033[0m"; //reset 
    }
    cout<<"Nhap dia chi: ";
	getline(cin,diaChi);
    cout<<"Nhap email: ";
	getline(cin,email);	
}
void Nguoi::xuat(){
    cout<<"Ho va ten: "<<hoTen<<endl;
    cout<<"Ngay sinh: "<<ngaySinh<<"/"<<thangSinh<<"/"<<namSinh<<endl;
    cout<<"Gioi tinh: "<<gioiTinh<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    cout<<"So CCCD: "<<cccd<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Dia chi: "<<diaChi<<endl;
}