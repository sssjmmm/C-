/* ��16 2151299 �ռ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int c, w;
	if (m != 1 && m != 2) {
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 1) {
		m = 13;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	if (w < 0)
		w = w % 7 + 7;
	else if (w > 0)
		w = w % 7;
	return w;
}

void daxie(int w)
{
	switch (w) {
		case 0:
			printf("��");
			break;
		case 1:
			printf("һ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
	}
}

int main()
{
	int year, month, day, a, k,ret;
	while (1) {
		a = 1;
		printf("��������[1900-2100]���¡��գ�\n");
		ret=scanf("%d %d %d",&year,&month,&day);
		while (ret!=3) {
			while (getchar() != '\n');
			printf("�����������������\n");
			printf("��������[1900-2100]���¡��գ�\n");
			scanf("%d %d %d", &year, &month, &day);
		}
		if (year < 1900 || year>2100) {//year
			printf("��ݲ���ȷ������������\n");
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month < 1 || month > 12)) {//month
			printf("�·ݲ���ȷ������������\n");
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month >= 1 || month <= 12)) {//day
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (month == 2 && day > 29) {
					printf("�ղ���ȷ������������\n");
					a = 0;
				}
			}
			if (month == 1 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 2 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (day <= 0 || day > 28)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 3 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 4 && (day <= 0 || day > 30)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 5 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 6 && (day <= 0 || day > 30)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 7 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 8 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 9 && (day <= 0 || day > 30)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 10 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 11 && (day <= 0 || day > 30)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
			else if (month == 12 && (day <= 0 || day > 31)) {
				printf("�ղ���ȷ������������\n");
				a = 0;
			}
		}
		if (a == 1 && (year >= 1900 && year <= 2100) && (month >= 1 || month <= 12))
			break;
	}
	k = zeller(year, month, day);
	printf("����");
	daxie(k);
	printf("\n");
	return 0;
}