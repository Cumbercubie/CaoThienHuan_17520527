// 08.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CVector.h"
using namespace std;
int main()
{
	CVector vt,vt1;
	cout << "nhap vector 1\n";
	cin >> vt;
	cout << vt;
	cout << "Nhap vector 2\n";
	cin >> vt1;
	cout << vt1;
	CVector vtTong = vt + vt;
	CVector vtHieu = vt - vt;
	cout << vtHieu ;
	system("pause");
    return 0;
}

