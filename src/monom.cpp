#include "monom.h"

// Monom
Monom::Monom() : degree(int(0)), coef(double(0))
{}

Monom::Monom(int var, double dvar) : degree(int(var)), coef(double(dvar))
{
	if (degree < 0 || degree > 999) throw "\"Monom::Monom\": min monom degree is 0 and max one is 999";
}

Monom::Monom(double dvar) : degree(int(0)), coef(double(dvar))
{}

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

Monom Monom::operator +(const Monom& other) const
{
	if (this->degree != other.degree) throw "\"Monom::operator+\": you can add two monoms only with equal size";
	Monom third(*this);
	third.coef += other.coef;
	return third;
}

Monom& Monom::operator +=(const Monom& other)
{
	if (this->degree != other.degree) throw "\"Monom::operator+=\": you can add two monoms only with equal size";
	this->coef += other.coef;
	return *this;
}

Monom Monom::operator -(const Monom& other) const
{
	if (this->degree != other.degree) throw "\"Monom::operator-\": you can subtract two monoms only with equal size";
	Monom third(*this);
	third.coef -= other.coef;
	return third;
}

Monom Monom::operator *(const Monom& other) const
{
	int x, y, z, xo, yo, zo;

	x = (this->degree / 100) % 10;
	y = (this->degree / 10) % 10;
	z = this->degree % 10;
	xo = (other.degree / 100) % 10;
	yo = (other.degree / 10) % 10;
	zo = other.degree % 10;

	if ((x + xo) > 9 ||
		(y + yo) > 9 ||
		(z + zo) > 9) throw "\"Monom::operator*\": max monom degree by variable is 9";

	Monom third(*this);
	third.degree += other.degree;
	third.coef *= other.coef;
	return third;
}

Monom Monom::operator *=(const Monom& other)
{
	int x, y, z, xo, yo, zo;

	x = (this->degree / 100) % 10;
	y = (this->degree / 10) % 10;
	z = this->degree % 10;
	xo = (other.degree / 100) % 10;
	yo = (other.degree / 10) % 10;
	zo = other.degree % 10;

	if ((x + xo) > 9 ||
		(y + yo) > 9 ||
		(z + zo) > 9) throw "\"Monom::operator*\": max monom degree by variable is 9";

	this->degree += other.degree;
	this->coef *= other.coef;
	return *this;
}

Monom Monom::operator *=(const double& temp)
{
	this->coef *= temp;
	return *this;
}

bool Monom::operator <(const Monom& other) const
{
	if (this->degree == other.degree) return this->coef < other.coef;
	return this->degree < other.degree;
}

bool Monom::operator <=(const Monom& other) const
{
	if (this->degree == other.degree) return this->coef <= other.coef;
	return this->degree <= other.degree;
}

bool Monom::operator >(const Monom& other) const
{
	if (this->degree == other.degree) return this->coef > other.coef;
	return this->degree > other.degree;
}

bool Monom::operator >=(const Monom& other) const
{
	if (this->degree == other.degree) return this->coef >= other.coef;
	return this->degree >= other.degree;
}

bool Monom::operator ==(const Monom& other) const
{
	if (this->degree == other.degree) return this->coef == other.coef;
	return false;
}

bool Monom::operator !=(const Monom& other) const
{
	return !(*this == other);
}

void Monom::setMonom(int _degree, double _coef)
{
	degree = _degree;
	coef = _coef;
}

void Monom::getMonom()
{
	int x, y, z;

	x = (this->degree / 100) % 10;
	y = (this->degree / 10) % 10;
	z = this->degree % 10;

	if (coef != 1.0) cout << this->coef;

	if (x)
	{
		cout << "x";
		if (x != 1) cout << "^(" << x << ")";
	}

	if (y)
	{
		cout << (x ? "*" : "") << "y";
		if (y != 1) cout << "^(" << y << ")";
	}

	if (z)
	{
		cout << (y ? "*" : "") << "z"; 
		if (z != 1) cout << "^(" << z << ")";
	}
}