#pragma once
#include <iostream>
class Fraction
{
private:
  int iNumerator, iDenominator;
  int GCD(int a, int b) const; // Greatest Common Divisor
  int LCM(int a, int b) const; // Least Common Multiple
public:
  Fraction();
  Fraction(int iNumerator);
  Fraction(int iNumerator, int iDenominator);

  void Input();
  void Output();
  int getNumerator() const;
  void setNumerator(int iNumerator);
  int getDenominator() const;
  void setDenominator(int iDenominator);
  Fraction getSimplified();
  Fraction QuyDong(const Fraction &f) const;
  Fraction Add(const Fraction &f) const;
  Fraction Subtract(const Fraction &f) const;
  Fraction Multiply(const Fraction &f) const;
  Fraction Divide(const Fraction &f) const;

  int CompareTo(const Fraction &f) const;
  bool IsSimplified() const;
  float ToFloat() const;

  Fraction operator+(const Fraction &f2) const;
  Fraction operator-(const Fraction &f2) const;
  Fraction operator*(const Fraction &f2) const;
  Fraction operator/(const Fraction &f2) const;
  Fraction operator+(const int &i) const;
  Fraction operator-(const int &i) const;
  Fraction operator*(const int &i) const;
  Fraction operator/(const int &i) const;

  Fraction& operator=(const Fraction &f) = default;
  Fraction& operator+=(const Fraction &f2);
  Fraction& operator-=(const Fraction &f2);
  Fraction& operator*=(const Fraction &f2);
  Fraction& operator/=(const Fraction &f2);
  Fraction& operator+=(const int &i);
  Fraction& operator-=(const int &i);
  Fraction& operator*=(const int &i);
  Fraction& operator/=(const int &i);
  Fraction& operator++(int);
  Fraction& operator++();
  Fraction& operator--(int);
  Fraction& operator--();

  bool operator>(const Fraction &f2) const;
  bool operator<(const Fraction &f2) const;
  bool operator==(const Fraction &f2) const;
  bool operator>=(const Fraction &f2) const;
  bool operator<=(const Fraction &f2) const;
  bool operator!=(const Fraction &f2) const;

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

  Fraction operator*() const;
  Fraction* operator&();

  operator float() const;
  friend Fraction operator+(const int &i, const Fraction &f);
  friend Fraction operator-(const int &i, const Fraction &f);
  friend Fraction operator*(const int &i, const Fraction &f);
  friend Fraction operator/(const int &i, const Fraction &f);
  friend std::ostream& operator<<(std::ostream& out, const Fraction &f);
  friend std::istream& operator>>(std::istream& in, Fraction &f);

  ~Fraction();
};

