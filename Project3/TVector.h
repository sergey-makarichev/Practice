#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;


template<typename ValueType>
class TVector
{
protected:
	int size;
	ValueType* elems;
	int StartIndex;
public:
	TVector(int size = 10, int StartIndex = 0);
	TVector(const TVector&);
	~TVector();
	ValueType& operator[] (int index);
	const ValueType& operator[] (int index) const;
	TVector operator+ (ValueType c);
	TVector operator- (ValueType c);
	TVector operator* (ValueType c);
	TVector operator+ (const TVector&);
	TVector operator- (const TVector&);
	ValueType operator* (const TVector& v) /*const*/;
	bool operator== (const TVector& v)const;
	bool operator!= (const TVector& v)const;
	const TVector& operator= (const TVector& v);
	int GetSize()const;
	friend ostream& operator<< (ostream& out, const TVector<ValueType>& v) //!!! отступы по start_index
	{
		for (int i = 0; i < v.StartIndex; i++)
			out << std::setw(10) << std::setprecision(2) << " ";
		for (int i = 0; i < v.size; i++)
			out << std::setw(10) << std::setprecision(5) << v.elems[i] << " ";
		out << std::endl;
		return out;

	}

	friend istream& operator>> (istream& in, TVector<ValueType>& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.elems[i];
		return in;
	}
};

template<typename ValueType>
TVector<ValueType>::TVector(int size, int StartIndex)
{
	this->StartIndex = StartIndex;
	this->size = size;
	this->elems = new ValueType[size];
	for (int i = 0; i < size; i++)
		elems[i] = 0;
}


template<typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& v)
{
	this->StartIndex = v.StartIndex;
	elems = new ValueType[size = v.size];
	for (int i = 0; i < size; i++)
		elems[i] = v.elems[i];
}

template<typename ValueType>
TVector<ValueType>::~TVector()
{
	delete[] elems;
}

template<typename ValueType> // Размер 
int TVector<ValueType>::GetSize() const
{
	return size;
}

template<typename ValueType>
ValueType& TVector<ValueType>::operator[](int index)
{
	if ((index < 0) || (index > this->size))
		throw "Error";
	return elems[index]; //!!! проверка index
}

template<typename ValueType>
const ValueType& TVector<ValueType>:: operator[] (int index) const
{
	if ((index < 0) || (index > this->size))
		throw "Error";
	return elems[index]; //!!! проверка index
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(ValueType c)
{
	TVector<ValueType> v(*this);
	for (int i = 0; i < size; i++)
	{
		v.elems[i] += c;
	}
	return v;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (ValueType c)
{
	TVector<ValueType> v(*this);
	for (int i = 0; i < size; i++)
	{
		v.elems[i] -= c;
	}
	return v;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(ValueType c)
{
	TVector<ValueType> v(*this);
	for (int i = 0; i < size; i++)
	{
		v.elems[i] *= c;
	}
	return v;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+ (const TVector<ValueType>& v)
{
	if ((this->size != v.size) || (this->StartIndex != v.StartIndex)) //!!! проверить start_index
	{
		throw "Error";
	}
	TVector<ValueType> z(*this);
	for (int i = 0; i < size; i++)
	{
		z.elems[i] += v.elems[i];
	}
	return z;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (const TVector<ValueType>& v)
{
	if ((this->size != v.size) || (this->StartIndex != v.StartIndex)) //!!! проверить start_index
	{
		throw "Error";
	}
	TVector<ValueType> z(*this);
	for (int i = 0; i < size; i++)
	{
		z.elems[i] -= v.elems[i];
	}
	return z;
}

template<typename ValueType>
ValueType TVector<ValueType>::operator* (const TVector<ValueType>& v) //const
{
	if ((this->size != v.size) || (this->StartIndex != v.StartIndex)) //!!! проверить start_index
	{
		throw "Error";
	}
	ValueType b = 0.0;
	for (int i = 0; i < size; i++)
	{
		b += v.elems[i] * this->elems[i];
	}
	return b;
}

template<typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator= (const TVector<ValueType>& v)
{
	if (*this == v)
		return *this;
	if (this->size != v.size)
	{
		delete[] this->elems;
		this->size = v.size;
		this->elems = new ValueType[size];
	}
	StartIndex = v.StartIndex;
	for (int i = 0; i < size; i++)
		elems[i] = v.elems[i];
	return *this;
}

template<typename ValueType>
bool TVector<ValueType>::operator == (const TVector<ValueType>& v) const
{
	if ((this->size != v.size) || (this->StartIndex != v.StartIndex)) //!!! проверить start_index
		return false;
	for (int i = 0; i < size; i++)
	{
		if (this->elems[i] != v.elems[i])
			return false;
	}
	return true;
}

template<typename ValueType>
bool TVector<ValueType>::operator != (const TVector<ValueType>& v) const
{
	return!((*this) == v);
}



