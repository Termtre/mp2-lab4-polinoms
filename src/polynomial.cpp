#include "polynomial.h"

// Monom
Monom::Monom() : degree(int()), coef(double())
{}

Monom::Monom(int var, double dvar) : degree(int(var)), coef(double(dvar))
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

// Polynomial
Polynomial::Polynomial()
{
	this->tData.push_back(Monom());
}

Polynomial::Polynomial(List<Monom>& other)
{
	if (other.isEmpty()) this->tData.push_back(Monom());

	else this->tData = other;
}

void Polynomial::getPolynomial()
{
	Node<Monom>* temp = tData.begin();
	string str;

	for (size_t i = 0; i < tData.size(); i++, temp = temp->next)
	{
		if ((i != 0) && temp->data.coef > 0) cout << "+";
		cout << temp->data.coef;
		if ((temp->data.degree / 100) % 10) cout << "x^(" << ((temp->data.degree / 100) % 10) << ")";
		if ((temp->data.degree / 10) % 10) cout << "y^(" << ((temp->data.degree / 10) % 10) << ")";
		if (temp->data.degree % 10) cout << "z^(" << (temp->data.degree % 10) << ")";
	}
}
