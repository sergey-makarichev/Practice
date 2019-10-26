#include "TMatrix.h"
#include"TVector.h"

using namespace std;

void Test1()
{
	cout << "\t Тест 1: конструктор с параметром" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << endl << v << endl << endl;

}

void Test2()
{
	cout << "\t Тест 2: конструктор копирования" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << endl << v << endl << endl;

}

void Test3()
{
	cout << "\t Тест 3: конструктор индексации" << endl;
	int n, k;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите индекс, к которому хотите обратиться" << endl;
	cin >> k;
	if (k < n)
		cout << v[2] << endl << endl;
	else
		cout << "В данном векторе элемента с таким индексом не существует" << endl << endl;
}

void Test4()
{
	cout << "\t Тест 4: прибавление константы" << endl;
	int n;
	float c;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (v + c) << endl << endl;
}

void Test5()
{
	cout << "\t Тест 5: вычитание константы" << endl;
	int n;
	float c;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (v - c) << endl << endl;
}

void Test6()
{
	cout << "\t Тест 6: умножение на константу" << endl;
	int n;
	float c;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (v * c) << endl << endl;
}

void Test7()
{
	cout << "\t Тест 7: сумма векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v + k) << endl << endl;
	}
	catch (...)
	{
		cout << " Ошибка: длины векторов не совпадают  " << endl << endl;
	}
}

void Test8()
{
	cout << "\t Тест 8: разность векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v - k) << endl << endl;
	}
	catch (...)
	{
		cout << " Ошибка: длины векторов не совпадают  " << endl << endl;
	}
}

void Test9()
{
	cout << "\t Тест 9: скалярное произведение векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	try
	{
		cout << endl << (v * k) << endl << endl;
	}
	catch (...)
	{
		cout << " Ошибка: длины векторов не совпадают  " << endl << endl;
	}
}

void Test10()
{
	cout << "\t Тест 10: присваивание векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	cout << endl << (v = k) << endl << endl;
}

void Test11()
{
	cout << "\t Тест 11: сравнение на равенство векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	if (v == k)
		cout << "Векторы совпадают" << endl << endl;
	else
		cout << "Векторы не совпадают" << endl << endl;
}

void Test12()
{
	cout << "\t Тест 12: сравнение на неравенство векторов" << endl;
	int n;
	cout << "Введите длину вектора v" << endl;
	cin >> n;
	TVector<float> v(n);
	cout << "Введите координаты вектора v" << endl;
	cin >> v;
	cout << "Введите длину вектора k" << endl;
	cin >> n;
	TVector<float> k(n);
	cout << "Введите координаты вектора k" << endl;
	cin >> k;
	if (v != k)
		cout << "Векторы не совпадают" << endl << endl;
	else
		cout << "Векторы совпадают" << endl << endl;
}

void TestM1()
{
	cout << "\t Тест 1: конструктор с параметром" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << endl << m << endl << endl;
}

void TestM2()
{
	cout << "\t Тест 2: прибавление константы" << endl;
	int n;
	float c;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите константу, которую хотите прибавить" << endl;
	cin >> c;
	cout << endl << (m + c) << endl << endl;
}

void TestM3()
{
	cout << "\t Тест 3: вычитание константы" << endl;
	int n;
	float c;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите константу, которую хотите вычесть" << endl;
	cin >> c;
	cout << endl << (m - c) << endl << endl;
}

void TestM4()
{
	cout << "\t Тест 4: умножение на константу" << endl;
	int n;
	float c;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите константу, на которую хотите умножить" << endl;
	cin >> c;
	cout << endl << (m * c) << endl << endl;
}

void TestM5()
{
	cout << "\t Тест 5: сложение матриц" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер матрицы m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m1" << endl;
	cin >> m1;
	try
	{
		cout << endl << (m + m1) << endl << endl;
	}
	catch (...)
	{
		cout << " Ошибка: размеры матриц не совпадают  " << endl << endl;
	}
}

void TestM6()
{
	cout << "\t Тест 6: вычитание матриц" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер матрицы m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m1" << endl;
	cin >> m1;
	try
	{
		cout << endl << (m - m1) << endl << endl;
	}
	catch (...)
	{
		cout << " Ошибка: размеры матриц не совпадают  " << endl << endl;
	}
}

void TestM7()
{
	cout << "\t Тест 7: присваивание матриц" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер матрицы m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m1" << endl;
	cin >> m1;
	cout << endl << (m = m1) << endl << endl;
}

void TestM8()
{
	cout << "\t Тест 8: сравнение на равенство матриц" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер матрицы m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m1" << endl;
	cin >> m1;
	if (m == m1)
		cout << "Матрицы совпадают" << endl << endl;
	else
		cout << "Матрицы не совпадают" << endl << endl;
}

void TestM9()
{
	cout << "\t Тест 9: сравнение на неравенство матриц" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер матрицы m1" << endl;
	cin >> n;
	TMatrix<float> m1(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m1" << endl;
	cin >> m1;
	if (m != m1)
		cout << "Матрицы не совпадают" << endl << endl;
	else
		cout << "Матрицы совпадают" << endl << endl;
}

void TestM10()
{
	cout << "\t Тест : умножение матрицы на вектор" << endl;
	int n;
	cout << "Введите размер матрицы m" << endl;
	cin >> n;
	TMatrix<float> m(n);
	cout << "Введите почленно элементы верхнетреугольной матрицы m" << endl;
	cin >> m;
	cout << "Введите размер вектора v1" << endl;
	cin >> n;
	TVector<float> v1(n);
	cout << "Введите координаты вектора v1" << endl;
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