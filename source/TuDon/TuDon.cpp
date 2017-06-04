#include "TuDon.h"

bool KiemTraTuDon(wchar_t *s, danhSachTu td[24], _danhSachNguyenAm &DS_vowel)
{
	wchar_t alphabet;
	int order = vowelOrder(mytoLower(s[0], &DS_vowel), alphabet);
	DocTuDien(alphabet, td, &DS_vowel);

	for (int i = 0; i < td[order].soTu; i++)
	if (!_wcsicmp(s, td[order].tu[i]))
			return 1;
	return 0;
}