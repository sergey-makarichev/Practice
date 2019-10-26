#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;
class Vector
{
private:
	int size;
	float* x;
public:
	Vector(int size);
	Vector(int size, float* x);
	Vector(const Vector& v);
	~Vector();
	float len()const;
	float& operator[] (int index);
	Vector operator+ (float c);
	Vector operator- (float c);
	Vector operator+ (const Vector& v);
	Vector operator- (const Vector& v);
	float operator* (const Vector& v);
	bool operator== (const Vector& v)const;
	bool operator!= (const Vector& v)const;
	const Vector& operator= (const Vector& v);
	friend ostream& operator<< (ostream& out, const Vector& v);
	friend istream& operator>> (istream& in, Vector& v);
};

