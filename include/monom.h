#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Monom
{
	const int max_degree = 999;
	int degree;
	double coef;

	Monom();                                        // Конструктор по умолчанию

	Monom(int, double);                             // Конструктор инициализации

	Monom(double);                                  // Конструктор преобразования

	Monom(const Monom&);                            // Конструктор копирования

	const Monom& operator =(const Monom&);          // оператор =

	Monom operator +(const Monom&) const;           // оператор +

	Monom& operator +=(const Monom&);               // оператор +=

	Monom operator -(const Monom&) const;           // оператор -

	Monom operator *(const Monom&) const;           // оператор *

	Monom operator *=(const Monom& other);          // оператор *=

	Monom operator *=(const double&);               // оператор *= на const

	bool operator <(const Monom&) const;            // оператор <

	bool operator <=(const Monom&) const;           // оператор <=

	bool operator >(const Monom&) const;            // оператор >

	bool operator >=(const Monom&) const;           // оператор >=

	bool operator ==(const Monom&) const;           // оператор ==

	bool operator !=(const Monom&) const;           // оператор !=

	string stringMonom() const;                     // Вернуть моном в качестве строки
};