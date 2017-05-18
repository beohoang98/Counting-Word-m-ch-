#include "NguyenAmPhuAm.h"
#include <cwctype>
#include <stdio.h>
#include <malloc.h>

_danhSachNguyenAm DocDSNguyenAm(wchar_t * filename) {
	_danhSachNguyenAm DS = { 0, 0 };

	FILE * f = _wfopen(filename, L"r,ccs=UTF-16LE");
	if (f == NULL) {
		DS.soAm = -1;
		return DS;
	}

	wchar_t p = L'\0';

	//
	while (!feof(f)) {
		if (p == L'#') {
			DS.soAm++;
			DS.ds = (_nguyenAm*)realloc(DS.ds, DS.soAm*sizeof(_nguyenAm));
			DS.ds[DS.soAm - 1].n = 0;
			DS.ds[DS.soAm - 1].ds = NULL;
			fwscanf(f, L"%lc", &DS.ds[DS.soAm - 1].name);
		}
		else if (p == L'@') {
			int k = DS.ds[DS.soAm - 1].n++;
			DS.ds[DS.soAm - 1].ds = (wchar_t*)realloc(DS.ds[DS.soAm - 1].ds, (k + 1)*sizeof(wchar_t));
			fwscanf(f, L"%lc", &DS.ds[DS.soAm - 1].ds[k]);
		}
		fwscanf(f, L"%lc", &p);
	}

	fclose(f);
	return DS;
}

//chuyen cai nguyen am dac biet thanh nguyen am thuong
wchar_t ToNguyenAm(wchar_t a, _danhSachNguyenAm * DS) {
	a = towlower(a);
	for (int i = 0; i < DS->soAm; ++i) {
		for (int j = 0; j < DS->ds[i].n; ++j) {
			if (a == DS->ds[i].ds[j]) {
				return DS->ds[i].name;
			}
		}
	}
	return L'\0';
}

//chuyen cac phu am dac biet thanh phu am thuong
wchar_t ToPhuAm(wchar_t a) {
	return (towlower(a));
}

//chuyen chu cai xuong nguyen am thuong
wchar_t mytoLower(wchar_t a, _danhSachNguyenAm * DS) {
	wchar_t c = ToNguyenAm(a, DS);
	if (c == L'\0') c = ToPhuAm(a);
	return c;
}