#include "stdafx.h"
#include <iostream>
#include "CString.h"
using namespace std;
CString::CString(const char*x)
{
	int l=0;
	while ((x[l])!='\0')
		l++;
	iLeng=l;
	s=new char[iLeng];
	for (int i=0;i<iLeng;i++)
		s[i]=x[i];
	
}
CString::CString(int l)
{
	this->iLeng=l;
	s=new char[l];
}
CString::CString(const CString& x)
{
	iLeng=x.iLeng;
	s = new char[iLeng];
	for (int i=0;i<iLeng;i++)
		s[i]=x.s[i];
}
CString::~CString()
{}
CString operator+(CString s1,CString s2)
{
	CString temp(s1.iLeng+s2.iLeng);
	for (int i=0;i<s1.iLeng;i++)
		temp.s[i]=s1.s[i];
	for (int i=0;i<s2.iLeng;i++)
		temp.s[s1.iLeng+i]=s2.s[i];
	return temp;
}
CString &CString::operator=(const CString& x)
{
	CString y(x);
	return y;
}
ostream& operator<<(ostream& os, CString x)
{
	for (int i=0;i<x.iLeng;i++)
	{
		os << x.s[i];
	}
	return os;
}
bool CString::operator==(const CString& x)
{
	for (int i=0;i<x.iLeng;i++)
	{
		if (s[i]!=x.s[i])
			return false;
	}
	return true;
}
bool CString::operator!=(const CString& x)
{
	return !operator==(x);
}
bool CString::operator>=(const CString& x)
{
	if (iLeng >= x.iLeng)
		return true;
	return false;
}
bool CString::operator<(const CString& x)
{
	return !operator>=(x);
}
bool CString::operator<=(const CString& x)
{
    for(int i=0; i<x.iLeng; i++)
        if(s[i] > x.s[i])
            return false;
    return true;
}
bool CString::operator>(const CString& x)
{
	return !operator<=(x);
}