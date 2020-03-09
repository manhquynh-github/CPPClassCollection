#include "TimeSpan.h"
#define abs(a) ((a >= 0) ? a : -a)


void TimeSpan::Convert()
{
	M += S / 60;
	S %= 60;
	H += M / 60;
	M %= 60;
	D += H / 24;
	H %= 24;
}

TimeSpan::TimeSpan()
{
	D = H = M = S = 0;
}

TimeSpan::TimeSpan(int s)
{
	D = H = M = 0;
	S = s;
	Convert();
}

TimeSpan::TimeSpan(int m, int s)
{
	D = H = 0;
	M = m;
	S = s;
	Convert();
}

TimeSpan::TimeSpan(int h, int m, int s)
{
	D = 0;
	H = h;
	M = m;
	S = s;
	Convert();
}

TimeSpan::TimeSpan(int d, int h, int m, int s)
{
	D = d;
	H = h;
	M = m;
	S = s;
	Convert();
}

int TimeSpan::getDay() const
{
	return D;
}

int TimeSpan::getHour() const
{
	return H;
}

int TimeSpan::getMinute() const
{
	return M;
}

int TimeSpan::getSecond() const
{
	return S;
}

void TimeSpan::setDay(int d)
{
	if (d > 0)
	{
		D = d;
		Convert();
	}
}

void TimeSpan::setHour(int h)
{
	if (h > 0)
	{
		H = h;
		Convert();
	}
}

void TimeSpan::setMinute(int m)
{
	if (m > 0)
	{
		M = m;
		Convert();
	}
}

void TimeSpan::setSecond(int s)
{
	if (s > 0)
	{
		S = s;
		Convert();
	}
}

TimeSpan TimeSpan::operator+(const TimeSpan & t2) const
{
	TimeSpan s(D + t2.getDay(), H + t2.getHour(), M + t2.getMinute(), S + t2.getMinute());
	return s;
}

TimeSpan TimeSpan::operator-(const TimeSpan & t2) const
{
	TimeSpan s(abs(ToSecond() - t2.ToSecond()));
	return s;
}

bool TimeSpan::operator>(const TimeSpan & t2) const
{
	return ToSecond() > t2.ToSecond();
}

bool TimeSpan::operator<(const TimeSpan & t2) const
{
	return ToSecond() < t2.ToSecond();
}

bool TimeSpan::operator==(const TimeSpan & t2) const
{
	return ToSecond() == t2.ToSecond();
}

bool TimeSpan::operator>=(const TimeSpan & t2) const
{
	return ToSecond() >= t2.ToSecond();
}

bool TimeSpan::operator<=(const TimeSpan & t2) const
{
	return ToSecond() <= t2.ToSecond();
}

bool TimeSpan::operator!=(const TimeSpan & t2) const
{
	return ToSecond() != t2.ToSecond();
}

unsigned long TimeSpan::ToSecond() const
{
	return D * 86400 + H * 3600 + M * 60 + S;
}

TimeSpan::~TimeSpan()
{
}
