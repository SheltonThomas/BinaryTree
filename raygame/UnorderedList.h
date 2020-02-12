#pragma once
#include "List.h"

template<typename T>
class UnorderedList : List<T> {
public:
	void insertFirst(const T&);
	void insertLast(const T&);
};

template<typename T>
void UnorderedList<T>::insertFirst(const T& tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->m_first == nullptr)
	{
		this->m_first = newNode;
		this->m_last = newNode;
		this->mCount++;
		return;
	}
	newNode->next = this->m_first;
	this->m_first = newNode;
	this->mCount++;
}

template<typename T>
void UnorderedList<T>::insertLast(const T& tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->m_last == nullptr)
	{
		this->m_first = newNode;
		this->m_last = newNode;
		this->mCount++;
		return;
	}
	this->m_last->next = newNode;
	this->m_last = newNode;
	this->mCount++;
}
