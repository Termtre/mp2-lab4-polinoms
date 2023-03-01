#pragma once

#include <iostream>

using namespace std;
												
template <class T>									// ���� ������
struct Node
{
	T data;
	Node<T>* next;

	Node();											// ����������� �� ���������

	Node(T);										// ����������� �������������
};

template<class T>
class List											// ����� ����������� ������ � ��������� �������
{
private:
	Node<T>* head;
	Node<T>* tale;
	size_t tsize;
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

	T pop_front();									// ��������� �������� ������� ���� ������ � ����������� ���������

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