#pragma once
class mString
{
private:
	char *pData;
	int iBuffer;

	void mstrcpy(char *&Dest, int ibuffer, char *Source) const;
public:
	mString();
	mString(int ibuffer);
	mString(int ibuffer, char *data);

	int getBuffer() const;
	void setBuffer(int ibuffer);
	char *getStr() const;
	void setStr(char *pdata);

	int Length() const;
	
	mString& operator=(const mString &s);
	mString operator+(const mString &s) const;
	
	bool operator>(const mString &s) const;
	bool operator<(const mString &s) const;
	bool operator==(const mString &s) const;
	bool operator!=(const mString &s) const;
	
	mString Swap() const;

	void Nhap();
	void Xuat();

	~mString(void);
};