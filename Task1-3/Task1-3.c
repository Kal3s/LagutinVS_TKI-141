#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
* @brief Считывает вещественное вещество.
* @return Вещественное вещество.
*/
double input();

/**
* @brief Рассчитывает кинетическую энергию.
* @param massa Масса пули.
* @param skorost Скорость пули.
* @return Кинетическую энергию.
*/
double get_energy(double massa, double skorost);

/**
* @brief Точка входа в программу.
* @return Код ошибки.
*/
int main() {
	setlocale(LC_ALL, "Russian");
	puts("Введите массу пули (в граммах): ");
	double massa = input();
	puts("Введите скорость пули (в м/с): ");
	double skorost = input();

	printf("Кинетическая энергия пули равна %lf", get_energy(massa, skorost));

	return 0;
}

double input(void) {
	double value;
	scanf_s("%lf", &value);
	return value;
}

double get_energy(double massa, double skorost) {
	return (massa * pow(skorost, 2)) / 2;
}