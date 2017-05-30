#include "TuDon.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void main() {
	//example
	danhSachTu * td = new danhSachTu[24];
	_danhSachNguyenAm dsNgAm = DocDSNguyenAm(L"NguyenAmDau.txt");

	int ktra = KiemTraTuDon(L"ân ái", td, dsNgAm);
	if (ktra) printf("La tu don");
	else printf("Khong la tu don");

	free(td);
	_getch();
}