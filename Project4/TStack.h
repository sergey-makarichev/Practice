#pragma once
#include <string>
#include "Exeption.h"
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
	ValueType Top();
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

template <class ValueType>
ValueType TStack<ValueType>::Top()
{
	/*if (IsEmpty())
		throw "Error";*/
	return (elems[top]);
}

/*int Prioritet(char v)
{
	{
		switch (v)
		{
		case '*':
			return 3;
			break;
		case '/':
			return 3;
			break;
		case '+':
			return 2;
			break;
		case '-':
			return 2;
			break;
		case '(':
			return 1;
			break;
		}
	}
}

/*template <class ValueType>
string TStack<ValueType> ::Postfix(string v)
{
	TStack<char> s1(v.length());
	TStack<char> s2(v.length());
	for (int i = 0; i < v.length(); i++)
	{
		if ((v[i] >= 65) && (v[i] <= 90))
		{
			if (i > 0)
			{
				if ((v[i - 1] >= 65) && (v[i - 1] <= 90) && (i - 1))
					throw "Error";
			}
			s1.Push(v[i]);
		}
		else if ((v[i] == 42) || (v[i] == 43) || (v[i] == 45) || (v[i] == 47))
		{
			if (s2.IsEmpty())
				s2.Push(v[i]);
			else
			{
				if (Prioritet(v[i]) <= Prioritet(s2.Top()))
				{
					while ((Prioritet(v[i]) <= Prioritet(s2.Top())) && (!s2.IsEmpty()))
					{
						s1.Push(s2.Pop());
					}
					s2.Push(v[i]);
				}
				else
				{
					s2.Push(v[i]);
				}

			}
		}
		else if (v[i] == '(')
			s2.Push(v[i]);
		else if (v[i] == ')')
		{
			while (s2.Top() != '(')
			{
				if(s2.top == -1)
					throw "Error";
				s1.Push(s2.Pop());
			}
			s2.Pop();
		}
		else if (v[i] == ' ')
			continue;
		else
			throw "Error";
	}
	while (s2.top != -1)
		s1.Push(s2.Pop());
	string q;
	for (int i = 0; i < s1.top + 1; i++)
	{
		if (s1.elems[i] == '(')
			throw "Error";
		q = q + s1.elems[i];
	}
	return q;
}

template <class ValueType>
float TStack<ValueType>::Calculating(string v, string name, float* values)
{
	TStack<float> s(v.length());
	float a, b;
	for (int i = 0; i < v.length(); i++)
	{
		if ((v[i] >= 65) && (v[i] <= 90))
		{
			for (int k = 0; k < v.length(); k++)
			{
				if (v[i] == name[k])
				{
					s.Push(values[k]);
					break;
				}
			}
		}
		else if ((v[i] == 42) || (v[i] == 43) || (v[i] == 45) || (v[i] == 47))
		{
			a = s.Pop();
			b = s.Pop();
			switch (v[i])
			{
			case '*':
				s.Push(b * a);
				break;
			case '/':
				if (a == 0)
					throw "Error";
				s.Push(b / a);
				break;
			case '+':
				s.Push(b + a);
				break;
			case '-':
				s.Push(b - a);
				break;
			}
		}

	}
	return s.Top();
}*/