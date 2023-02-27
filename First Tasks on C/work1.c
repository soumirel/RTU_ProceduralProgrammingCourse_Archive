#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
	int zadanie;
	// 2ая задача
	float num1, num2;
	// 3я и 4ая задача
	float a, b, c, D, x1, x2, x;
	// 5ая задача 
	int d_time, lamp, room, curtains;
	setlocale(LC_ALL, "Rus");
	while(1) {
		printf("Введите номер задания, которое хотите проверить: \n");
		scanf_s("%d", &zadanie);
		switch (zadanie)
		{
		case 1:
			printf("Задание 1.\nПривет! Моего создателя зовут: \n Мазанов  Алексей  Евгеньевич\n");
			break;
		case 2:
			printf("\n Задание 2.\nКалькулятор\nВведите два числа:\n");
			scanf_s("%f%f",&num1, &num2);
			printf("\nСумма введённых чисел: %f", num1 + num2);
			printf("\nРазность введённых чисел: %f ", num1 - num2);
			printf("\nПроизведение введённых чисел: %f ", num1 * num2);
			if (num2 == 0) 
				printf("\nДелитель является нулём. Деление на ноль невозможно");
			else {
				printf("\n Частное введённых чисел: %f \n", num1 / num2);
			}
			break;
		case 3:
			printf("\nВведите коэффициенты b и с:\n ");
			scanf_s("%f%f", &b, &c);
			if (c != 0 && b != 0) {
				printf("Полученное уравнение %fx + %f = 0 \n x = %f\n", b, c, -b / c);
			}
			else if (c == 0 && b != 0) {
				printf("Полученное уравнение %fx  = 0 \n x = 0\n", b);
			}
			else if (c != 0 && b == 0) {
				printf("Полученное уравнение %fx + %f = 0 \n уравнение не имеет решений\n", b, c);
			}
			else if (c == 0 && b == 0) {
				printf("Полученное уравнение %fx + %f = 0 \n x - все числа\n", b, c);
			}
			break;
		case 4:
			printf(".\nВведите коэффициенты a, b и с: ");
			scanf_s("%f%f%f", &a, &b, &c);
			if (a == 0) {
				if (c != 0 && b != 0) {
					printf("Полученное уравнение %fx + %f = 0 \n x = %f\n", b, c, -b / c);
				}
				else if (c == 0 && b != 0) {
					printf("Полученное уравнение %fx  = 0 \n x = 0\n", b);
				}
				else if (c != 0 && b == 0) {
					printf("Полученное уравнение %fx + %f = 0 \n уравнение не имеет решений\n", b, c);
				}
				else if (c == 0 && b == 0) {
					printf("Полученное уравнение %fx + %f = 0 \n x - все числа\n", b, c);
				}
			}
			else {
				printf("Полученное уравнение %fx^2 + %fx + %f = 0 \n", a, b, c);
				D = b * b - 4 * a * c;
				if (D < 0) {
					printf("Дискриминант меньше нуля. \nУравнение не имеет решений на множестве действительных чисел\n");
				}
				else if (D == 0) {
					x = -b / 2 * a;
					printf(" x = %f", x);
				}
				else {
					x1 = (-b - sqrt(D)) / 2 * a;
					x2 = (-b + sqrt(D)) / 2 * a;
					printf("x1 = %f    x2 = %f\n", x1, x2);
				}
			}
			;
			break;
		case 5:
			printf("Какое сейчас время суток? (выберите соответсвующую цифру и наберите её) \n 1.День 2. Ночь\n");
			scanf_s("%d", &d_time);
			printf("В комнате раздвунуты шторы? (выберите соответсвующую цифру и наберите её) \n 1.Раздвинуты 2.Не раздвинуты\n ");
			scanf_s("%d", &curtains);
			printf("В комнате включена лампа? (выберите соответсвующую цифру и наберите её) \n 1.Включена 2.Выключена\n");
			scanf_s("%d", &lamp);
			if (lamp == 1) {
				printf("В комнате светло.");
			}
			else if (curtains == 1 && d_time == 1) {
				printf("В комнате светло.");
			}
			else {
				printf("В комнате темно.");
			}
			return 0;
			break;
		}
	}
	return 0;
}












