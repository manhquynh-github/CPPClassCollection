#include "Matrix.h"
using namespace std;


Matrix::Matrix()
{
  Row = Column = 0;
  Data = nullptr;
}

Matrix::Matrix(int row, int column)
{
  Row = row;
  Column = column;

  Data = new float*[Row];
  for (int i = 0; i < Column; i++)
    Data[i] = new float[Column];
}

Matrix::Matrix(int row, int column, float ** data)
{
  Row = row;
  Column = column;

  Data = new float*[Row];
  for (int i = 0; i < Column; i++)
    Data[i] = new float[Column];

  for (int i = 0; i < Row; i++)
    for (int j = 0; j < Column; j++)
      Data[i][j] = data[i][j];
}

Matrix::~Matrix()
{
  if (Data)
  {
    if (Row == 1 || Column == 1)
      delete[] Data;
    else
    {
      for (int i = 0; i < Row; i++)
        if (Data[i] != nullptr)
          delete[] Data[i];

      delete[] Data;
    }
  }
}

float ** Matrix::getData() const
{
  return Data;
}

int Matrix::getRow() const
{
  return Row;
}

int Matrix::getColumn() const
{
  return Column;
}

Matrix Matrix::getSimplified() const
{
  Matrix C = *this;

  for (int k = 0; k < Row - 1; k++)
    for (int i = k + 1; i < Row; i++)
    {
      if (Data[i][k] == 0.0f)
        break;

      float x = -(Data[i][k] / Data[k][k]);

      for (int j = 0; j < Column; j++)
        C.Data[i][j] = Data[k][j] * x + Data[i][j];
    }
  return C;
}

float Matrix::Det() const
{
  Matrix C = this->getSimplified();
  float x = 1.0f;

  for (int i = 0; i < Row; i++)
    x *= C.Data[i][i];

  return x;
}

Matrix Matrix::operator+(const Matrix & m) const
{
  if (Row == m.Row && Column == m.Row)
  {
    Matrix C(Row, Column);
    for (int i = 0; i < Row; i++)
      for (int j = 0; j < Column; j++)
        C.Data[i][j] = Data[i][j] + m.Data[i][j];

    return C;
  }
  return Matrix();
}

Matrix Matrix::operator-(const Matrix & m) const
{
  if (Row == m.Row && Column == m.Row)
  {
    Matrix C(Row, Column);
    for (int i = 0; i < Row; i++)
      for (int j = 0; j < Column; j++)
        C.Data[i][j] = Data[i][j] - m.Data[i][j];

    return C;
  }
  return Matrix();
}

Matrix Matrix::operator*(const Matrix & m) const
{
  if (Column == m.Row)
  {
    Matrix C(Row, m.Column);
    for (int i = 0; i < C.Row; i++)
      for (int j = 0; j < C.Column; j++)
        for (int k = 0; k < Column; k++)
          C.Data[i][j] = Data[i][k] * m.Data[k][j];

    return C;
  }

  return Matrix();
}

Matrix Matrix::operator*(const float & f) const
{
  Matrix C = *this;
  for (int i = 0; i < Row; i++)
    for (int j = 0; j < Column; j++)
      C.Data[i][j] = f * Data[i][j];

  return C;
}

Matrix Matrix::operator*(const int & i) const
{
  return *this * (float)i;
}

float Matrix::operator()(const int & i, const int & j) const
{
  if (i < Row && j < Column)
    return Data[i][j];
  return 0.0f;
}

std::istream & operator >> (std::istream & in, Matrix & m)
{
  cout << endl << "|| Assign new Mat:" << endl;
  cout << "Row = "; cin >> m.Row;
  cout << "Column = "; cin >> m.Column;

  m.Data = new float*[m.Row];
  for (int i = 0; i < m.Column; i++)
    m.Data[i] = new float[m.Column];

  for (int i = 0; i < m.Row; i++)
    for (int j = 0; j < m.Column; j++)
    {
      cout << "A" << i + 1 << j + 1 << " = ";
      cin >> m.Data[i][j];
    }

  return in;
}

std::ostream & operator<<(std::ostream & out, const Matrix & m)
{
  out << endl << "|| Output Mat: " << endl;
  for (int i = 0; i < m.Row; i++)
  {
    for (int j = 0; j < m.Column; j++)
      out << "   " << m.Data[i][j];
    out << endl;
  }

  return out;
}
