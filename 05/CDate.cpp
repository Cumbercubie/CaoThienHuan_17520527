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
void CDate::IncreaseDay(CDate &Date)
{
	Date.iNgay++;
	if (Date.iNgay > Date.DayinMonth())
	{
		if (Date.iThang == 12)
		{
			Date.iThang = 1;
			Date.iNgay = 1;
			Date.iNam++;
		}
		else
		{
			Date.iNgay = 1;
			Date.iThang++;
		}
	}
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
		IncreaseDay(Date);
	}
	return Date;
}
CDate CDate::operator-(int iSoNgay)
{
	CDate Date(*this);
	for (int i=0;i<iSoNgay;i++)
		DecreaseDay(Date);

	return Date;
}

CDate CDate::operator++(int)
{
	IncreaseDay(*this);
	return *this;
}
void CDate::DecreaseDay(CDate &Date)
{
	if (Date.iNgay <= 1)
	{
		if (Date.iThang == 1)
		{
			Date.iThang = 12;
			Date.iNgay = Date.DayinMonth();
			Date.iNam -= 1;
		}
		else
		{
			Date.iThang -= 1;
			Date.iNgay = Date.DayinMonth();
		}
	}
	else
		Date.iNgay--;
}
CDate CDate::operator--(int)
{
	DecreaseDay(*this);
	return *this;
}