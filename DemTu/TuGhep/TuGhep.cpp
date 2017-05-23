#include "TuGhep.h"
#include <wchar.h>
#include <malloc.h>

bool KiemTraTuGhep(wchar_t *s1, wchar_t *s2, danhSachTu td[24], _danhSachNguyenAm &dsNgAm) {
	int len = wcslen(s1) + 1 + wcslen(s2) + 1;
	wchar_t * s = new wchar_t[len];
	wcscpy(s, s1);
	wcscat(s, L" ");
	wcscat(s, s2);

	bool result = KiemTraTuDon(s, td, dsNgAm);
	free(s);

	return result;
}