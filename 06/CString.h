#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
class CString
{
private:
	int iLeng;
	char* s;
public:
	CString();
	~CString();
	CString(int);
	CString(const char*);
	CString(const CString&);
	friend CString operator+(CString, CString);
	friend ostream& operator<<(ostream&, CString);
	CString& operator=(const CString&);
	bool operator==(const CString&);
	bool operator!=(const CString&);
	bool operator>=(const CString&);
	bool operator<=(const CString&);
	bool operator>(const CString&);
	bool operator<(const CString&);
};

