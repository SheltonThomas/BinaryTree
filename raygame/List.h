#pragma once
#include "Node.h"

template<typename T>
class List {
protected:
	int mCount;
	
	Node<T>* m_last; 
	Node<T>* m_first;

public:
	bool isListEmpty();
	T front();
	T back();
	virtual void insertFirst(const T&) = 0;
	virtual void insertLast(const T&) = 0;
};

template<typename T>
bool List<T>::isListEmpty()
{
	if (m_first == nullptr) false;
	else true;
}

template<typename T>
T List<T>::front()
{
	return m_first;
}

template<typename T>
T List<T>::back()
{
	return m_last();
}
