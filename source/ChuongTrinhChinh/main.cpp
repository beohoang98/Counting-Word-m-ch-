#include <stdio.h>
#include <conio.h>
#include "ChuongTrinhChinh.h"

void main() {
	//khai bao
	danhSachTu my_input;		// du lieu vao
	danhSachTu tuDienChu[24];	// tu dien tung chu cai alphabet
	_danhSachNguyenAm dsNgAm;	// danh sach cac nguyen am dau
	int soTuDon = 0;	// so tu don
	int soTuGhep = 0;	// so tu ghep
	int soTuLay = 0;	// so tu lay

	//Read Input
	if (!readInput(my_input)) 
		BaoLoi("Khong doc duoc file input");
	dsNgAm = DocDSNguyenAm(DUONG_DAN_NG_AM);


	//Counting
	for (int i = 0; i < my_input.soTu; ++i) {
		// dem tu don
		if (KiemTraTuDon(my_input.tu[i], tuDienChu, dsNgAm))
			++soTuDon;

		// dem tu ghep & tu lay
		if (i < my_input.soTu - 1) {
			if (KiemTraTuGhep(my_input.tu[i], my_input.tu[i + 1], tuDienChu, dsNgAm)) {
				
				++soTuGhep;
				
				//neu la tu ghep thi kiem tra co phai tu lay hay khong?
				if (KiemTraTuLay(my_input.tu[i], my_input.tu[i + 1], tuDienChu, &dsNgAm)) {
					++soTuLay;
				}
			}
		}//ket thuc viec xet' tu` thu' i
	}//finish counting


	//Write Output
	if (!writeOutput(soTuDon, soTuGhep, soTuLay))
		BaoLoi("Khong ghi ra file output duoc");


	printf("Ket qua da xuat ra file output thanh cong.");
	_getch();
}
