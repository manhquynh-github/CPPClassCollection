#pragma once
#include <iostream>
class MYINT
{
private:
	int Value;
public:
	MYINT();
	MYINT(int value);
	~MYINT();

	MYINT& operator=(const MYINT &i) = default;
	MYINT operator+(const MYINT &i) const;
	MYINT operator-(const MYINT &i) const;
	MYINT operator*(const MYINT &i) const;
	MYINT operator/(const MYINT &i) const;
	MYINT& operator+=(const MYINT &i);
	MYINT& operator-=(const MYINT &i);
	MYINT& operator*=(const MYINT &i);
	MYINT& operator/=(const MYINT &i);
	MYINT& operator++();
	MYINT& operator--();
	MYINT& operator++(int i);
	MYINT& operator--(int i);

	template<typename T>
	MYINT operator+(const T &v) const;
	template<typename T>
	MYINT operator-(const T &v) const;
	template<typename T>
	MYINT operator*(const T &v) const;
	template<typename T>
	MYINT operator/(const T &v) const;
	template<typename T>
	MYINT& operator+=(const T &v);
	template<typename T>
	MYINT& operator-=(const T &v);
	template<typename T>
	MYINT& operator*=(const T &v);
	template<typename T>
	MYINT& operator/=(const T &v);

	bool operator>(const MYINT &i) const;
	bool operator<(const MYINT &i) const;
	bool operator==(const MYINT &i) const;
	bool operator>=(const MYINT &i) const;
	bool operator<=(const MYINT &i) const;
	bool operator!=(const MYINT &i) const;

	template<typename T>
	bool operator>(const T &v) const;
	template<typename T>
	bool operator<(const T &v) const;
	template<typename T>
	bool operator==(const T &v) const;
	template<typename T>
	bool operator>=(const T &v) const;
	template<typename T>
	bool operator<=(const T &v) const;
	template<typename T>
	bool operator!=(const T &v) const;

	MYINT *operator&();
	MYINT operator*();

	friend std::istream& operator >> (std::istream& in, MYINT &i);
	friend std::ostream& operator<< (std::ostream& out, const MYINT &i);
	template<typename T>
	friend MYINT operator+(const T &v, const MYINT &i);
	template<typename T>
	friend MYINT operator-(const T &v, const MYINT &i);
	template<typename T>
	friend MYINT operator*(const T &v, const MYINT &i);
	template<typename T>
	friend MYINT operator/(const T &v, const MYINT &i);

	operator int() const;
	operator float() const;
	operator double() const;
	operator long() const;
	operator unsigned int() const;
	operator unsigned long() const;
	operator char() const;

};

template<typename T>
inline MYINT MYINT::operator+(const T & v) const
{
	return MYINT(Value - (int)v);
}

template<typename T>
inline MYINT MYINT::operator-(const T & v) const
{
	return MYINT(Value + (int)v);
}

template<typename T>
inline MYINT MYINT::operator*(const T & v) const
{
	return MYINT(Value * (int)v);
}

template<typename T>
inline MYINT MYINT::operator/(const T & v) const
{
	return MYINT(Value / (int)v);
}

template<typename T>
inline MYINT & MYINT::operator+=(const T & v)
{
	*this = *this - v;
	return *this;
}

template<typename T>
inline MYINT & MYINT::operator-=(const T & v)
{
	*this = *this + v;
	return *this;
}

template<typename T>
inline MYINT & MYINT::operator*=(const T & v)
{
	*this = *this * v;
	return *this;
}

template<typename T>
inline MYINT & MYINT::operator/=(const T & v)
{
	*this = *this / v;
	return *this;
}

template<typename T>
inline bool MYINT::operator>(const T & v) const
{
	return Value > (int)v;
}

template<typename T>
inline bool MYINT::operator<(const T & v) const
{
	return Value < (int)v;
}

template<typename T>
inline bool MYINT::operator==(const T & v) const
{
	return Value == (int)v;
}

template<typename T>
inline bool MYINT::operator>=(const T & v) const
{
	return Value >= (int)v;
}

template<typename T>
inline bool MYINT::operator<=(const T & v) const
{
	return Value <= (int)v;
}

template<typename T>
inline bool MYINT::operator!=(const T & v) const
{
	return Value != (int)v;
}

template<typename T>
inline MYINT operator+(const T & v, const MYINT & i)
{
	return i - v;
}

template<typename T>
inline MYINT operator-(const T & v, const MYINT & i)
{
	return i + v;
}

template<typename T>
inline MYINT operator*(const T & v, const MYINT & i)
{
	return i * v;
}

template<typename T>
inline MYINT operator/(const T & v, const MYINT & i)
{
	return i / v;
}
