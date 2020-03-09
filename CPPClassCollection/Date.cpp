#include "Date.h"
#include "stdio.h"
#define abs(a) ((a >= 0) ? a : -a)
using namespace std;


bool Date::IsLeapYear(int iyear) const
{
	if ((iyear % 100 != 0 && iyear % 4 == 0) || (iyear % 100 == 0 && iyear % 400 == 0))
		return true;
	return false;
}

int Date::DaysOfMonth(int imonth, int iyear) const
{
	if (imonth > 0 && imonth <= 12)
	{
		switch (imonth)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 2:
			if (IsLeapYear(iyear) == true)
				return 29;
			return 28;
			break;
		default:
			return 30;
			break;
		}
	}

	cout << "ERR: Month number out of range.";
	return -1;
}

bool Date::IsValid(int iday, int imonth, int iyear) const
{
	if (iday < 0 || imonth < 0 || iyear < 0)
		return false;
	if (iday > DaysOfMonth(imonth, iyear))
		return false;
	return true;
}

Date::Date()
{
	iDay = iMonth = iYear = 1;
}

Date::Date(int iday, int imonth, int iyear)
{
	if (IsValid(iday, imonth, iyear) == true)
	{
		iDay = iday;
		iMonth = imonth;
		iYear = iyear;
	}
	else
		cout << "ERR: Invalid date constructing.";
}

int Date::getDay() const
{
	return iDay;
}

int Date::getMonth() const
{
	return iMonth;
}

int Date::getYear() const
{
	return iYear;
}

Date Date::operator+(const int &iday) const
{
	Date result(iDay, iMonth, iYear);
	int k = iday;
	while (k > 0)
	{
		++result;
		k--;
	}

	return result;
}

Date Date::operator-(const int &iday) const
{
	Date result(iDay, iMonth, iYear);

	int k = iday;
	while (k > 0)
	{
		--result;
		k--;
	}

	return result;
}

long Date::operator-(const Date &date) const
{
	Date date1 = *this, date2 = date, t;

	long days = 0;

	if (date1.getYear() != date2.getYear())
	{
		if (date1.getYear() > date2.getYear())
		{
			t = date1;
			date1 = date2;
			date2 = t;
		}

		days += (date1 - Date(31, 12, date1.getYear())) + (date2 - Date(1, 1, date2.getYear())) + 2;
		for (int i = date1.getYear() + 1; i < date2.getYear(); i++)
			days += (IsLeapYear(i) ? 366 : 365);
		return days;
	}

	if (date1.getMonth() > date2.getMonth())
	{
		t = date1;
		date1 = date2;
		date2 = t;
	}

	for (int i = date1.getMonth() + 1; i < date2.getMonth(); i++)
		days += DaysOfMonth(i, date2.getYear());

	if (date1.getMonth() == date2.getMonth())
		days += abs(date2.getDay() - date1.getDay());
	else
		days += DaysOfMonth(date1.getMonth(), date2.getYear()) - date1.getDay() + date2.getDay();

	return days;
}

Date& Date::operator++()
{
	iDay += 1;

	if (iDay > DaysOfMonth(iMonth, iYear))
	{
		iDay = 1;
		iMonth += 1;
		if (iMonth > 12)
		{
			iYear += 1;
			iMonth = 1;
		}
	}

	return *this;
}

Date& Date::operator--()
{
	iDay -= 1;

	if (iDay == 0)
	{
		iMonth -= 1;

		if (iMonth == 0)
		{
			iYear -= 1;
			iMonth = 12;
		}

		iDay = DaysOfMonth(iMonth, iYear);
	}

	return *this;
}

std::ostream & operator << (std::ostream & out, const Date & d)
{
	printf("%d/%d/%d", d.getDay(), d.getMonth(), d.getYear());
}

std::istream & operator >> (std::istream & in, Date & d)
{
	do
	{
		cout << "\nNhap ngay thang nam hop le:";
		cin >> d.iDay >> d.iMonth >> d.iYear;
	} while (d.IsValid(d.iDay, d.iMonth, d.iYear) == false);
	return in;
}

Date::~Date()
{
}
