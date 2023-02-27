#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#define n 1000



void sieve()
{
	int arr[n] = { 0 };
	;
	for (int i = 2; pow(i, 2) < n; i++)
	{
		if (arr[i] == 0) {
			for (int j = pow(i, 2); j < n; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i < n; i++)
	{
		if (arr[i] == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}



void Euc_Alg(num1, num2, type)
{
	if (type == 0) 
	{
		if (num1 != 0 && num2 != 0)
		{
			while (num1 != 0 && num2 != 0)
			{
				if (num1 > num2) num1 %= num2;
				else num2 %= num1;
			}
			printf("%d\n", num1 + num2);
		}
		else printf("����� ��� ����������.\n");
	}		
	if (type == 1) {
		if (num1 == 0 && num2 == 0)
		{
			printf("����� ��� ����������.\n");
		}
		else if (num1 == 0 || num2 == 0)
		{
			printf("���������� ����� �������� �������� �����:\n%d\n", max(num1, num2));
		}
		else {
			num1 = abs(num1);
			num2 = abs(num2);
			if (num1 != num2)
			{
				while (num1 != num2)
				{
					if (num1 > num2) num1 -= num2;
					else num2 -= num1;
				}
				printf("���������� ����� �������� �������� �����:\n%d\n", num1);
			}
			else printf("���������� ����� �������� �������� �����:\n%d\n", num1);
		}
	}
	
}



void main() 
	{
	;
	setlocale(LC_ALL, "Russian");
	;
	int zadanie; // ����� �������
	bool flag = true;   // ��������, ����� �� ������������ ��������� ������
	int num_to_EA1, num_to_EA2, diff_or_div;    // ��� ����� ��� ������ ���, ��������� - ����� ������� ���������� ���
	;
	while (flag != false)
	{
		printf("������� ����� �������, ������� ������ ���������. (���� �� ������ ��������� �������� - ������� 0) \n");
		scanf_s("%d", &zadanie);
		//
		switch (zadanie)
		{
		case(0):
			flag = false;
			break;
		case(1):
			printf("������� ��� ����� ��� ���������� ���:\n");
			scanf_s("%d%d", &num_to_EA1, &num_to_EA2);
			printf("����� �������� ��� �������� ���?\n ������� \"0\" ��� ������ ��������\n ������� \"1\" ��� ������ ����������\n");
			scanf_s("%d", &diff_or_div);
			Euc_Alg(num_to_EA1, num_to_EA2, diff_or_div);
			break;
		case(2):
			sieve();
			break;
		default:
			printf("� �� ������� ���.\n");
		}
	}
}