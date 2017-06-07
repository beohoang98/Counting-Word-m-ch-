#include "DocTuDien.h"

#include <stdio.h>
#include <wchar.h>
#include <malloc.h>


///---------------------------main function-----------------------------

//doc tu dien
void DocTuDien(wchar_t ch, danhSachTu dic[24], _danhSachNguyenAm * DS_vowel)
{
	wchar_t filePath[50];
	wchar_t fileName[10] = L"a.txt";
	wchar_t *tmp = NULL;
	wchar_t letterA;

	int vt = vowelOrder(mytoLower(ch, DS_vowel), fileName[0]);
	if (dic[vt].soTu > 0) return;// neu tu dien ung voi chu cai ch da doc roi thi ko doc nua

	wcscpy(filePath, DUONG_DAN_TU_DIEN);
	wcscat(filePath, fileName);
	FILE *f = _wfopen(filePath, L"r,ccs=UTF-16LE");
	if (!f)
	{
		printf("Khong tim thay file");
		return;
	}

	dic[vt].soTu = 0;
	dic[vt].tu = NULL;
	while (!feof(f))
	{	
		wchar_t s[50];
		fwscanf(f, L"%lc", &letterA);
		fgetws(s, 50, f);
		
		s[wcslen(s) - 1] = '\0'; //vi doc = fgetws se co ki tu \n nam cuoi

		dic[vt].tu	= (wchar_t**)realloc(dic[vt].tu, (dic[vt].soTu+1)*sizeof(wchar_t*));
		tmp			= new wchar_t[(wcslen(s) + 1)];
		wcscpy(tmp, s);

		dic[vt].tu[dic[vt].soTu] = tmp;
		dic[vt].soTu++;
	}

	fclose(f);
}

///----------------------------sub function-----------------------------

//lay so thu tu cua chu cai trong tu dien va chu cai alphabet cua no
/*
	param: vowel
	output: vowelOrder, outVowel
*/
int vowelOrder(wchar_t vowel, wchar_t &outVowel) 
{

	FILE *f = _wfopen(DUONG_DAN_THU_TU_AM, L"r,ccs=UTF-16LE");
	if (!f) 
	{
		return -1;// file ko tim thay
	}

	int order = 0;
	wchar_t c;
	while (!feof(f)) 
	{
		fwscanf(f, L"%d ", &order);
		fwscanf(f, L"%lc", &c);
		outVowel = c; // luu lai chu cai alphabet do vao outVowel
		while ((c != L'.') && !feof(f)) 
		{
			if (c == vowel) 
			{
				fclose(f);
				return order; //xuat ra thu tu tuong ung
			}
			fwscanf(f, L"%lc", &c);
		}
	}

	fclose(f);
	return -1; // ko tim duoc thu tu tuong ung
}