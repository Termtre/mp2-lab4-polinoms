#pragma once

#include <iostream>
#include "list.hpp"

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										// ����������� �� ���������

	Monom(int, double);								// ����������� �������������

	Monom(const Monom&);							// ����������� �����������

	const Monom& operator =(const Monom&);			// �������� =

	Monom operator +(const Monom&);					// �������� +

	Monom operator -(const Monom&);					// �������� -

	Monom operator *(const Monom&);					// �������� *

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
	List<Monom> tData;
public:
	Polynomial();									// ����������� �� ���������		
													
	Polynomial(List<Monom>&);						// ����������� ������������� �������

	Polynomial(Monom*, size_t);						// ����������� ������������� �������� �������
	//������� ������???
	// ���� ��, �������� ������� �����

	Polynomial(const Monom&);						// ����������� ������������� �������

	Polynomial(const Polynomial&);					// ����������� �����������

	const Polynomial& operator =(Polynomial&);		// �������� =

	Polynomial operator +(const Polynomial&) const; // �������� +

	void getPolynomial();							// ������� ������� �� �����
};