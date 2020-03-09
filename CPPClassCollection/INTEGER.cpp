#include "INTEGER.h"



INTEGER::INTEGER()
{
	Value = 0;
}

INTEGER::INTEGER(int value)
{
	Value = value;
}


INTEGER::~INTEGER()
{
}

INTEGER INTEGER::operator+(const INTEGER & i) const
{
	return INTEGER(Value + i.Value);
}

INTEGER INTEGER::operator-(const INTEGER & i) const
{
	return INTEGER(Value - i.Value);
}

INTEGER INTEGER::operator*(const INTEGER & i) const
{
	return INTEGER(Value * i.Value);
}

INTEGER INTEGER::operator/(const INTEGER & i) const
{
	return INTEGER(Value / i.Value);
}

INTEGER & INTEGER::operator+=(const INTEGER & i)
{
	*this = *this + i;
	return *this;
}

INTEGER & INTEGER::operator-=(const INTEGER & i)
{
	*this = *this - i;
	return *this;
}

INTEGER & INTEGER::operator*=(const INTEGER & i)
{
	*this = *this * i;
	return *this;
}

INTEGER & INTEGER::operator/=(const INTEGER & i)
{
	*this = *this / i;
	return *this;
}

INTEGER & INTEGER::operator++()
{
	*this += 1;
	return *this;
}

INTEGER & INTEGER::operator--()
{
	*this -= 1;
	return *this;
}

INTEGER & INTEGER::operator++(int i)
{
	INTEGER x = *this;
	*this += 1;
	return x;
}

INTEGER & INTEGER::operator--(int i)
{
	INTEGER x = *this;
	*this -= 1;
	return x;
}

bool INTEGER::operator>(const INTEGER & i) const
{
	return Value > i.Value;
}

bool INTEGER::operator<(const INTEGER & i) const
{
	return Value < i.Value;
}

bool INTEGER::operator==(const INTEGER & i) const
{
	return Value == i.Value;
}

bool INTEGER::operator>=(const INTEGER & i) const
{
	return Value >= i.Value;
}

bool INTEGER::operator<=(const INTEGER & i) const
{
	return Value <= i.Value;
}

bool INTEGER::operator!=(const INTEGER & i) const
{
	return Value != i.Value;
}

INTEGER * INTEGER::operator&()
{
	return this;
}

INTEGER INTEGER::operator*()
{
	return *this;
}

std::istream & operator >> (std::istream & in, INTEGER & i)
{
	in >> i.Value;
	return in;
}

std::ostream & operator<<(std::ostream & out, const INTEGER & i)
{
	out << i.Value;
	return out;
}

INTEGER::operator int() const
{
	return Value;
}

INTEGER::operator float() const
{
	return (float)Value;
}

INTEGER::operator double() const
{
	return (double)Value;
}

INTEGER::operator long() const
{
	return (long)Value;
}

INTEGER::operator unsigned int() const
{
	return (unsigned int)Value;
}

INTEGER::operator unsigned long() const
{
	return (unsigned long)Value;
}

INTEGER::operator char() const
{
	return (char)Value;
}
