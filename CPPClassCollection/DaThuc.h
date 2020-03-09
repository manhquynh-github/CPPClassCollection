#pragma once
class DaThuc
{
private:
	int iSoPhanTu, iSoMu[1000];
	float fHeSo[1000];
public:
	DaThuc();
	DaThuc(int isophantu, float fheso[1000], int isomu[1000]);

	int getSoPhanTu() const;
	float getHeSo(int iViTri) const;
	void setHeSo(int iViTri, float fValue);
	int getSoMu(int iViTri) const;
	void setSoMu(int iViTri, int iValue);

	void Xuat();
	void Nhap();

	void ThemPhanTu(float fheso, int isomu);
	DaThuc SapXep() const;
	DaThuc RutGon();

	DaThuc operator+(const DaThuc &dt) const;
	DaThuc operator-(const DaThuc &dt) const;
	DaThuc operator*(const DaThuc &dt) const;
	DaThuc operator/(const DaThuc &dt) const;
	int operator()(const int &iValue) const;
	float operator()(const float &fValue) const;

	DaThuc DaoHamCap(int iCap);
	DaThuc NguyenHam();

	~DaThuc();
};

