// 06.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include "CString.h"
using namespace std;

int main()
{
	CString str("Cao");
	CString str1(str);
	CString strTong = str + str1;
	cout << str1;
	system("pause");
    return 0;
}

