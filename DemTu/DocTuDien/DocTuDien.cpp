#include "DocTuDien.h"

#include <stdio.h>
#include <wchar.h>
#include <malloc.h>

int DocTuDien(wchar_t* filename, danhSachTu &DS) {
	FILE * f = _wfopen(filename, L"r,ccs=UTF-16LE");
	if (!f) {
		return false;
	}
	else {
		DS.soTu = 0;
		wchar_t c;
		wchar_t s[50];

		while (!feof(f)) {
			c = L' ';
			while (c != L'@' && !feof(f)) fwscanf(f, L"%lc", &c);// doc dau @
			fwscanf(f, L"%[^\n]ls", &s); //doc chu
			int len = wcslen(s);

			DS.tu = (wchar_t**)realloc(DS.tu, (DS.soTu + 1)*sizeof(wchar_t*)); //tao them du lieu
			
			DS.tu[DS.soTu] = new wchar_t[len];
			wcscpy(DS.tu[DS.soTu], s);

			++DS.soTu;
		}

		fclose(f);
		return true;
	}
}

int DocTuDienTheoChuCai(wchar_t chuCai, danhSachTu &DS, _danhSachNguyenAm * dsNgAm) {
	int len = wcslen(DUONG_DAN) + 6;
	wchar_t * tenFile = new wchar_t[len];
	wcscpy(tenFile, DUONG_DAN);
	tenFile[len - 6] = ToNguyenAm(chuCai, dsNgAm);
	tenFile[len - 6 + 1] = L'\0';
	wcscat(tenFile, L".txt");

	return DocTuDien(tenFile, DS);
}