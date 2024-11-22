#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <locale.h>

/**
* @brief Провереяет вводимое значение.
* @return Если 1 выводит введенное значение, если 0 выводит ошибку.
*/
int get_int(void);

/**
* @brief Проверяет введеное значение на то, что оно больше 0.
* @return Если 1 выводит введенное значение, если 0 выводит ошибку.
*/
size_t get_non_negative_int(void);

/**
* @brief Считает сумму членов последовательности.
* @param count Количество членов последовательности.
* @return Возвращает сумму членов последовательности.
*/
double get_sum(const size_t count);

/**
* @brief Считает член последовательности.
* @param k Меняющийся параметр в функции.
* @return Возвращает высчитанный член последовательности.
*/
double get_reccurent(const size_t k);

/**
* @brief Провереяет вводимое значение.
* @return Если 1 выводит введенное значение, если 0 выводит ошибку.
*/
double get_double(void);

/**
* @brief Проверяет введеное значение на то, что оно больше 0.
* @return Если 1 выводит введенное значение, если 0 выводит ошибку.
*/
double get_epsilon(void);

/**
* @brief Проверяет е на то, что оно больше 0 и меньше 1.
* @param epsilon Число е.
*/
void check_epsilon(const double epsilon);

/**
* @brief Считает сумму членов последовательности.
* @param epsilon Число е.
* @return Возвращает сумму членов последовательности.
*/
double get_sum_epsilon(const double epsilon);

/**
* @brief Точка входа в программу.
* @return 0 В случае успеха
*/
int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("Количество членов последовательности:");
	size_t count = get_non_negative_int();
	printf("Сумма последовательности из %zu элементов равна %.10lf\n", count, get_sum(count));
	puts("Введите точность вычисления:");
	double epsilon = get_epsilon();
	printf("Сумма последовательности с точностью %lf равна %.10lf\n", epsilon, get_sum_epsilon(epsilon));
	return EXIT_SUCCESS;
}

int get_int(void) {
	int value = 0;
	int result = scanf("%d", &value);
	if (result != 1) {
		errno = EDOM;
		perror("Неверное введеное значение!");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t get_non_negative_int(void) {
	int value = get_int();
	if (value <= 0) {
		errno = EDOM;
		perror("Неверное введеное значение!");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_sum(size_t count) {
	double current = -1.0 / 12;
	double summ = current;
	for (size_t i = 0; i < count; ++i) {
		current *= get_reccurent(i);
		summ += current;
	}

	return summ;
}

double get_reccurent(size_t k) {
	return -1.0 / ((k + 3) * (k + 4));
}

double get_epsilon(void) {
	double epsilon = get_double();
	if (epsilon <= 0.0) {
		puts("Error input!");
		exit(EXIT_FAILURE);
	};
	return epsilon;
}

double get_double(void) {
	double value = 0.0;
	int result = scanf("%lf", &value); 
	if (result != 1) {
		errno = EIO;
		perror("Неверное введеное значение!");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_sum_epsilon(const double epsilon) {
	double summ = 0;
	double current = -1.0/12;
	for (size_t i = 0; fabs(current) > epsilon - DBL_EPSILON; ++i) {
		summ += current;
		current *= get_reccurent(i);
	}
	return summ;
}
