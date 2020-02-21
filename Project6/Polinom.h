#pragma once
#include "TMonom.h"
#include "TPolinom.h"
#include <string>

using namespace std;

class Polinom
{
private:
	TList<int, float>* monoms;
public:
	Polinom();
	Polinom(TList<int, float>* list);
	Polinom(const string&);
	Polinom(const Polinom& list);
	~Polinom();
	void SortMonoms();

	Polinom operator + (const Polinom& polynom);
	Polinom operator - ();
	Polinom operator - (const Polinom& polynom);
	const Polinom operator= (const Polinom& polynom);
};