#ifndef DOCTUDIEN_H
#define DOCTUDIEN_H

#include "../TuLay/NguyenAmPhuAm.h" // dung de doc file theo chu cai dau`

#define DUONG_DAN L"../Data/"
#define DUONG_DAN_TU_DIEN L"../Data/TuDien/"

//data of word read for dictionary
struct danhSachTu {
	int soTu;
	wchar_t ** tu;
};

///---------------------------main function-----------------------------

//read Dictionary
void DocTuDien(wchar_t ch, danhSachTu dic[24], _danhSachNguyenAm * DS_vowel);

///----------------------------sub function-----------------------------

//lay so thu tu cua chu cai trong tu dien
int vowelOrder(wchar_t vowel, wchar_t &outVowel);


#endif