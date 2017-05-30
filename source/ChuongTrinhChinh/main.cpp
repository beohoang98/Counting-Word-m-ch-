#include <stdio.h>
#include <conio.h>
#include "ChuongTrinhChinh.h"

void main() {
	//khai bao
	danhSachTu my_input;		// du lieu vao
	danhSachTu tuDienChu[24];	// tu dien tung chu cai alphabet
	_danhSachNguyenAm dsNgAm;	// danh sach cac nguyen am dau

	//Read Input
	if (!readInput(my_input)) 
		BaoLoi("Khong doc duoc file input");
	dsNgAm = DocDSNguyenAm(DUONG_DAN_NG_AM);


	//Write Output
	if (!writeOutput(my_input, tuDienChu, dsNgAm))
		BaoLoi("Khong ghi ra file output duoc");


	printf("Ket qua da xuat ra file output thanh cong.");
	_getch();
}
