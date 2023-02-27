#include <stdio.h>
#include <locale.h>
#define a 5
#define b 5
#include <stdlib.h>

int x = 1;
int mass[a] = { 0 };




int main() {
	setlocale(LC_ALL, "Russian");
	int mass_1[a][b];
	my_func(mass_1, a, b);
	;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d\t", mass_1[i][j]);
		}
		printf("\n");
	}
	int s1 = my_func1(mass_1, a, b);
	printf("i_s_max_summoi = %d", s1);
	;
	return 0;
}

int my_func(int* mass, int a_f, int b_f) {
	srand(time(NULL));
	for (size_t i = 0; i < a_f; i++)
	{
		for (size_t j = 0; j < b_f; j++)
		{
			*(mass + i * b_f + j) = rand() % 10 + 1;
		}
		}
	}


int my_func1(int* mass, int a_f, int b_f) {
	int s = 0;
	int temp_s, iM = 0;
	for (size_t i = 0; i < a_f; i++)
	{
		temp_s = 0;
		for (size_t j = 0; j < b_f; j++)
		{
			temp_s += *(mass + i * b_f + j);
		}
		if (temp_s >= s) {
			s = temp_s;
			iM = i;
		}
	}
	return iM;

}