#pragma once

#include <iostream>

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										// ����������� �� ���������

	Monom(int, double);								// ����������� �������������

	Monom(double);									// ����������� ��������������

	Monom(const Monom&);							// ����������� �����������

	const Monom& operator =(const Monom&);			// �������� =

	Monom operator +(const Monom&) const;			// �������� +

	Monom operator -(const Monom&) const;			// �������� -

	Monom operator *(const Monom&) const;			// �������� *

	Monom operator *(const double&) const;			// �������� * �� const

	bool operator <(const Monom&) const;			// �������� <

	bool operator <=(const Monom&) const;			// �������� <=

	bool operator >(const Monom&) const;			// �������� >

	bool operator >=(const Monom&) const;			// �������� >=

	bool operator ==(const Monom&) const;			// �������� ==

	bool operator !=(const Monom&) const;			// �������� !=

	void setMonom(int, double);						// ��������� �������� ������
	
	void getMonom();								// ����� �� ����� ������
};