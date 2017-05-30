#include "TuDon.h"

bool KiemTraTuDon(wchar_t *s, danhSachTu td[24], _danhSachNguyenAm &DS_vowel)
{
	wchar_t tmp;
	int vowel = vowelOrder(mytoLower(s[0], &DS_vowel), tmp);
	DocTuDien(tmp, td, &DS_vowel);

	for (int i = 0; i < td[vowel].soTu; i++)
		if (!_wcsicmp(s, td[vowel].tu[i]))
			return 1;
	return 0;
}