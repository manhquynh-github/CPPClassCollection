#pragma once
#include <iostream>
class Date
{
private:
	int iDay, iMonth, iYear;
	bool IsLeapYear(int iyear) const;
	int DaysOfMonth(int imonth, int iyear) const;
	bool IsValid(int iday, int imonth, int iyear) const;
public:
	Date();
	Date(int iday, int imonth, int iyear);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	Date operator+(const int &iday) const;
	Date operator-(const int &iday) const;
	long operator-(const Date &date) const;
	Date& operator++();
	Date& operator--();

	friend std::istream& operator>>(std::istream& in, Date &d);
	friend std::ostream& operator<<(std::ostream& out, const Date &d);

	~Date();
};

