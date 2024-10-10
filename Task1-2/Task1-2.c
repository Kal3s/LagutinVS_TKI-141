#include <stdio.h> 
#include <locale.h> 

/**
* @brief ������������ ������ � ������� ����� � �����������.
* @param length ����� ��������������
* @param n ����������
* @return ������ ��������������.
*/
double get_Width(const double length, const double n);

/**
* @brief ������������ ������� ��������������.
* @param length ����� ��������������
* @param width ������ ��������������
* @return ������� ��������������.
*/
double get_Area(const double length, const double width);

/**
* @brief ������������ �������� ��������������.
* @param length ����� ��������������
* @param width ������ ��������������
* @return �������� ��������������.
*/

double get_Perimetr(const double length, const double width);

/**
* @brief ��������� ������������ �����.
* @return ���������� ������������ �����.
*/
double get_Input();

/**
* @brief ����� ����� � ���������
* @return ���������� � ������ ������
*/
int main(void) {
	setlocale(LC_ALL, "Russian");
	puts("������� ����� ��������������.");
	double length = get_Input();
	puts("������� ����������.");
	double n = get_Input();
	double width = get_Width(length, n);
	printf_s("������� �������������� %lf", get_Area(length, width));
	printf_s("\n�������� �������������� %lf", get_Perimetr(length, width));

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