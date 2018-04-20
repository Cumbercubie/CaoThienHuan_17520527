#include <iostream>
#include "stdafx.h"
#include <conio.h>
#include "SoPhuc.h"

using namespace std;

int main()
{
	SoPhuc sp1,sp2;
	cout << " Nhap so phuc 1: ";
	cin >> sp1;
	cout << sp1;
	cout << "\nNhap so phuc 2: ";
	cin >> sp2;
	cout << "\nSo phuc 2 " << sp2;
	SoPhuc Tong;
	Tong = sp1 - sp2;
	cout << "\nTong " << Tong;
	if (sp1 < sp2)
		cout << "\nSp1 < Sp2";
	if (sp1 == sp2)
		cout << "\nSp1 = sp2";
	if (sp1 > sp2)
		cout << "\nsp1 > sp2\n";
	if (sp1 != sp2)
		cout << "\nsp1<>sp2\n";
	system("pause");
	return 0;
}