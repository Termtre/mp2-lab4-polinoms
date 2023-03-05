#include "polynomial.h"

// Polynomial
Polynomial::Polynomial()
{}

Polynomial::Polynomial(const Polynomial& other) : tData(other.tData)
{}

Polynomial::Polynomial(const List<Monom>& other)
{
	if (other.isEmpty());

	else this->tData = other;
}

Polynomial::Polynomial(const Monom& monom)
{
	this->tData.push_back(monom);
}

void Polynomial::truePolynomial()
{
	if (tData.isEmpty()) return;
	Node<Monom>* slow = tData.begin();
	Node<Monom>* fast = slow->next;
	
	while (fast)
	{
		if (slow->data.degree == fast->data.degree)
		{
			slow->data += fast->data;
			tData.deleteNextNode(slow);
			fast = slow->next;
		}

		else
		{
			fast = fast->next;
			slow = slow->next;
		}
	}

	slow = tData.begin();
	fast = slow->next;

	while (fast) // Удаление первого элемента?
	{
		if (fabs(fast->data.coef) < 1e-15)
		{
			tData.deleteNextNode(slow);
			fast = slow->next;
		}

		else
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	if (fabs(tData.begin()->data.coef) < 1e-15) tData.pop_front();
}

void Polynomial::setPolynomial()
{
	size_t degree;
	int size;
	double coef;

	cout << "Введите количество мономов в полиноме: ";
	cin >> size;

	if (size < 0) throw "\"Polynomial::setPolynomial\": min size is 0";

	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите степень монома: ";
		cin >> degree;

		cout << "Введите коэффициент монома: ";
		cin >> coef;

		tData.push_back(Monom(degree, coef));
	}

	tData.sort();
	this->truePolynomial();
}

void Polynomial::getPolynomial()
{
	if (tData.isEmpty()) cout << "0";

	else
	{
		Node<Monom>* temp = tData.begin();

		for (size_t i = 0; i < tData.size(); i++, temp = temp->next)
		{
			if ((i != 0) && temp->data.coef > 0) cout << "+";
			temp->data.getMonom();
		}
	}

	cout << endl;
}

const Polynomial& Polynomial::operator =(const Polynomial& other)
{
	this->tData = other.tData;

	return *this;
}

Polynomial Polynomial::operator +(const Polynomial& other) const
{
	Polynomial third(*this);

	third.tData.merge(other.tData);
	third.truePolynomial();

	return third;
}

Polynomial Polynomial::operator *(const Monom& monom) const
{
	Polynomial third(*this);
	Node<Monom>* temp = third.tData.begin();

	while (temp)
	{
		temp->data *= monom;
		temp = temp->next;
	}

	third.truePolynomial();

	return third;
}

Polynomial Polynomial::operator *(const double& var) const
{
	Polynomial third(*this);
	
	Node<Monom>* temp = third.tData.begin();

	while (temp)
	{
		temp->data *= var;
		temp = temp->next;
	}

	third.truePolynomial();

	return third;
}

Polynomial Polynomial::operator *=(const double& var)
{
	Node<Monom>* temp = this->tData.begin();

	while (temp)
	{
		temp->data *= var;
		temp = temp->next;
	}

	this->truePolynomial();

	return *this;
}

Polynomial Polynomial::operator -(const Polynomial& other) const
{
	Polynomial third(*this);
	third.tData.merge((other * -1.0).tData);
	third.truePolynomial();

	return third;
}

Polynomial Polynomial::operator *(const Polynomial& other) const
{
	Polynomial third(*this);
	Polynomial fourth;
	Node<Monom>* temp = other.tData.begin();

	while (temp)
	{
		fourth = fourth + third * temp->data;
		temp = temp->next;
	}

	third = fourth;

	third.truePolynomial();

	return third;
}