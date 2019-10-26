#include "Vector.h"



void Test1() // ����������� ���������
{
	int n, c;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (v + c) << endl;
}

void Test2() // ��������� ���������
{
	int n;
	float c;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << "������� ���������, ������� ������ ���������" << endl;
	cin >> c;
	cout << endl << (v - c) << endl;
}

void Test3() //�����������
{
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << endl << v << endl;

}

void Test4() // �����������
{
	int n;
	cout << "������� ����� ������� ��������" << endl;
	cin >> n;
	float* x = new float(n);
	cout << "������� ���������� ������� ��������" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	TVector<float> v(n, x);
	cout << endl << v << endl;
}

void Test5() // ����������� �����������
{
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << endl << v << endl;
	
}

void Test6() //�����
{
	int n;
	cout << "������� ����� ������� v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "������� ���������� ������� v" << endl;
	cin >> v;
	cout << endl << v.len() << endl;
}

void Test7() // ����� ��������
{
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
		cout << endl << (v + k) << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl;
	}
}

void Test8() // �������� ��������
{
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
		cout << endl << (v - k) << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl;
	}
}

void Test9() // ��������� ������������
{
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
		cout << endl << (v * k) << endl;
	}
	catch (...)
	{
		cout << " ������: ����� �������� �� ���������  " << endl;
	}
}

void Test10() // ������������
{
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
	cout << endl << (v = k) << endl;
	
}

void Test11() // ��������� �� ���������
{
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
		cout << "������� ���������" << endl;
}

void Test12() // ��������� �� �����������
{
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
		cout << "������� �� ���������" << endl;
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
	system("pause");
}