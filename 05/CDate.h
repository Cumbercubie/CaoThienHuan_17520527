#include "stdafx.h"
#include <iostream>
using namespace std;

class CDate
{
private:
	int iNgay, iThang, iNam;
public:
	CDate();
	CDate(const CDate&);
	CDate(int, int, int);
	~CDate();
	bool isNhuan();
	bool isDayMax();
	int DayinMonth();
	friend istream& operator>>(istream&, CDate&);
	friend ostream& operator<<(ostream&, CDate&);
	CDate operator+(int);
	CDate operator-(int);
	void IncreaseDay(CDate&);
	void DecreaseDay(CDate&);
	CDate operator++(int);
	CDate operator--(int);
};