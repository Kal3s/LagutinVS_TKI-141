#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

int input(void);

double avg(const double pervoe, const double vtoroe);

int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("Введите первое натуральное число:");
	double pervoe = input();
	puts("Введите второе натуральное число:");
	double vtoroe = input();
	if (avg(pervoe, vtoroe) == 1) {
		printf("Среденее арифметическое целое");
	}
	else {
		printf("Среднее арифметическое не целое");
	}

	return 0;
}

int input(void) {
	int value = 0;
	int result = scanf("%d", &value);
	if (result != 1) {
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}

	return value;
}

double avg(const double pervoe, const double vtoroe) {
	double avg = (pervoe + vtoroe) / 2;
	if ((int)avg == avg) {
		return 1;
	}
	else {
		return 0;
	}
}