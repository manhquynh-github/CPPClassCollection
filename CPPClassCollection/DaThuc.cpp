#include "DaThuc.h"
#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;

DaThuc::DaThuc()
{
	iSoPhanTu = 0;
}

DaThuc::DaThuc(int isophantu, float fheso[1000], int isomu[1000])
{
	if (isophantu < 0 && isophantu > 1000)
		cout << "ERR: So phan tu khong dung.";
	else
		for (int i = 0; i < iSoPhanTu; i++)
		{
			fHeSo[i] = fheso[i];
			iSoMu[i] = isomu[i];
		}
}

int DaThuc::getSoPhanTu() const
{
	return iSoPhanTu;
}

float DaThuc::getHeSo(int iViTri) const
{
	if (iViTri < iSoPhanTu && iViTri >= 0)
		return fHeSo[iViTri];
	else
	{
		cout << "ERR: Vi tri nam ngoai so phan tu.";
		return NULL;
	}
}

void DaThuc::setHeSo(int iViTri, float fValue)
{
	if (iViTri < iSoPhanTu && iViTri >= 0)
		fHeSo[iViTri] = fValue;
	else
		cout << "ERR: Vi tri nam ngoai so phan tu.";
}

int DaThuc::getSoMu(int iViTri) const
{
	if (iViTri < iSoPhanTu && iViTri >= 0)
		return iSoMu[iViTri];
	else
	{
		cout << "ERR: Vi tri nam ngoai so phan tu.";
		return NULL;
	}
}

void DaThuc::setSoMu(int iViTri, int iValue)
{
	if (iViTri < iSoPhanTu && iViTri >= 0)
		iSoMu[iViTri] = iValue;
	else
		cout << "ERR: Vi tri nam ngoai so phan tu.";
}

DaThuc DaThuc::SapXep() const
{
	DaThuc dt = *this;

	for (int i = 0; i < dt.iSoPhanTu; i++)
		for (int j = i + 1; j < dt.iSoPhanTu; j++)
			if (dt.iSoMu[i] < dt.iSoMu[j])
			{
				swap<int>(dt.iSoMu[i], dt.iSoMu[j]);
				swap<float>(dt.fHeSo[i], dt.fHeSo[j]);
			}

	return dt;
}

void DaThuc::Nhap()
{
	cout << "Nhap so phan tu da thuc: ";
	cin >> iSoPhanTu;
	for (int i = 0; i < iSoPhanTu; i++)
	{
		printf("He so %d: ", i + 1);
		cin >> fHeSo[i];
		printf("So mu [%d]: ", i + 1);
		cin >> iSoMu[i];
	}
	this->SapXep();
}

void DaThuc::ThemPhanTu(float fheso, int isomu)
{
	fHeSo[iSoPhanTu] = fheso;
	iSoMu[iSoPhanTu] = isomu;
	iSoPhanTu++;
}

void DaThuc::Xuat()
{
	for (int i = 0; i < iSoPhanTu; i++)
	{
		if (fHeSo[i] == 1 && iSoMu[i] != 0)
			cout << "+";
		else if (fHeSo[i] >= 0)
			printf("+%.1f", fHeSo[i]);
		else
			printf("%.1f", fHeSo[i]);

		if (iSoMu[i] == 1)
			cout << "x ";
		else if (iSoMu[i] != 0)
			printf("x^%d ", iSoMu[i]);
		else
			printf(" ");
	}
}

DaThuc DaThuc::RutGon()
{
	DaThuc dt;

	for (int i = 0; i < iSoPhanTu; i++) // Loai bo he so bang 0
		if (fHeSo[i] == 0.0)
		{
			for (int j = i; j < iSoPhanTu - 1; j++)
			{
				fHeSo[j] = fHeSo[j + 1];
				iSoMu[j] = iSoMu[j + 1];
			}
			iSoPhanTu--;
		}

	for (int i = 0; i < iSoPhanTu; i++)
	{
		int j = i + 1;
		for (; j < iSoPhanTu && iSoMu[i] != iSoMu[j]; j++);

		if (j == iSoPhanTu)
		{
			float fheso = 0.0;

			for (int k = i; k >= 0; k--)
				if (iSoMu[k] == iSoMu[i])
					fheso += fHeSo[k];

			dt.ThemPhanTu(fheso, iSoMu[i]);
		}
	}

	return dt;
}

DaThuc DaThuc::operator*(const DaThuc &dt) const
{
	DaThuc kq;
	for (int i = 0; i < iSoPhanTu; i++)
		for (int j = 0; j < dt.iSoPhanTu; j++)
			kq.ThemPhanTu(fHeSo[i] * dt.fHeSo[j], iSoMu[i] + dt.iSoMu[j]);

	kq.RutGon();
	return kq;
}

DaThuc DaThuc::operator+(const DaThuc &dt) const
{
	DaThuc kq;

	for (int i = 0; i < iSoPhanTu; i++)
		kq.ThemPhanTu(fHeSo[i], iSoMu[i]);

	for (int i = 0; i < dt.iSoPhanTu; i++)
		kq.ThemPhanTu(dt.fHeSo[i], dt.iSoMu[i]);

	kq.RutGon();
	return kq;
}

DaThuc DaThuc::operator-(const DaThuc &dt) const
{
	DaThuc kq;

	for (int i = 0; i < iSoPhanTu; i++)
		kq.ThemPhanTu(fHeSo[i], iSoMu[i]);

	for (int i = 0; i < dt.iSoPhanTu; i++)
		kq.ThemPhanTu(-dt.fHeSo[i], dt.iSoMu[i]);

	kq.RutGon();
	return kq;
}

DaThuc DaThuc::operator/(const DaThuc &dt) const
{
	DaThuc kq, remainder = *this;
	while (remainder.iSoMu[0] >= dt.iSoMu[0])
	{
		float fHeSo[1] = { remainder.fHeSo[0] / dt.fHeSo[0] };
		int iSoMu[1] = { remainder.iSoMu[0] - dt.iSoMu[0] };
		DaThuc temp = DaThuc(1, fHeSo, iSoMu);

		kq = kq + temp;

		remainder = remainder - (temp * dt);
	}

	return kq;
}

int DaThuc::operator()(const int & iValue) const
{
	return (int)((*this)((float)iValue));
}

float DaThuc::operator()(const float & fValue) const
{
	float kq = 0.0;

	for (int i = 0; i < iSoPhanTu; i++)
		kq += fHeSo[i] * powf(fValue, (float)iSoMu[i]);

	return kq;
}

DaThuc DaThuc::DaoHamCap(int iCap)
{
	DaThuc dt = *this;

	if (iCap == 1)
		for (int i = 0; i < iSoPhanTu; i++)
		{
			dt.fHeSo[i] = fHeSo[i] * iSoMu[i];
			dt.iSoMu[i] -= 1;
		}

	else
		for (int j = 1; j <= iCap; j++)
			dt = dt.DaoHamCap(1);

	return dt;
}

DaThuc DaThuc::NguyenHam()
{
	DaThuc dt = *this;

	for (int i = 0; i < iSoPhanTu; i++)
	{
		dt.fHeSo[i] = fHeSo[i] / (iSoMu[i] + 1);
		dt.iSoMu[i] += 1;
	}

	return dt;
}

DaThuc::~DaThuc()
{
}
