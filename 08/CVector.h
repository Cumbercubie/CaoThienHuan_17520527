#pragma once
#include <iostream>
#include "CMatrix.h"
using namespace std;
class CMatrix;
class CVector
{
private:
	int size[100];
	int n;
public:
	CVector();
	~CVector();
	void Nhap();
	friend istream& operator>>(istream&,CVector&);
	friend ostream& operator<<(ostream&, CVector&);
	friend CMatrix operator*(const CMatrix &mt, const CVector& vt);
	CVector operator+(CVector);
	CVector operator-(CVector);
	int operator*(CVector); //TichVoHuong
};


