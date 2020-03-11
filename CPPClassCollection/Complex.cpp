#pragma once
#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex()
{
  fReal = fImaginary = Fraction();
}

Complex::Complex(Fraction fReal)
{
  this->fReal = fReal;
  this->fImaginary = Fraction();
}

Complex::Complex(Fraction fReal, Fraction fImaginary)
{
  this->fReal = fReal;
  this->fImaginary = fImaginary;
}

Complex::Complex(int iReal, int iImaginary)
{
  this->fReal = Fraction(iReal);
  this->fImaginary = Fraction(iImaginary);
}

void Complex::Output()
{
  cout << "(";
  fReal.Output();
  cout << ") + (";
  fImaginary.Output();
  cout << ")i";
}

void Complex::Input()
{
  cout << "Inputting a complex number:" << endl;
  cout << "Input Real number:";
  fReal.Input();
  cout << "Input Imaginary number: ";
  fImaginary.Input();
}

Fraction Complex::getReal() const
{
  return fReal;
}

void Complex::setReal(Fraction _fThuc)
{
  fReal = _fThuc;
}

Fraction Complex::getImaginary() const
{
  return fImaginary;
}

void Complex::setImaginary(Fraction _fAo)
{
  fImaginary = _fAo;
}

Complex Complex::Add(const Complex &c) const
{
  return Complex(fReal + c.fReal, fImaginary + c.fImaginary);
}

Complex Complex::Subtract(const Complex &c) const
{
  return Complex(fReal - c.fReal, fImaginary - c.fImaginary);
}

Complex Complex::Multiply(const Complex &c) const
{
  Fraction a1 = this->fReal, b1 = this->fImaginary,
    a2 = c.fReal, b2 = c.fImaginary;

  return Complex((a1 * a2) - (b1 * b2), (a1 * b2) + (a2 * b1));
}

Complex Complex::Divide(const Complex &c) const
{
  Fraction a1 = this->fReal, b1 = this->fImaginary,
    a2 = c.fReal, b2 = c.fImaginary;

  return Complex(((a1 * a2) + (b1 * b2)) / ((a2 * a2) + (b2 * b2)),
    ((b1 * a2) - (a1 * b2)) / ((a2 * a2) + (b2 * b2)));
}

float Complex::Modul() const
{
  return sqrtf(powf((float)fReal, 2.0f) + powf((float)fImaginary, 2.0f));
}

Complex Complex::operator+(const Complex & c2) const
{
  return this->Add(c2);
}

Complex Complex::operator-(const Complex & c2) const
{
  return this->Subtract(c2);
}

Complex Complex::operator*(const Complex & c2) const
{
  return this->Multiply(c2);
}

Complex Complex::operator/(const Complex & c2) const
{
  return this->Divide(c2);
}

Complex Complex::operator+(const int & i) const
{
  return *this + Complex(i);
}

Complex Complex::operator-(const int & i) const
{
  return *this - Complex(i);
}

Complex Complex::operator*(const int & i) const
{
  return *this * Complex(i);
}

Complex Complex::operator/(const int & i) const
{
  return *this / Complex(i);
}

Complex & Complex::operator+=(const Complex & c2)
{
  *this = *this + c2;
  return *this;
}

Complex & Complex::operator-=(const Complex & c2)
{
  *this = *this - c2;
  return *this;
}

Complex & Complex::operator*=(const Complex & c2)
{
  *this = *this * c2;
  return *this;
}

Complex & Complex::operator/=(const Complex & c2)
{
  *this = *this / c2;
  return *this;
}

Complex & Complex::operator+=(const int & i)
{
  *this = *this + i;
  return *this;
}

Complex & Complex::operator-=(const int & i)
{
  *this = *this - i;
  return *this;
}

Complex & Complex::operator*=(const int & i)
{
  *this = *this * i;
  return *this;
}

Complex & Complex::operator/=(const int & i)
{
  *this = *this / i;
  return *this;
}

Complex & Complex::operator++()
{
  *this += 1;
  return *this;
}

Complex & Complex::operator++(int)
{
  Complex c = *this;
  *this += 1;
  return c;
}

Complex & Complex::operator--()
{
  *this -= 1;
  return *this;
}

Complex & Complex::operator--(int)
{
  Complex c = *this;
  *this -= 1;
  return c;
}

bool Complex::operator>(const Complex & c2) const
{
  return Modul() > c2.Modul();
}

bool Complex::operator<(const Complex & c2) const
{
  return Modul() < c2.Modul();
}

bool Complex::operator==(const Complex & c2) const
{
  return Modul() == c2.Modul();
}

bool Complex::operator>=(const Complex & c2) const
{
  return Modul() >= c2.Modul();
}

bool Complex::operator<=(const Complex & c2) const
{
  return Modul() <= c2.Modul();
}

bool Complex::operator!=(const Complex & c2) const
{
  return Modul() != c2.Modul();
}

bool Complex::operator>(const int & i) const
{
  return Modul() > (float)i;
}

bool Complex::operator<(const int & i) const
{
  return Modul() < (float)i;
}

bool Complex::operator==(const int & i) const
{
  return Modul() == (float)i;
}

bool Complex::operator>=(const int & i) const
{
  return Modul() >= (float)i;
}

bool Complex::operator<=(const int & i) const
{
  return Modul() <= (float)i;
}

bool Complex::operator!=(const int & i) const
{
  return Modul() != (float)i;
}

bool Complex::operator>(const float & f) const
{
  return Modul() > f;
}

bool Complex::operator<(const float & f) const
{
  return Modul() < f;
}

bool Complex::operator==(const float & f) const
{
  return Modul() == f;
}

bool Complex::operator>=(const float & f) const
{
  return Modul() >= f;
}

bool Complex::operator<=(const float & f) const
{
  return Modul() <= f;
}

bool Complex::operator!=(const float & f) const
{
  return Modul() != f;
}

Complex * Complex::operator&()
{
  return this;
}

Complex Complex::operator*() const
{
  return *this;
}

Complex::~Complex(void)
{
}

Complex operator+(const int & i, const Complex & c)
{
  return Complex(i + c.getReal(), c.getImaginary());
}

Complex operator-(const int & i, const Complex & c)
{
  return Complex(i - c.getReal(), c.getImaginary());
}
Complex operator*(const int & i, const Complex & c)
{
  return Complex(i * c.getReal(), c.getImaginary());
}

Complex operator/(const int & i, const Complex & c)
{
  return Complex(i / c.getReal(), c.getImaginary());
}

std::istream & operator >> (std::istream & in, Complex & c)
{
  c.Input();
  return in;
}

std::ostream & operator<<(std::ostream & out, const Complex & c)
{
  out << "(" << c.getReal() << ") + (" << c.getImaginary() << ")i";
  return out;
}
