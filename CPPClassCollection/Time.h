#pragma once
#include "TimeSpan.h"
#include <iostream>
class Time : protected TimeSpan
{
public:
	Time() : TimeSpan() { }
	Time(int s) : TimeSpan(s) { }
	Time(int m, int s) : TimeSpan(m, s) { }
	Time(int h, int m, int s) : TimeSpan(h, m, s) { }
	~Time();

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	Time operator+(const int &i) const;
	Time operator-(const int &i) const;
	TimeSpan operator-(const Time &t) const;
	Time& operator++();
	Time& operator--();
	Time& operator++(int a);
	Time& operator--(int a);

	friend std::istream& operator>>(std::istream& in, Time &t);
	friend std::ostream& operator<<(std::ostream& out, const Time &t);
};

