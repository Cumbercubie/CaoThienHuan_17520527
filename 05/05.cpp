// 05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CDate.h"
using namespace std;

int main()
{
	CDate Date,Date1;
	cout << "INPUT DATE: \n";
	cin >> Date;
	Date=Date-2;
	cout << Date;
	system("pause");
    return 0;
}

