#include "../DocTuDien/DocTuDien.h"
#include "../TuLay/TuLay.h"
#include "../TuLay/NguyenAmPhuAm.h"
#include "../TuDon/TuDon.h"
#include "../TuGhep/TuGhep.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define fileInput L"../../data/Input/input.txt"
#define fileOutput L"../../data/Output/output.txt"

bool readInput(danhSachTu &input);

danhSachTu DemTu(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm);
danhSachTu DemTuDon(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm);
danhSachTu DemTuGhep(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm);
danhSachTu DemTuLay(danhSachTu &dsTuGhep, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm);

bool writeOutput(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm);

void BaoLoi(char * mes);