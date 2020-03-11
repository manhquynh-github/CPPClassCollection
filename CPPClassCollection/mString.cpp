#include "mString.h"
#include <iostream>
using namespace std;

void mString::mstrcpy(char *& Dest, int ibuffer, char * Source) const
{
  for (int i = 0; i < ibuffer; i++)
    Dest[i] = Source[i];
}

mString::mString()
{
  iBuffer = 256;
  pData = new char[iBuffer];
}

mString::mString(int ibuffer)
{
  pData = new char[ibuffer];
  iBuffer = ibuffer;
}

mString::mString(int ibuffer, char * data)
{
  iBuffer = ibuffer;
  pData = new char[ibuffer];
  mstrcpy(pData, ibuffer, data);
}

int mString::getBuffer() const
{
  return iBuffer;
}

void mString::setBuffer(int ibuffer)
{
  if (ibuffer >= 0)
    iBuffer = ibuffer;
}

char* mString::getStr() const
{
  return pData;
}

void mString::setStr(char *pdata)
{
  mstrcpy(pData, iBuffer, pdata);
}

void mString::Input()
{
  cout << "Inputting a new String: ";
  cin.getline(pData, iBuffer);
}

void mString::Output()
{
  cout << pData << endl;
}

int mString::Length() const
{
  int i = 0;
  for (; pData[i] != '\0'; i++);
  return i;
}

mString mString::Swap() const
{
  mString newstr = *this;

  for (int i = 0, j = this->Length() - 1; i < this->Length() / 2; i++, j--)
    swap<char>(newstr.pData[i], newstr.pData[j]);

  return newstr;
}

mString & mString::operator=(const mString & s)
{
  iBuffer = s.getBuffer();
  pData = new char[iBuffer];
  mstrcpy(pData, iBuffer, s.getStr());

  return *this;
}

mString mString::operator+(const mString &s) const
{
  mString newstr(this->Length() + s.Length() + 1);

  int i = 0;
  for (; i < this->Length(); i++)
    newstr.pData[i] = pData[i];

  for (int j = 0; j < s.Length() + 1; j++, i++)
    newstr.pData[i] = s.pData[j];

  return newstr;
}

bool mString::operator>(const mString & s) const
{
  char *x = s.getStr();
  for (int i = 0; (pData[i]) && (x[i]) && (i < iBuffer); i++)
    if (pData[i] <= x[i])
      return false;

  return true;
}

bool mString::operator<(const mString & s) const
{
  char *x = s.getStr();
  for (int i = 0; (pData[i]) && (x[i]) && (i < iBuffer); i++)
    if (pData[i] >= x[i])
      return false;

  return true;
}

bool mString::operator==(const mString & s) const
{
  char *x = s.getStr();
  for (int i = 0; (pData[i]) && (x[i]) && (i < iBuffer); i++)
    if (pData[i] != x[i])
      return false;

  return true;
}

bool mString::operator!=(const mString & s) const
{
  return !(*this == s);
}

mString::~mString()
{
  if (pData != nullptr)
    delete[] pData;
}