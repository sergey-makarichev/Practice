#include "TList.h"
#include "TNode.h"
#include <string>
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main()
{
	string s;
	float a = 1;
	std::getline(std::cin, s);
	int i = s[0] - 48;
	cout << s.length() << endl;
	cout << s[0] << endl;
	if (!isdigit(s[0]))
		cout << "1" << endl;
	cout << i << endl;
	if (s[0] > 2)
	{
		cout << "yes";
	}
	a = (atof(s.c_str()));
	cout << a;
	system ("pause");
}