#include <iostream>
#include "TStack.h"
#include "Postfix.h"
using namespace std;

int main()
{
	try
	{
		string str;
		std::getline(std::cin, str);
		str = Postfix::PostfixForm(str);
		cout << str << endl;
		
		char* operands;
		float* values;
		int count = 0;
		Postfix::GetOperandsValues(str, operands, values, count);
		
		float k = Postfix::Calculating(str, operands, values, count);
		cout << str << "  =" << k << endl;
		
		delete[] operands;
		delete[] values;
	}
	catch (const M_Exeption &exception)
	{
		cerr << " Error: "<< exception.what() << endl;
		
		
	}

	system("pause");
	return 0;
}