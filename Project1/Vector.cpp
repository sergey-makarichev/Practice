#include "Vector.h"

Vector::Vector(int size)
{
	this->size = size;
	this->x = new float[size];
}

Vector::Vector(int size, float* x)
{
	this->size = size;
	this->x = new float[size];
	for (int i = 0; i < size; i++)
		this->x[i] = x[i];
}

Vector::Vector(const Vector &v)
{
	x = new float[size = v.size];
	for (int i = 0; i < size; i++)
		x[i] = v.x[i];
}

Vector::~Vector()
{
	delete[] x;
}

float Vector::len()const
{
	float l = 0.0f;
	for (int i = 0; i < size; i++)
		l += x[i] * x[i];
	return sqrt(l);
}

float& Vector::operator[](int index)
{
	return this->x[index];
}

Vector Vector::operator+ (float c)
{
	Vector v(*this);
	for (int i = 0; i < size; i++)
	{
		v.x[i] += c;
	}
	return v;
}

Vector Vector::operator- (float c)
{
	Vector v(*this);
	for (int i = 0; i < size; i++)
	{
		v.x[i] -= c;
	}
	return v;
}

Vector Vector::operator+ (const Vector& v)
{
	if (this->size != v.size)
	{
		throw "Error";
	}
	Vector z(*this);
	for (int i = 0; i < size; i++)
	{
		z.x[i] += v.x[i];
	}
	return z;
}

Vector Vector::operator- (const Vector& v)
{
	if (this->size != v.size)
	{
		throw "Erorr";
	}
	Vector z(*this);
	for (int i = 0; i < size; i++)
	{
		z.x[i] -= v.x[i];
	}
	return z;
}

float Vector::operator* (const Vector& v)
{
	if (this->size != v.size)
	{
		throw "Erorr";
	}
	float b = 0.0f;
	for (int i = 0; i < size; i++)
	{
		b += v.x[i] * this->x[i];
	}
	return b;
}

bool Vector::operator == (const Vector& v) const
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

bool Vector::operator != (const Vector& v) const
{
	if (this->size != v.size)
		return true;
	for (int i = 0; i < size; i++)
	{
		if (this->x[i] == v.x[i])
			return false;
	}
	return true;
}

const Vector& Vector::operator = (const Vector& v)
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
	for (int i = 0; i < size; i++)
		x[i] = v.x[i];
	return *this;
}

ostream& operator<< (ostream &out, const Vector &v)
{
	for (int i = 0; i < v.size; i++)
	{
		out << v.x[i] << "  ";
		out << endl;
	}
	return out;
}

istream& operator>> (istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
		in >> v.x[i];
	return in;
}


