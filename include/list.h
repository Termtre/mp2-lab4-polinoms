#pragma once

#include <iostream>

using namespace std;
												
template <class T>								// Узел списка
struct Node
{
	T data = T();
	Node<T>* next = nullptr;

	Node() {}									// Конструктор по умолчанию

	Node(T var) : data(static_cast<T>(var)) {}	// Конструктор инициализации
};

template<class T>
class List										// Класс односвязный список с фиктивной головой
{
private:
	Node<T>* head = new Node<T>();
	//???Node<T>* tale = new Node<T>();
	size_t tsize = static_cast <size_t>(0);
public:
	List();// it's correct							// Конструктор по умолчанию

	List(T); // it's correct						// Конструктор инициализации одного элемента

	List(T*, int); // it's correct					// Конструктор инициализации массивом элементов

	List(const List&); // it's correct				// Конструктор копирования

	~List(); // it's maybe correct, require to confirm // Деструктор

	Node<T>* getNode(int);							// Получение узла списка

	void push_back(T); // it's correct				// Добавление узла в конец списка

	void push_front(T);								// Добавление узла в начадл списка

	void insert(size_t, T); // it's correct// User must be accurate to use this method // Добавление узла в любое место списка

	T pop_back(); // it's correct					// Получение значения последнего узла списка с последующим удалением

	void merge(const List&); // it's correct		Deprecate

	void erase(size_t); //it's correct				// Удаление узла 

	void clear(); // It's correct					// Очистка списка

	const List& operator =(const List&); // it isn't correct // Оператор =

	bool operator ==(const List&) const; // correct	// Оператор ==
	
	bool operator !=(List&) const;					// Оператор ==

	Node<T>*& begin();								// Получение следующего после головы узла

	void getSize();									// Вывод на экран количества узлов в списке

	size_t size();									// Получение количества узлов в списке

	bool isEmpty() const;							// Получение количества узлов в списке

	void getList() const;							// Вывод на экран значения всех узлов, при условии реализации оператора << у данных

	friend ostream& operator <<(ostream&, List&);	// оператор << 

	void merge(int, int); // without []				// Объеденинение списка

	void sort(int, int);							// Сортировка слиянием
};