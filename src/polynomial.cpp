#include "polynomial.h"

// Monom
Monom::Monom() : degree(int()), coef(double())
{}

Monom::Monom(int _degree, double _coef)
{
	if (_degree < 0) throw "\"Monom::initialization constructor\": degree can't be less than zero";

	degree = _degree;
	coef = _coef;
}

Monom::Monom(const Monom& other)
{
	this->degree = other.degree;
	this->coef = other.coef;
}

const Monom& Monom::operator =(const Monom& other)
{
	this->degree = other.degree;
	this->coef = other.coef;

	return *this;
}

Monom Monom::operator +(const Monom& other)
{
	if (*this != other) throw "\"Monom::operator +\": monoms have diff degrees";

	Monom third(*this);

	third.coef += other.coef;

	return third;
}

Monom& Monom::operator +=(const Monom& other)
{
	if (*this != other) throw "\"Monom::operator +\": monoms have diff degrees";

	this->coef += other.coef;

	return *this;
}

Monom Monom::operator -(const Monom& other)
{
	if (*this != other) throw "\"Monom operator -\": monoms have diff degrees";

	Monom third(*this);

	third.coef -= other.coef;

	return third;
}

Monom& Monom::operator -=(const Monom& other)
{
	if (*this != other) throw "\"Monom::operator +\": monoms have diff degrees";

	this->coef -= other.coef;

	return *this;
}

Monom Monom::operator *(const Monom& other)
{
	Monom third(*this);

	third.degree += other.degree;
	third.coef *= other.coef;

	return third;
}

Monom& Monom::operator *=(double var) // ????
{
	this->coef *= var;

	return *this;
}

Monom Monom::operator /(const Monom& other)
{
	if (other.coef == 0) throw "\"Monom::operator /\": Division by zero";

	Monom third(*this);

	third.degree -= other.degree;
	third.coef /= other.coef;

	return third;
}

bool Monom::operator <(const Monom& other) const
{
	if (this->degree != other.degree) return this->degree < other.degree;
	return this->coef < other.coef;
}

bool Monom::operator <=(const Monom& other) const
{
	if (this->degree != other.degree) return this->degree <= other.degree;
	return this->coef <= other.coef;
}

bool Monom::operator >(const Monom& other) const
{
	if (this->degree != other.degree) return this->degree > other.degree;
	return this->coef > other.coef;
}

bool Monom::operator >=(const Monom& other) const
{
	if (this->degree != other.degree) return this->degree >= other.degree;
	return this->coef >= other.coef;
}

bool Monom::operator ==(const Monom& other) const // ????
{
	if (this->degree != other.degree) return false;
	return this->coef == other.coef;
}

bool Monom::operator !=(const Monom& other) const // ????
{
	if (this->degree != other.degree) return this->degree < other.degree;
	return this->coef < other.coef;
}

void Monom::setMonom(int _degree, double _coef)
{
	degree = _degree;
	coef = _coef;
}

// Polynomial
Polynomial::Polynomial()
{}

Polynomial::Polynomial(const List<Monom>& other)
{}

Polynomial::Polynomial(Monom* array, size_t arraySize): data(array, arraySize) // Нулевой массив???/ Если да, добавить нулевой моном
{}

Polynomial::Polynomial(const Monom& monom)
{}

Polynomial::Polynomial(const Polynomial& other)
{}

const Polynomial& Polynomial::operator =(Polynomial& other)
{
	return *this;
}

Polynomial Polynomial::operator +(const Polynomial& other) const
{
	return *this;
}

Polynomial& Polynomial::operator +=(const Polynomial& other)
{
	return *this;
}

Polynomial& Polynomial::operator *=(double var)
{
	return *this;
}

Polynomial& Polynomial::operator -=(Polynomial& other) // peredelat'
{
	return *this;
}

void Polynomial::getPolynomial()
{}