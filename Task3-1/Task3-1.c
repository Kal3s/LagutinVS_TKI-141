#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief Функция считает нашу функцию
* @param x значение аргумента
* @return Возвращает значения функции
*/
double get_equation(const double x);

/**
* @brief Проверка на введенное значение
* @return возрващает значение, если верное, иначе ошибку
*/
double input(void);

/**
 * @brief Проверяет корректность интервала.
 * @param x_start Начальное значение интервала.
 * @param x_final Конечное значение интервала.
 * @return Возвращет ошибку если интервал задан неверно
 */
void check_interval(const double x_start, const double x_final);

/**
* @brief Проверяет коррекность шага
* @param x_step Значение шага
* @return Возвращает ошибку если шаг задан неверно
*/
void check_step(const double x_step);

/**
* @brief Точка входа
* @return Возвращает значение функции с заданным в цикле корнем
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    puts("Введите начальное значение интервала:");
    const double x_start = input(); 
    puts("Введите конечное значение интервала:");
    const double x_final = input(); 
    puts("Введите размер шага:");
    const double x_step = input();
    check_interval(x_start, x_final);
    check_step(x_step);
    double x = x_start;

    while (x <= x_final + DBL_EPSILON) {
        printf("x = %f y = %f\n", x, get_equation(x));
        x = x + x_step;
    }

    return 0;
}

void check_interval(const double x_start, const double x_final)
{
    if (x_final - x_start < DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}
void check_step(const double x_step)
{
    if (x_step <= DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}

double input(void) {
    double input = 0.0;
    int result = scanf_s("%lf", &input);
    if (result != 1)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
    return input;
}

double get_equation(const double x)
{
    return 3 * sin(pow(x, 0.5)) + 0.39 * x - 3.8;
}