#include "Fraction.h"
#include <cmath>
#include <iostream>
using namespace std;

Fraction::Fraction(int iTu, int iMau)
{
  this->iTu = iTu;
  if (iMau != 0) this->iMau = iMau;
}

void Fraction::Nhap()
{
  cout << "Nhap phan so:" << endl;
  cout << "Tu so: ";
  cin >> iTu;
  cout << "Mau so: ";
  cin >> iMau;
}

void Fraction::Xuat()
{
  if (iMau < 0)
  {
    iMau *= -1;
    iTu *= -1;
  }
  cout << iTu;
  if (iMau != 1) cout << "/" << iMau;
}

int Fraction::getTu() const
{
  return iTu;
}

void Fraction::setTu(int iTu)
{
  this->iTu = iTu;
}

int Fraction::getMau() const
{
  return iMau;
}

void Fraction::setMau(int iMau)
{
  this->iMau = iMau;
}

int Fraction::UCLN(int a, int b) const
{
  a = abs(a); b = abs(b);
  while (a*b > 0)
  {
    if (a > b) a -= b;
    else b -= a;
  }
  return (a + b);
}

int Fraction::BCNN(int a, int b) const
{
  return(abs(a * b) / UCLN(a, b));
}

Fraction::Fraction()
{
  iTu = 0;
  iMau = 1;
}

Fraction::Fraction(int iTu)
{
  this->iTu = iTu;
  iMau = 1;
}

Fraction Fraction::RutGon()
{
  if (iMau < 0)
  {
    iMau *= -1;
    iTu *= -1;
  }
  int x = UCLN(iTu, iMau);
  if (x != 0) return Fraction(iTu / x, iMau / x);
}

Fraction Fraction::QuyDong(const Fraction &f) const
{
  int x = BCNN(iMau, f.iMau);
  if (x != 0) return Fraction(iTu * (x / iMau), x);
}

Fraction Fraction::Cong(const Fraction &f) const
{
  return Fraction(iTu * f.iMau + iMau * f.iTu, iMau * f.iMau).RutGon();
}

Fraction Fraction::Tru(const Fraction &f) const
{
  return Fraction(iTu * f.iMau - iMau * f.iTu, iMau * f.iMau).RutGon();
}

Fraction Fraction::Nhan(const Fraction &f) const
{
  return Fraction(iTu * f.iTu, iMau * f.iMau).RutGon();
}

Fraction Fraction::Chia(const Fraction &f) const
{
  return Fraction(iTu * f.iMau, iMau * f.iTu).RutGon();
}

int Fraction::SoSanh(const Fraction &f) const
{
  if (iTu * f.iMau > iMau * f.iTu) return 1;
  if (iTu * f.iMau == iMau * f.iTu) return 0;
  return -1;
}

bool Fraction::ToiGian() const
{
  Fraction x = *this;
  x = x.RutGon();
  if (x.iMau == iMau) return true;
  return false;
}

float Fraction::ToFloat() const
{
  return (float)iTu / (float)iMau;
}

Fraction Fraction::operator+(const Fraction & f2) const
{
  return this->Cong(f2);
}

Fraction Fraction::operator-(const Fraction & f2) const
{
  return this->Tru(f2);
}

Fraction Fraction::operator*(const Fraction & f2) const
{
  return this->Nhan(f2);
}

Fraction Fraction::operator/(const Fraction & f2) const
{
  return this->Chia(f2);
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
  *this = this->Cong(f2);
  return *this;
}

Fraction & Fraction::operator-=(const Fraction & f2)
{
  *this = this->Tru(f2);
  return *this;
}

Fraction & Fraction::operator*=(const Fraction & f2)
{
  *this = this->Nhan(f2);
  return *this;
}

Fraction & Fraction::operator/=(const Fraction & f2)
{
  *this = this->Chia(f2);
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
  if (this->SoSanh(f2) == 1)
    return true;
  return false;
}

bool Fraction::operator<(const Fraction & f2) const
{
  if (this->SoSanh(f2) == -1)
    return true;
  return false;
}

bool Fraction::operator==(const Fraction & f2) const
{
  if (this->SoSanh(f2) == 0)
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
  if (this->SoSanh(f2) != 0)
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
  out << f.getTu();
  if (f.getMau() != 1) out << "/" << f.getMau();
  return out;
}

std::istream & operator >> (std::istream & in, Fraction & f)
{
  f.Nhap();
  return in;
}
