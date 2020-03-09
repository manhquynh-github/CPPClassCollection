#pragma once
#include "Matrix.h"
class Vector : public Matrix
{
private:
	float *Data;
	int Dimension;
public:
	Vector() : Matrix(), Dimension(0) { }
	Vector(int dimension, float *data) : Matrix(1, dimension)
	{
		for (int i = 0; i < dimension; i++)
			Data[i] = data[i];
	}
	~Vector();

	int getDimension() const;
	Matrix ToMatrix() const;

	Matrix operator*(const Matrix &m) const;
	friend Matrix operator*(const Matrix &m, const Vector &v);
};

