#include "monom.h"

// Monom
Monom::Monom() : degree(int(0)), coef(double(0))
{}

Monom::Monom(int var, double dvar) : degree(int(var)), coef(double(dvar))
{
	if (degree < 0 || degree > 999)
	{
		string temp = "\"Monom::Monom\": min monom degree is 0 and max one is 999,\n but it's " + to_string(degree);
		throw temp;
	};
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
	if (this->degree != other.degree)
	{
		string temp = "\"Monom::operator+\": you can add two monoms only with equal degree,\n";
		temp += "but first monom has " + to_string(this->degree) + "degree and second one has ";
		temp += to_string(other.degree);
		throw temp;
	}

	Monom third(*this);
	third.coef += other.coef;
	return third;
}

Monom& Monom::operator +=(const Monom& other)
{
	if (this->degree != other.degree)
	{
		string temp = "\"Monom::operator+\": you can add two monoms only with equal degree,\n";
		temp += "but first monom has " + to_string(this->degree) + "degree and second one has ";
		temp += to_string(other.degree);
		throw temp;
	}

	this->coef += other.coef;
	return *this;
}

Monom Monom::operator -(const Monom& other) const
{
	if (this->degree != other.degree)
	{
		string temp = "\"Monom::operator-\": you can subtract two monoms only with equal degree,\n";
		temp += "but first monom has " + to_string(this->degree) + "degree and second one has ";
		temp += to_string(other.degree);
		throw temp;
	}

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
	int px = x + xo, py = y + yo, pz = z + zo;

	if (px > 9 || py > 9 || pz > 9)
	{
		string temp = "\"Monom::operator*\": max monom degree by variable is 9,\n";
		temp += "but if ";
		temp += this->stringMonom();
		temp += " * ";
		temp += other.stringMonom();
		temp += " : ";
		if (px > 9) temp += "x degree = " + to_string(px) + "; ";
		if (py > 9) temp += "y degree = " + to_string(py) + "; ";
		if (pz > 9) temp += "z degree = " + to_string(pz) + "; ";
		throw temp;
	}

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
	int px = x + xo, py = y + yo, pz = z + zo;

	if (px > 9 || py > 9 || pz > 9)
	{
		string temp = "\"Monom::operator*=\": max monom degree by variable is 9,\n";
		temp += "but if ";
		temp += this->stringMonom();
		temp += " * ";
		temp += other.stringMonom();
		temp += " : ";
		if (px > 9) temp += "x degree = " + to_string(px) + "; ";
		if (py > 9) temp += "y degree = " + to_string(py) + "; ";
		if (pz > 9) temp += "z degree = " + to_string(pz) + "; ";
		throw temp;
	}

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

void Monom::getMonom() const
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

string Monom::stringMonom() const
{
	int x, y, z;
	string result;
	x = (this->degree / 100) % 10;
	y = (this->degree / 10) % 10;
	z = this->degree % 10;

	if (coef != 1.0) result += to_string(this->coef);

	if (x)
	{
		result += "x";
		if (x != 1) result += "^(" + to_string(x) + ")";
	}

	if (y)
	{
		result += (x ? "*" : "");
		result += "y";
		if (y != 1) result += "^(" + to_string(y) + ")";
	}

	if (z)
	{
		result += (y ? "*" : "");
		result += "z";
		if (z != 1) result += "^(" + to_string(z) + ")";
	}

	return result;
}