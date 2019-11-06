#include <iostream>
#include "TStack.h"

int main()
{
	string v;
	cin >> v;
	/*for (int i = 0; i < 6; i++)
	{
		cout << v[i];
	}*/
	TStack<char> :: Postfix(v);
	cout << v;
	system("pause");

}