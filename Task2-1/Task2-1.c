#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

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
* @brief Точка входа в програsмму
* @return 0 в случае успеха
*/
int main() {
	double R;
	int vybor;
	printf("Введите радиус : ");
	scanf_s("%lf", &R);
	
	if ((R <= 0) || (scanf("%lf", &R) != 1)) {
		printf("Радиус должен быть положительным числом\n");
		printf("Введите радиус: ");
		scanf_s("%lf", &R);
	}

	printf("Выберите какую операцию хотите произвести:\n");
	printf("1. Объем шара\n");
	printf("2. Площадь поверхности шара\n");
	printf("(1/2)? ");
	scanf_s("%d", &vybor);

	if ((vybor != 1) && (vybor != 2))
	{
		printf("Недопустимое значение. Введите 1 или 2: ");
		scanf_s("%d", &vybor);
	}
	if (vybor == 2) {
		printf("Площадь поверхности шара равна: %f \n", get_S(R));
	}
	if (vybor == 1) {
		printf("Объём шара равен: %f \n", get_V(R));
	}
	
	return 0;
}

double get_V(double R) {
	return (4  * M_PI * (R * R * R))/ 3;
}

double get_S(double R) {
	return (4 * M_PI * R * R);
}