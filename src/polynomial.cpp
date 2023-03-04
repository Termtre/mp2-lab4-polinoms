#include "polynomial.h"

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


	for (size_t i = 0; i < tData.size(); i++, temp = temp->next)
	{
		if ((i != 0) && temp->data.coef > 0) cout << "+";
		temp->data.getMonom();
	}
}
