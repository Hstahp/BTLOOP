#include "./NhanVien/NhanVien.hpp"
#include "./DatPhong/DatPhong.hpp"
#include <fstream> // Include fstream for file operations
#include <iomanip> // Include for setting precision

int main(){
	int choice;
	NhanVien NV;
	NhanVien *ds = NULL;
    DatPhong vitri[100]; 
    int count = 0;  
    int n = 0;
	do{
	cout<<"\033[1;32m================================MENU==================================\033[0m"<<endl;
	cout<<"\033[1;32m|\033[0m \033[1;33;1m 1\033[0m. Nhap so luong nhan vien!                                       \033[1;32m|\033[0m"<<endl;
	cout<<"\033[1;32m|\033[0m \033[1;33;1m 2\033[0m. Nhap danh sach nhan vien!                                      \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 3\033[0m. Xuat danh sach nhan vien!                                      \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 4\033[0m. Sap xep nhan vien tang dan theo ID!                            \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 5\033[0m. Sap xep nhan vien tang dan theo ho ten!                        \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 6\033[0m. Tim kiem nhan vien theo ID!                                    \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 7\033[0m. Tim kiem nhan vien theo ho ten!                                \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 8\033[0m. Tim kiem nhan vien co luong cao nhat!                          \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m 9\033[0m. Tim kiem nhan vien theo so CCCD!                               \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m10\033[0m. Dat phong                                                      \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m11\033[0m. Xuat thong tin dat phong                                       \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m12\033[0m. Tim kiem thong tin khach da dat phong theo CCCD                \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m13\033[0m. Tim kiem thong tin khach da dat phong theo ten khach hang      \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m14\033[0m. Xoa khach hang                                                 \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m15\033[0m. Xuat thong tin khach hang dat phong ra file                    \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m|\033[0m \033[1;33;1m0\033[0m. Thoat!                                                          \033[1;32m|\033[0m"<<endl;
    cout<<"\033[1;32m======================================================================\033[0m"<<endl;
    cout<<"\033[1;34;1mXin moi nhap lua chon cua ban: \033[0m";
    cin>>choice;
    switch (choice){
            case 1:
            	cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				if (n > 0) {
					ds = new NhanVien[n];
				} else {
					cout << "\033[1;31;1mWARNING: SO LUONG NHAN VIEN PHAI LON HON 0!\033[0m" << endl;
				}
                break;
            case 2:
                if(ds!=NULL){
                	NV.nhapDanhSachNV(ds,n);
                    
                    // Luu file
                    ofstream outFile("employees.txt"); // Mo file
                    if (outFile.is_open()) {// kiem tra file da mo thanh cong 
                        for (int i = 0; i < n; i++) {
                            outFile << ds[i].getId() << ","
                                    << ds[i].getHoTen() << ","
                                    << ds[i].getChucVu() << ","
                                    << fixed << setprecision(2) << ds[i].getLuong() << "," // Format salary
                                    << ds[i].gioiTinh << ","
                                    << ds[i].ngaySinh << "/"
                                    << ds[i].thangSinh << "/"
                                    << ds[i].namSinh << ","
                                    << ds[i].cccd << ","
                                    << ds[i].sdt << ","
                                    << ds[i].email << ","
                                    << ds[i].diaChi << endl; // Ghi vao du lieu cua nhan vien
                        }
                        outFile.close(); //Dong file
                        cout << "\033[1;32mDANH SACH NHAN VIEN DA DUOC LUU VAO FILE 'employees.txt'.\033[0m" << endl;
                    } else {
                        cout << "\033[1;31mWARNING: KHONG THE MO FILE!\033[0m" << endl;
                    }
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP SO LUONG NHAN VIEN!\033[0m"<< endl;
                }
                break;
            case 3:
                if(ds!=NULL){
                	cout<<"DANH SACH NHAN VIEN"<<endl;
					NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 4:
                if(ds!=NULL){
	                NV.sapXepTheoID(ds,n);
	                NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 5:
                if(ds!=NULL){
                    NV.sapXepTheoHoTen(ds,n);
    				NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 6:
                if(ds!=NULL){
				    cout<<"Nhap ID cua nhan vien can tim: ";
				    string ID;
					cin.ignore();
					getline(cin,ID);
					cout<<"============================================"<<endl;
				    NV.timKiemTheoID(ds,n,ID);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 7:
                if(ds!=NULL){
				    cout<<"Nhap ho ten cua nhan vien can tim: ";
				    string ten;
				    cin.ignore();
				    getline(cin, ten);
				    cout<<"============================================"<<endl;
				    NV.timKiemTheoHoTen(ds,n,ten);
                } else {
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 8:
                if(ds!=NULL){
                	NV.timKiemNVLuongCaoNhat(ds,n);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
            case 9:
                if(ds!=NULL){
				    cout<<"Nhap so CCCD cua nhan vien can tim: ";
				    string x;
					cin.ignore();
					getline(cin,x);
					cout<<"============================================"<<endl;
				    NV.timKiemTheoCCCD(ds,n,x);
                }else{
                    cout<<"\033[1;31;1mWARNING: BAN CHUA NHAP DANH SACH NHAN VIEN!\033[0m"<<endl;
                }
                break;
             case 10:
                if (count < 100) {
                    vitri[count].nhapDatPhong(vitri, count);
                    count++;
                } else {
                    cout << "\033[1;31;1mWARNING: KHONG THE THEM KHACH HANG. PHONG DA DAT TOI DA.\033[0m" << endl;
                }
                break;
              case 11:
                if (count == 0) {
                    cout << "\033[1;31;1mWARNING: KHONG CO KHACH HANG.\033[0m" << endl;
                } else {
                    DatPhong::xuatDanhSachDatPhong(vitri, count);
                }
                break;
            case 12: {
                string cccd;
                cout << "Nhap CCCD khach hang can tim: ";
                cin.ignore();
                getline(cin, cccd);
                vitri[0].searchByCCCD(vitri, count, cccd);
                break;
            }
            case 13: {
                string name;
                cout << "Nhap ten khach hang can tim: ";
                cin.ignore();
                getline(cin, name);
                vitri[0].searchByName(vitri, count, name);
                break;
            }
            case 14:
                xoaKhachHang(vitri, count);
                break;
            case 15: {
                if (count == 0) {
                    cout << "\033[1;31;1mWARNING: KHONG CO KHACH HANG.\033[0m" << endl;
                } else 
                    DatPhong::xuatThongTinDatPhongRaFile(vitri, count, "Datphong.txt");
                
                break;
            }
            case 0:
                cout<<"\033[1;32mEXITING THE PROGRAM!\033[0m"<<endl;
                break;
            default:
                cout<<"\033[1;31;1mWARNING: LUA CHON KHONG HOP LE! VUI LONG NHAP LAI.\033[0m"<<endl;
        }
    }while(choice!=0);
	return 0;
}