#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


int* merge_sort(int* up, int* down, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	unsigned int middle = (left + right) / 2;

	// �������� � ��������
	int* l_buff = merge_sort(up, down, left, middle);
	int* r_buff = merge_sort(up, down, middle + 1, right);

	// ������� ���� ��������������� �������
	int* target = l_buff == up ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
}


int sorting()
{
	FILE* file;
	char* fname = "text.txt";
	char result_string[255];

	file = fopen(fname, "r");
	if (file == NULL)
	{
		printf("���� %s �� ������\n", fname);
		return 0;
	}

	char mass_buffer[255];
	char mass_main[255];
	fgets(result_string, sizeof(result_string), file);
	printf("%s", merge_sort(result_string, mass_buffer, 0, 1));
	printf("\n");
	fclose(file);

	return 0;
}


void digit_filter()
{
	FILE* file;
	char* fname = "text.txt";
	char result_string;

	file = fopen(fname, "r");
	if (file == NULL)
	{
		printf("���� %s �� ������\n", fname);
		return 0;
	}

	result_string = fgetc(file);
	while (result_string != EOF)
	{
		if (result_string >= '0' && result_string <= '9')
		{
			printf("%c", result_string);
		}
		if (result_string == '\n')
		{
			printf("\n");
		}
		result_string = fgetc(file);
	}
	printf("\n");
	fclose(file);

	return 0;
}


int copy_text()
{
	FILE* file;
	char* fname = "text.txt";
	char result_string[255];

	file = fopen(fname, "r");
	if (file == NULL)
	{
		printf("���� %s �� ������\n", fname);
		return 0;
	}


	while (fgets(result_string, sizeof(result_string), file))
	{
		printf("%s", result_string);
	}
	printf("\n");
	fclose(file);

	return 0;
}
	

float ssyda(float S, float m, float n) // Cc���
{
	float r, m1;
	float p = 0;
	bool flag = false;
	if (n * 12 * m < S)
	{
		printf("����� �������� �������� ������� ������, ��� ������ �����. ������ ����������.\n");
		return -1;
	}
	else if (n * 12 * m == S)
	{
		return 0;
	}
	else
	{
		while (flag == false)
		{
			p += 0.0001;
			r = p / 100;
			m1 = (S * r * pow((1 + r), n)) / (12 * ((pow((1 + r), n) - 1)));
			if (abs(m - m1) < 0.001)
			{
				flag = true;
				return p;
			}
		}
	}
}


float debt(float S, float n, float p) // ���
{
	float r, pay;
	r = p / 100;
	pay = (S * r * pow((1 + r), n)) / (12 * ((pow((1 + r), n) - 1)));
	return pay;
}


void main()
{
	setlocale(LC_ALL, "Russian");
	//
	int zadanie;                   // ����� �������
	bool flag = true;			   // ��������, ����� �� ������������ ��������� ������
	//
	float percentage, credit, years, payment;     // ��� � �����
	//
	while (flag != false)
	{
		printf("������� ����� �������, ������� ������ ���������. (���� �� ������ ��������� �������� - ������� 0) \n");
		scanf_s("%d", &zadanie);
		//
		switch (zadanie)
		{
		//
		case(0):
			flag = false;
			break;
		//
		case(1):  // ����
			printf("������� ������ ����� S:\n");
			scanf_s("%f", &credit);
			printf("������� ���� ������� (� �����) n:\n");
			scanf_s("%f", &years);
			printf("������� ������ ���������� ������ p:\n");
			scanf_s("%f", &percentage);
			printf("����������� ������� = %.1f\n", debt(credit, years, percentage));
			break;
		//
		case(2):  // C����
			printf("������� ������ ����� S:\n");
			scanf_s("%f", &credit);
			printf("������� ������ ����������� ������� m:\n");
			scanf_s("%f", &payment);
			printf("������� ���� ������� (� �����) n:\n");
			scanf_s("%f", &years);
			if (ssyda(credit, payment, years) != -1) 
			{
			printf("������ ��������� �� ������ �������� ��������: %.3f\n", ssyda(credit, payment, years));
			}
			break;
		//
		case(3): // ����������� �����
			copy_text();
			break;
		//
		case(4):  //������
			digit_filter();
			break;
		//
		case(5):  //���������� ����
			sorting();
			break;
		//
		default:
			printf("� �� ������� ���.\n");
			break;
		}
	}
}