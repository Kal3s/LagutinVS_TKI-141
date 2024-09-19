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

/**
* @brief Функция проверки правельности выбора
* @return Возвращает значение выбора, если ошибка, проверяет заново
*/
int get_vybor() {
	int vybor;
	scanf_s("%d", &vybor);
	if ((vybor != 1) && (vybor != 2))
	{
		printf("Invalid value. Enter 1 or 2: ");
		vybor = get_vybor();
	}
	return vybor;
}

/**
* @brief Точка входа в програsмму
* @return 0 в случае успеха
*/
int main() {
	double R;
	int vybor;
	printf("Enter radius: ");
	R = get_input();

	printf("Select what operation you want to perform:\n");
	printf("1. Ball volume\n");
	printf("2. Sphere surface area\n");
	printf("(1/2)? ");
	vybor = get_vybor();
	
	if (vybor == 2) {
		printf("The surface area of the ball is %f \n", get_S(R));
	}
	if (vybor == 1) {
		printf("The volume of the ball is %f \n", get_V(R));
	}
	
	return 0;
}

double get_V(double R) {
	return (4  * M_PI * (R * R * R))/ 3;
}

double get_S(double R) {
	return (4 * M_PI * R * R);
}