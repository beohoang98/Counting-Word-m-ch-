#include "DocTuDien.h"
#include <stdio.h>
#include <conio.h>

void main() {
	//kiem tra ham, khong lien quan den chuong trinh chinh
	danhSachTu DS = { 0, 0 }; // 0 = NULL
	_danhSachNguyenAm dsNgAm = DocDSNguyenAm(L"../Data/NguyenAmDau.txt");
	if (!DocTuDienTheoChuCai(L'a', DS, &dsNgAm)) {
		wprintf(L"Loi doc file %lc", L'a');
		_getch();
		return;
	}
	for (int i = 0; i < DS.soTu; ++i) {
		wprintf(L"%ls \n", DS.tu[i]);
	}
	_getch();
}