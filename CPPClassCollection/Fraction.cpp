#include "Fraction.h"
#include <cmath>
#include <iostream>
using namespace std;

Fraction::Fraction(int iNumerator, int iDenominator)
{
  this->iNumerator = iNumerator;
  if (iDenominator != 0) this->iDenominator = iDenominator;
}

void Fraction::Input()
{
  cout << "Nhap phan so:" << endl;
  cout << "Tu so: ";
  cin >> iNumerator;
  cout << "Mau so: ";
  cin >> iDenominator;
}

void Fraction::Output()
{
  if (iDenominator < 0)
  {
    iDenominator *= -1;
    iNumerator *= -1;
  }
  cout << iNumerator;
  if (iDenominator != 1) cout << "/" << iDenominator;
}

int Fraction::getNumerator() const
{
  return iNumerator;
}

void Fraction::setNumerator(int iNumerator)
{
  this->iNumerator = iNumerator;
}

int Fraction::getDenominator() const
{
  return iDenominator;
}

void Fraction::setDenominator(int iDenominator)
{
  this->iDenominator = iDenominator;
}

int Fraction::GCD(int a, int b) const
{
  a = abs(a); b = abs(b);
  while (a*b > 0)
  {
    if (a > b) a -= b;
    else b -= a;
  }
  return (a + b);
}

int Fraction::LCM(int a, int b) const
{
  return(abs(a * b) / GCD(a, b));
}

Fraction::Fraction()
{
  iNumerator = 0;
  iDenominator = 1;
}

Fraction::Fraction(int iNumerator)
{
  this->iNumerator = iNumerator;
  iDenominator = 1;
}

Fraction Fraction::getSimplified()
{
  if (iDenominator < 0)
  {
    iDenominator *= -1;
    iNumerator *= -1;
  }
  int x = GCD(iNumerator, iDenominator);
  if (x != 0) return Fraction(iNumerator / x, iDenominator / x);
}

Fraction Fraction::QuyDong(const Fraction &f) const
{
  int x = LCM(iDenominator, f.iDenominator);
  if (x != 0) return Fraction(iNumerator * (x / iDenominator), x);
}

Fraction Fraction::Add(const Fraction &f) const
{
  return Fraction(iNumerator * f.iDenominator + iDenominator * f.iNumerator, iDenominator * f.iDenominator).getSimplified();
}

Fraction Fraction::Subtract(const Fraction &f) const
{
  return Fraction(iNumerator * f.iDenominator - iDenominator * f.iNumerator, iDenominator * f.iDenominator).getSimplified();
}

Fraction Fraction::Multiply(const Fraction &f) const
{
  return Fraction(iNumerator * f.iNumerator, iDenominator * f.iDenominator).getSimplified();
}

Fraction Fraction::Divide(const Fraction &f) const
{
  return Fraction(iNumerator * f.iDenominator, iDenominator * f.iNumerator).getSimplified();
}

int Fraction::CompareTo(const Fraction &f) const
{
  if (iNumerator * f.iDenominator > iDenominator * f.iNumerator) return 1;
  if (iNumerator * f.iDenominator == iDenominator * f.iNumerator) return 0;
  return -1;
}

bool Fraction::IsSimplified() const
{
  Fraction x = *this;
  x = x.getSimplified();
  if (x.iDenominator == iDenominator) return true;
  return false;
}

float Fraction::ToFloat() const
{
  return (float)iNumerator / (float)iDenominator;
}

Fraction Fraction::operator+(const Fraction & f2) const
{
  return this->Add(f2);
}

Fraction Fraction::operator-(const Fraction & f2) const
{
  return this->Subtract(f2);
}

Fraction Fraction::operator*(const Fraction & f2) const
{
  return this->Multiply(f2);
}

Fraction Fraction::operator/(const Fraction & f2) const
{
  return this->Divide(f2);
}

Fraction Fraction::operator+(const int & i) const
{
  return *this + Fraction(i);
}

Fraction Fraction::operator-(const int & i) const
{
  return *this - Fraction(i);
}

Fraction Fraction::operator*(const int & i) const
{
  return *this * Fraction(i);
}

Fraction Fraction::operator/(const int & i) const
{
  return *this / Fraction(i);
}

Fraction & Fraction::operator+=(const Fraction & f2)
{
  *this = this->Add(f2);
  return *this;
}

Fraction & Fraction::operator-=(const Fraction & f2)
{
  *this = this->Subtract(f2);
  return *this;
}

Fraction & Fraction::operator*=(const Fraction & f2)
{
  *this = this->Multiply(f2);
  return *this;
}

Fraction & Fraction::operator/=(const Fraction & f2)
{
  *this = this->Divide(f2);
  return *this;
}

Fraction & Fraction::operator+=(const int & i)
{
  *this = *this + i;
  return *this;
}

Fraction & Fraction::operator-=(const int & i)
{
  *this = *this - i;
  return *this;
}

Fraction & Fraction::operator*=(const int & i)
{
  *this = *this * i;
  return *this;
}

Fraction & Fraction::operator/=(const int & i)
{
  *this = *this / i;
  return *this;
}

Fraction & Fraction::operator++(int)
{
  Fraction f = *this;
  *this += 1;
  return f;
}

Fraction & Fraction::operator++()
{
  *this += 1;
  return *this;
}

Fraction & Fraction::operator--(int)
{
  Fraction f = *this;
  *this -= 1;
  return f;
}

Fraction & Fraction::operator--()
{
  *this -= 1;
  return *this;
}

bool Fraction::operator>(const Fraction & f2) const
{
  if (this->CompareTo(f2) == 1)
    return true;
  return false;
}

bool Fraction::operator<(const Fraction & f2) const
{
  if (this->CompareTo(f2) == -1)
    return true;
  return false;
}

bool Fraction::operator==(const Fraction & f2) const
{
  if (this->CompareTo(f2) == 0)
    return true;
  return false;
}

bool Fraction::operator>=(const Fraction & f2) const
{
  if (*this > f2 || *this == f2)
    return true;
  return false;
}

bool Fraction::operator<=(const Fraction & f2) const
{
  if (*this < f2 || *this == f2)
    return true;
  return false;
}

bool Fraction::operator!=(const Fraction & f2) const
{
  if (this->CompareTo(f2) != 0)
    return true;
  return false;
}

bool Fraction::operator>(const int & i) const
{
  return *this > Fraction(i);
}

bool Fraction::operator<(const int & i) const
{
  return *this < Fraction(i);
}

bool Fraction::operator==(const int & i) const
{
  return *this == Fraction(i);
}

bool Fraction::operator>=(const int & i) const
{
  return *this >= Fraction(i);
}

bool Fraction::operator<=(const int & i) const
{
  return *this <= Fraction(i);
}

bool Fraction::operator!=(const int & i) const
{
  return *this != Fraction(i);
}

bool Fraction::operator>(const float & f) const
{
  return (float)(*this) > f;
}

bool Fraction::operator<(const float & f) const
{
  return (float)(*this) < f;
}

bool Fraction::operator==(const float & f) const
{
  return (float)(*this) == f;
}

bool Fraction::operator>=(const float & f) const
{
  return (float)(*this) >= f;
}

bool Fraction::operator<=(const float & f) const
{
  return (float)(*this) <= f;
}

bool Fraction::operator!=(const float & f) const
{
  return (float)(*this) != f;
}

Fraction Fraction::operator*() const
{
  return *this;
}

Fraction * Fraction::operator&()
{
  return this;
}

Fraction::operator float() const
{
  return ToFloat();
}

Fraction::~Fraction()
{
}

Fraction operator+(const int & i, const Fraction & f)
{
  return Fraction(i) + f;
}

Fraction operator-(const int & i, const Fraction & f)
{
  return Fraction(i) - f;
}

Fraction operator*(const int & i, const Fraction & f)
{
  return Fraction(i) * f;
}

Fraction operator/(const int & i, const Fraction & f)
{
  return Fraction(i) / f;
}

std::ostream & operator<<(std::ostream & out, const Fraction & f)
{
  out << f.getNumerator();
  if (f.getDenominator() != 1) out << "/" << f.getDenominator();
  return out;
}

std::istream & operator >> (std::istream & in, Fraction & f)
{
  f.Input();
  return in;
}
