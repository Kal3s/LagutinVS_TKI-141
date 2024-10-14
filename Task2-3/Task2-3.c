#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

/**
* @brief Проверка введенных данных.
* @return Возвращает значение, если выполнено успешно, или ошибку, если иначе.
*/
int input(void);

/**
* @brief Рассчитывает среднее значение и проверяет целое оно или нет.
* @param pervoe Первое натуральное число.
* @param vtoroe Второе натуральное число.
* @return Возвращает 1 если целое, или 0 если не целое.
*/
double avg(const double first, const double second);

/**
* @brief Точка входа в программу.
* @return 0 в случае успеха.
*/
int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("Введите первое натуральное число:");
	double first = input();
	puts("Введите второе натуральное число:");
	double second = input();
	if (avg(first, second) == 1) {
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

double avg(const double first, const double second) {
	double avg = (first + second) / 2;
	if ((int)avg == avg) {
		return 1;
	}
	return 0;
}
