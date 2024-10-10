#include <stdio.h>
#include <math.h>

/**
* @brief –ассчитывает переменную а по заданной формуле
* @param x значение константы х
* @param y значение константы y
* @param z значение константы z
* @return рассчитанное значение
*/

double get_a(const double x, const double y, const double z);

/**
* @brief –ассчитывает переменную b по заданной формуле
* @param x значение константы х
* @param y значение константы y
* @param z значение константы z
* @return рассчитанное значение
*/

double get_b(const double x, const double y, const double z);

/**
* @brief “очка входа в програsмму
* @return 0 в случае успеха
*/

int main() {
	const double x = 0.78;
	const double y = 1.24;
	const double z = 0.5;

	printf("«начение а равно: %f \n", get_a(x, y, z)); // ¬ывели a
	printf("«начение b ровно: %f \n", get_b(x, y, z)); // ¬ывели b


	return 0;
}

double get_a(const double x, const double y, const double z) {
	return ((2 * pow(z, x)) / (sqrt(pow(y, x) * cos(x + y) * cos(x + y)) - 3 * z));
}

double get_b(const double x, const double y, const double z) {
	return (x * exp(sqrt(z)) * cos((x * x) / (y * z)));
}
