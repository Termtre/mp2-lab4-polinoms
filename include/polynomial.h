#pragma once

#include <iostream>
#include "list.hpp"

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										//  онструктор по умолчанию

	Monom(int, double);								//  онструктор инициализации

	Monom(const Monom&);							//  онструктор копировани€

	const Monom& operator =(const Monom&);			// ќператор =

	Monom operator +(const Monom&);					// оператор +

	Monom operator -(const Monom&);					// оператор -

	Monom operator *(const Monom&);					// оператор *

	Monom operator /(const Monom&);					// оператор /

	bool operator <(const Monom&) const;			// оператор <

	bool operator <=(const Monom&) const;			// оператор <=

	bool operator >(const Monom&) const;			// оператор >

	bool operator >=(const Monom&) const;			// оператор >=

	bool operator ==(const Monom&) const;			// оператор ==

	bool operator !=(const Monom&) const;			// оператор !=

	void setMonom(int, double);						// ”становка значени€ монома
};

class Polynomial
{
private:
	List<Monom> tData;
public:
	Polynomial();									//  онструктор по умолчанию		
													
	Polynomial(List<Monom>&);					//  онструктор инициализации списком

	Polynomial(Monom*, size_t);						//  онструктор инициализации массивом мономов
	//Ќулевой массив???
	// ≈сли да, добавить нулевой моном

	Polynomial(const Monom&);						//  онструктор инициализации мономом

	Polynomial(const Polynomial&);					//  онструктор копировани€

	const Polynomial& operator =(Polynomial&);		// оператор =

	Polynomial operator +(const Polynomial&) const; // оператор +

	Polynomial& operator +=(const Polynomial&);		// оператор +=

	Polynomial& operator *=(double);				// оператор *=

	Polynomial& operator -=(Polynomial&);			// оператор -=
	// peredelat'

	void getPolynomial();							// ¬ывести полином на экран
};