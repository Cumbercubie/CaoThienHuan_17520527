#include "stdafx.h"
#include <iostream>
#include "CMatrix.h"
#include "CVector.h"
using namespace std;

CMatrix::CMatrix()
{
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			a[i][j] = 0;
}


CMatrix operator*(const CMatrix &mt, const CVector& vt)
{
	CMatrix mtTich;
	for (int i = 1; i <=mt.iCot; i++)
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
	cout << "Nhap so cot ma tran";
	cout << iHang;
	for (int i = 0; i<iCot; i++)
		for (int j = 0; j<iHang; j++)
		{
			cout << "nhap phan tu thu: " << i + 1 << " " << j + 1;
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
	for (int i = 0; i < iCot; i++)
		for (int j = 0; j < iHang; j++)
			mtTong.a[i][j] = a[i][j] + mtB.a[i][j];
	return mtTong;
}
CMatrix CMatrix::operator-(CMatrix mtB)
{
	CMatrix mtHieu;
	for (int i = 0; i < iCot; i++)
		for (int j = 0; j < iHang; j++)
			mtHieu.a[i][j] = a[i][j] - mtB.a[i][j];
	return mtHieu;
}
CMatrix CMatrix::operator*(CMatrix mtB)
{
	CMatrix mtTich;
	if (iHang != mtB.iCot)
	{
		cout << "Can't multiply";
		exit(1);
	}
	else
		for (int i = 0; i < iCot; i++)
			for (int j = 0; j < mtB.iCot; j++)
				mtTich.a[i][j] += a[i][j] * mtB.a[i][j];
	return mtTich;
}