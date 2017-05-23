#include "TuLay.h"
#include <wchar.h>
#include <cwctype>
#include <malloc.h>

wchar_t * PhuAmCuoi(wchar_t * s, _danhSachNguyenAm * dsNgAm) {
	wchar_t * PhAmDau = PhuAmDau(s, dsNgAm);

	int idbegin = wcslen(PhAmDau);
	int lenS = wcslen(s);

	//kiem tra do dai phu am dau
	if (idbegin >= lenS) {
		free(PhAmDau);
		return L"\0";
	}

	//copy phu am cuoi tu chuoi goc ra phAmCuoi
	wchar_t* phAmCuoi = new wchar_t[lenS - idbegin];
	for (int i = idbegin; i < lenS; ++i) {
		phAmCuoi[i - idbegin] = mytoLower(s[i], dsNgAm);
	}
	phAmCuoi[lenS - idbegin] = L'\0';

	return phAmCuoi;
}


wchar_t * PhuAmDau(wchar_t * s, _danhSachNguyenAm * dsNgAm) {
	_danhSachPhuAm dsPhuAmDau = { 0, 0 };
	dsPhuAmDau = DocDanhSachPhuAm(filePhuAmDau);

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
		phAm = (wchar_t*)realloc(phAm, (id + 2)*sizeof(wchar_t));
		phAm[id] = towlower(s[id]);
		phAm[id + 1] = L'\0';
	}

	if (id == 0) {
		free(phAm);
		return L"\0";
	}
	phAm = (wchar_t*)realloc(phAm, (id)*sizeof(wchar_t));
	phAm[id] = L'\0';

	free(dsPhuAmDau.phAm);
	return phAm;
}


bool KiemTraPhuAmCuoi(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm) {
	wchar_t * ph1 = PhuAmCuoi(s1, dsNgAm);
	wchar_t * ph2 = PhuAmCuoi(s2, dsNgAm);
	if (wcscmp(ph1, ph2) != 0) return false;
	return true;
}
bool KiemTraPhuAmDau(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm) {
	wchar_t * phAmDau1 = PhuAmDau(s1, dsNgAm);
	wchar_t * phAmDau2 = PhuAmDau(s2, dsNgAm);
	
	if (phAmDau1[0] == L'\0' || phAmDau2[0] == L'\0') return false;
	if (wcscmp(phAmDau1, phAmDau2) != 0) return false;
	return true;
}


bool KiemTraTuLay(wchar_t * s1, wchar_t * s2, danhSachTu * dsTu, _danhSachNguyenAm * dsNgAm) {
	if ((KiemTraPhuAmDau(s1, s2, dsNgAm) || KiemTraPhuAmCuoi(s1, s2, dsNgAm))) return true;
	return false;
}