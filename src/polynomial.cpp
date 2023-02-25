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

Monom& Monom::operator *=(double var)
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
	return this->degree < other.degree;
}

bool Monom::operator <=(const Monom& other) const
{
	return this->degree <= other.degree;
}

bool Monom::operator >(const Monom& other) const
{
	return this->degree > other.degree;
}

bool Monom::operator >=(const Monom& other) const
{
	return this->degree >= other.degree;
}

bool Monom::operator ==(const Monom& other) const
{
	return this->degree == other.degree;
}

bool Monom::operator !=(const Monom& other) const
{
	return this->degree != other.degree;
}

void Monom::setMonom(int _degree, double _coef)
{
	degree = _degree;
	coef = _coef;
}

// Polynomial
Polynomial::Polynomial()
{
	this->data.push_front(Monom());
}

Polynomial::Polynomial(const List<Monom>& other)
{
	if (other.isEmpty()) this->data.push_front(Monom());

	else this->data = other;
}

Polynomial::Polynomial(Monom* array, size_t arraySize): data(array, arraySize) // Нулевой массив???/ Если да, добавить нулевой моном
{}

Polynomial::Polynomial(const Monom& monom)
{
	this->data.push_front(monom);
}

Polynomial::Polynomial(const Polynomial& other)
{
	this->data = other.data;
}

const Polynomial& Polynomial::operator =(Polynomial& other)
{
	if (this->data != other.data) this->data = other.data;

	return *this;
}

Polynomial Polynomial::operator +(const Polynomial& other) const
{
	Polynomial third(*this);

	third.data.merge(other.data);
	third.data.sort(0, third.data.size() - 1);

	for (size_t i = 0; i < third.data.size(); i++)
	{
		//if (((i + 1) != third.data.size()) && (third.data[i] == third.data[i + 1]))
		//{
			//third.data[i] += third.data[i + 1];
			//third.data.erase(i + 1);
		//}

		//if (fabs(third.data[i].coef) < static_cast<double>(1e-15))
		//{
		//	third.data.erase(i);
		//	i--;
		//}
	}

	if (third.data.isEmpty()) third.data.push_front(Monom());

	return third;
}

Polynomial& Polynomial::operator +=(const Polynomial& other)
{
	this->data.merge(other.data);
	this->data.sort(0, this->data.size() - 1);

	for (size_t i = 0; i < this->data.size(); i++)
	{
		//if (((i + 1) != this->data.size()) && (this->data[i] == this->data[i + 1]))
		//{
			//this->data[i] += this->data[i + 1];
			this->data.erase(i + 1);
		//}

		//if (fabs(this->data[i].coef) < static_cast<double>(1e-15))
		//{
			//this->data.erase(i);
			//i--;
		//}
	}

	if (this->data.isEmpty()) this->data.push_front(Monom());

	return *this;
}

Polynomial& Polynomial::operator *=(double var)
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		//this->data[i] *= var;

		//if (fabs(this->data[i].coef) < static_cast<double>(1e-15))
		//{
		//	this->data.erase(i);
		//	i--;
		//}
	}

	if (this->data.isEmpty()) this->data.push_front(Monom());

	return *this;
}

Polynomial& Polynomial::operator -=(Polynomial& other) // peredelat'
{
	Polynomial temp(other);
	*this += temp *= -1.0;

	return *this;
}

void Polynomial::getPolynomial()
{
	if (data.isEmpty()) cout << "0" << endl;

	else
	{
		for (size_t i = 0; i < data.size(); i++)
		{
				//cout << data[i].coef << " " << data[i].degree << endl;
		}
	}
}