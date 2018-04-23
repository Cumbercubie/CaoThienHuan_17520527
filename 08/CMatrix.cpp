#include "stdafx.h"
#include <iostream>
#include "CMatrix.h"
#include "CVector.h"
#include <cstdlib>
using namespace std;
CMatrix::CMatrix()
{
	for (int i = 1; i <10; i++)
		for (int j = 1; j <10; j++)
			a[i][j] = 0;
}
CMatrix::CMatrix(int x, int y)
{
	for (int i = 1; i <x; i++)
		for (int j = 1; j <y; j++)
			a[i][j] = 0;
}
CMatrix operator*(const CMatrix &mt, const CVector& vt)
{
	CMatrix mtTich;
	for (int i = 1; i <= mt.iCot; i++)
	{
		for (int j = 1; j <= vt.n; j++)
		{
			mtTich.a[i][j] += mt.a[i][j] * vt.size[i];
		}
	}
	return mtTich;
}
void CMatrix::Nhap()
{
	cout << "Nhap so hang ma tran ";
	cin >> iCot;
	cin.ignore(1);
	cout << "Nhap so cot ma tran";
	cin >> iHang;
	for (int i = 0; i<iCot; i++)
		for (int j = 0; j<iHang; j++)
		{
			cout << "nhap a[" << i << "," << j << "]";
			cin >> a[i][j];
		}
}
istream& operator>> (istream& is, CMatrix& MT)
{
	MT.Nhap();
	return is;
}
ostream& operator<< (ostream& os, CMatrix& MT)
{
	for (int i = 0; i<MT.iCot; i++)
	{
		for (int j = 0; j<MT.iHang; j++)
			os << "a[" << i << "," << j << "]: " << MT.a[i][j] << "\t";
		os << endl;
	}
	return os;
}
CMatrix CMatrix::operator+ (CMatrix mtB)
{
	CMatrix mtTong;
	mtTong.iCot = iCot > mtB.iCot ? iCot : mtB.iCot;
	mtTong.iHang = iHang > mtB.iHang ? iHang : mtB.iHang;
	for (int i = 0; i < mtTong.iCot; i++)
		for (int j = 0; j < mtTong.iHang; j++)
			mtTong.a[i][j] = a[i][j] + mtB.a[i][j];
	return mtTong;
}
CMatrix CMatrix::operator-(CMatrix mtB)
{
	CMatrix mtHieu;
	mtHieu.iCot = iCot > mtB.iCot ? iCot : mtB.iCot;
	mtHieu.iHang = iHang > mtB.iHang ? iHang : mtB.iHang;
	for (int i = 0; i < mtHieu.iCot; i++)
		for (int j = 0; j < mtHieu.iHang; j++)
			mtHieu.a[i][j] = a[i][j] - mtB.a[i][j];
	return mtHieu;
}
CMatrix CMatrix::operator*(CMatrix mtB)
{
	CMatrix mtTich;
	if (iHang == mtB.iCot)
		for (int i = 0; i < iCot; i++)
			for (int j = 0; j < mtB.iCot; j++)
				mtTich.a[i][j] += a[i][j] * mtB.a[i][j];
	return mtTich;
}
CMatrix CMatrix::operator=(CMatrix mtB)
{
	iCot = mtB.iCot;
	iHang = mtB.iHang;
	for (int i = 0; i<iCot; i++)
		for (int j = 0; j<iHang; j++)
			a[i][j] = mtB.a[i][j];
	return (*this);
}