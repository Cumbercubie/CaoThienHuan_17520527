#include "stdafx.h"
#include <iostream>
#include "CVector.h"
CVector::CVector()
{
	for (int i = 0; i<100; i++)
		size[i] = 0;
	//ctor
}
CVector::~CVector()
{
	//dtor
}
void CVector::Nhap()
{
	cout << "nhap so chieu cua vector";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> size[i];
		cout << "\n";
	}
}
istream& operator>>(istream& is, CVector& CV)
{
	CV.Nhap();
	return is;
}
ostream& operator<<(ostream& os, CVector& CV)
{
	os << "(";
	for (int i = 0; i< CV.n - 1; i++)
		os << CV.size[i] << ",";
	os << CV.size[CV.n - 1];
	os << ")\n";
	return os;
}
CVector CVector::operator+(CVector CV)
{
	CVector cvTong;
	cvTong.n = n>CV.n ? n : CV.n;
	for (int i = 0; i<cvTong.n; i++)
		cvTong.size[i] = size[i] + CV.size[i];
	return cvTong;
}
CVector CVector::operator-(CVector CV)
{
	CVector cvHieu;
	cvHieu.n = n>CV.n ? n : CV.n;
	for (int i = 0; i<cvHieu.n; i++)
		cvHieu.size[i] = size[i] - CV.size[i];
	return cvHieu;
}
int CVector::operator*(CVector CV)
{
	CVector cvTichVH;
	int S = 0;
	cvTichVH.n = n>CV.n ? n : CV.n;
	for (int i = 0; i<cvTichVH.n; i++)
	{
		S += size[i] * CV.size[i];
	}
	return S;
}