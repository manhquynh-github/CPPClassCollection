#pragma once

class SinglePolynomial
{
private:
  int iElementCount, iExponents[1000];
  float fCoefficients[1000];
public:
  SinglePolynomial();
  SinglePolynomial(int iElementCount, float fCoefficients[1000], int iExponents[1000]);

  int getElementCount() const;
  float getCoefficientAt(int index) const;
  void setCoefficientAt(int index, float fValue);
  int getExponentAt(int index) const;
  void setExponentAt(int index, int iValue);

  void Output();
  void Input();

  void AddElement(float fCoefficient, int iExponent);
  SinglePolynomial Arrange() const;
  SinglePolynomial getSimplified();

  SinglePolynomial operator+(const SinglePolynomial &sp) const;
  SinglePolynomial operator-(const SinglePolynomial &sp) const;
  SinglePolynomial operator*(const SinglePolynomial &sp) const;
  SinglePolynomial operator/(const SinglePolynomial &sp) const;
  int operator()(const int &iValue) const;
  float operator()(const float &fValue) const;

  SinglePolynomial getDerivative(int iDepth);
  SinglePolynomial getIntegral();

  ~SinglePolynomial();
};

