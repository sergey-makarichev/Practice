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
private:
	int size;
	ValueType* x;
public:
	TVector(int size);
	TVector(int size, ValueType* x);
	TVector(const TVector& v);
	~TVector();
	float len()const;
	ValueType& operator[] (int index);
	TVector operator+ (float c);
	TVector operator- (float c);
	TVector operator+ (const TVector& v);
	TVector operator- (const TVector& v);
	ValueType operator* (const TVector& v) const;
	bool operator== (const TVector& v)const;
	bool operator!= (const TVector& v)const;
	const TVector& operator= (const TVector& v);
	friend ostream& operator<< (ostream& out, const TVector<ValueType> &v)
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.x[i] << "  ";
			out << endl;
		}
		return out;
	}

	friend istream& operator>> (istream& in, TVector<ValueType> &v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.x[i];
		return in;
	}
};

template<typename ValueType>
TVector<ValueType>::TVector(int size)
{
	this->size = size;
	this->x = new ValueType[size];
}

template<typename ValueType>
TVector<ValueType>::TVector(int size, ValueType* x)
{
	this->size = size;
	this->x = new ValueType[size];
	memcpy(this->x, x, size * sizeof(ValueType)); 
}

template<typename ValueType>
TVector<ValueType>::TVector(const TVector < ValueType> &v)
{
	x = new ValueType[size = v.size];
	for (int i = 0; i < size; i++)
		x[i] = v.x[i];
	//memcpy(this->x, x, size * sizeof(ValueType)); 
}

template<typename ValueType>
TVector<ValueType>::~TVector()
{
	delete[] x;
}

template<typename ValueType>
float TVector<ValueType>::len()const
{
	float l = 0.0f;
	l = (*this) * (*this);
	return sqrt(l);
}

template<typename ValueType>
ValueType& TVector<ValueType>::operator[](int index)
{
	return this->x[index];
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(float c)
{
	TVector<ValueType> v(*this);
	for (int i = 0; i < size; i++)
	{
		v.x[i] += c;
	}
	return v;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (float c)
{
	TVector<ValueType> v(*this);
	for (int i = 0; i < size; i++)
	{
		v.x[i] -= c;
	}
	return v;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+ (const TVector<ValueType> &v)
{
	if (this->size != v.size)
	{
		throw "Error";
	}
	TVector<ValueType> z(*this);
	for (int i = 0; i < size; i++)
	{
		z.x[i] += v.x[i];
	}
	return z;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator- (const TVector<ValueType> &v)
{
	if (this->size != v.size)
	{
		throw "Erorr";
	}
	TVector<ValueType> z(*this);
	for (int i = 0; i < size; i++)
	{
		z.x[i] -= v.x[i];
	}
	return z;
}

template<typename ValueType>
ValueType TVector<ValueType>::operator* (const TVector<ValueType> &v) const
{
	if (this->size != v.size)
	{
		throw "Erorr";
	}
	ValueType b = 0.0;
	for (int i = 0; i < size; i++)
	{
		b += v.x[i] * this->x[i];
	}
	return b;
}

template<typename ValueType>
bool TVector<ValueType>::operator == (const TVector<ValueType> &v) const
{
	if (this->size != v.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (this->x[i] != v.x[i])
			return false;
	}
	return true;
}

template<typename ValueType>
bool TVector<ValueType>::operator != (const TVector<ValueType> &v) const
{
	if (this->size == v.size)
		return false;
	else
		return true;
}

template<typename ValueType>
const TVector<ValueType>& TVector<ValueType>::operator = (const TVector<ValueType> &v)
{
	if (*this == v)
	{
		return *this;
	}
	if (this->size != v.size)
	{
		delete[] this->x;
		this->size = v.size;
		this->x = new float[size];
	}
	memcpy(this->x, x, size * sizeof(ValueType));
	return *this;
}

