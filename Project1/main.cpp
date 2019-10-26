#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, k, s, c;
	cout << " Введите длину 1-го вектора" << endl;
	cin >> n;
	Vector a(n);
	cout << " Введите координаты 1-го вектора" << endl;
	cin >> a;
	cout << " Введите длину 2-го вектора" << endl;
	cin >> k;
	Vector b(k);
	cout << " Введите координаты 2-го вектора" << endl;
	cin >> b;
	cout << " Выберите действие, которыое хотели бы сделать с данным вектором" << endl;
	cout << "1. Длина данного вектора " << endl;
	cout << "2. Прибавление константы " << endl;
	cout << "3. Вычитание константы " << endl;
	cout << "4. Прибавление вектора " << endl;
	cout << "5. Вычитание вектора " << endl;
	cout << "6. Скалярное произведение векторов " << endl;
	cout << "7. Присваивание векторов " << endl;
	cout << "8. Сравнение на равенство двух векторов " << endl;
	cout << "9. Сравнение на неравенство двух векторов " << endl;
	cin >> s;
	switch (s)
	{
	case 1:
		cout << a.len();
		break;
	case 2:
		cout << " Введите число, которое хотели бы прибавить" << endl;
		cin >> c;
		cout << (a + c) << endl;
		break;
	case 3:
		cout << " Введите число, которое хотели бы вычесть" << endl;
		cin >> c;
		cout << (a - c) << endl;
		break;
	case 4:
		try
		{
			cout << (a + b);
		}
		catch (...)
		{
			cout << " Ошибка: длины векторов не совпадают  " << endl;
		}
		break;
	case 5:
		try
		{
			cout << (a - b);
		}
		catch (...)
		{
			cout << " Ошибка: длины векторов не совпадают  " << endl;
		}
		break;
	case 6:
		try
		{
			cout << (a * b) << endl;
		}
		catch (...)
		{
			cout << " Ошибка: длины векторов не совпадают " << endl;
		}
		break;
	case 7:
		cout << (a = b) << endl;
		break;
	case 8:
		if (a == b)
			cout << "Векторы совпадают" << endl;
		else
			cout << "Векторы не совпадают" << endl;
		break;
	case 9:
		if (a != b)
			cout << "Векторы не совпадают" << endl;
		else
			cout << "Векторы совпадают" << endl;
		break;

	default:
		cout << "Неправильный ввод" << endl;
	}
	system("pause");
}