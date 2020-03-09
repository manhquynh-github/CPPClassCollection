#include "Time.h"
#include "stdio.h"
using namespace std;

Time::~Time()
{
}

int Time::getHour() const
{
  return H;
}

int Time::getMinute() const
{
  return M;
}

int Time::getSecond() const
{
  return S;
}

Time Time::operator+(const int & i) const
{
  Time t(H, M, S + i);
  t.Convert();
  return t;
}

Time Time::operator-(const int & i) const
{
  if (ToSecond() <= (long)i)
    return Time(0);

  TimeSpan t(ToSecond() - (long)i);

  return Time(t.getHour(), t.getMinute(), t.getSecond());
}

TimeSpan Time::operator-(const Time & t) const
{
  return TimeSpan(ToSecond() - t.ToSecond());
}

Time & Time::operator++()
{
  *this = *this + 1;
  return *this;
}

Time & Time::operator--()
{
  *this = *this - 1;
  return *this;
}

Time & Time::operator++(int a)
{
  Time t = *this;
  ++*this;
  return t;
}

Time & Time::operator--(int a)
{
  Time t = *this;
  --*this;
  return t;
}

std::istream & operator >> (std::istream & in, Time & t)
{
  t.D = 0;
  cout << "H = "; cin >> t.H;
  cout << "M = "; cin >> t.M;
  cout << "S = "; cin >> t.S;
  t.Convert();

  return in;
}

std::ostream & operator<<(std::ostream & out, const Time & t)
{
  printf_s("%d:%02d:%02d", t.getHour(), t.getMinute(), t.getSecond());
  return out;
}
