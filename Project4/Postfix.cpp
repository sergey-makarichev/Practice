#include "Postfix.h"
#include "TStack.h"
using namespace std;

string Postfix::PostfixForm(const string &v)
{
	    TStack<char> s1(v.length());
		TStack<char> s2(v.length());
		for (int i = 0; i < v.length(); i++)
		{
			if ((v[i] >= 65) && (v[i] <= 90))
			{
				if (i > 0)
				{
					if ((v[i - 1] >= 65) && (v[i - 1] <= 90))
						throw M_Exeption
						("two letters stand side by side");
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
					if (s2.Top() == -1)
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
		while (s2.Top() != -1)
		{
			s1.Push(s2.Top());
			s2.Pop();
		}
		string q;
		while (s1.Top() != -1)
		{
			q = q + s1.Top();
			s1.Pop();
		}
		string q1;
		for (int i = 0; i < q.length(); i++)
		{
			q1[i] = q[q.length() - (i + 1)];
		}
		/*for (int i = 0; i < s1.Top() + 1; i++)
		{
			if (s1.GetElem(i) == '(')
				throw M_Exeption("a closing bracket is not found");
			q = q + s1.GetElem(i);
		}*/
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
			for (int k = 0; k < v.length(); k++)
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

	}
	return (s.Top());
}

void Postfix::GetOperandsValues(const string& postfix, char*& operands, float*& values, int& count)
{
	for (int i = 0; i < postfix.length; i++)
	{
		if ((postfix[i] >= 65) && (postfix[i] <= 90))
			count++;
	}
	char* operands = new char[count];
	int k = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= 65) && (postfix[i] <= 90))
		{
			if (k == 0)
			{
				operands[0] = postfix[i];
				k++;
				continue;
			}
			for(i = 1; i < postfix.length(); i)
			
			
		}
	}
	float* value = new float[name.length()];
	for (int i = 0; i < name.length(); i++)
	{
		cout << "enter the value of " << name[i] << ": " << endl;
		cin >> value[i];
	}
	float k = 0;
	try
	{
		k = Postfix::Calculating(str, name, value);
	}
	catch (M_Exeption& exception)
	{
		cerr << " Error: " << exception.what() << endl;
		system("pause");
		return 0;
	}
	cout << str << "  =" << k << endl;
	system("pause");
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