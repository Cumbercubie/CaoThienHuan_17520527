#include <iostream>
#include "stdafx.h"
#include "Time.h"
using namespace std;


Time::Time()
{
	iGio = 0;
	iPhut = 0;
	iGiay = 0;
}


Time::~Time()
{
}
istream& operator>> (istream& is, Time& t)
{
	cout << "\nNhap gio:";
	is >> t.iGio;
	cout << "\nNhap phut:";
	is >> t.iPhut;
	cout << "\nNhap giay:";
	is >> t.iGiay;
	return is;
}

ostream& operator<< (ostream &os, Time& t)
{
	cout << t.iGio << " gio " << t.iPhut << " phut " << t.iGiay << " giay.";
	return os;
}
Time Time::operator+(const int &x)
{
	Time tg;
	int a, b;
	a = (iGiay + x) / 60;
	tg.iGiay = (iGiay + x) % 60;
	b = (iPhut + a) / 60;
	tg.iPhut = (iPhut + a) % 60;
	tg.iGio = b + iGio;
	return tg;
}

Time Time::operator-(const int &x)
{
	Time tg;
	int a, b;
	a = iGiay - x < 0 ? -1 : 0;
	tg.iGiay = (a == -1) ? 60 + iGiay - x : iGiay - x;
	b = (iPhut + a) < 0 ? -1 : 0;
	tg.iPhut = (b == -1) ? 60 + iPhut + a : iPhut + a;
	tg.iGio = b + iGio;
	if (tg.iGio < 0)
	{
		a = -(iGiay - x) ? -1 : 0;
		tg.iGiay = (a == -1) ? 60 - iGiay + x : -iGiay + x;
		b = (-iPhut + a) < 0 ? -1 : 0;
		tg.iPhut = (b == -1) ? 60 - iPhut + a : -iPhut + a;
		tg.iGio = -b + iGio;
		if (tg.iGio == 0)
		{
			if (tg.iPhut != 0) tg.iPhut = 0 - tg.iPhut;
			else if (tg.iGiay != 0) tg.iGiay = 0 - tg.iGiay;
		}
		return tg;
	}
	return tg;
}

Time &Time::operator++ ()
{
	Time tg;
	int a, b;
	a = (iGiay + 1) / 60;
	tg.iGiay = (iGiay + 1) % 60;
	b = (iPhut + a) / 60;
	tg.iPhut = (iPhut + a) % 60;
	tg.iGio = iGio + b;
	iGiay = tg.iGiay;
	iPhut = tg.iPhut;
	iGio = tg.iGio;
	return tg;
}

Time &Time::operator-- ()
{
	Time tg;
	int a, b;
	a = iGiay - 1 < 0 ? -1 : 0;
	tg.iGiay = (a == -1) ? 60 + iGiay - 1 : iGiay - 1;
	b = iPhut + a < 0 ? -1 : 0;
	tg.iPhut = (a == -1) ? 60 + iPhut + a : iPhut + a;
	tg.iGio = b + iGio;
	if (tg.iGio < 0)
	{
		a = -(iGiay - 1) < 0 ? -1 : 0;
		tg.iGiay = (a == -1) ? 60 - iGiay + 1 : -iGiay + 1;
		b = -iPhut + a < 0 ? -1 : 0;
		tg.iPhut = (a == -1) ? 60 - iPhut + a : -iPhut + a;
		tg.iGio = -b + iGio;
		if (tg.iGio == 0)
		{
			if (tg.iPhut != 0) tg.iPhut = 0 - tg.iPhut;
			else if (tg.iGiay != 0) tg.iGiay = 0 - tg.iGiay;
		}
		iGio = tg.iGio;
		iPhut = tg.iPhut;
		iGiay = tg.iGiay;
	}
	iGio = tg.iGio;
	iPhut = tg.iPhut;
	iGiay = tg.iGiay;

}
