#pragma once
#include"TVector.h"

template <class ValueType>
class TMatrix : public TVector<TVector<ValueType> > // вектор, каждый элемент кторого является вектором
{
public:
	TMatrix(int size = 10);
	//TMatrix(int size);
	TMatrix(const TMatrix&);
	TMatrix(const TVector<TVector<ValueType> >&);//конструктор преобразования типов
	~TMatrix() {};
	TMatrix operator+ (const ValueType c);
	TMatrix operator- (const ValueType c);
	TMatrix operator* (const ValueType c);
	TMatrix operator+ (const TMatrix&);
	TMatrix operator- (const TMatrix&);
	TVector<ValueType> operator*(const TVector<ValueType>& v1);
	TMatrix& operator= (const TMatrix&);
	bool operator== (const TMatrix& m)const;
	bool operator!= (const TMatrix& m)const;
	friend std::ostream& operator<<(std::ostream& out, const TMatrix& m)
	{
		for (int i = 0; i < m.size; i++)
		{
			out << m.elems[i] << std::endl;
		}
		out << std::endl;
		return out;
	};
};

template <class ValueType>
TMatrix<ValueType> ::TMatrix(int size) :TVector<TVector<ValueType> >(size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
		this->elems[i] = TVector<ValueType>(size - i, i);
}

template <class ValueType>
TMatrix<ValueType> ::TMatrix(const TMatrix<ValueType>& m) :TVector<TVector<ValueType> >(m) //передаем ссылку или объект?
{
}

template <class ValueType>
TMatrix<ValueType> ::TMatrix(const TVector<TVector<ValueType> >& m) : TVector<TVector<ValueType> >(m)
{
}

template <class ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType c)
{
	TMatrix<ValueType> m(*this);
	for (int i = 0; i < this->size; i++)
		m.elems[i] = this->elems[i] + c;
	return m;
}

template <class ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const ValueType c)
{
	TMatrix<ValueType> m(*this);
	for (int i = 0; i < this->size; i++)
		m.elems[i] = this->elems[i] - c;
	return m;
}

template <class ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const ValueType c)
{
	TMatrix<ValueType> m(*this);
	for (int i = 0; i < this->size; i++)
		m.elems[i] = this->elems[i] * c;
	return m;
}

template <class ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix <ValueType> &m)
{
	if (this->size != m.size)
	{
		throw "Error";
	}
	TMatrix<ValueType> m1(*this);
	for (int i = 0; i < this->size; i++)
		m1.elems[i] = m1.elems[i] + m.elems[i];
	return m1;
}

template <class ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix <ValueType> &m)
{
	if (this->size != m.size)
	{
		throw "Error";
	}
	TMatrix<ValueType> m1(*this);
	for (int i = 0; i < this->size; i++)
		m1.elems[i] = m1.elems[i] - m.elems[i];
	return m1;
}

template<class ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& v)
{
	if (this->size != v.GetSize())
		throw "Error";
	TVector<ValueType> v1(this->size);
	for (int i = 0; i < this->size; i++)
	{
		v1[i] = 0;
		for (int j = 0; j < this->elems[i].GetSize(); j++)
			v1[i] += this->elems[i][j] * v[i + j];
	}
	return v1;
}

template <class ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix <ValueType> &m)
{
	if (*this == m)
		return(*this);
	if (this->size != m.size)
	{
		delete[] this->elems;
		this->size = m.size;
		this->elems = new TVector<ValueType>[this->size];
	}
	for (int i = 0; i < this->size; i++)
	{
		this->elems[i] = m.elems[i];
	}
	return(*this);
}

template <class ValueType>
bool TMatrix<ValueType>::operator == (const TMatrix<ValueType>& m) const
{
	if (this->size != m.size)
		return false;
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i] != m.elems[i])
			return false;
	}
	return true;
}

template <class ValueType>
bool TMatrix<ValueType>::operator != (const TMatrix<ValueType>& m) const
{
	return!((*this) == m);
}
