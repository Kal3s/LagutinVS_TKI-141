#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>

/**
* @brief Функция считает нашу функцию
* @param x значение аргумента
* @return Возвращает значения функции
*/
float get_equation(float x);

/**
* @brief Проверка на введенное значение
* @return возрващает значение, если верное, иначе ошибку
*/
float input(void);

/**
 * @brief Проверяет корректность интервала.
 * @param x_start Начальное значение интервала.
 * @param x_final Конечное значение интервала.
 * @return Возвращет ошибку если интервал задан неверно
 */
void check_interval(const float x_start, const float x_final);

/**
* @brief Проверяет коррекность шага
* @param x_step Значение шага
* @return Возвращает ошибку если шаг задан неверно
*/
void check_step(const float x_step);

/**
* @brief Точка входа
* @return Возвращает значение функции с заданным в цикле корнем
*/
int main(void)
{
    const float x_start = input(), x_final = input(), x_step = input();
    check_interval(x_start, x_final);
    check_step(x_step);
    float x = x_start;

    while (x <= x_final + DBL_EPSILON) {
        printf("x = %f y = %f\n", x, get_equation(x));
        x = x + x_step;
    }

    return 0;
}

void check_interval(const float x_start, const float x_final)
{
    if (x_final - x_start < DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}
void check_step(const float x_step)
{
    if (x_step <= DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}

float input(void) {
    float input;
    if (scanf_s("%f", &input) != 1)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
    return input;
}

float get_equation(float x)
{
    return 3 * sin(pow(x, 0.5)) + 0.39 * x - 3.8;
}