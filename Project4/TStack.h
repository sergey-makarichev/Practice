#pragma once
#include <string>

template <class ValueType>
class TStack
{
private:
	int size;
	ValueType* = elems;
	int top;
public:
	TStack(int size);
	TStack(const TStack &s);
	~TStack();
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(ValueType e);
	ValueType Pop();
	void Postfix(string v);
};

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
	this - top = s.top;
	for (int i = 0; i < top; i++)
		elems[i] = s.elems[i];
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
		throw "Error";
	elems[++top] = e;
}

template <class ValueType>
ValueType TStack<ValueType>::Pop()
{
	if (IsEmpty())
		throw "Error";
	return(elems[top--]);
}

template <class ValueType>
void TStack<ValueType> ::Postfix(string v)
{
	while (!'\0')
	{

	}
}