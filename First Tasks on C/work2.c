#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
	int zadanie;
	int R, r, h, l;   // Задание 1
	float V, S;       // Задание 1
	//
	float w, a, x;    // Задание 2
	//
	float x3, y3, b3; // Задание 3
	//
	int N4;			  // Задание 4
	//
	double y5, x5;    // Задание 5
	//
	setlocale(LC_ALL, "Rus");
	//
	while (1) {
		//
		printf("Введите номер задания, которое хотите проверить: \n");
		scanf_s("%d", &zadanie);
		//
		switch (zadanie)
		{
		case 1:   // конус
			printf("Введите R, r и h в указаном порядке\n");
			scanf_s("%d%d%d", &R, &r, &h);				
			l = sqrt(pow(h, 2) + pow((abs(R - r)), 2));
			V = (1.0 / 3.0) * 3.14 * h * (pow(R, 2) + R * r + pow(r, 2));
			S = 3.14 * (pow(R, 2) + (R + r) * l + pow(r, 2));
			printf("V = %f\nS= %f\n", V, S);
			break;
		//
		case 2:       // разветвление 
			printf("Введите \'a\' и \'x\' в указанном порядке\n");
			scanf_s("%f%f", &a, &x);
			if (fabs(x) < 1) {
				w = log(fabs(x)) * a;
				printf("w = %f\n", w);
			}
			else {
				if (x * x >= a) {
					printf("Значение w не определено\n");
				}
				else {
					w = sqrt(a - x * x);
					printf("w = %f\n", w);
				}
			}
			break;
		//
		case 5:     // табуляция
			printf("   x      y\n");
			for (float i = -4; i <= 4; i += 0.5) {
				x5 = i;
				if (x5 - 1 != 0) {
					y5 = (x5 * x5 - 2 * x5 + 2) / (x5 - 1);
					printf("%.3f   %.3f\n", x5, y5);
				}
				else {
					printf("%.3f   N/A\n", x5);
				}
			}
			break;
		case 3:     // функция
			printf("Введите значения x, y и b в указанном порядке:\n");
			scanf_s("%f%f%f", &x3, &y3, &b3);
			if (b3 - y3 > 0 && b3 - x3 >= 0) {
				printf("z = %f\n", logf(b3 - y3) * sqrt(b3 - x3));
			}
			else {
				printf("Значение z не определено\n");
			}
			break;
		case 4:     // Порядок
			printf("Введите N:\n");
			scanf_s("%d", &N4);
			for (int i4 = N4; i4 < N4 + 10; i4 += 1) {
				printf("%d ", i4);
			}
			printf("\n");
			break;
		}	
	}
}







