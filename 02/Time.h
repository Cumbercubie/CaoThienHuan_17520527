#pragma once
#include <iostream>
using namespace std;
class Time
{

private:
	int iGio;
	int iPhut;
	int iGiay;
public:
	Time();
	~Time();
	friend istream& operator>>(istream&, Time&);
	friend ostream& operator<<(ostream&, Time&);
	Time operator+ (const int&);
	Time operator- (const int&);
	Time &operator++();
	Time &operator--();
};

};

