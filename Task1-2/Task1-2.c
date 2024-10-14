#include <stdio.h> 
#include <locale.h> 

/**
* @brief Рассчитывает ширину с помощью длины и коэффицента.
* @param length Длина прямоугольника
* @param n Коэффицент
* @return Ширина прямоугольника.
*/
double get_Width(const double length, const double n);

/**
* @brief Рассчитывает площадь прямоугольника.
* @param length Длина прямоугольника
* @param width Ширина прямоугольника
* @return Площадь прямоугольника.
*/
double get_Area(const double length, const double width);

/**
* @brief Рассчитывает периметр прямоугольника.
* @param length Длина прямоугольника
* @param width Ширина прямоугольника
* @return Периметр прямоугольника.
*/

double get_Perimetr(const double length, const double width);

/**
* @brief Считывает вещественное число.
* @return Возвращает вещественное число.
*/
double get_Input();

/**
* @brief Точка входа в программу
* @return Возвразает в случае успеха
*/
int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("Введите длину прямоугольника.");
	double length = get_Input();
	puts("Введите коэффицент.");
	double n = get_Input();
	double width = get_Width(length, n);
	printf_s("Площадь прямоугольника %lf", get_Area(length, width));
	printf_s("\nПериметр прямоугольника %lf", get_Perimetr(length, width));

	return 0;
}

double get_Width(const double length, const double n) {
	return length * n;
}

double get_Area(const double length, const double width) {
	return length * width;
}

double get_Perimetr(const double length, const double width) {
	return (length + width) * 2;
}

double get_Input() {
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}