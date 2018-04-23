#pragma once
#include <iostream>
using namespace std;
class CVector;
class CMatrix
{
private:
	int iHang, iCot;
	long a[10][10];
public:
	CMatrix();
	CMatrix(int, int);
	//CMatrix(CMatrix&);
	void Nhap();
	friend istream& operator>>(istream&, CMatrix&);
	friend ostream& operator<<(ostream&, CMatrix&);
	friend CMatrix operator*(const CMatrix &mt, const CVector& vt);
	CMatrix operator+(CMatrix);
	CMatrix operator*(CMatrix);
	CMatrix operator-(CMatrix);
	CMatrix operator=(CMatrix);
};

