#pragma once
#include "TMonom.h"
#include "TPolinom.h"
#include <string>

using namespace std;

class Polinom
{
private:
	TList<int, float>* monoms;
	void SortMonoms();
public:
	Polinom();
	Polinom(TList<int, float>* list);
	Polinom(const string&);
	Polinom(const Polinom& list);
	~Polinom();
	//private

	Polinom operator + (const Polinom& polynom);
	Polinom operator - () const;
	Polinom operator - (const Polinom& polynom);//*
	const Polinom operator= (const Polinom& polynom);
};