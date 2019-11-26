#include <iostream>
#include "TStack.h"
#include "Postfix.h"

int main()
{
	string str;
	string name;
	std::getline(std::cin, str);
	try
	{
		str = Postfix::PostfixForm(str);
	}
	catch (M_Exeption &exception)
	{
		cerr << " Error: "<< exception.what() << endl;
		system("pause");
		return 0;
	}
	cout << str << endl;
	char* operands;
	float* values;
	int count;
	Postfix :: GetOperandsValues(/*const string &*/ str, /*char*&*/ operands, /*float*&*/ values, /*int&*/ count);
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 65) && (str[i] <= 90))
		{
				if (name.find(str[i]) != -1)
					continue;
				name = name + str[i];
		}
	}
	float* value = new float[name.length()];
	for (int i = 0; i < name.length(); i++)
	{
		cout << "enter the value of " << name[i] <<": " << endl;
		cin >> value[i];
	}
	float k = 0;
	try
	{
		k = Postfix::Calculating(str, name, value);
	}
	catch (M_Exeption &exception)
	{
		cerr << " Error: " << exception.what() << endl;
		system("pause");
		return 0;
	}
	cout << str << "  =" << k << endl;
	system("pause");
}