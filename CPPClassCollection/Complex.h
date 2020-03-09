#pragma once
#include "Fraction.h"
class Complex
{
private:
  Fraction fReal;
  Fraction fImaginary;
public:
  Complex();
  Complex(Fraction fReal);
  Complex(Fraction fReal, Fraction fImaginary);
  Complex(int iReal, int iImaginary);

  void Output();
  void Input();
  Fraction getReal() const;
  void setReal(Fraction _fThuc);
  Fraction getImaginary() const;
  void setImaginary(Fraction _fAo);

  Complex Add(const Complex &c) const;
  Complex Subtract(const Complex &c) const;
  Complex Multiply(const Complex &c) const;
  Complex Divide(const Complex &c) const;
  float Modul() const;

  Complex operator+(const Complex &c2) const;
  Complex operator-(const Complex &c2) const;
  Complex operator*(const Complex &c2) const;
  Complex operator/(const Complex &c2) const;
  Complex operator+(const int &i) const;
  Complex operator-(const int &i) const;
  Complex operator*(const int &i) const;
  Complex operator/(const int &i) const;

  Complex& operator=(const Complex &c2) = default;
  Complex& operator+=(const Complex &c2);
  Complex& operator-=(const Complex &c2);
  Complex& operator*=(const Complex &c2);
  Complex& operator/=(const Complex &c2);
  Complex& operator+=(const int &i);
  Complex& operator-=(const int &i);
  Complex& operator*=(const int &i);
  Complex& operator/=(const int &i);
  Complex& operator++();
  Complex& operator++(int);
  Complex& operator--();
  Complex& operator--(int);

  bool operator>(const Complex &c2) const;
  bool operator<(const Complex &c2) const;
  bool operator==(const Complex &c2) const;
  bool operator>=(const Complex &c2) const;
  bool operator<=(const Complex &c2) const;
  bool operator!=(const Complex &c2) const;

  bool operator>(const int &i) const;
  bool operator<(const int &i) const;
  bool operator==(const int &i) const;
  bool operator>=(const int &i) const;
  bool operator<=(const int &i) const;
  bool operator!=(const int &i) const;

  bool operator>(const float &f) const;
  bool operator<(const float &f) const;
  bool operator==(const float &f) const;
  bool operator>=(const float &f) const;
  bool operator<=(const float &f) const;
  bool operator!=(const float &f) const;

  Complex* operator&();
  Complex operator*() const;

  friend Complex operator+(const int &i, const Complex &c);
  friend Complex operator-(const int &i, const Complex &c);
  friend Complex operator*(const int &i, const Complex &c);
  friend Complex operator/(const int &i, const Complex &c);
  friend std::istream& operator>>(std::istream& in, Complex &c);
  friend std::ostream& operator<<(std::ostream& out, const Complex &c);

  ~Complex(void);
};