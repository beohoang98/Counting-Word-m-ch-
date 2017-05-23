#include "../DocTuDien/DocTuDien.h"
#include "../TuLay/TuLay.h"
#include "../TuLay/NguyenAmPhuAm.h"
#include "../TuDon/TuDon.h"
#include "../TuGhep/TuGhep.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define fileInput L"../Input/input.txt"
#define fileOutput L"../Output/output.txt"

bool readInput(danhSachTu &input);
bool writeOutput(int soTuDon, int soTuGhep, int soTuLay);
void BaoLoi(char * mes);