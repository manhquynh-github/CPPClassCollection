#pragma once
#include <iostream>
class INTEGER
{
private:
	int Value;
public:
	INTEGER();
	INTEGER(int value);
	~INTEGER();
	
	INTEGER& operator=(const INTEGER &i) = default;
	INTEGER operator+(const INTEGER &i) const;
	INTEGER operator-(const INTEGER &i) const;
	INTEGER operator*(const INTEGER &i) const;
	INTEGER operator/(const INTEGER &i) const;
	INTEGER& operator+=(const INTEGER &i);
	INTEGER& operator-=(const INTEGER &i);
	INTEGER& operator*=(const INTEGER &i);
	INTEGER& operator/=(const INTEGER &i);
	INTEGER& operator++();
	INTEGER& operator--();
	INTEGER& operator++(int i);
	INTEGER& operator--(int i);

	template<typename T>
	INTEGER operator+(const T &v) const;
	template<typename T>
	INTEGER operator-(const T &v) const;
	template<typename T>
	INTEGER operator*(const T &v) const;
	template<typename T>
	INTEGER operator/(const T &v) const;
	template<typename T>
	INTEGER& operator+=(const T &v);
	template<typename T>
	INTEGER& operator-=(const T &v);
	template<typename T>
	INTEGER& operator*=(const T &v);
	template<typename T>
	INTEGER& operator/=(const T &v);

	bool operator>(const INTEGER &i) const;
	bool operator<(const INTEGER &i) const;
	bool operator==(const INTEGER &i) const;
	bool operator>=(const INTEGER &i) const;
	bool operator<=(const INTEGER &i) const;
	bool operator!=(const INTEGER &i) const;

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

	INTEGER *operator&();
	INTEGER operator*();

	friend std::istream& operator>> (std::istream& in, INTEGER &i);
	friend std::ostream& operator<< (std::ostream& out, const INTEGER &i);
	template<typename T>
	friend INTEGER operator+(const T &v, const INTEGER &i);
	template<typename T>
	friend INTEGER operator-(const T &v, const INTEGER &i);
	template<typename T>
	friend INTEGER operator*(const T &v, const INTEGER &i);
	template<typename T>
	friend INTEGER operator/(const T &v, const INTEGER &i);

	operator int() const;
	operator float() const;
	operator double() const;
	operator long() const;
	operator unsigned int() const;
	operator unsigned long() const;
	operator char() const;

};

template<typename T>
inline INTEGER INTEGER::operator+(const T & v) const
{
	return INTEGER(Value +(int)v);
}

template<typename T>
inline INTEGER INTEGER::operator-(const T & v) const
{
	return INTEGER(Value - (int)v);
}

template<typename T>
inline INTEGER INTEGER::operator*(const T & v) const
{
	return INTEGER(Value * (int)v);
}

template<typename T>
inline INTEGER INTEGER::operator/(const T & v) const
{
	return INTEGER(Value / (int)v);
}

template<typename T>
inline INTEGER & INTEGER::operator+=(const T & v)
{
	*this = *this + v;
	return *this;
}

template<typename T>
inline INTEGER & INTEGER::operator-=(const T & v)
{
	*this = *this - v;
	return *this;
}

template<typename T>
inline INTEGER & INTEGER::operator*=(const T & v)
{
	*this = *this * v;
	return *this;
}

template<typename T>
inline INTEGER & INTEGER::operator/=(const T & v)
{
	*this = *this / v;
	return *this;
}

template<typename T>
inline bool INTEGER::operator>(const T & v) const
{
	return Value > (int)v;
}

template<typename T>
inline bool INTEGER::operator<(const T & v) const
{
	return Value < (int)v;
}

template<typename T>
inline bool INTEGER::operator==(const T & v) const
{
	return Value == (int)v;
}

template<typename T>
inline bool INTEGER::operator>=(const T & v) const
{
	return Value >= (int)v;
}

template<typename T>
inline bool INTEGER::operator<=(const T & v) const
{
	return Value <= (int)v;
}

template<typename T>
inline bool INTEGER::operator!=(const T & v) const
{
	return Value != (int)v;
}

template<typename T>
inline INTEGER operator+(const T & v, const INTEGER & i)
{
	return i + v;
}

template<typename T>
inline INTEGER operator-(const T & v, const INTEGER & i)
{
	return i - v;
}

template<typename T>
inline INTEGER operator*(const T & v, const INTEGER & i)
{
	return i * v;
}

template<typename T>
inline INTEGER operator/(const T & v, const INTEGER & i)
{
	return i / v;
}
