#include "SinglePolynomial.h"
#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;

SinglePolynomial::SinglePolynomial()
{
  this->iElementCount = 0;
}

SinglePolynomial::SinglePolynomial(int iElementCount, float fCoefficients[1000], int iExponents[1000])
{
  if (iElementCount < 0 && iElementCount > 1000)
    cout << "ERR: So phan tu khong dung.";
  else
  {
    this->iElementCount = iElementCount;

    for (int i = 0; i < this->iElementCount; i++)
    {
      this->fCoefficients[i] = fCoefficients[i];
      this->iExponents[i] = iExponents[i];
    }
  }
}

int SinglePolynomial::getElementCount() const
{
  return iElementCount;
}

float SinglePolynomial::getCoefficientAt(int index) const
{
  if (index < iElementCount && index >= 0)
    return fCoefficients[index];
  else
  {
    cout << "ERR: Vi tri nam ngoai so phan tu.";
    return NULL;
  }
}

void SinglePolynomial::setCoefficientAt(int index, float fValue)
{
  if (index < iElementCount && index >= 0)
    fCoefficients[index] = fValue;
  else
    cout << "ERR: Vi tri nam ngoai so phan tu.";
}

int SinglePolynomial::getExponentAt(int index) const
{
  if (index < iElementCount && index >= 0)
    return iExponents[index];
  else
  {
    cout << "ERR: Vi tri nam ngoai so phan tu.";
    return NULL;
  }
}

void SinglePolynomial::setExponentAt(int index, int iValue)
{
  if (index < iElementCount && index >= 0)
    iExponents[index] = iValue;
  else
    cout << "ERR: Vi tri nam ngoai so phan tu.";
}

SinglePolynomial SinglePolynomial::Arrange() const
{
  SinglePolynomial sp = *this;

  for (int i = 0; i < sp.iElementCount; i++)
    for (int j = i + 1; j < sp.iElementCount; j++)
      if (sp.iExponents[i] < sp.iExponents[j])
      {
        swap<int>(sp.iExponents[i], sp.iExponents[j]);
        swap<float>(sp.fCoefficients[i], sp.fCoefficients[j]);
      }

  return sp;
}

void SinglePolynomial::Input()
{
  cout << "Input Polynomial's element count: ";
  cin >> iElementCount;
  for (int i = 0; i < iElementCount; i++)
  {
    printf("Input coefficient #%d: ", i + 1);
    cin >> fCoefficients[i];
    printf("Input exponent #[%d]: ", i + 1);
    cin >> iExponents[i];
  }
  this->Arrange();
}

void SinglePolynomial::AddElement(float fCoefficient, int iExponent)
{
  fCoefficients[iElementCount] = fCoefficient;
  iExponents[iElementCount] = iExponent;
  iElementCount++;
  // TODO boundary checking
}

void SinglePolynomial::Output()
{
  for (int i = 0; i < iElementCount; i++)
  {
    if (fCoefficients[i] == 1 && iExponents[i] != 0)
      cout << "+";
    else if (fCoefficients[i] >= 0)
      printf("+%.1f", fCoefficients[i]);
    else
      printf("%.1f", fCoefficients[i]);

    if (iExponents[i] == 1)
      cout << "x ";
    else if (iExponents[i] != 0)
      printf("x^%d ", iExponents[i]);
    else
      printf(" ");
  }
}

SinglePolynomial SinglePolynomial::getSimplified()
{
  SinglePolynomial sp;

  for (int i = 0; i < iElementCount; i++) // Loai bo he so bang 0
    if (fCoefficients[i] == 0.0)
    {
      for (int j = i; j < iElementCount - 1; j++)
      {
        fCoefficients[j] = fCoefficients[j + 1];
        iExponents[j] = iExponents[j + 1];
      }
      iElementCount--;
    }

  for (int i = 0; i < iElementCount; i++)
  {
    int j = i + 1;
    for (; j < iElementCount && iExponents[i] != iExponents[j]; j++);

    if (j == iElementCount)
    {
      float fheso = 0.0;

      for (int k = i; k >= 0; k--)
        if (iExponents[k] == iExponents[i])
          fheso += fCoefficients[k];

      sp.AddElement(fheso, iExponents[i]);
    }
  }

  return sp;
}

SinglePolynomial SinglePolynomial::operator*(const SinglePolynomial &sp) const
{
  SinglePolynomial ret;
  for (int i = 0; i < iElementCount; i++)
    for (int j = 0; j < sp.iElementCount; j++)
      ret.AddElement(fCoefficients[i] * sp.fCoefficients[j], iExponents[i] + sp.iExponents[j]);

  ret.getSimplified();
  return ret;
}

SinglePolynomial SinglePolynomial::operator+(const SinglePolynomial &sp) const
{
  SinglePolynomial ret;

  for (int i = 0; i < iElementCount; i++)
    ret.AddElement(fCoefficients[i], iExponents[i]);

  for (int i = 0; i < sp.iElementCount; i++)
    ret.AddElement(sp.fCoefficients[i], sp.iExponents[i]);

  ret.getSimplified();
  return ret;
}

SinglePolynomial SinglePolynomial::operator-(const SinglePolynomial &sp) const
{
  SinglePolynomial ret;

  for (int i = 0; i < iElementCount; i++)
    ret.AddElement(fCoefficients[i], iExponents[i]);

  for (int i = 0; i < sp.iElementCount; i++)
    ret.AddElement(-sp.fCoefficients[i], sp.iExponents[i]);

  ret.getSimplified();
  return ret;
}

SinglePolynomial SinglePolynomial::operator/(const SinglePolynomial &sp) const
{
  SinglePolynomial ret, remainder = *this;
  while (remainder.iExponents[0] >= sp.iExponents[0])
  {
    float fCoefficients[1] = { remainder.fCoefficients[0] / sp.fCoefficients[0] };
    int iExponents[1] = { remainder.iExponents[0] - sp.iExponents[0] };
    SinglePolynomial temp = SinglePolynomial(1, fCoefficients, iExponents);

    ret = ret + temp;

    remainder = remainder - (temp * sp);
  }

  return ret;
}

int SinglePolynomial::operator()(const int & iValue) const
{
  return (int)((*this)((float)iValue));
}

float SinglePolynomial::operator()(const float & fValue) const
{
  float ret = 0.0;

  for (int i = 0; i < iElementCount; i++)
    ret += fCoefficients[i] * powf(fValue, (float)iExponents[i]);

  return ret;
}

SinglePolynomial SinglePolynomial::getDerivative(int iDepth)
{
  SinglePolynomial sp = *this;

  if (iDepth == 1)
    for (int i = 0; i < iElementCount; i++)
    {
      sp.fCoefficients[i] = fCoefficients[i] * iExponents[i];
      sp.iExponents[i] -= 1;
    }

  else
    for (int j = 1; j <= iDepth; j++)
      sp = sp.getDerivative(1);

  return sp;
}

SinglePolynomial SinglePolynomial::getIntegral()
{
  SinglePolynomial sp = *this;

  for (int i = 0; i < iElementCount; i++)
  {
    sp.fCoefficients[i] = fCoefficients[i] / (iExponents[i] + 1);
    sp.iExponents[i] += 1;
  }

  return sp;
}

SinglePolynomial::~SinglePolynomial()
{
}
