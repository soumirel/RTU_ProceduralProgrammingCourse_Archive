#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
	int zadanie;
	// 2�� ������
	float num1, num2;
	// 3� � 4�� ������
	float a, b, c, D, x1, x2, x;
	// 5�� ������ 
	int d_time, lamp, room, curtains;
	setlocale(LC_ALL, "Rus");
	while(1) {
		printf("������� ����� �������, ������� ������ ���������: \n");
		scanf_s("%d", &zadanie);
		switch (zadanie)
		{
		case 1:
			printf("������� 1.\n������! ����� ��������� �����: \n �������  �������  ����������\n");
			break;
		case 2:
			printf("\n ������� 2.\n�����������\n������� ��� �����:\n");
			scanf_s("%f%f",&num1, &num2);
			printf("\n����� �������� �����: %f", num1 + num2);
			printf("\n�������� �������� �����: %f ", num1 - num2);
			printf("\n������������ �������� �����: %f ", num1 * num2);
			if (num2 == 0) 
				printf("\n�������� �������� ����. ������� �� ���� ����������");
			else {
				printf("\n ������� �������� �����: %f \n", num1 / num2);
			}
			break;
		case 3:
			printf("\n������� ������������ b � �:\n ");
			scanf_s("%f%f", &b, &c);
			if (c != 0 && b != 0) {
				printf("���������� ��������� %fx + %f = 0 \n x = %f\n", b, c, -b / c);
			}
			else if (c == 0 && b != 0) {
				printf("���������� ��������� %fx  = 0 \n x = 0\n", b);
			}
			else if (c != 0 && b == 0) {
				printf("���������� ��������� %fx + %f = 0 \n ��������� �� ����� �������\n", b, c);
			}
			else if (c == 0 && b == 0) {
				printf("���������� ��������� %fx + %f = 0 \n x - ��� �����\n", b, c);
			}
			break;
		case 4:
			printf(".\n������� ������������ a, b � �: ");
			scanf_s("%f%f%f", &a, &b, &c);
			if (a == 0) {
				if (c != 0 && b != 0) {
					printf("���������� ��������� %fx + %f = 0 \n x = %f\n", b, c, -b / c);
				}
				else if (c == 0 && b != 0) {
					printf("���������� ��������� %fx  = 0 \n x = 0\n", b);
				}
				else if (c != 0 && b == 0) {
					printf("���������� ��������� %fx + %f = 0 \n ��������� �� ����� �������\n", b, c);
				}
				else if (c == 0 && b == 0) {
					printf("���������� ��������� %fx + %f = 0 \n x - ��� �����\n", b, c);
				}
			}
			else {
				printf("���������� ��������� %fx^2 + %fx + %f = 0 \n", a, b, c);
				D = b * b - 4 * a * c;
				if (D < 0) {
					printf("������������ ������ ����. \n��������� �� ����� ������� �� ��������� �������������� �����\n");
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
			printf("����� ������ ����� �����? (�������� �������������� ����� � �������� �) \n 1.���� 2. ����\n");
			scanf_s("%d", &d_time);
			printf("� ������� ���������� �����? (�������� �������������� ����� � �������� �) \n 1.���������� 2.�� ����������\n ");
			scanf_s("%d", &curtains);
			printf("� ������� �������� �����? (�������� �������������� ����� � �������� �) \n 1.�������� 2.���������\n");
			scanf_s("%d", &lamp);
			if (lamp == 1) {
				printf("� ������� ������.");
			}
			else if (curtains == 1 && d_time == 1) {
				printf("� ������� ������.");
			}
			else {
				printf("� ������� �����.");
			}
			return 0;
			break;
		}
	}
	return 0;
}












