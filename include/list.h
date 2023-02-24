#pragma once

#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data = T();
	Node<T>* next = nullptr;

	Node()
	{}

	Node(T var) : data(static_cast<T>(var))
	{}
};

template<class T>
class List
{
private:
	Node<T>* head = new Node<T>();
	//???Node<T>* tale = new Node<T>();
	size_t tsize = static_cast <size_t>(0);
public:
	List() {}// it's correct

	List(T var) // it's correct
	{
		head->next = new Node<T>(var);
		tsize++;
	}

	List(T* array, size_t arraySize) // it's correct
	{
		for (int i = arraySize - 1; i >= 0; i--)
		{
			this->push_front(array[i]);
		}
	}

	List(const List& other) // it's correct
	{
		if (other.isEmpty()) return;

		else if (other.tsize == 1)
		{
			this->head->next = new Node<T>(other.head->next->data);
			this->tsize++;
		}

		else
		{
			Node<T>* p = this->head;
			Node<T>* temp = other.head;

			while (temp->next != nullptr)
			{
				p->next = new Node<T>(temp->next->data);
				this->tsize++;
				temp = temp->next;
				p = p->next;
			}
		}
	}

	~List() // it's maybe correct, require to confirm
	{
		this->clear();
		delete head;
		head = nullptr;
	}

	Node<T>* getNode(int index)
	{
		if ((index < 0) || (index > this->tsize)) throw "\"List::getNode\": Wrong index";

		if (index == 0) return head->next;

		else
		{
			Node<T>* temp = head;

			for (size_t i = 0; i <= index; i++)
				temp = temp->next;

			return temp;
		}
	}

	void push_back(T var) // it's correct
	{
		if (isEmpty()) head->next = new Node<T>(var);

		else
		{
			Node<T>* temp;

			if (tsize == 1) temp = head->next;

			else  temp = getNode(tsize);

			temp = new Node<T>(var);
			tsize++;
			// С использованием getNode
			/*Node<T>* temp = head->next;

			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = new Node<T>(var);*/
		}
	}

	void push_front(T var)
	{
		Node<T>* temp = head->next;
		head->next = new Node<T>(var);
		head->next->next = temp;
		tsize++;
	}

	void insert(size_t index, T var) // it's correct// User must be accurate to use this method
	{
		if (index == 0) push_front(var);

		else
		{
			Node<T>* t = getNode(index - 1);
			Node<T>* p = t->next;

			t->next = new Node<T>(var);
			t->next->next = p;
			tsize++;
		}
		/*if (index == 0)
		{
			Node<T>* temp = new Node<T>(var);
			temp->next = head->next;
			head->next = temp;
			tsize++;
		}

		else
		{
			Node<T>* temp = head->next;

			for (size_t i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}

			Node<T>* p = new Node<T>(var);
			p->next = temp->next;
			temp->next = p;
			tsize++;
		}*/
	}

	T pop_back() // it's correct
	{
		if (isEmpty()) throw "\"List::pop\": List is empty";

		else
		{
			Node<T>* temp;

			if (tsize == 1) temp = head;

			else temp = getNode(tsize - 2);

			T result = temp->next->data;

			delete temp->next;
			temp->next = nullptr;

			return result;
		}
		/*Node<T>* temp = head->next;

		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}

		T tmp = temp->next->data;
		delete temp->next;
		temp->next = nullptr;
		tsize--;

		return tmp;*/
	}

	void merge(const List& other) // it's correct
	{
		if (other.isEmpty()) return;

		else if (other.tsize == 1) this->push_back(other.head->next->data);

		else
		{
			Node<T>* temp = other.head;

			while (temp->next != nullptr)
			{
				temp = temp->next;

				this->push_back(temp->data);
			}
		}
	}

	void erase(size_t index) //it's correct
	{
		if ((index < 0) || (index >= tsize)) throw "\"List::erase\": Wrong index";

		Node<T>* temp = head;

		for (size_t i = 0; i < index; i++)
			temp = temp->next;

		Node<T>* tmp = temp->next;
		temp->next = tmp->next;
		delete tmp;
		tsize--;
	}

	void clear() // It's correct
	{
		if (isEmpty()) return;

		else if (tsize == 1)
		{
			delete head->next;
			head->next = nullptr;
			tsize--;
		}

		else
		{
			Node<T>* p = this->head;
			Node<T>* t = p->next;

			while (t)
			{
				p = t;
				t = t->next;
				delete p;
				tsize--;
			}

			head->next = nullptr;
		}
	}

	List& operator =(const List& other) // it isn't correct
	{
		if (this != &other)
		{
			if (this->tsize == other.tsize)
			{
				if (this->tsize == 1) this->head->next->data = other.head->next->data;

				else
				{
					Node<T>* t = this->head->next;
					Node<T>* p = other.head->next;

					while (p)
					{
						t->data = p->data;
						t = t->next;
						p = p->next;
					}
					/*for (size_t i = 0; i < this->size; i++)
						(*this)[i] = other[i];*/
				}
			}

			else
			{
				this->clear();

				Node<T>* t = this->head;
				Node<T>* p = other.head->next;

				while (p)
				{
					tsize++;
					t->next = new Node<T>(p->data);
					t = t->next;
					p = p->next;
				}
				//for (size_t i = 0; i < other.size; i++)
				//{
				//	this->push(other[i]);
				//}
			}
		}

		return *this;
	}

	bool operator ==(const List& other) const // correct
	{
		if (this->tsize != other.tsize) return false;

		else if (this->isEmpty() && other.isEmpty()) return true;

		else if (this->tsize == 1)
		{
			if (this->head->next->data == other.head->next->data) return true;

			else return false;
		}

		else
		{
			Node<T>* temp = this->head;
			Node<T>* p = other.head;

			while (temp->next != nullptr)
			{
				if (temp->next->data != p->next->data) return false;
				temp = temp->next;
				p = p->next;
			}

			return true;
		}
	}

	bool operator !=(List& other) const
	{
		return !(*this == other);
	}

	Node<T>*& begin()
	{
		return head->next;
	}

	void getSize()
	{
		cout << tsize << endl;
	}

	size_t size()
	{
		return tsize;
	}

	bool isEmpty() const
	{
		return tsize == 0;
	}

	void getList() const
	{
		if (isEmpty()) cout << "\"List::getList\": List is empty" << endl;

		else if (tsize == 1) cout << head->next->data << endl;

		else
		{
			Node<T>* temp = head->next;

			while (temp != nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}

			cout << endl;
		}
	}

	friend ostream& operator <<(ostream& ostr, List& other)
	{
		Node<T>* temp = other.head;

		while (temp->next != nullptr)
		{
			temp = temp->next;

			ostr << temp->data << " ";
		}

		return ostr;
	}

	void merge(int first, int last) // without []
	{
		List<T> other(*this);

		int middle = (first + last) / 2;

		for (size_t i = first, j = middle + 1; (i + j) <= last;)
		{
			//if ()
		}
	}

	/*void merge(int first, int last) // without []
	{
		List<T> other(*this);

		int middle = (first + last) / 2;
		int left = first;
		int right = middle + 1;

		for (size_t i = first; i <= last; i++)
		{
			if ((left <= middle) && ((right > last) || ((*this)[left] < (*this)[right])))
			{
				other[i] = (*this)[left];
				left++;
			}

			else
			{
				other[i] = (*this)[right];
				right++;
			}
		}

		for (size_t i = first; i <= last; i++)
		{
			(*this)[i] = other[i];
		}
	}*/

	void sort(int first, int last)
	{
		if ((first < 0) || (last >= this->tsize)) throw "\"List::sort\": Wrong range";

		int middle = (first + last) / 2;

		if (first < last)
		{
			this->sort(first, middle);
			this->sort(middle + 1, last);
			this->merge(first, last);
		}
	}
};