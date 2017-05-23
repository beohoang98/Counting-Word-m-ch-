#include "ChuongTrinhChinh.h"
#include <wchar.h>

bool readInput(danhSachTu &input) {
	FILE *f = _wfopen(fileInput, L"r,ccs=UTF-16LE");
	if (f == NULL) return false;

	input.soTu = 0;
	input.tu = NULL;
	while (!feof(f)) {
		wchar_t s[40];
		fwscanf(f, L"%ls", &s);
		
		input.tu = (wchar_t**)realloc(input.tu, (input.soTu+1)*sizeof(wchar_t*));
		input.tu[input.soTu] = new wchar_t[wcslen(s) + 1];
		wcscpy(input.tu[input.soTu], s);

		input.soTu++;
	}

	fclose(f);
	return true;
}


bool writeOutput(int soTuDon, int soTuGhep, int soTuLay) {
	FILE *f = _wfopen(fileOutput, L"w,ccs=UTF-16LE");
	if (f == NULL) return false;
	fwprintf(f, L"Số từ đơn: %d\n", soTuDon);
	fwprintf(f, L"Số từ ghép: %d\n", soTuGhep);
	fwprintf(f, L"Số từ láy: %d\n", soTuLay);

	fclose(f);
	return true;
}


void BaoLoi(char * mes) {
	printf("%s", mes);
	_getch();
	exit(0);
}

