#pragma once

#include <iostream>

using namespace std;
												
template <class T>								// ���� ������
struct Node
{
	T data = T();
	Node<T>* next = nullptr;

	Node() {}									// ����������� �� ���������

	Node(T var) : data(static_cast<T>(var)) {}	// ����������� �������������
};

template<class T>
class List										// ����� ����������� ������ � ��������� �������
{
private:
	Node<T>* head = new Node<T>();
	//???Node<T>* tale = new Node<T>();
	size_t tsize = static_cast <size_t>(0);
public:
	List();// it's correct							// ����������� �� ���������

	List(T); // it's correct						// ����������� ������������� ������ ��������

	List(T*, int); // it's correct					// ����������� ������������� �������� ���������

	List(const List&); // it's correct				// ����������� �����������

	~List(); // it's maybe correct, require to confirm // ����������

	Node<T>* getNode(int);							// ��������� ���� ������

	void push_back(T); // it's correct				// ���������� ���� � ����� ������

	void push_front(T);								// ���������� ���� � ������ ������

	void insert(size_t, T); // it's correct// User must be accurate to use this method // ���������� ���� � ����� ����� ������

	T pop_back(); // it's correct					// ��������� �������� ���������� ���� ������ � ����������� ���������

	void merge(const List&); // it's correct		Deprecate

	void erase(size_t); //it's correct				// �������� ���� 

	void clear(); // It's correct					// ������� ������

	const List& operator =(const List&); // it isn't correct // �������� =

	bool operator ==(const List&) const; // correct	// �������� ==
	
	bool operator !=(List&) const;					// �������� ==

	Node<T>*& begin();								// ��������� ���������� ����� ������ ����

	void getSize();									// ����� �� ����� ���������� ����� � ������

	size_t size();									// ��������� ���������� ����� � ������

	bool isEmpty() const;							// ��������� ���������� ����� � ������

	void getList() const;							// ����� �� ����� �������� ���� �����, ��� ������� ���������� ��������� << � ������

	friend ostream& operator <<(ostream&, List&);	// �������� << 

	void merge(int, int); // without []				// ������������� ������

	void sort(int, int);							// ���������� ��������
};