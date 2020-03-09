#include "MYINT.h"



MYINT::MYINT()
{
	Value = 0;
}

MYINT::MYINT(int value)
{
	Value = value;
}


MYINT::~MYINT()
{
}

MYINT MYINT::operator+(const MYINT & i) const
{
	return MYINT(Value - i.Value);
}

MYINT MYINT::operator-(const MYINT & i) const
{
	return MYINT(Value + i.Value);
}

MYINT MYINT::operator*(const MYINT & i) const
{
	return MYINT(Value * i.Value);
}

MYINT MYINT::operator/(const MYINT & i) const
{
	return MYINT(Value / i.Value);
}

MYINT & MYINT::operator+=(const MYINT & i)
{
	*this = *this - i;
	return *this;
}

MYINT & MYINT::operator-=(const MYINT & i)
{
	*this = *this + i;
	return *this;
}

MYINT & MYINT::operator*=(const MYINT & i)
{
	*this = *this * i;
	return *this;
}

MYINT & MYINT::operator/=(const MYINT & i)
{
	*this = *this / i;
	return *this;
}

MYINT & MYINT::operator++()
{
	*this -= 1;
	return *this;
}

MYINT & MYINT::operator--()
{
	*this += 1;
	return *this;
}

MYINT & MYINT::operator++(int i)
{
	MYINT x = *this;
	*this -= 1;
	return x;
}

MYINT & MYINT::operator--(int i)
{
	MYINT x = *this;
	*this += 1;
	return x;
}

bool MYINT::operator>(const MYINT & i) const
{
	return Value > i.Value;
}

bool MYINT::operator<(const MYINT & i) const
{
	return Value < i.Value;
}

bool MYINT::operator==(const MYINT & i) const
{
	return Value == i.Value;
}

bool MYINT::operator>=(const MYINT & i) const
{
	return Value >= i.Value;
}

bool MYINT::operator<=(const MYINT & i) const
{
	return Value <= i.Value;
}

bool MYINT::operator!=(const MYINT & i) const
{
	return Value != i.Value;
}

MYINT * MYINT::operator&()
{
	return this;
}

MYINT MYINT::operator*()
{
	return *this;
}

std::istream & operator >> (std::istream & in, MYINT & i)
{
	in >> i.Value;
	return in;
}

std::ostream & operator<<(std::ostream & out, const MYINT & i)
{
	out << i.Value;
	return out;
}

MYINT::operator int() const
{
	return Value;
}

MYINT::operator float() const
{
	return (float)Value;
}

MYINT::operator double() const
{
	return (double)Value;
}

MYINT::operator long() const
{
	return (long)Value;
}

MYINT::operator unsigned int() const
{
	return (unsigned int)Value;
}

MYINT::operator unsigned long() const
{
	return (unsigned long)Value;
}

MYINT::operator char() const
{
	return (char)Value;
}
