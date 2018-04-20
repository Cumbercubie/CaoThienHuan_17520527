#pragma once
#include <iostream>
using namespace std;

class SoPhuc
{
private:
	int iThuc;
	int iAo;
public:
	SoPhuc();
	SoPhuc(int,int);
	~SoPhuc();
	float Module();
	friend istream& operator>>(istream&, SoPhuc&);
	friend ostream& operator<<(ostream&, SoPhuc&);
	SoPhuc operator+ (SoPhuc );
	SoPhuc operator- (SoPhuc );
	SoPhuc operator* (SoPhuc );
	SoPhuc operator/ (SoPhuc );
	bool operator== (SoPhuc );
	bool operator!= (SoPhuc ) ;
	bool operator<= (SoPhuc ) ;
	bool operator< (SoPhuc ) ;
	bool operator>= (SoPhuc ) ;
	bool operator> (SoPhuc ) ;
	SoPhuc operator=(SoPhuc);
};

