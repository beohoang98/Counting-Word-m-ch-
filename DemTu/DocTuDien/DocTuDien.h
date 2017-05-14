#ifndef DOCTUDIEN_H
#define DOCTUDIEN_H

#include "../TuLay/NguyenAmPhuAm.h" // dung de doc file theo chu cai dau`

#define DUONG_DAN L"../Data/"

struct danhSachTu {
	int soTu;
	wchar_t ** tu;
};

int DocTuDien(wchar_t* filename, danhSachTu &DS);
int DocTuDienTheoChuCai(wchar_t chuCai, danhSachTu &DS, _danhSachNguyenAm * dsNgAm);

#endif