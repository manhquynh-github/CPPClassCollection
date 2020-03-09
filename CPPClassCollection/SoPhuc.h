#pragma once
#include "Fraction.h"
class SoPhuc
{
private:
	Fraction fThuc;
	Fraction fAo;
public:
	SoPhuc();
	SoPhuc(Fraction _fThuc);
	SoPhuc(Fraction _fThuc, Fraction _fAo);
	SoPhuc(int iTuThuc, int iTuAo);
	SoPhuc(int iTuThuc, int iMauThuc, int iTuAo, int iMauAo);

	void Xuat();
	void Nhap();
	Fraction getThuc() const;
	void setThuc(Fraction _fThuc);
	Fraction getAo() const;
	void setAo(Fraction _fAo);

	SoPhuc Cong(const SoPhuc &sp) const;
	SoPhuc Tru(const SoPhuc &sp) const;
	SoPhuc Nhan(const SoPhuc &sp) const;
	SoPhuc Chia(const SoPhuc &sp) const;
	float Modul() const;

	SoPhuc operator+(const SoPhuc &sp2) const;
	SoPhuc operator-(const SoPhuc &sp2) const;
	SoPhuc operator*(const SoPhuc &sp2) const;
	SoPhuc operator/(const SoPhuc &sp2) const;
	SoPhuc operator+(const int &i) const;
	SoPhuc operator-(const int &i) const;
	SoPhuc operator*(const int &i) const;
	SoPhuc operator/(const int &i) const;
	
	SoPhuc& operator=(const SoPhuc &sp2) = default;
	SoPhuc& operator+=(const SoPhuc &sp2);
	SoPhuc& operator-=(const SoPhuc &sp2);
	SoPhuc& operator*=(const SoPhuc &sp2);
	SoPhuc& operator/=(const SoPhuc &sp2);
	SoPhuc& operator+=(const int &i);
	SoPhuc& operator-=(const int &i);
	SoPhuc& operator*=(const int &i);
	SoPhuc& operator/=(const int &i);
	SoPhuc& operator++();
	SoPhuc& operator++(int);
	SoPhuc& operator--();
	SoPhuc& operator--(int);

	bool operator>(const SoPhuc &sp2) const;
	bool operator<(const SoPhuc &sp2) const;
	bool operator==(const SoPhuc &sp2) const;
	bool operator>=(const SoPhuc &sp2) const;
	bool operator<=(const SoPhuc &sp2) const;
	bool operator!=(const SoPhuc &sp2) const;

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

	SoPhuc* operator&();
	SoPhuc operator*() const;
	
	friend SoPhuc operator+(const int &i, const SoPhuc &sp);
	friend SoPhuc operator-(const int &i, const SoPhuc &sp);
	friend SoPhuc operator*(const int &i, const SoPhuc &sp);
	friend SoPhuc operator/(const int &i, const SoPhuc &sp);
	friend std::istream& operator>>(std::istream& in, SoPhuc &sp);
	friend std::ostream& operator<<(std::ostream& out, const SoPhuc &sp);

	~SoPhuc(void);
};