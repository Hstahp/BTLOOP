#pragma once
#include "../Nguoi/Nguoi.hpp"



class NhanVien:public Nguoi{
	private:
		string chucVu;
		string id;
		double luong;
		static string dsID[200]; 
        static int soLuongID;
	public:
		NhanVien();
		NhanVien(string id,string chucVu,double luong);
		NhanVien(const NhanVien &NV);
        static bool kiemTraID(const string& id);
		void nhapNV();
		void xuatNV();
		void nhapDanhSachNV(NhanVien ds[], int n);
        void xuatDanhSachNV( NhanVien ds[], int n);
        void sapXepTheoID(NhanVien ds[], int n);
        void sapXepTheoHoTen(NhanVien ds[], int n);
        void timKiemTheoID(NhanVien ds[],int n,string ID);
        void timKiemTheoHoTen(NhanVien ds[],int n,string ten);
        void timKiemNVLuongCaoNhat(NhanVien ds[],int n);
        void timKiemTheoCCCD(NhanVien ds[],int n,string x);
};




string NhanVien::dsID[200];
int NhanVien::soLuongID = 0;
NhanVien::NhanVien():Nguoi(){
	id=" ";
	chucVu=" ";
	luong=0;
}
NhanVien::NhanVien(string id,string chucVu,double luong):Nguoi(){
	this->id=id;
	this->chucVu=chucVu;
	this->luong=luong;
}
NhanVien::NhanVien(const NhanVien &NV):Nguoi(NV){
	this->id=NV.id;
	this->chucVu=NV.chucVu;
	this->luong=NV.luong;
}
//kiem tra id co trung hay khong
bool NhanVien::kiemTraID(const string& id){
    for(int i = 0; i < soLuongID; i++){
        if(dsID[i] == id){
            return true;
        }
    }
    return false;
}

//nhap 1 nhan vien
void NhanVien::nhapNV(){
    while(true){
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        if(!kiemTraID(id)){ 
            dsID[soLuongID++] = id; 
            break;
        }else{
        	cout << "\033[31m";//red
            cout << "ID da ton tai! Vui long nhap lai." << endl;
            cout << "\033[0m"; //reset 
        }
    }
	Nguoi::nhap();
	cout<<"Nhap chuc vu: ";
	getline(cin,chucVu);
	cout<<"Nhap luong trung binh: ";
	cin>>luong;		
}
//xuat 1 nhan vien
void NhanVien::xuatNV(){
    cout << "|" << left<< setw(12) << id 
			    << "|" << setw(22) << hoTen 
			    << "|" << setw(11) << gioiTinh 
		        << "|" << setw(3) << setfill('0') << ngaySinh 
                << "/" << setw(2) << setfill('0') << thangSinh 
                << "/" << setw(4) << setfill('0') << namSinh << setfill(' ')
		        << "|" << setw(15) << cccd
		        << "|" << setw(12) << sdt 
		        << "|" << setw(27) << email 
		        << "|" << setw(32) << diaChi
				<< "|" << setw(20) << chucVu  
				<< "|" << setw(18) << fixed << setprecision(2) << luong << "|" << endl;
}
//Nhap danh sach nhan vien
void NhanVien:: nhapDanhSachNV(NhanVien ds[],int n){
	for(int i=0;i<n;i++){
		cout<<"============================================"<<endl;
		cout<<"Nhap nhan vien thu "<<i+1<<":"<<endl;
		ds[i].nhapNV();
	}
}
//xuat danh sach sinh vien
void NhanVien::xuatDanhSachNV( NhanVien ds[],int n){
    cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
    cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
    cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
    for(int i=0;i<n;i++){
    	ds[i].xuatNV();
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	}
}
//sap xep tang dan theo ID
void NhanVien::sapXepTheoID(NhanVien ds[], int n){
	cout<<"Danh sach nhan vien sau khi sap xep theo ID:"<<endl;
	cout<<"============================================"<<endl;
	int pos;
	NhanVien x;
	for(int i=1; i<n; i++){
		x = ds[i]; pos = i-1;
		while((pos>=0)&&(ds[pos].id>x.id)){
			ds[pos+1] = ds[pos];
			pos--;
		}
		ds[pos+1] = x;
	}
}
//sap xep theo ho ten
void NhanVien::sapXepTheoHoTen(NhanVien ds[], int n){
    cout<<"Danh sach nhan vien sau khi sap xep theo ho ten:"<<endl;
    cout<<"============================================"<<endl;
    for(int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (ds[i].hoTen > ds[j].hoTen){
                NhanVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}
//tim kiem theo ID
void NhanVien::timKiemTheoID(NhanVien ds[],int n,string ID){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].id==ID){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co ID: "<<ID<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem theo ho ten
void NhanVien::timKiemTheoHoTen(NhanVien ds[],int n,string ten){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].hoTen==ten){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
        cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co ho ten: "<<ten<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem theo so CCCD
void NhanVien::timKiemTheoCCCD(NhanVien ds[],int n,string x){
	bool found = false;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	for(int i=0;i<n;i++){
		if(ds[i].cccd==x){
			found = true;
            cout << "\033[1;32m"; // Green
            ds[i].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
            cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
	if(!found){
		cout<<"\033[31m";//red
		cout<<"Khong tim thay nhan vien co so CCCD: "<<x<<endl;
	    cout << "\033[0m"; //reset
	}
}
//tim kiem nhan vien co muc luong cao nhat
void NhanVien::timKiemNVLuongCaoNhat(NhanVien ds[],int n){
	cout << "Thong tin nhan vien co muc luong cao nhat :" << endl;
	cout << "\n+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	cout << "|    ID      |        Ho ten        | Gioi tinh | Ngay Sinh |     CCCD      |     SDT    |          Email            |             Dia chi            |      Chuc Vu       | Luong Co Ban |\n";
	cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
	int max=0;
	for(int i=0;i<n;i++){
		if(ds[i].luong>ds[max].luong){
			max=i;
			cout << "\033[1;32m"; // Green
            ds[max].xuatNV();
            cout << "\033[0m"; // Reset color
        } else {
            ds[i].xuatNV();
        }
            cout << "+------------+----------------------+-----------+-----------+---------------+------------+---------------------------+--------------------------------+--------------------+--------------+\n";
		}
}