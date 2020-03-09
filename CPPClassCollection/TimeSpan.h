#pragma once
class TimeSpan
{
protected:
	int D, H, M, S;
	void Convert();
public:
	TimeSpan();
	TimeSpan(int s);
	TimeSpan(int m, int s);
	TimeSpan(int h, int m, int s);
	TimeSpan(int d, int h, int m, int s);

	int getDay() const;
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void setDay(int d);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	TimeSpan operator+(const TimeSpan &t2) const;
	TimeSpan operator-(const TimeSpan &t2) const;
	
	bool operator>(const TimeSpan &t2) const;
	bool operator<(const TimeSpan &t2) const;
	bool operator==(const TimeSpan &t2) const;
	bool operator>=(const TimeSpan &t2) const;
	bool operator<=(const TimeSpan &t2) const;
	bool operator!=(const TimeSpan &t2) const;

	unsigned long ToSecond() const;

	~TimeSpan();
};

