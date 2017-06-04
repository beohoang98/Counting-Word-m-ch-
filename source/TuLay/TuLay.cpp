#include "TuLay.h"
#include <wchar.h>
#include <cwctype>
#include <malloc.h>

/*
	@param
	- s			: chu cai can lay phu am cuoi
	- dsNgAm	: danh sach nguyen am de doi chieu
	@output
	- 1 chuoi la phu am cuoi cua s
*/
wchar_t * PhuAmCuoi(wchar_t * s, _danhSachNguyenAm * dsNgAm) {
	wchar_t * PhAmDau = PhuAmDau(s, dsNgAm);

	int idbegin = wcslen(PhAmDau);//vi tri bat dau cua phu am cuoi
	int lenS = wcslen(s);

	//kiem tra do dai phu am dau
	if (lenS <= idbegin) {
		free(PhAmDau);
		return L"\0";
		// tuc la khong ton tai vi tri phu am cuoi
	}

	wchar_t* phAmCuoi = new wchar_t[lenS - idbegin];
	for (int i = idbegin; i < lenS; ++i) {
		phAmCuoi[i - idbegin] = mytoLower(s[i], dsNgAm);
	}
	phAmCuoi[lenS - idbegin] = L'\0';

	return phAmCuoi;
}

/*
	@param:	s (tu can lay phu am dau)
			dsNgAm (danh sach nguyen am truyen vao de doi chieu)
	@output: chuoi
*/
wchar_t * PhuAmDau(wchar_t * s, _danhSachNguyenAm * dsNgAm) {
	_danhSachPhuAm dsPhuAmDau = { 0, 0 };
	dsPhuAmDau = DocDanhSachPhuAm(DUONG_DAN_PH_AM);

	int id = 0;
	wchar_t * phAm = new wchar_t[2];
	phAm[0] = towlower(s[id]);
	phAm[1] = L'\0';

	while (true) {
		bool IsPhAm = false;
		for (int i = 0; i < dsPhuAmDau.soAm; ++i) {
			if (wcscmp(phAm, dsPhuAmDau.phAm[i]) == 0) {
				IsPhAm = true;
				break;
			}
		}
		if (IsPhAm == false) break;
		++id;
		phAm		= (wchar_t*)realloc(phAm, (id + 2)*sizeof(wchar_t));
		phAm[id]	= towlower(s[id]);
		phAm[id+1]	= L'\0';
	}

	if (id == 0) {
		// khong tim duoc vi tri cua phu am dau
		free(phAm);
		return L"\0";
	}
	phAm	 = (wchar_t*)realloc(phAm, (id)*sizeof(wchar_t));
	phAm[id] = L'\0';

	free(dsPhuAmDau.phAm);
	return phAm;
}


bool KiemTraPhuAmCuoi(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm) {
	wchar_t * phuAmTu1 = PhuAmCuoi(s1, dsNgAm);
	wchar_t * phuAmTu2 = PhuAmCuoi(s2, dsNgAm);
	
	bool haiTuGiongNhau = wcscmp(phuAmTu1, phuAmTu2) == 0;
	if (haiTuGiongNhau) return true;
	return false;
}
bool KiemTraPhuAmDau(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm) {
	wchar_t * phAmDau1 = PhuAmDau(s1, dsNgAm);
	wchar_t * phAmDau2 = PhuAmDau(s2, dsNgAm);
	
	if (phAmDau1[0] == L'\0' || phAmDau2[0] == L'\0') return false;
	// neu ca hai deu khong co phu am dau thi khong the xet duoc
	
	bool haiTuKhacNhau = wcscmp(phAmDau1, phAmDau2) != 0;
	if (haiTuKhacNhau) return false;
	return true;
}

/*
	@param:
	-s1 : tu don dau tien cua tu ghep
	-s2 : tu don thu 2 cua tu ghep
	@output:
	-Co phai la tu lay hay khong
*/
bool KiemTraTuLay(wchar_t * s1, wchar_t * s2, danhSachTu * dsTu, _danhSachNguyenAm * dsNgAm) {
	bool giongPhuAmDau  = KiemTraPhuAmDau(s1, s2, dsNgAm);
	bool giongPhuAmCuoi = KiemTraPhuAmCuoi(s1, s2, dsNgAm);
	
	if (giongPhuAmDau || giongPhuAmCuoi) return true;
	return false;
}