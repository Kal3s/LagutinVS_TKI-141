#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Рассчитывает объём шара
* @param R значение радиуса
* @return Рассчитанное значение
*/
double get_V(double R);

/**
* @brief Рассчитывает площадь поверхности шара
* @param R значение радиуса
* @return Рассчитанное значение
*/
double get_S(double R);

/**
* @brief Функция проверки введенных значений.
* @return Возвращает значение, если выполнено успешно, или ошибку, если иначе
*/
double get_input();


/**
* @brief Точка входа в програsмму
* @return 0 в случае успеха
*/
int main() {
	printf("Enter radius: ");
	double R = get_input();
	
	printf("The surface area of the ball is %f \n", get_S(R));
	printf("The volume of the ball is %f \n", get_V(R));
	
	return 0;
}

double get_input()
{
	double input;
	if (scanf_s("%lf", &input) != 1 || (input <= 0))
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double get_V(double R) {
	return (4  * M_PI * pow(R,3))/ 3;
}

double get_S(double R) {
	return (4 * M_PI * pow(R,2));
}