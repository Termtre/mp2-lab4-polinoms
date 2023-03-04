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
	Polynomial();									// Конструктор по умолчанию		
													
	Polynomial(List<Monom>&);						// Конструктор инициализации списком

	Polynomial(Monom*, size_t);						// Конструктор инициализации массивом мономов
	//Нулевой массив???
	// Если да, добавить нулевой моном

	Polynomial(const Monom&);						// Конструктор инициализации мономом

	Polynomial(const Polynomial&);					// Конструктор копирования

	const Polynomial& operator =(Polynomial&);		// оператор =

	Polynomial operator +(const Polynomial&) const; // оператор +

	void getPolynomial();							// Вывести полином на экран // for Monom
};