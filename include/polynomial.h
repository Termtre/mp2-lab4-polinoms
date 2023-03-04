#pragma once

#include <iostream>
#include "list.hpp"

using namespace std;

struct Monom
{
	int degree;
	double coef;

	Monom();										// Конструктор по умолчанию

	Monom(int, double);								// Конструктор инициализации

	Monom(const Monom&);							// Конструктор копирования

	const Monom& operator =(const Monom&);			// Оператор =

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

	void setMonom(int, double);						// Установка значения монома
};

class Polynomial
{
private:
	List<Monom> tData;
public:
	Polynomial();									// Конструктор по умолчанию		
													
	Polynomial(List<Monom>&);						// Конструктор инициализации списком

	Polynomial(Monom*, size_t);						// Конструктор инициализации массивом мономов
	//Нулевой массив???
	// Если да, добавить нулевой моном

	Polynomial(const Monom&);						// Конструктор инициализации мономом

	Polynomial(const Polynomial&);					// Конструктор копирования

	const Polynomial& operator =(Polynomial&);		// оператор =

	Polynomial operator +(const Polynomial&) const; // оператор +

	void getPolynomial();							// Вывести полином на экран
};