#include "Postfix.h"
#include "TStack.h"
using namespace std;

string Postfix::PostfixForm(const string &v)
{
	    TStack<char> s1(v.length());
		TStack<char> s2(v.length());
		if((v[0] == 42) || (v[0] == 43) || (v[0] == 45) || (v[0] == 47))
			throw M_Exeption("an expression cannot start with operands");
		for (int i = 0; i < v.length(); i++)
		{
			if ((v[i] >= 65) && (v[i] <= 90))
			{
				if (i > 0)
				{
					if ((v[i - 1] >= 65) && (v[i - 1] <= 90))
						throw M_Exeption("two letters stand side by side");
				}
				s1.Push(v[i]);
			}
			else if ((v[i] == 42) || (v[i] == 43) || (v[i] == 45) || (v[i] == 47))
			{
				if ((v[i-1] == 42) || (v[i-1] == 43) || (v[i-1] == 45) || (v[i-1] == 47))
					throw M_Exeption("2 operands stand side by side");
				if (s2.IsEmpty())
					s2.Push(v[i]);
				else
				{
					if (Prioritet(v[i]) <= Prioritet(s2.Top()))
					{
						while ((Prioritet(v[i]) <= Prioritet(s2.Top())) && (!s2.IsEmpty()))
						{
							s1.Push(s2.Top());
							s2.Pop();
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
				while ((s2.Top()) != '(')
				{
					if (s2.IsEmpty())
						throw M_Exeption("an opening bracket is not found");
					s1.Push(s2.Top());
					s2.Pop();
				}
				s2.Pop();
			}
			else if (v[i] == ' ')
				continue;
			else
				throw  M_Exeption("one of the characters is entered incorrectly");
		}
		while (!s2.IsEmpty())
		{
			s1.Push(s2.Top());
			s2.Pop();
		}
		string q;
		while (!s1.IsEmpty())
		{
			q = q + s1.Top();
			s1.Pop();
		}
		string q1;
		int len = q.length();
		for (int i = 0; i < len; i++)
		{
			if(q[len - (i + 1)] == '(')
				throw M_Exeption("a closing bracket is not found");
			q1 = q1 + q[len - (i + 1)];
		}
		return q1;
}

float Postfix::Calculating(const string& v, char* operands, float* values, int count)
{
	TStack<float> s(v.length());
	float a, b;
	for (int i = 0; i < v.length(); i++)
	{
		if ((v[i] >= 65) && (v[i] <= 90))
		{
			for (int k = 0; k < count; k++)
			{
				if (v[i] == operands[k])
				{
					s.Push(values[k]);
					break;
				}
			}
		}
		else if ((v[i] == 42) || (v[i] == 43) || (v[i] == 45) || (v[i] == 47))
		{
			a = s.Top();
			s.Pop();
			b = s.Top();
			s.Pop();
			switch (v[i])
			{
			case '*':
				s.Push(b * a);
				break;
			case '/':
				if (a == 0)
					throw M_Exeption("division by zero");
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
		else
			throw "Incorrect symbol";

	}
	return (s.Top());
}

void Postfix::GetOperandsValues(const string& postfix, char*& operands, float*& values, int& count)
{
	count = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= 65) && (postfix[i] <= 90))
		{
			count++;
		}
	}

	operands = new char[count];
	values = new float[count];

	int n = 0;
	for (int i = 0; i < postfix.length(); i++)
	{		
		if ((postfix[i] >= 65) && (postfix[i] <= 90))
		{
			int f = 0;
			for (int j = 0; j < n; j++)
			{
				if (postfix[i] == operands[j])
					f = 1;
			}
			if (f == 0)
			{
				operands[n] = postfix[i];
				cout << "enter the value of " << operands[n] << ": " << endl;
				cin >> values[n];
				n++;
			}
		}
	}
}

int Postfix::Prioritet(char v)
{
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
}