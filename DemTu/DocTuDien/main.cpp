#include "DocTuDien.h"
#include <stdio.h>
#include <conio.h>

void main() {
	//kiem tra ham, khong lien quan den chuong trinh chinh
	danhSachTu dic[24];
	_danhSachNguyenAm DS_vowel = DocDSNguyenAm(L"NguyenAmDau.txt");
	DocTuDien(L'â', dic, &DS_vowel);

	for (int i = 0; i < dic[0].soTu; ++i) {
		wprintf(L"%ls\n", dic[0].tu[i]);
	}

	_getch();
}