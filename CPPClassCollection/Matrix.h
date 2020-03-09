#pragma once
#include <iostream>
class Matrix
{
private:
	float **Data;
	int Row, Column;
public:
	Matrix();
	Matrix(int row, int column);
	Matrix(int row, int column, float **data);
	~Matrix();

	float** getData() const;
	int getRow() const;
	int getColumn() const;

	Matrix Simplify() const;
	float Det() const;

	Matrix operator+(const Matrix &m) const;
	Matrix operator-(const Matrix &m) const;
	Matrix operator*(const Matrix &m) const;
	Matrix operator*(const float &f) const;
	Matrix operator*(const int &i) const;
	float operator()(const int &i, const int &j) const;

	friend std::istream& operator >> (std::istream& in, Matrix &m);
	friend std::ostream& operator << (std::ostream& out, const Matrix &m);
};

