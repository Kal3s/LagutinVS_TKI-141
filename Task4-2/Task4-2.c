#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

/**
* @brief ������� ������ ������ ���������� ������� �������������
* @param command - ���������� ��� ������ ������ ���������� �������
* @param array - ������, ���������� �������������
* @param low_value - ������ �������
* @param size_array - ������ �������
* @remarks ��� ������������ ����� ������� ������� ������
*/
void fill_array(const int command, int* array, const int low_value, const int high_value, const size_t size_array);

/**
* @brief ������� ���������� ������� ����������, ������� ����� ������������
* @param array - ������, ���������� �������������
* @param size_array - ������ �������
*/
void fill_by_input(int* array, const size_t size_array);

/**
* @brief ������� ���������� ������� ���������� �������
* @param array - ������, ���������� �������������
* @param low_value - ������ �������
* @param size_array - ������ �������
*/
void fill_by_random(int* array, const int low_value, const int high_value, const size_t size_array);

/**
* @brief ������� ������ �������
* @param array - ������, ���������� �������������
* @param size_array - ������ �������
*/
void print_array(const int* array, const size_t size_array);

/**
* @brief ������� ����� �������� �������������
* @remarks ��� ������������ ����� ��������� ��� ������ /c EXIT_FAILURE
*/
int get_input(void);

/**
* @brief ������� �������� ���������� �������
* @remarks ���� �������� 0 � ������ ���������� ��� ������ /c EXIT_FAILURE
*/
size_t get_above_zero_value(void);

/**
* @brief ������� ���������� ������� 1
* @param arr - ������, ���������� �������������
* @param size_array - ������ �������
* @return ���������� ����� ����� �������� �������
*/
void task1(int* arr, const size_t size_array, const int low_value);

/**
* @brief ������� ���������� ������� 2
* @param arr - ������, ���������� �������������
* @param size_array - ������ �������
* @remarks ������� ������� �������� �������
*/
void task2(int* arr2, const size_t size_array, int k);

/**
* @brief ������� ���������� ������� 3
* @param arr - ������, ���������� �������������
* @param size_array - ������ �������
* @return ���������� ���������� ������
*/
void task3(int* a, int* d, const size_t size_array);

/**
* @brief ������� �������� �������� � �������� �������� ��������� ������ ����� ��� ���������� ���������� �������
* @param low_value - ������� ��������
* @param high_value - ������� ��������
* @remarks ��� ������������� �������� ���������� ��� ������ /c EXIT_FAILURE
*/
void check_interval(const int low_value, const int high_value);

/**
* @brief ������� �������� �������
* @param arr - ������, ������� �� ��������� �� NULL
* @remarks ��� ������������� �������� ���������� ��� ������ /c EXIT_FAILURE
*/
void check_array(int* const arr);

/**
* @brief ������� ��������������� �������
* @param arr - ���������� ������
* @param size_array - ������ ��������
* @return ���������� ������ �� ���������� ������������ �������
*/
int* copy_array(int* const arr, const size_t size_array);
/**
 * @brief ������� �������� �������
 * @param size_array - ������ ������������ �������
 * @return ���������� ��������� �� ������� ������
 */
int* create_array(size_t const size_array);

/**
* @brief ������� �������� ������� 2-�� �������� ��� ������� 3
* @remarks ��������� ��������� � ����� ������ /c EXIT_FAILURE ���� � ������� ������ 2-� ���������
*/
void check_second_element(const size_t size_array);

/**
* @brief ������� �������� ������� �������������� �������� ��� ������� 3
* @remarks ��������� ��������� � ����� ������ /c EXIT_FAILURE ���� � ������� ��� �������������� ��������
*/
void check_negative_element(const int low_value);

/**
* @brief ������� ���������� ������� �������������� �������� ��� ������� 3
* @return ������ ������� �������������� ��������
*/
int find_first_negative_element(int* const arr, const size_t size_array);

int find_number_one(int n);

int number_of_digits(int n);

/**
* @brief ����� ����������� �������
* @param fill_random - ���������� ���������� �������
* @param fill_input - ���������� ������� ������������
*/
enum Task
{
	fill_random = 1,
	fill_input = 2,
};

/**
* @brief ����� �����
* @return ���������� ��� ������ 0
*/
int main(void) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf_s("��� �� ������ ��������� ������ ? \n%d - ���������� ����, %d - ������ ����\n", fill_random, fill_input);
	int command = get_input();
	puts("������� ������ �������");
	size_t size_array = get_above_zero_value();
	puts("������� ������� � ������� �������� �������:");
	int low_value = get_input(), high_value = get_input();
	puts("������� ����� K:");
	int k = get_input();
	check_interval(low_value, high_value);
	int* arr = create_array(size_array);
	fill_array(command, arr, low_value, high_value, size_array);
	puts("������:");
	print_array(arr, size_array);
	int* arr_ = copy_array(arr, size_array);
	int* arr2 = copy_array(arr, size_array);
	int* d = copy_array(arr, size_array);
	int* a = copy_array(arr, size_array);
	puts("������� 1:");
	task1(arr_, size_array, low_value);
	print_array(arr_, size_array);
	puts("������� 2: ");
	task2(arr2, size_array, k);
	print_array(arr2, size_array);
	puts("������� 3: ");
	task3(a, d, size_array);
	print_array(a, size_array);
	free(arr_);
	free(arr2);
	free(d);
	free(a);
	free(arr);
	return 0;
}

int* create_array(size_t const size_array) {
	int* arr = (int*)malloc(size_array * sizeof(int));
	check_array(arr);
	return arr;
}

int* copy_array(int* const arr, const size_t size_array) {
	int* arr_ = create_array(size_array);
	for (size_t i = 0; i < size_array; i++) {
		arr_[i] = arr[i];
	}
	return arr_;
}

void check_array(int* const arr) {
	if (arr == NULL) {
		printf("������� ������ ������");
		exit(EXIT_FAILURE);
	}
}

void check_interval(const int low_value, const int high_value) {
	if (low_value > high_value) {
		puts("������ ���������");
		exit(EXIT_FAILURE);
	}
}

void fill_array(const int command, int* array, const int low_value, const int high_value, const size_t size_array) {
	switch ((enum Task)command) {
	case fill_random:
		fill_by_random(array, low_value, high_value, size_array);
		break;
	case fill_input:
		fill_by_input(array, size_array);
		break;
	default:
		puts("������ �������");
		exit(EXIT_FAILURE);
	}
}

void fill_by_input(int* array, const size_t size_array) {
	for (size_t i = 0; i < size_array; i++) {
		array[i] = get_input();
	}
}

void fill_by_random(int* array, const int low_value, const int high_value, const size_t size_array) {
	for (size_t i = 0; i < size_array; i++) {
		array[i] = rand() % (high_value - low_value + 1) + low_value;
	}
}

int get_input(void) {
	int value = 0;
	int result = scanf_s("%d", &value);
	if (result != 1) {
		puts("������������ �������� ��������!");
		exit(EXIT_FAILURE);
	}
	return value;
}

size_t get_above_zero_value(void) {
	int input_ = get_input();
	if (input_ <= 0) {
		puts("������������ �������� ��������!");
		exit(EXIT_FAILURE);
	}
	return (size_t)input_;
}

void print_array(const int* array, const size_t size_array) {
	printf("[");
	for (size_t i = 0; i < size_array; i++) {
		printf("%d,", array[i]);
	}
	puts("]");
}

void task1(int* arr, const size_t size_array, const int low_value) {
	check_second_element(size_array);
	check_negative_element(low_value);
	int index_first_negative = find_first_negative_element(arr, size_array);
	int maximum_negative_element = 0;
	for (size_t i = index_first_negative + 1; i < size_array; ++i) {
		if (arr[i] > arr[index_first_negative] && arr[i] < 0) {
			maximum_negative_element = arr[i];
		}
	}
	if (maximum_negative_element < 0) {
		arr[1] = maximum_negative_element;
	}
}

void check_second_element(const size_t size_array) {
	if (size_array < 1) {
		printf("������� 1 �� ����� ���� ���������!\n");
		//exit(EXIT_FAILURE);
	}
}

void check_negative_element(const int low_value) {
	if (low_value >= 0) {
		printf("������� 1 �� ����� ���� ���������!\n");
		//exit(EXIT_FAILURE);
	}
}

int find_first_negative_element(int* const arr, const size_t size_array) {
	int index = 0;
	while (arr[index] >= 0) {
		index++;
	}
	return index;
}

void task2(int* arr2, const size_t size_array, int k){
	char str[12];
	for (int i = 0; i < size_array; i++) {
		if (find_number_one(arr2[i]) == 1) {
			int count = number_of_digits(arr2[i]);
			if (arr2[i] > 0) {
				arr2[i] = (k * pow(10, count)) + arr2[i];
			}
			else if (arr2[i] < 0) {
				arr2[i] = (-k * pow(10, count)) + arr2[i];
			}
		}
	}
}

int find_number_one(int n) {
	while (n != 0) {
		if (abs(n) % 10 == 1) {
			return 1;
		}
		n /= 10;
	}
}

int number_of_digits(int n) {
	int k = 0;
	if (n / 10 == 0) {			
		return 1;
	}
	else {
		while (n != 0)
		{
			n = n / 10;
			k += 1;
		}
		return k;
	}
}

void task3(int* a, int* d, const size_t size_array) {
	for (int i = 0; i < size_array; i++) {
		if (abs(i) % 2 == 0) {
			a[i] = pow(d[i], 2);
		}
		else {
			a[i] = d[i] / i;
		}
	}
}