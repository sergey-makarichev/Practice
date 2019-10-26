#include "Vector.h"



void Test1() // прибавление константы
{
	int n, c;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (v + c) << endl;
}

void Test2() // вычитание константы
{
	int n;
	float c;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (v - c) << endl;
}

void Test3() //конструктор
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << endl << v << endl;

}

void Test4() // конструктор
{
	int n;
	cout << "¬ведите длину массива значений" << endl;
	cin >> n;
	float* x = new float(n);
	cout << "¬ведите координаты массива значений" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	TVector<float> v(n, x);
	cout << endl << v << endl;
}

void Test5() // конструктор копировани€
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << endl << v << endl;
	
}

void Test6() //длина
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << endl << v.len() << endl;
}

void Test7() // сумма векторов
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v + k) << endl;
	}
	catch (...)
	{
		cout << " ќшибка: длины векторов не совпадают  " << endl;
	}
}

void Test8() // разность векторов
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v - k) << endl;
	}
	catch (...)
	{
		cout << " ќшибка: длины векторов не совпадают  " << endl;
	}
}

void Test9() // скал€рное произведение
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v * k) << endl;
	}
	catch (...)
	{
		cout << " ќшибка: длины векторов не совпадают  " << endl;
	}
}

void Test10() // присваивание
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	cout << endl << (v = k) << endl;
	
}

void Test11() // сравнение на равенство
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	if (v == k)
		cout << "¬екторы совпадают" << endl;
}

void Test12() // сравнение на неравенство
{
	int n;
	cout << "¬ведите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "¬ведите координаты вектора v" << endl;
	cin >> v;
	cout << "¬ведите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "¬ведите координаты вектора k" << endl;
	cin >> k;
	if (v != k)
		cout << "¬екторы не совпадают" << endl;
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