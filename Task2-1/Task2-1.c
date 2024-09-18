#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
* @brief ������뢠�� ���� ��
* @param R ���祭�� ࠤ���
* @return �����⠭��� ���祭��
*/
double get_V(double R);

/**
* @brief ������뢠�� ���頤� �����孮�� ��
* @param R ���祭�� ࠤ���
* @return �����⠭��� ���祭��
*/
double get_S(double R);

/**
* @brief ��窠 �室� � �ண�s���
* @return 0 � ��砥 �ᯥ�
*/
int main() {
	double R;
	int vybor;
	printf("������ ࠤ���: ");
	scanf_s("%lf", &R);
	
	printf("�롥�� ����� ������ ��� �ந�����:\n");
	printf("1. ��ꥬ ��\n");
	printf("2. ���頤� �����孮�� ��\n");
	printf("(1/2)? ");
	scanf_s("%d", &vybor);

	if (vybor != 1)
	{
		if (vybor != 2){
			printf("�������⨬�� ���祭��. ������ 1 ��� 2: ");
			scanf_s("%d", &vybor);
		}
	}
	if (vybor == 2) {
		printf("���頤� �����孮�� �� ࠢ��: %f \n", get_S(R));
	}
	if (vybor == 1) {
		printf("���� �� ࠢ��: %f \n", get_V(R));
	}
	
	return 0;
}

double get_V(double R) {
	return (4  * M_PI * (R * R * R))/ 3;
}

double get_S(double R) {
	return (4 * M_PI * R * R);
}