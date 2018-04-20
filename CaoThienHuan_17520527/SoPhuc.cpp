#include <iostream>
#include "stdafx.h"
#include "SoPhuc.h"
using namespace std;

SoPhuc::SoPhuc(int x, int y=0)
{
	iThuc = x;
	iAo = y;
}

SoPhuc::SoPhuc()
{
	iThuc = 0;
	iAo = 0;
}
SoPhuc::~SoPhuc()
{

}
float SoPhuc::Module()
{
	return (float)sqrt(iThuc*iThuc + iAo * iAo);
}

istream& operator>> (istream& is, SoPhuc& spB)
{
	is >> spB.iThuc >> spB.iAo;
	return is;
}
ostream& operator<< (ostream& os, SoPhuc& spB)
{
	os << spB.iThuc << "+" << spB.iAo << "i";
	return os;
}

SoPhuc SoPhuc::operator+ (SoPhuc spB)
{
	SoPhuc Tong(iThuc + spB.iThuc,iAo + spB.iAo);
	return Tong;
}
SoPhuc SoPhuc::operator- (SoPhuc spB)
{
	SoPhuc Hieu(iThuc - spB.iThuc,iAo - spB.iAo);
	return Hieu;
}
SoPhuc SoPhuc:: operator* (SoPhuc spB)
{
	SoPhuc Tich(iThuc * spB.iThuc -iAo*spB.iAo,iThuc*spB.iAo + spB.iAo*spB.iThuc);
	return Tich;
}
SoPhuc SoPhuc::operator/ (SoPhuc spB)
{
	SoPhuc Thuong((iThuc*spB.iThuc + iAo*spB.iAo) / ((spB.iThuc* spB.iThuc) +(spB.iAo* spB.iAo)),(spB.iThuc*iAo - iThuc*spB.iAo)/( (spB.iThuc* spB.iThuc) +(spB.iAo*spB.iAo)));
	return Thuong;
}

bool SoPhuc::operator== (SoPhuc spB)
{
	if ((iThuc == spB.iThuc)&&(iAo==spB.iAo))
		return true;
	return false;
}
bool SoPhuc::operator!= (SoPhuc spB)
{
	if ((iThuc != spB.iThuc)||(iAo!=spB.iAo))
		return true;
	else if ((iThuc == spB.iThuc)&&(iAo==spB.iAo))
		return false;
}
bool SoPhuc:: operator> (SoPhuc spB)
{
	float sp1= this->Module();
	float sp2= spB.Module();
	if (sp1 > sp2)
		return true;
	else 
		return false;
}
bool SoPhuc::operator<(SoPhuc spB)
{
	float sp1 = this->Module();
	float sp2 = spB.Module();
	if (sp1 < sp2)
		return true;
	else 
		return false;
}
bool SoPhuc::operator<=(SoPhuc spB)
{
	float sp1 = this->Module();
	float sp2 = spB.Module();
	if ((sp1 < sp2) || (sp1 == sp2))
		return true;
	else 
		return false;
}
bool SoPhuc::operator>=(SoPhuc spB)
{
	float sp1 = this->Module();
	float sp2 = spB.Module();
	if ((sp1 > sp2) || (sp1 == sp2))
		return true;
	else 
		return false;
}
SoPhuc SoPhuc::operator=(SoPhuc spB)
{
	iThuc = spB.iThuc;
	iAo = spB.iAo;
	return 0;
}
