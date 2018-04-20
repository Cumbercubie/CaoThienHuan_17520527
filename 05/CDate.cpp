#include "stdafx.h"
#include <iostream>
#include "CDate.h"

CDate::CDate()
{
	//ctor
}
CDate::CDate(const CDate &Date)
{
	iNgay = Date.iNgay;
	iThang = Date.iThang;
	iNam = Date.iNam;
}
CDate::CDate(int x = 1, int y = 1, int z = 1999)
{
	iNgay = x;
	iThang = y;
	iNam = z;
}
CDate::~CDate()
{
	//dtor
}
bool CDate::isNhuan()
{
	if (iThang % 4 == 0 && iThang % 100 != 0 && iThang % 400 != 0)
		return true;
	else
		return false;
}
int CDate::DayinMonth()
{
	if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12)
		return 31;
	else
		if (iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11)
			return 30;
		else
		{
			if (this->isNhuan() == true)
				return 29;
			else return 28;
		}
}
bool CDate::isDayMax()
{
	if (iNgay>this->DayinMonth())
		return true;
	else return false;
}
istream& operator>>(istream& is, CDate& Date)
{
	is >> Date.iNgay >> Date.iThang >> Date.iNam;
	return is;
}
ostream& operator<<(ostream& os, CDate& Date)
{
	os << Date.iNgay << "/" << Date.iThang << "/" << Date.iNam;
	return os;
}
CDate CDate::operator+(int iSoNgay)
{
	CDate Date(*this);
	for (int i = 0; i < iSoNgay; i++)
	{
		IncreaseDay();
		if (Date.isDayMax() == true)
		{
			Date.iThang += 1;
			Date.iNgay += 1;
		}
		if (iThang == 12)
		{
			Date.iNam += 1;
			Date.iThang = 1;
			Date.iNgay = 1;
		}
	}
	return Date;
}
CDate CDate::operator-(int iSoNgay)
{
	CDate Date(*this);
	if (Date.iNgay <= iSoNgay)
	{
		Date.iThang -= 1;
		Date.iNgay = Date.DayinMonth() - (iSoNgay - Date.iNgay);
	}
	else
	{
		Date.iNgay -= iSoNgay;
	}
	return Date;
}
void CDate::IncreaseDay()
{
	iNgay++;
	if (iNgay == this->DayinMonth())
	{
		if (iThang == 12)
		{
			iThang = 1;
			iNgay = 1;
			iNam++;
		}
		else
		{
			iNgay = 1;
			iThang++;
		}
	}
}
CDate CDate::operator++(int)
{
	IncreaseDay();
	return *this;
}
void CDate::DecreaseDay()
{
	if (iNgay == 1)
	{
		iThang -= 1;
		iNgay = this->DayinMonth();
	}
	else
		iNgay--;
}
CDate CDate::operator--(int)
{
	DecreaseDay();
	return *this;
}