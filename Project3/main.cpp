#include "TMatrix.h"
#include"TVector.h"

using namespace std;

void Test1()
{
	cout << "\t ���� 1: ����������� � ����������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << endl << v << endl << endl;

}

void Test2()
{
	cout << "\t ���� 2: ����������� �����������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << endl << v << endl << endl;

}

void Test3()
{
	cout << "\t ���� 3: ����������� ����������" << endl;
	int n, k;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ������, � �������� ������ ����������" << endl;
	cin >> k;
	if (k < n)
		cout << v[2] << endl << endl;
	else
		cout << "� ������ ������� �������� � ����� �������� �� ����������" << endl << endl;
}

void Test4()
{
	cout << "\t ���� 4: ����������� ���������" << endl;
	int n;
	float c;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (v + c) << endl << endl;
}

void Test5()
{
	cout << "\t ���� 5: ��������� ���������" << endl;
	int n;
	float c;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (v - c) << endl << endl;
}

void Test6()
{
	cout << "\t ���� 6: ��������� �� ���������" << endl;
	int n;
	float c;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (v * c) << endl << endl;
}

void Test7()
{
	cout << "\t ���� 7: ����� ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v + k) << endl << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl << endl;
	}
}

void Test8()
{
	cout << "\t ���� 8: �������� ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v - k) << endl << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl << endl;
	}
}

void Test9()
{
	cout << "\t ���� 9: ��������� ������������ ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v * k) << endl << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl << endl;
	}
}

void Test10()
{
	cout << "\t ���� 10: ������������ ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	cout << endl << (v = k) << endl << endl;
}

void Test11()
{
	cout << "\t ���� 11: ��������� �� ��������� ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	if (v == k)
		cout << "������� ���������" << endl << endl;
	else
		cout << "������� �� ���������" << endl << endl;
}

void Test12()
{
	cout << "\t ���� 12: ��������� �� ����������� ��������" << endl;
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ����� ������� k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "������� ���������� ������� k" << endl;
	cin >> k;
	if (v != k)
		cout << "������� �� ���������" << endl << endl;
	else
		cout << "������� ���������" << endl << endl;
}

void TestM1()
{
	cout << "\t ���� 1: ����������� � ����������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << endl << m << endl << endl;
}

void TestM2()
{
	cout << "\t ���� 2: ����������� ���������" << endl;
	int n;
	float c;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (m + c) << endl << endl;
}

void TestM3()
{
	cout << "\t ���� 3: ��������� ���������" << endl;
	int n;
	float c;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ���������, ������� ������ �������" << endl;
	cin >> c;
	cout << endl << (m - c) << endl << endl;
}

void TestM4()
{
	cout << "\t ���� 4: ��������� �� ���������" << endl;
	int n;
	float c;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ���������, �� ������� ������ ��������" << endl;
	cin >> c;
	cout << endl << (m * c) << endl << endl;
}

void TestM5()
{
	cout << "\t ���� 5: �������� ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "������� �������� �������� ����������������� ������� m1" << endl;
	cin >> m1;
	try
	{
		cout << endl << (m + m1) << endl << endl;
	}
	catch (...)
	{
		cout << " ������: ������� ������ �� ���������  " << endl << endl;
	}
}

void TestM6()
{
	cout << "\t ���� 6: ��������� ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "������� �������� �������� ����������������� ������� m1" << endl;
	cin >> m1;
	try
	{
		cout << endl << (m - m1) << endl << endl;
	}
	catch (...)
	{
		cout << " ������: ������� ������ �� ���������  " << endl << endl;
	}
}

void TestM7()
{
	cout << "\t ���� 7: ������������ ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "������� �������� �������� ����������������� ������� m1" << endl;
	cin >> m1;
	cout << endl << (m = m1) << endl << endl;
}

void TestM8()
{
	cout << "\t ���� 8: ��������� �� ��������� ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "������� �������� �������� ����������������� ������� m1" << endl;
	cin >> m1;
	if (m == m1)
		cout << "������� ���������" << endl << endl;
	else
		cout << "������� �� ���������" << endl << endl;
}

void TestM9()
{
	cout << "\t ���� 9: ��������� �� ����������� ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "������� �������� �������� ����������������� ������� m1" << endl;
	cin >> m1;
	if (m != m1)
		cout << "������� �� ���������" << endl << endl;
	else
		cout << "������� ���������" << endl << endl;
}

void TestM10()
{
	cout << "\t ���� : ��������� ������� �� ������" << endl;
	int n;
	cout << "������� ������ ������� m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "������� �������� �������� ����������������� ������� m" << endl;
	cin >> m;
	cout << "������� ������ ������� v1" << endl;
	cin >> n;
	TVector<float> v1(n);
	cout << "������� ���������� ������� v1" << endl;
	cin >> v1;
	cout << (m * v1) << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();
	TestM1();
	TestM2();
	TestM4();
	TestM5();
	TestM6();
	TestM7();
	TestM8();
	TestM9();
	TestM10();
	system("pause");
}