#pragma once

#include <iostream>
#include "list.h"

using namespace std;

struct Monom // MB class??
{
	int degree;
	double coef;

	Monom();										// ����������� �� ���������

	Monom(int, double);								// ����������� �������������

	Monom(const Monom&);							// ����������� �����������

	const Monom& operator =(const Monom&);			// �������� =

	Monom operator +(const Monom&);					// �������� +

	Monom& operator +=(const Monom&);				// �������� +=

	Monom operator -(const Monom&);					// �������� -

	Monom& operator -=(const Monom&);				// �������� -=

	Monom operator *(const Monom&);					// �������� *

	Monom& operator *=(double);						// �������� *=

	Monom operator /(const Monom&);					// �������� /

	bool operator <(const Monom&) const;			// �������� <

	bool operator <=(const Monom&) const;			// �������� <=

	bool operator >(const Monom&) const;			// �������� >

	bool operator >=(const Monom&) const;			// �������� >=

	bool operator ==(const Monom&) const;			// �������� ==

	bool operator !=(const Monom&) const;			// �������� !=

	void setMonom(int, double);						// ��������� �������� ������
};

class Polynomial
{
private:
	List<Monom> data;
public:
	Polynomial();									// ����������� �� ���������		
													
	Polynomial(const List<Monom>&);					// ����������� ������������� �������

	Polynomial(Monom*, size_t);						// ����������� ������������� �������� �������
	//������� ������???
	// ���� ��, �������� ������� �����

	Polynomial(const Monom&);						// ����������� ������������� �������

	Polynomial(const Polynomial&);					// ����������� �����������

	const Polynomial& operator =(Polynomial&);		// �������� =

	Polynomial operator +(const Polynomial&) const; // �������� +

	Polynomial& operator +=(const Polynomial&);		// �������� +=

	Polynomial& operator *=(double);				// �������� *=

	Polynomial& operator -=(Polynomial&);			// �������� -=
	// peredelat'

	void getPolynomial();							// ������� ������� �� �����
};