#pragma once
#include "SoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

SoPhuc::SoPhuc()
{
	fThuc = fAo = Fraction();
}

SoPhuc::SoPhuc(Fraction _fThuc)
{
	fThuc = _fThuc;
	fAo = Fraction();
}

SoPhuc::SoPhuc(Fraction _fThuc, Fraction _fAo)
{
	fThuc = _fThuc;
	fAo = _fAo;

}

SoPhuc::SoPhuc(int iTuThuc, int iTuAo)
{
	fThuc = Fraction(iTuThuc);
	fAo = Fraction(iTuAo);
}

SoPhuc::SoPhuc(int iTuThuc, int iMauThuc, int iTuAo, int iMauAo)
{
	fThuc = Fraction(iTuThuc, iMauThuc);
	fAo = Fraction(iTuAo, iMauAo);
}

void SoPhuc::Xuat()
{
	cout << "(";
	fThuc.Xuat();
	cout << ") + (";
	fAo.Xuat();
	cout << ")i";
}

void SoPhuc::Nhap()
{
	cout << "Nhap so phuc:" << endl;
	cout << "So thuc:";
	fThuc.Nhap();
	cout << "So ao: ";
	fAo.Nhap();
}

Fraction SoPhuc::getThuc() const
{
	return fThuc;
}

void SoPhuc::setThuc(Fraction _fThuc)
{
	fThuc = _fThuc;
}

Fraction SoPhuc::getAo() const
{
	return fAo;
}

void SoPhuc::setAo(Fraction _fAo)
{
	fAo = _fAo;
}

SoPhuc SoPhuc::Cong(const SoPhuc &sp) const
{
	return SoPhuc(fThuc + sp.fThuc, fAo + sp.fAo);
}

SoPhuc SoPhuc::Tru(const SoPhuc &sp) const
{
	return SoPhuc(fThuc - sp.fThuc, fAo - sp.fAo);
}

SoPhuc SoPhuc::Nhan(const SoPhuc &sp) const
{
	Fraction a1 = this->fThuc, b1 = this->fAo,
		a2 = sp.fThuc, b2 = sp.fAo;

	return SoPhuc((a1 * a2) - (b1 * b2), (a1 * b2) + (a2 * b1)); 
}

SoPhuc SoPhuc::Chia(const SoPhuc &sp) const
{
	Fraction a1 = this->fThuc, b1 = this->fAo,
		a2 = sp.fThuc, b2 = sp.fAo;

	return SoPhuc(((a1 * a2) + (b1 * b2)) / ((a2 * a2) + (b2 * b2)),
		((b1 * a2) - (a1 * b2)) / ((a2 * a2) + (b2 * b2)));
}

float SoPhuc::Modul() const
{
	return sqrtf(powf((float)fThuc, 2.0f) + powf((float)fAo, 2.0f));
}

SoPhuc SoPhuc::operator+(const SoPhuc & sp2) const
{
	return this->Cong(sp2);
}

SoPhuc SoPhuc::operator-(const SoPhuc & sp2) const
{
	return this->Tru(sp2);
}

SoPhuc SoPhuc::operator*(const SoPhuc & sp2) const
{
	return this->Nhan(sp2);
}

SoPhuc SoPhuc::operator/(const SoPhuc & sp2) const
{
	return this->Chia(sp2);
}

SoPhuc SoPhuc::operator+(const int & i) const
{
	return *this + SoPhuc(i);
}

SoPhuc SoPhuc::operator-(const int & i) const
{
	return *this - SoPhuc(i);
}

SoPhuc SoPhuc::operator*(const int & i) const
{
	return *this * SoPhuc(i);
}

SoPhuc SoPhuc::operator/(const int & i) const
{
	return *this / SoPhuc(i);
}

SoPhuc & SoPhuc::operator+=(const SoPhuc & sp2)
{
	*this = *this + sp2;
	return *this;
}

SoPhuc & SoPhuc::operator-=(const SoPhuc & sp2)
{
	*this = *this - sp2;
	return *this;
}

SoPhuc & SoPhuc::operator*=(const SoPhuc & sp2)
{
	*this = *this * sp2;
	return *this;
}

SoPhuc & SoPhuc::operator/=(const SoPhuc & sp2)
{
	*this = *this / sp2;
	return *this;
}

SoPhuc & SoPhuc::operator+=(const int & i)
{
	*this = *this + i;
	return *this;
}

SoPhuc & SoPhuc::operator-=(const int & i)
{
	*this = *this - i;
	return *this;
}

SoPhuc & SoPhuc::operator*=(const int & i)
{
	*this = *this * i;
	return *this;
}

SoPhuc & SoPhuc::operator/=(const int & i)
{
	*this = *this / i;
	return *this;
}

SoPhuc & SoPhuc::operator++()
{
	*this += 1;
	return *this;
}

SoPhuc & SoPhuc::operator++(int)
{
	SoPhuc sp = *this;
	*this += 1;
	return sp;
}

SoPhuc & SoPhuc::operator--()
{
	*this -= 1;
	return *this;
}

SoPhuc & SoPhuc::operator--(int)
{
	SoPhuc sp = *this;
	*this -= 1;
	return sp;
}

bool SoPhuc::operator>(const SoPhuc & sp2) const
{
	return Modul() > sp2.Modul();
}

bool SoPhuc::operator<(const SoPhuc & sp2) const
{
	return Modul() < sp2.Modul();
}

bool SoPhuc::operator==(const SoPhuc & sp2) const
{
	return Modul() == sp2.Modul();
}

bool SoPhuc::operator>=(const SoPhuc & sp2) const
{
	return Modul() >= sp2.Modul();
}

bool SoPhuc::operator<=(const SoPhuc & sp2) const
{
	return Modul() <= sp2.Modul();
}

bool SoPhuc::operator!=(const SoPhuc & sp2) const
{
	return Modul() != sp2.Modul();
}

bool SoPhuc::operator>(const int & i) const
{
	return Modul() > (float)i;
}

bool SoPhuc::operator<(const int & i) const
{
	return Modul() < (float)i;
}

bool SoPhuc::operator==(const int & i) const
{
	return Modul() == (float)i;
}

bool SoPhuc::operator>=(const int & i) const
{
	return Modul() >= (float)i;
}

bool SoPhuc::operator<=(const int & i) const
{
	return Modul() <= (float)i;
}

bool SoPhuc::operator!=(const int & i) const
{
	return Modul() != (float)i;
}

bool SoPhuc::operator>(const float & f) const
{
	return Modul() > f;
}

bool SoPhuc::operator<(const float & f) const
{
	return Modul() < f;
}

bool SoPhuc::operator==(const float & f) const
{
	return Modul() == f;
}

bool SoPhuc::operator>=(const float & f) const
{
	return Modul() >= f;
}

bool SoPhuc::operator<=(const float & f) const
{
	return Modul() <= f;
}

bool SoPhuc::operator!=(const float & f) const
{
	return Modul() != f;
}

SoPhuc * SoPhuc::operator&()
{
	return this;
}

SoPhuc SoPhuc::operator*() const
{
	return *this;
}

SoPhuc::~SoPhuc(void)
{
}

SoPhuc operator+(const int & i, const SoPhuc & sp)
{
	return SoPhuc(i + sp.getThuc(), sp.getAo());
}

SoPhuc operator-(const int & i, const SoPhuc & sp)
{
	return SoPhuc(i - sp.getThuc(), sp.getAo());
}
SoPhuc operator*(const int & i, const SoPhuc & sp)
{
	return SoPhuc(i * sp.getThuc(), sp.getAo());
}

SoPhuc operator/(const int & i, const SoPhuc & sp)
{
	return SoPhuc(i / sp.getThuc(), sp.getAo());
}

std::istream & operator >> (std::istream & in, SoPhuc & sp)
{
	sp.Nhap();
	return in;
}

std::ostream & operator<<(std::ostream & out, const SoPhuc & sp)
{
	out << "(" << sp.getThuc() << ") + (" <<sp.getAo() << ")i";
	return out;
}
