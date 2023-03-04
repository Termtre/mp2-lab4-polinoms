#pragma once

#include <iostream>

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										//  онструктор по умолчанию

	Monom(int, double);								//  онструктор инициализации

	Monom(double);									//  онструктор преобразовани€

	Monom(const Monom&);							//  онструктор копировани€

	const Monom& operator =(const Monom&);			// оператор =

	Monom operator +(const Monom&) const;			// оператор +

	Monom operator -(const Monom&) const;			// оператор -

	Monom operator *(const Monom&) const;			// оператор *

	Monom operator *(const double&) const;			// оператор * на const

	bool operator <(const Monom&) const;			// оператор <

	bool operator <=(const Monom&) const;			// оператор <=

	bool operator >(const Monom&) const;			// оператор >

	bool operator >=(const Monom&) const;			// оператор >=

	bool operator ==(const Monom&) const;			// оператор ==

	bool operator !=(const Monom&) const;			// оператор !=

	void setMonom(int, double);						// ”становка значени€ монома
	
	void getMonom();								// ¬ывод на экран монома
};