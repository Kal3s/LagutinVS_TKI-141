#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Проверка введенных данных.
* @return Возвращает значение, если выполнено успешно, или ошибку, если иначе.
*/
double input(void);

/**
* @brief Рассчитывает функцию.
* @param a Неизменная константа.
* @param x Введенное значение.
* @return Возвращает функцию в зависимости от введенного числа.
*/
double get_function(const double a, const double x);

/**
* @brief Точка входа в программу.
* @return 0 в случае успеха.
*/
int main() {
	setlocale(LC_ALL, "Russian");
	const double a = 2.5;
	puts("Введите х: ");
	double x = input();
	printf("y = %lf", get_function(a, x));

	return 0;
}

double input(void) {
	double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1) {
		errno = EIO;
		perror("Не удалось считать число");
		exit(EXIT_FAILURE);
	}

	return value;
}

double get_function(const double a, const double x) {
	if (x > a) {
		return x * cbrt(x - a);
	}
	else {
		return x * sin(a * x);
	}
}