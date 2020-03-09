#pragma once
#include <iostream>
class Fraction
{
private:
	int iTu, iMau;
	int UCLN(int a, int b) const;
	int BCNN(int a, int b) const;
public:
	Fraction();
	Fraction(int iTu);
	Fraction(int iTu, int iMau);

	void Nhap();
	void Xuat();
	int getTu() const;
	void setTu(int iTu);
	int getMau() const;
	void setMau(int iMau);
	Fraction RutGon();
	Fraction QuyDong(const Fraction &f) const;
	Fraction Cong(const Fraction &f) const;
	Fraction Tru(const Fraction &f) const;
	Fraction Nhan(const Fraction &f) const;
	Fraction Chia(const Fraction &f) const;	

	int SoSanh(const Fraction &f) const;
	bool ToiGian() const;
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

