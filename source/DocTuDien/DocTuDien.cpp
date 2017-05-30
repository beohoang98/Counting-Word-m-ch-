#include "DocTuDien.h"

#include <stdio.h>
#include <wchar.h>
#include <malloc.h>


///---------------------------main function-----------------------------

//read Dictionary
void DocTuDien(wchar_t ch, danhSachTu dic[24], _danhSachNguyenAm * DS_vowel)
{
	wchar_t s[50], s1[10] = L"a.txt";
	wchar_t *tmp = NULL;
	wchar_t letter;
	int vt = vowelOrder(mytoLower(ch, DS_vowel), s1[0]);
	if (dic[vt].soTu > 0) return;

	wcscpy(s, DUONG_DAN_TU_DIEN);
	wcscat(s, s1);
	FILE *f = _wfopen(s, L"r,ccs=UTF-16LE");

	dic[vt].soTu = 0;
	dic[vt].tu = NULL;
	if (!f)
	{
		printf("FILE NOT FOUND");
		return;
	}
	while (!feof(f))
	{	
		fwscanf(f, L"%lc", &letter);
		fgetws(s, 50, f);
		
		s[wcslen(s) - 1] = '\0';

		dic[vt].tu = (wchar_t**)realloc(dic[vt].tu, (dic[vt].soTu+1)*sizeof(wchar_t*));
		tmp = new wchar_t[(wcslen(s) + 1)];

		for (int i = 0; i < wcslen(s); i++)
		{
			tmp[i] = s[i];
		}
		tmp[wcslen(s)] = '\0';

		dic[vt].tu[dic[vt].soTu] = tmp;
		dic[vt].soTu++;
	}

	fclose(f);
}

///----------------------------sub function-----------------------------

//lay so thu tu cua chu cai trong tu dien
int vowelOrder(wchar_t vowel, wchar_t &outVowel) {

	FILE *f = _wfopen(DUONG_DAN_THU_TU_AM, L"r,ccs=UTF-16LE");
	if (!f) {
		return -1;
	}

	int order = 0;
	wchar_t c;
	while (!feof(f)) {
		fwscanf(f, L"%d ", &order);
		fwscanf(f, L"%lc", &c);
		outVowel = c;
		while ((c != L'.') && !feof(f)) {
			if (c == vowel) {
				fclose(f);
				return order;
			}
			fwscanf(f, L"%lc", &c);
		}
	}

	fclose(f);
	return -1;
}