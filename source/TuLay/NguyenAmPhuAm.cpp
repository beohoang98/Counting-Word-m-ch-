#include "NguyenAmPhuAm.h"
#include "../DocTuDien/DocTuDien.h"
#include <cwctype>
#include <wchar.h>
#include <stdio.h>
#include <malloc.h>

/*
	@param: chuoi ten file
	@output: danh sach sau khi doc tu file
	*/
_danhSachNguyenAm DocDSNguyenAm(wchar_t * filename) 
{
	_danhSachNguyenAm DS = { 0, 0 };

	FILE * f = _wfopen(filename, L"r,ccs=UTF-16LE");
	if (f == NULL) {
		DS.soAm = -1;
		return DS;
	}
	wchar_t p = L'\0';

	while (!feof(f)) {
		if (p == L'#') 
		{
			DS.soAm++;
			DS.ds = (_nguyenAm*)realloc(DS.ds, DS.soAm*sizeof(_nguyenAm));
			DS.ds[DS.soAm - 1].n = 0;
			DS.ds[DS.soAm - 1].ds = NULL;
			fwscanf(f, L"%lc", &DS.ds[DS.soAm - 1].name);
		}
		else if (p == L'@') 
		{
			int k = DS.ds[DS.soAm - 1].n++;
			DS.ds[DS.soAm - 1].ds = (wchar_t*)realloc(DS.ds[DS.soAm - 1].ds, (k + 1)*sizeof(wchar_t));
			fwscanf(f, L"%lc", &DS.ds[DS.soAm - 1].ds[k]);
		}
		fwscanf(f, L"%lc", &p);
	}

	fclose(f);
	return DS;
}


/*
	@param: chuoi ten file
	@output: danh sach phu am doc tu file
	*/
_danhSachPhuAm DocDanhSachPhuAm(wchar_t *filename) 
{
	_danhSachPhuAm A = { -1, 0 };

	FILE *f = _wfopen(DUONG_DAN_PH_AM, L"r,ccs=UTF-16LE");
	if (!f) return A;

	wchar_t letterA;
	wchar_t s[5];

	A.soAm = 0;
	A.phAm = NULL;

	fwscanf(f, L"%lc", &letterA);//doc dau @ dau tien

	while (!feof(f))
	{
		fwscanf(f, L"%[^@]ls", s);//doc chuoi dung boi ki tu @
		fwscanf(f, L"%lc", &letterA);//doc ki tu @

		int len = wcslen(s);
		A.phAm = (wchar_t**)realloc(A.phAm, (A.soAm + 1)*sizeof(wchar_t*));
		A.phAm[A.soAm] = new wchar_t[len];
		wcscpy(A.phAm[A.soAm], s);

		A.soAm++;
	}

	fclose(f);
	return A;
}



/*
	@param:
	-a: chu cai can chuyen ve nguyen am chuan
	-DS: danh sach nguyen am de so sanh
	@output:
	-nguyen am chuan
	*/
wchar_t ToNguyenAm(wchar_t a, _danhSachNguyenAm * DS)
{
	a = towlower(a);
	for (int i = 0; i < DS->soAm; ++i) 
	{
		for (int j = 0; j < DS->ds[i].n; ++j) 
		{
			if (a == DS->ds[i].ds[j]) 
			{
				return DS->ds[i].name;
			}
		}
	}
	return L'\0';
}

/*
	@param: chu cai can chuyen ve phu am chuan
	@output: phu am chuan
	*/
wchar_t ToPhuAm(wchar_t a) 
{
	return (towlower(a));
}

/*
	@param:
	-a : chu cai can lowercase
	-DS: danh sach nguyen am de su dung doi chieu
	@output:
	-chu cai da duoc lowercase
	*/
wchar_t mytoLower(wchar_t a, _danhSachNguyenAm * DS) 
{
	wchar_t c = ToNguyenAm(a, DS);
	if (c == L'\0') c = ToPhuAm(a);
	return c;
}