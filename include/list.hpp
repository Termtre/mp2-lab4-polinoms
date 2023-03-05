#pragma once

#include <iostream>

using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;

	Node() : data(T()), next(nullptr) {}						// Конструктор по умолчанию

	Node(T var) : data(static_cast<T>(var)), next(nullptr) {}	// Конструктор инициализации
};

template<class T>
class List														// Класс односвязный список с фиктивной головой
{
private:
	Node<T>* head;
	Node<T>* tail;
	size_t tsize;
public:
	List() : head(new Node<T>()), tsize(size_t(0)), tail(nullptr)
	{
		head->next = tail;
	}

	List(T var) : head(new Node<T>()), tsize(size_t(1)), tail(new Node<T>(static_cast<T>(var)))
	{
		head->next = tail;
	}

	List(const List& other) : head(new Node<T>()), tsize(other.tsize)
	{
		if (other.isEmpty())
		{
			this->tail = nullptr;
			this->head->next = this->tail;
		}

		else if (other.tsize == 1)
		{
			this->tail = new Node<T>(other.head->next->data);
			this->head->next = this->tail;
		}

		else
		{
			Node<T>* o = other.head->next;
			Node<T>* t = this->head;

			while (o->next)
			{
				t->next = new Node<T>(o->data);
				t = t->next;
				o = o->next;
			}

			this->tail = new Node<T>(o->data);
			t->next = tail;
		}
	}

	~List()
	{
		clear();

		delete head;
		head = nullptr;
	}

	Node<T>* begin() const
	{
		return head->next;
	}

	Node<T>* end() const
	{
		return tail;
	}

	bool isEmpty() const
	{
		return tail == nullptr;
	}

	size_t size()
	{
		return tsize;
	}

	void push_front(T var)
	{
		if (isEmpty())
		{
			tail = new Node<T>(static_cast<T>(var));
			head->next = tail;
		}

		else
		{
			Node<T>* temp = head->next;
			head->next = new Node<T>(static_cast<T>(var));
			head->next->next = temp;
		}

		tsize++;
	}

	void push_back(T var)
	{
		if (isEmpty())
		{
			tail = new Node<T>(static_cast<T>(var));
			head->next = tail;
		}

		else
		{
			tail->next = new Node<T>(static_cast<T>(var));
			tail = tail->next;
		}

		tsize++;
	}

	bool find(Node<T>* cur) const
	{
		if (isEmpty()) return cur == nullptr;

		else if (this->tsize == 1) return tail == cur;

		else
		{
			Node<T>* temp = head->next;

			while (temp)
			{
				if (temp == cur) return true;
				temp = temp->next;
			}

			return false;
		}
	}

	void deleteNextNode(Node<T>* node)
	{
		if (!find(node) || tsize == 1 || isEmpty() || node == tail) return;

		if (node->next == tail)
		{
			Node<T>* temp = node;
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}

		else
		{
			Node<T>* temp;
			Node<T>* cur = node;
			temp = cur;
			cur = cur->next;
			temp->next = cur->next;
			delete cur;
		}

		tsize--;
	}

	void clear()
	{
		if (!isEmpty())
		{
			Node<T>* pointer = head->next;
			Node<T>* temp;

			while (pointer)
			{
				temp = pointer;
				pointer = pointer->next;
				delete temp;
			}

			tail = nullptr;
			head->next = tail;
			tsize = size_t(0);
		}
	}

	bool operator ==(const List& other) const
	{
		if (this->tsize == other.tsize)
		{
			if (this->isEmpty()) return true;

			else if (this->tsize == 1) return this->head->next->data == other.head->next->data;

			else
			{
				Node<T>* t = this->head->next;
				Node<T>* o = other.head->next;

				while (t)
				{
					if (t->data != o->data) return false;
					t = t->next;
					o = o->next;
				}

				return true;
			}
		}

		return false;
	}

	bool operator !=(const List& other) const
	{
		return !(*this == other);
	}

	const List& operator =(const List& other) // ???
	{
		if (*this != other)
		{	
			if (this->tsize == other.tsize)
			{
				if (this->tsize == 1) head->next->data = other.head->next->data;

				else
				{
					Node<T>* t = this->head->next;
					Node<T>* o = other.head->next;

					while (o)
					{
						t->data = o->data;
						t = t->next;
						o = o->next;
					}
				}
			}

			else
			{
				this->clear();

				if (other.isEmpty());

				else if (other.tsize == 1)
				{
					this->push_back(other.head->next->data);
				}

				else
				{
					Node<T>* temp = other.head->next;

					while (temp)
					{
						this->push_back(temp->data);
						temp = temp->next;
					}
				}
			}
		}

		return *this;
	}

	void merge(const List& other)
	{
		if (other.isEmpty()) return;

		Node<T>* t = this->head->next;
		Node<T>* o = other.head->next;
		List<T> third;

		while (t || o)
		{
			if (t && ((o == nullptr) || (t->data <= o->data)))
			{
				third.push_back(t->data);
				t = t->next;
			}

			else
			{
				third.push_back(o->data);
				o = o->next;
			}
		}

		*this = third;
	}

	void splice(List& one, List& second) const
	{
		if (!one.isEmpty()) one.clear();
		if (!second.isEmpty()) second.clear();

		Node<T>* temp = this->begin();
		int middle = this->tsize != 1 ? (static_cast<int>(this->tsize) / 2) : 1;

		for (int i = 0; i < middle; i++, temp = temp->next)
			one.push_back(temp->data);

		for (int i = middle; i < this->tsize; i++, temp = temp->next)
			second.push_back(temp->data);
	}

	void sort()
	{
		if (!this->isEmpty() && this->tsize != 1)
		{
			List<T> left, right;
			this->splice(left, right);
			left.sort();
			right.sort();
			left.merge(right);
			*this = left;
		}
	}

	T pop_front()
	{
		if (this->isEmpty()) throw "\"List::pop_front\": list is empty";

		T result = this->head->next->data;

		if (this->tsize == 1)
		{
			delete this->head->next;
			this->tail = nullptr;
			this->head->next = this->tail;
		}

		else
		{
			Node<T>* temp = this->head->next->next;
			delete this->head->next;
			this->head->next = temp;
		}

		tsize--;

		return result;
	}

	friend ostream& operator <<(ostream& ostr, const List& other)
	{
		Node<T>* temp = other.begin();

		while (temp)
		{
			ostr << temp->data << " ";
			temp = temp->next;
		}

		return ostr;
	}
};