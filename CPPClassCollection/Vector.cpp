#include "Vector.h"



Vector::~Vector()
{
	if (Data)
		delete[] Data;
}

int Vector::getDimension() const
{
	return Dimension;
}

Matrix Vector::ToMatrix() const
{
	float **data = new float*[1];
	for (int i = 0; i < Dimension; i++)
		data[1][i] = Data[i];

	return Matrix(1, Dimension, data);
}

Matrix Vector::operator*(const Matrix & m) const
{
	return ToMatrix() * m;
}

Matrix operator*(const Matrix & m, const Vector & v)
{
	return m * v.ToMatrix();
}
