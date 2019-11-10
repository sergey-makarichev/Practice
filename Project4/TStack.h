#pragma once
#include <string>
#include "Exñeption.h"
using namespace std;

template <class ValueType>
class TStack
{
private:
	int size;
	ValueType* elems;
	int top;
public:
	TStack(int size);
	TStack(const TStack &s);
	~TStack(); 
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(ValueType e);
	int Get_top();
	ValueType GetElem(int index);
	ValueType Pop();
};

template <class ValueType>
ValueType TStack<ValueType>::GetElem(int index)
{
	if ((index < 0) || (index > this->top))
		throw M_Exeption("Invalid index");
	return(this->elems[index]);
}


template <class ValueType>
TStack<ValueType>::TStack(int size)
{
	this->top = -1;
	this->size = size;
	elems = new ValueType[size];
}

template <class ValueType>
TStack<ValueType> ::TStack(const TStack<ValueType> &s)
{
	this->size = s.size;
	this->top = s.top;
	for (int i = 0; i < top; i++)
		this->elems[i] = s.elems[i];
}

template<typename ValueType>
TStack<ValueType>::~TStack()
{
	delete[] elems;
}

template <class ValueType>
bool TStack<ValueType> ::IsEmpty()const
{
	return (top == -1);
}

template <class ValueType>
bool TStack<ValueType> ::IsFull()const
{
	return(top == size - 1);
}

template <class ValueType>
void TStack<ValueType> ::Push(ValueType e)
{
	if (IsFull())
		throw M_Exeption("Stack is full");
	elems[++top] = e;
}

template <class ValueType>
ValueType TStack<ValueType>::Pop()
{
	if (IsEmpty())
		throw M_Exeption("Stack is empty");
	return(elems[top--]);
}

template <class ValueType>
int TStack<ValueType>::Get_top()
{
	return(this->top);
}