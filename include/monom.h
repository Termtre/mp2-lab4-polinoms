﻿#pragma once

#include <iostream>

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										// Конструктор по умолчанию

	Monom(int, double);								// Конструктор инициализации

	Monom(double);									// Конструктор преобразования

	Monom(const Monom&);							// Конструктор копирования

	const Monom& operator =(const Monom&);			// оператор =

	Monom operator +(const Monom&) const;			// оператор +

	Monom& operator +=(const Monom&);				// оператор +=

	Monom operator -(const Monom&) const;			// оператор -

	Monom operator *(const Monom&) const;			// оператор *

	Monom operator *=(const Monom& other);			// оператор *=

	Monom operator *=(const double&);				// оператор *= на const

	bool operator <(const Monom&) const;			// оператор <

	bool operator <=(const Monom&) const;			// оператор <=

	bool operator >(const Monom&) const;			// оператор >

	bool operator >=(const Monom&) const;			// оператор >=

	bool operator ==(const Monom&) const;			// оператор ==

	bool operator !=(const Monom&) const;			// оператор !=

	void setMonom(int, double);						// Установка значения монома
	
	void getMonom();								// Вывод на экран монома
};