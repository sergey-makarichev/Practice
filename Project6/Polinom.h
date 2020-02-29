#ifndef POLINOM_H    
#define POLINOM_H
#include "TMonom.h"
#include <string>
#include <iostream>
#include "TList.h"
#include "Exception.h"

using namespace std;

class Polinom
{
private:
	TList<int, float>* monoms;
	void SortMonoms();
	void SimilarMonoms();
public:
	Polinom();
	Polinom(TList<int, float>* list);
	Polinom(const string&);
	Polinom(const Polinom& list);
	~Polinom();

	Polinom operator + (const Polinom& polynom);
	Polinom operator - () const;
	Polinom operator - (const Polinom& polynom);
	Polinom operator * (const Polinom& polynom);
	Polinom operator *(const TNode<int, float>& monom);
	bool operator ==(const Polinom& polynom)const;
	const Polinom& operator= (const Polinom& polynom);
	friend ostream& operator <<(std::ostream& out, const Polinom& pol);
};

Polinom::Polinom()
{
	monoms = new TList<int, float>();
}

Polinom::Polinom(TList<int, float>* list)
{
	list->Reset();
	while (!list->IsEnded())
	{
		if (list->GetCurrent()->key > 999 || list->GetCurrent()->key < 0)
			throw M_Exeption ("invalid parameter");
		list->Next();
	}
	monoms = new TList<int, float>(*list);
	SimilarMonoms();
	SortMonoms(); 
}

Polinom::Polinom(const Polinom& list)
{
	monoms = new TList<int, float>(*list.monoms);
}

Polinom :: ~Polinom()
{
	delete monoms;
}

void Polinom::SortMonoms()
{
	if (monoms->GetFirst() == nullptr)
		return;
	if (monoms->GetFirst()->pNext == nullptr)
		return;
	TNode<int, float>* a, * b, * rev, * prev_a;
	for (bool ListDone = true; ListDone;)
	{
		ListDone = false;
		a = monoms->GetFirst();
		b = monoms->GetFirst()->pNext;
		prev_a = a;
		while (b != nullptr)
		{
			if (a->key < b->key)
			{
				if (prev_a = a)
					monoms->pFirst = b;
				else
					prev_a->pNext = b;
				a->pNext = b->pNext;
				b->pNext = a;
				rev = a;
				a = b;
				b = rev;
				ListDone = true;
			}
			prev_a = a;
			a = a->pNext;
			b = b->pNext;
		}

	}
	monoms->Reset();
}

void Polinom::SimilarMonoms()
{
	monoms->Reset();
	TNode<int, float>* tmp = monoms->GetNext();
	while (!monoms->IsEnded())
	{
		while (tmp->pNext->key != monoms->GetCurrent()->key && tmp != nullptr)
		{
			if (monoms->GetCurrent()->key == tmp->pNext->key && monoms->GetCurrent()->pData == -tmp->pNext->pData)
			{
				monoms->Remove(monoms->GetCurrent()->key);
				TNode<int, float>* node = tmp->pNext;
				tmp->pNext = tmp->pNext->pNext;
				delete node;
				tmp = tmp->pNext;
				continue;
			}
			monoms->GetCurrent()->pData += tmp->pNext->pData;
			TNode<int, float>* node = tmp->pNext;
			tmp->pNext = tmp->pNext->pNext;
			delete node;
			tmp = tmp->pNext;
		}
		monoms->Next();
		tmp = monoms->GetNext();
	}
}

Polinom::Polinom(const string& polinom)
{
	monoms = new TList<int, float>();
	string str = polinom;
	unsigned int i = 0;
	float coeff = 1;
	bool is_x = false;
	bool is_y = false;
	bool is_z = false;
	int deg_x = 0;
	int deg_y = 0;
	int deg_z = 0;
	while (i < str.length())
	{
		do
		{
			if (isdigit(str[i]) && !is_x && !is_y && !is_z)
			{
				string StrCoeff;
				while (isdigit(str[i]))
				{
					if (str[i + 1] == '.')
					{
						StrCoeff += str[i];
						StrCoeff += str[i + 1];
						i = i + 2;
					}
					else
					{
						StrCoeff += str[i];
						i++;
					}
				}
				coeff = (float)(atof(StrCoeff.c_str()));
				continue;
			}
			if (str[i] == '^')
			{
				i++;
				continue;
			}
			if (str[i] == 'x')
			{
				if ((i + 1) != str.length())
				{
					is_x = true;
					is_y = false;
					is_z = false;
					i++;
					continue;
				}
				else
				{
					is_x = true;
					is_y = false;
					is_z = false;
				}
			}
			if (is_x && (str[i] == 'y' || str[i] == 'z' || str[i] == ' '))
			{
				deg_x = 1;
				is_x = false;
			}
			if (is_x && isdigit(str[i]))
			{
				if (isdigit(str[i + 1]))
					throw M_Exeption("degree > 9");
				deg_x = (int)str[i] - 48;
				is_x = false;
				i++;
				continue;
			}
			if (is_x && (i + 1 == str.length()))
			{
				deg_x = 1;
				is_x = false;
				i++;
			}
			if (str[i] == 'y')
			{
				if ((i + 1) != str.length())
				{
					is_x = false;
					is_y = true;
					is_z = false;
					i++;
					continue;
				}
				else
				{
					is_x = false;
					is_y = true;
					is_z = false;
				}
			}
			if (is_y && (str[i] == 'x' || str[i] == 'z' || str[i] == ' '))
			{
				deg_y = 1;
				is_y = false;
			}
			if (is_x && isdigit(str[i]))
			{
				if (isdigit(str[i + 1]))
					throw M_Exeption("degree > 9");
				deg_y = (int)str[i] - 48;
				is_y = false;
				i++;
				continue;
			}
			if (is_y && i + 1 == str.length())
			{
				deg_y = 1;
				is_y = false;
				i++;
			}

			if (str[i] == 'z')
			{
				if ((i + 1) != str.length())
				{
					is_x = false;
					is_y = false;
					is_z = true;
					i++;
					continue;
				}
				else
				{
					is_x = false;
					is_y = false;
					is_z = true;
				}
			}
			if (is_z && (str[i] == 'x' || str[i] == 'y' || str[i] == ' '))
			{
				deg_z = 1;
				is_z = false;
			}
			if (is_z && isdigit(str[i]))
			{
				if (isdigit(str[i + 1]))
					throw M_Exeption("degree > 9");
				deg_z = (int)str[i] - 48;
				is_z = false;
				i++;
				continue;
			}
			if (is_z && i + 1 == str.length())
			{
				deg_z = 1;
				is_z = false;
				i++;
			}
			if (str[i] == '+')
			{
				i++;
				continue;
			}
			if (str[i] == '-')
			{
				coeff *= -1;
				i++;
				continue;
			}
			if (str[i] == ' ')
			{
				i++;
				continue;
			}
		} while ((!is_x || !is_y || !is_z) && !((str[i] == '+') || (str[i] == '-')) && (i != str.length()));
		TNode<int, float>* NewMon = new TNode<int, float>(deg_x, deg_y, deg_z, coeff);
		monoms->InsertEnd(NewMon);
		deg_x = deg_y = deg_z = 0;
		coeff = 1;
	}
	SortMonoms();
}

Polinom Polinom::operator+(const Polinom& polynom)
{
	if (monoms->IsEmpty())
		return polynom;
	if (polynom.monoms->IsEmpty())
		return *this;
	Polinom sum;
	monoms->Reset();
	polynom.monoms->Reset();
	while (!monoms->IsEnded() && !polynom.monoms->IsEnded())
	{
		if (monoms->GetCurrent() > polynom.monoms->GetCurrent())
		{
			sum.monoms->InsertEnd(monoms->GetCurrent());
			monoms->Next();
		}
		else if (monoms->GetCurrent() < polynom.monoms->GetCurrent())
		{
			sum.monoms->InsertEnd(polynom.monoms->GetCurrent());
			polynom.monoms->Next();
		}
		else if (monoms->GetCurrent()->key == polynom.monoms->GetCurrent()->key)
		{
			if ((monoms->GetCurrent()->pData + polynom.monoms->GetCurrent()->pData) != 0)
				sum.monoms->InsertEnd(monoms->GetCurrent()->key, polynom.monoms->GetCurrent()->pData + monoms->GetCurrent()->pData);
			polynom.monoms->Next();
			monoms->Next();
		}
	}
	while (!polynom.monoms->IsEnded())
	{
		sum.monoms->InsertEnd(monoms->GetCurrent());
		monoms->Next();
	}
	while (!monoms->IsEnded())
	{
		sum.monoms->InsertEnd(polynom.monoms->GetCurrent());
		polynom.monoms->Next();
	}
	sum.monoms->Reset();
	return sum;
}

Polinom Polinom::operator-() const
{
	Polinom tmp(*this);
	while (!tmp.monoms->IsEnded())
	{
		tmp.monoms->GetCurrent()->pData *= -1;
		tmp.monoms->Next();
	}
	tmp.monoms->Reset();
	return tmp;
}

Polinom Polinom::operator-(const Polinom& polynom)
{
	return *this + (-polynom);
}

bool Polinom::operator==(const Polinom& polynom) const
{
	TNode<int, float>* first = monoms->pFirst;
	TNode<int, float>* second = polynom.monoms->pFirst;
	while (first != nullptr && second != nullptr && (*first == *second))
	{
		first = first->pNext;
		second = second->pNext;
	}
	if (first == nullptr && second == nullptr)
		return true;
	else
		return false;
}

const Polinom& Polinom::operator=(const Polinom& polynom)
{
	if (*this == polynom) // ==
		return *this;
	if (!monoms->IsEmpty())
		delete monoms;
	monoms = new TList<int, float>(*polynom.monoms);
	return *this;
}

Polinom Polinom::operator*(const Polinom& polynom)
{
	if (polynom.monoms->IsEmpty())
		return *this;
	monoms->Reset();
	polynom.monoms->Reset();
	Polinom product;
	while (!monoms->IsEnded())
	{
		while (!polynom.monoms->IsEnded())
		{
			TNode<int, float>* product1;
			product1 = *monoms->GetCurrent() * *polynom.monoms->GetCurrent();
			product.monoms->InsertEnd(product1);
			polynom.monoms->Next();
		}
		monoms->Next();
		polynom.monoms->Reset();
	}
	/*product.SimilarMonoms();
	product.SortMonoms();*/
	return product;
}

Polinom Polinom::operator*(const TNode<int, float>& monom)
{
	if (monom.pData == 0)
		return monoms;
	Polinom res;
	TNode<int, float>* tmp = new TNode<int, float>(monom);
	while (!monoms->IsEnded())
	{
		res.monoms->InsertEnd(*tmp * *monoms->GetCurrent());
		monoms->Next();
	}
	return res;
}

ostream& operator <<(std::ostream& out, const Polinom& pol)
{
	pol.monoms->Reset();
	while (!pol.monoms->IsEnded())
	{
		int deg_x = pol.monoms->GetCurrent()->key / 100;
		int deg_y = (pol.monoms->GetCurrent()->key - deg_x * 100) / 10;
		int deg_z = pol.monoms->GetCurrent()->key - deg_x * 100 - deg_y * 10;
		if (pol.monoms->GetCurrent()->pData == 0)
		{
			pol.monoms->Next();
			continue;
		}
		else
		{
			if (pol.monoms->GetCurrent()->pData != 1)
			{
				if (pol.monoms->GetCurrent()->pData > 0)
					out << "+" << pol.monoms->GetCurrent()->pData;
				if (pol.monoms->GetCurrent()->pData < 0)
					out << "-" << pol.monoms->GetCurrent()->pData;
			}
			if (deg_x > 0 && deg_x != 1)
				out << "x^" << deg_x;
			if (deg_y > 0 && deg_y != 1)
				out << "y^" << deg_y;
			if (deg_z > 0 && deg_z != 1)
				out << "z^" << deg_z;
			if (deg_x == 1)
				out << "x";
			if (deg_y == 1)
				out << "y";
			if (deg_z == 1)
				out << "z";
		}
		pol.monoms->Next();
	}
	return out;
}
#endif