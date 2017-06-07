#include "TuGhep.h"
#include <wchar.h>
#include <malloc.h>

bool KiemTraTuGhep(wchar_t *tuDau, wchar_t *tuSau, danhSachTu td[24], _danhSachNguyenAm &dsNgAm) 
{
	int len = wcslen(tuDau) + 1 + wcslen(tuSau) + 1;
	wchar_t * tuDuocGhep = new wchar_t[len];
	
	wcscpy(tuDuocGhep, tuDau);
	wcscat(tuDuocGhep, L" ");
	wcscat(tuDuocGhep, tuSau); //ghep 2 tu don thanh tu ghep

	bool result = KiemTraTuDon(tuDuocGhep, td, dsNgAm);
	free(tuDuocGhep);

	return result;
}