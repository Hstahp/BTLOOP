#include "../NhanVien/NhanVien.hpp"
#include "../DatPhong/DatPhong.hpp"

int main(){
	int choice;
	NhanVien NV;
	NhanVien *ds = NULL;
    DatPhong vitri[100]; 
    int count = 0; 
    int n = 0;
	do{
	cout<<"====================MENU===================="<<endl;
	cout<<"1. Nhap so luong nhan vien!"<<endl;
	cout<<"2. Nhap danh sach nhan vien!"<<endl;
    cout<<"3. Xuat danh sach nhan vien!" << endl;
    cout<<"4. Sap xep nhan vien tang dan theo ID!"<<endl;
    cout<<"5. Sap xep nhan vien tang dan theo ho ten!"<<endl;
    cout<<"6. Tim kiem nhan vien theo ID!"<<endl;
    cout<<"7. Tim kiem nhan vien theo ho ten!"<<endl;
    cout<<"8. Tim kiem nhan vien co luong cao nhat!"<<endl;
    cout<<"9. Tim kiem nhan vien theo so CCCD!"<<endl;
    cout<< "10. Dat phong" << endl;
    cout<< "11. Xuat thong tin dat phong" << endl;
    cout<< "12. Tim kiem thong tin khach da dat phong theo CCCD" << endl;
    cout<< "13. Tim kiem thong tin khach da dat phong theo ten khach hang" << endl;
    cout<< "14. Xoa khach hang" << endl;
    cout<<"0.Thoat!"<<endl;
    cout<<"============================================"<<endl;
    cout<<"Xin moi nhap lua chon cua ban: ";
    cin>>choice;
    switch (choice){
            case 1:
            	cout<<"Nhap so luong nhan vien: ";
				cin>>n;
				if (n > 0) {
					ds = new NhanVien[n];
				} else {
					cout << "So luong nhan vien phai lon hon 0!" << endl;
				}
                break;
            case 2:
                if(ds!=NULL){
                	NV.nhapDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap so luong nhan vien!"<< endl;
                }
                break;
            case 3:
                if(ds!=NULL){
                	cout<<"DANH SACH NHAN VIEN"<<endl;
					NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 4:
                if(ds!=NULL){
	                NV.sapXepTheoID(ds,n);
	                NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 5:
                if(ds!=NULL){
                    NV.sapXepTheoHoTen(ds,n);
    				NV.xuatDanhSachNV(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
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
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
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
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
            case 8:
                if(ds!=NULL){
                	NV.timKiemNVLuongCaoNhat(ds,n);
                }else{
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
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
                    cout<<"Ban chua nhap danh sach nhan vien!"<<endl;
                }
                break;
             case 10:
                if (count < 100) {
                    vitri[count].nhapDatPhong(vitri, count);
                    count++;
                } else {
                    cout << "Khong the them khach hang. Phong da dat toi da." << endl;
                }
                break;
              case 11:
                if (count == 0) {
                    cout << "Khong co khach hang." << endl;
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
            case 0:
                cout<<"Thoat chuong trinh!"<<endl;
                break;
            default:
                cout<<"Lua chon khong hop le! Vui long nhap lai."<<endl;
        }
    }while(choice!=0);
	return 0;
}