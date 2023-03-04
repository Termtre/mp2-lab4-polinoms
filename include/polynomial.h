#pragma once

#include <iostream>
#include "list.hpp"
#include "monom.h"

using namespace std;

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

	void getPolynomial();							// ������� ������� �� ����� // for Monom
};