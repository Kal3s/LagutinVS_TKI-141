#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <locale.h>

/**
* @brief ���������� �������� ��������.
* @return ���� 1 ������� ��������� ��������, ���� 0 ������� ������.
*/
int get_int(void);

/**
* @brief ��������� �������� �������� �� ��, ��� ��� ������ 0.
* @return ���� 1 ������� ��������� ��������, ���� 0 ������� ������.
*/
size_t get_non_negative_int(void);

/**
* @brief ������� ����� ������ ������������������.
* @param count ���������� ������ ������������������.
* @return ���������� ����� ������ ������������������.
*/
double get_sum(const size_t count);

/**
* @brief ������� ���� ������������������.
* @param k ���������� �������� � �������.
* @return ���������� ����������� ���� ������������������.
*/
double get_reccurent(const size_t k);

/**
* @brief ���������� �������� ��������.
* @return ���� 1 ������� ��������� ��������, ���� 0 ������� ������.
*/
double get_double(void);

/**
* @brief ��������� �������� �������� �� ��, ��� ��� ������ 0.
* @return ���� 1 ������� ��������� ��������, ���� 0 ������� ������.
*/
double get_epsilon(void);

/**
* @brief ��������� � �� ��, ��� ��� ������ 0 � ������ 1.
* @param epsilon ����� �.
*/
void check_epsilon(const double epsilon);

/**
* @brief ������� ����� ������ ������������������.
* @param epsilon ����� �.
* @return ���������� ����� ������ ������������������.
*/
double get_sum_epsilon(const double epsilon);

int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("���������� ������ ������������������:");
	size_t count = get_non_negative_int();
	printf("����� ������������������ �� %zu ��������� ����� %.10lf\n", count, get_sum(count));
	puts("������� �������� ����������:");
	double epsilon = get_epsilon();
	printf("����� ������������������ � ��������� %lf ����� %.10lf\n", epsilon, get_sum_epsilon(epsilon));
	return EXIT_SUCCESS;
}

int get_int(void) {
	int value = 0;
	int result = scanf("%d", &value);
	if (result != 1) {
		errno = EDOM;
		perror("�������� �������� ��������!");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t get_non_negative_int(void) {
	int value = get_int();
	if (value <= 0) {
		errno = EDOM;
		perror("�������� �������� ��������!");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_sum(size_t count) {
	double summ = 0;
	double current = 0;
	for (size_t i = 0; i < count; ++i) {
		current += get_reccurent(i);
		summ = current;
	}

	return summ;
}

double get_reccurent(size_t k) {
	return 1.0 / ((k + 3) * (k + 4));
}

double get_epsilon(void) {
	double epsilon = get_double();
	if (epsilon <= 0.0) {
		puts("Error input!");
		exit(EXIT_FAILURE);
	};
	return epsilon;
}

void check_epsilon(const double epsilon) {
	if (epsilon >= 1 && epsilon <= 0) {
		puts("Error of accuracy!");
		exit(EXIT_FAILURE);
	}
}

double get_double(void) {
	double value = 0.0;
	int result = scanf("%lf", &value); 
	if (result != 1) {
		errno = EIO;
		perror("�������� �������� ��������!");
		exit(EXIT_FAILURE);
	}
	return value;
}

double get_sum_epsilon(const double epsilon) {
	double summ = 0;
	double current = 1.0/12;
	for (size_t i = 0; i < epsilon + DBL_EPSILON; ++i) {
		current += get_reccurent(i);
		summ = current;
	}
	return summ;
}