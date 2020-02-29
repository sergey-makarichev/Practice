#include "Polinom.h"
//#include "TNode.h"
#include <string>
#include <stdlib.h> 
#include"Exception.h"
using namespace std;

int main()
{
	try
	{
		string s;
		std::getline(std::cin, s);
		Polinom pol(s);
		cout << pol;
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