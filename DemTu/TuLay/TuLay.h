#ifndef _TU_LAY_H
#define _TU_LAY_H

#include "../DocTuDien/DocTuDien.h"
#include "NguyenAmPhuAm.h"

#define _CRT_SECURE_NO_WARNINGS
#define fileNguyenAm L"../DataIn/NguyenAmDau.txt"
#define filePhuAmDau L"../DataIn/PhuAmDau.txt"

wchar_t * PhuAmDau(wchar_t * s, _danhSachNguyenAm * dsNgAm);
wchar_t * PhuAmCuoi(wchar_t * s, _danhSachNguyenAm * dsNgAm);

bool KiemTraPhuAmCuoi(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm);
bool KiemTraPhuAmDau(wchar_t * s1, wchar_t * s2, _danhSachNguyenAm * dsNgAm);

bool KiemTraTuLay(wchar_t * s1, wchar_t * s2, danhSachTu * dsTu, _danhSachNguyenAm * dsNgAm);

#endif