#ifndef _NGAM_PHAM_H
#define _NGAM_PHAM_H

#define _CRT_SECURE_NO_WARNINGS

struct _nguyenAm {
	wchar_t name;
	int n; // so chu cai cung nguyen am
	wchar_t * ds; //danh sach cac chu cai cung nguyen am
};

struct _danhSachNguyenAm {
	int soAm;
	_nguyenAm * ds; // danh sach cac nguyen am
};

struct _danhSachPhuAm {
	int soAm;
	wchar_t **phAm;
};

_danhSachNguyenAm DocDSNguyenAm(wchar_t * filename);
_danhSachPhuAm DocDanhSachPhuAm(wchar_t *filename);

//chuyen cai nguyen am dac biet thanh nguyen am thuong
wchar_t ToNguyenAm(wchar_t a, _danhSachNguyenAm * DS);

//chuyen cac phu am dac biet thanh phu am thuong
wchar_t ToPhuAm(wchar_t a);

//chuyen chu cai xuong nguyen am thuong
wchar_t mytoLower(wchar_t a, _danhSachNguyenAm * DS);

#endif