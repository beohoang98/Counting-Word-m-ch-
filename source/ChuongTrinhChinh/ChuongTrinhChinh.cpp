#include "ChuongTrinhChinh.h"
#include <wchar.h>

bool readInput(danhSachTu &input) {
	FILE *f = _wfopen(fileInput, L"r,ccs=UTF-16LE");
	if (f == NULL) return false;

	input.soTu	= 0;
	input.tu	= NULL;
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

//kiem tra cac chu co trung lap lai khong
bool KiemTraTuTrongDS(wchar_t * s, danhSachTu &DS) {
	for (int i = 0; i < DS.soTu; ++i) {
		if (wcscmp(s, DS.tu[i]) == 0) return true;
	}
	return false;
}
//them tu vao danh sach
void ThemTuVaoDanhSach(wchar_t * s, danhSachTu &DS) {
	DS.tu = (wchar_t**)realloc(DS.tu, (DS.soTu + 1)*sizeof(wchar_t*));
	DS.tu[DS.soTu] = new wchar_t[wcslen(s) + 1];
	wcscpy(DS.tu[DS.soTu], s);
	DS.soTu++;
}


danhSachTu DemTu(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm) {
	danhSachTu dsTu = { 0, NULL };
	for (int i = 0; i < input.soTu; ++i) {
		bool chuaCoTrongDS = !KiemTraTuTrongDS(input.tu[i], dsTu);
		if (chuaCoTrongDS) {
			ThemTuVaoDanhSach(input.tu[i], dsTu);
		}
	}
	return dsTu;
}
danhSachTu DemTuDon(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm) {
	danhSachTu dsTuDon = { 0, NULL };
	for (int i = 0; i < input.soTu; ++i) 
	{
		ThemTuVaoDanhSach(input.tu[i], dsTuDon);
	}
	return dsTuDon;
}
danhSachTu DemTuGhep(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm) {
	danhSachTu dsTuGhep = { 0, NULL };
	for (int i = 0; i < input.soTu-1; ++i) 
	{
		wchar_t * tuDau		= input.tu[i];
		wchar_t * tuSau		= input.tu[i+1];
		wchar_t * tuCanGhep	= new wchar_t[wcslen(tuDau) + wcslen(tuSau) + 2]; // " " va "\0"
		
		wcscpy(tuCanGhep, tuDau);
		wcscat(tuCanGhep, L" ");
		wcscat(tuCanGhep, tuSau);// ghep 2 tu don thanh tu ghep

		bool chuaCoTrongDS	= !KiemTraTuTrongDS(tuCanGhep, dsTuGhep);
		bool coNghia		= KiemTraTuGhep(tuDau, tuSau, tuDienChu, dsNgAm);
		if (chuaCoTrongDS && coNghia) 
		{
			ThemTuVaoDanhSach(tuCanGhep, dsTuGhep);
		}
	}
	return dsTuGhep;
}
danhSachTu DemTuLay(danhSachTu &dsTuGhep, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm) {
	danhSachTu dsTuLay = { 0, NULL };
	for (int i = 0; i < dsTuGhep.soTu; ++i)
	{
		wchar_t * buf = new wchar_t[wcslen(dsTuGhep.tu[i])+1];
		wcscpy(buf, dsTuGhep.tu[i]);
		wchar_t * tuDau = wcstok(buf, L" "); //cat boi khoang trong
		wchar_t * tuSau = wcstok(NULL, L"\0");//cat phan con lai

		bool chuaCoTrongDS	= !KiemTraTuTrongDS(dsTuGhep.tu[i], dsTuLay);
		bool dungQuiTac		= KiemTraTuLay(tuDau, tuSau, tuDienChu, &dsNgAm);

		if ( chuaCoTrongDS && dungQuiTac ) {
			ThemTuVaoDanhSach(dsTuGhep.tu[i], dsTuLay);
		}
	}
	return dsTuLay;
}

void ghiDS(FILE *f, danhSachTu &DS, wchar_t * ten) {
	fwprintf(f, L"%ls: %d\n\t", ten, DS.soTu);
	for (int i = 0; i < DS.soTu; ++i) {
		fwprintf(f, L"%ls,", DS.tu[i]);
	}
	fwprintf(f, L"\n");
}

bool writeOutput(danhSachTu &input, danhSachTu tuDienChu[], _danhSachNguyenAm &dsNgAm) {
	danhSachTu dsTu		= DemTu(input, tuDienChu, dsNgAm);
	danhSachTu dsTuDon	= DemTuDon(input, tuDienChu, dsNgAm);
	danhSachTu dsTuGhep	= DemTuGhep(input, tuDienChu, dsNgAm);
	
	//dem tu lay dua theo danh sach tu ghep
	danhSachTu dsTuLay	= DemTuLay(dsTuGhep, tuDienChu, dsNgAm);

	FILE *f = _wfopen(fileOutput, L"w,ccs=UTF-16LE");
	if (!f) return false;

	ghiDS(f, dsTu		,L"So Tu");//ghi output so tu
	ghiDS(f, dsTuDon	,L"So Tu Don");//ghi output so tu don
	ghiDS(f, dsTuGhep	,L"So Tu Ghep");//ghi output so tu ghep
	ghiDS(f, dsTuLay	,L"So Tu Lay");//ghi output so tu lay
	
	fclose(f);
	return true;
}

void BaoLoi(char * mes) {
	printf("%s", mes);
	_getch();
	exit(0);
}

