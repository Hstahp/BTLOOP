#pragma once
#include"../Nguoi/Nguoi.hpp"


class KhachHang:public Nguoi{
    private:
    public:
        string getCCCD();  
       string getHoTen();

};
string KhachHang::getCCCD(){
    return cccd;
}
string KhachHang::getHoTen(){
  return hoTen;  
}