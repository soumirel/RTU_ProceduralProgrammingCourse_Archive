#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h> 
#include <typeinfo>



using namespace std;

void sorting(int arr[], int size) 
{
	double factor = 1.2473309;
	int step = size - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < size; i++)
		{
			if (arr[i] > arr[i + step])
			{
				swap(arr[i], arr[i + step]);
			}
		}
		step /= factor;
	}
}


void digit_filter()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	char letter;
	bool first_num = false;
	ifstream myfile("num3-4.txt");
	if (!myfile.is_open())
	{
		cout << "Файл не можеит быть открыт" << endl;
	}
	else
	{
		cout << "Все числа из файла text.txt:" << endl;
		while (!myfile.eof())
		{
			while (myfile.get(letter))
			{
				if (int(letter) >= 48 && int(letter) <= 57)
				{
					cout << letter;
					first_num = true;
				}
				if (letter == ' ' && first_num)
				{
					cout << " ";
				}
				if (letter == '\n' && first_num)
				{
					cout << "\n";
				}
			}
		}
	}
	myfile.close();
	cout << endl;
}


void copy_text()
{
	setlocale(LC_ALL, "rus");
	char buff[255];
	ifstream myfile("num3-4.txt");
	if (!myfile.is_open())
	{
		cout << "Файл не можеит быть открыт" << endl;
	}
	else
	{
		cout << "Текст из файла text.txt:" << endl;
		while (myfile.getline(buff, 255))
		{
			cout << buff << endl;
		}
		myfile.close();
			 
	}
}


void loan() {
	double S, n, r, m, E, m1, step;
	cout << "Введите размер кредита: \n";
	while (!(cin >> S) || S < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Введите величину месячных выплат: \n";
	while (!(cin >> m))
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	}
	cout << "Введите количество лет n:\n";
	while (!(cin >> n) || n < 0)
	{
		cout << "Ошибка ввода.\nВведите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	int k = m, deg_of_err = -8;
	while (k > 0)
	{
		deg_of_err += 1; 
		k /= 10;
	}
	E = pow(10, deg_of_err); 
	if (m > S) 
	{
		cout << "Кредит был погашен первой выплатой.\nОпределение процента невозможно.\n";
	}
	else if (S / (n * 12) == m) 
	{
		cout << "Кредит выдан под нулевой процент.\n";
	}
	else if (S / (n * 12) > m) 
	{
		double r = (m * n * 12 - S) / S;
		printf("\nКредит размера %.2lf, ежемесячные выплаты %.2lf в течение %.2lf лет, выдан под процент %lf.\n\n", S, m, n, r * 100);
	}
	else
	{
		int i = 0;
		step = 1;
		r = 1;
		m1 = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m1 - m) >= E)
		{
			i += 1;
			printf("m1 = %lf\t r = %lf\t\t i = %d\t\n", m1, r, i);
			if (m1 > m)
			{
				r -= step;
				step /= 2;
			}
			if (2 * m1 < m)
			{
				step *= 2;
			}
			r += step;
			m1 = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		printf("\nm1 = %lf\t r = %lf\t\t i = %d\t\n", m1, r, i);
		printf("\nКредит размера %.2lf, ежемесячные выплаты %.2lf в течение %.2lf лет, выдан под процент %lf. (с погрешностью +- %lf).\n\n", S, m, n, r * 100, E);
	}
}


void debt() // Заём
{
	float p, S, n;
	cout << "Введите размер займа S:" << endl;
	cin >> S;
	cout << "Введите срок выплаты (в годах) n:" << endl;
	cin >> n;
	cout << "Введите размер процентной ставки p:" << endl;
	cin >> p;
	float r, pay;
	r = p / 100;
	if (p == 0)
	{
		cout << (S / 12 * n) << endl;
	}
	pay = (S * r * pow((1 + r), n)) / (12 * ((pow((1 + r), n) - 1)));
	if (p < -100)
	{
		cout << "Ссудя по величине введенных процентов - вместо того, чтобы платить банку, банк будет платить вам\n";
		cout << -pay << endl; 
	}

	cout << "Выплата равна: ";
	cout << pay << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	const int SIZE = 30;
	ifstream myfile;
	//
	int zadanie;                   // Номер задания
	bool flag = true;			   // Проверка, хочет ли пользователь проверять дальше
	//
	while (flag != false)
	{
		cout << "Введите номер задания, которое хотите проверить. (Если вы хотите закончить проверку - введите 0)" << endl;
		cin >> zadanie;
		//
		switch (zadanie)
		{
			//
		case(0):
			flag = false;
			break;
			//
		case(1):  // Заем
			debt();
			break;
			//
		case(2):  // Cсуда
			loan();
			break;
			//
		case(3): // Копирование файла
			copy_text();
			break;
			//
		case(4):  //Фильтр
			digit_filter();
			break;
			//
		case(5):  //Сортировка букв
			char C[SIZE];
			int c_to_int[SIZE];
			char int_to_c[SIZE];
			myfile.open("num5.txt");

			if (myfile.is_open())
			{
				char ch;
				for (size_t i = 0; i < 30; i++)
				{
					myfile.get(ch);
					C[i] = ch;
				}
				myfile.close();

				for (int i = 0; i < SIZE; i++)
				{
					c_to_int[i] = C[i];
				}

				sorting(c_to_int, SIZE); 

				for (int i = 0; i < SIZE; i++)
				{
					int_to_c[i] = c_to_int[i];
				}

				for (int i = 0; i < SIZE; i++)
				{
					cout << int_to_c[i] << " ";
				}

				cout << endl << endl;
			}
			else
			{
				cout << "Не удается открыть файл" << endl;
				break;
			}
			break;
		default:
			cout << "Я не понимаю вас."<< endl;
			break;
		}
	}
}