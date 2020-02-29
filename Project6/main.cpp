#include "Polinom.h"
#include <string>
#include <stdlib.h> 
#include"Exception.h"
using namespace std;


//-2+5x^2y+z-yz+x^2yz
//2 + y - 2z + x ^ 2y
int main()
{
	try
	{
		string s1, s2;
		std::getline(std::cin, s1);
		Polinom pol1(s1);
		std::getline(std::cin, s2);
		Polinom pol2(s2);
		cout << pol1 + pol2;
	}
	catch (const M_Exeption & exception)
	{
		cerr << " Error: " << exception.what() << endl;


	}
	/*TList<int, float> l;
	TNode<int, float> k(2,5);
	TNode<int, float> m(1, 6);
	l.InsertBegin(3,4);
	l.InsertBefore(3,&k);
	l.InsertAfter(3, &m);
	l.Sort();
	cout << l;
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
	cout << a;*/
	system ("pause");

	return 0;
}