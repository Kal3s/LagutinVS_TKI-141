#include <stdio.h>
#include <math.h>

/**
* @brief ������������ ���������� � �� �������� �������
* @param x �������� ��������� �
* @param y �������� ��������� y
* @param z �������� ��������� z
* @return ������������ ��������
*/
double get_a(const double x, const double y, const double z);

/**
* @brief ������������ ���������� b �� �������� �������
* @param x �������� ��������� �
* @param y �������� ��������� y
* @param z �������� ��������� z
* @return ������������ ��������
*/
double get_b(const double x, const double y, const double z);

/**
* @brief ����� ����� � ������s���
* @return 0 � ������ ������
*/
int main() {
	const double x = 0.78;
	const double y = 1.24;
	const double z = 0.5;

	printf("a = %f \n", get_a(x, y, z));
	printf("b = %f \n", get_b(x, y, z));

	return 0;
}

double get_a(const double x, const double y, const double z) {
	return ((2 * pow(z, x)) / (sqrt(pow(y, x) * cos(x + y) * cos(x + y)) - 3 * z));
}

double get_b(const double x, const double y, const double z) {
	return (x * exp(sqrt(z)) * cos((x * x) / (y * z)));
}
