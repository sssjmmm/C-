/*2151299 ��16 �ռ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day, x, r,a=1;
	day = 0;
	x = 0;
	r = 28;
	printf( "�������꣬�£���\n" );
	scanf("%d %d %d",&year, &month, &day);
	if (month >= 13 || month <= 0) {
		printf("�������-�·ݲ���ȷ\n");
		a = 0;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day > 31 || day < 1) {
			printf("�������-�����µĹ�ϵ�Ƿ�\n");
			a = 0;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30 || day < 1) {
			printf("�������-�����µĹ�ϵ�Ƿ�\n");
			a = 0;
		}
	}
	else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		if (month == 2 && day > 29) {
			printf("�������-�����µĹ�ϵ�Ƿ�");
			a = 0;
		}
		else
			r = 29;
	}
	else if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
		if (month == 2 && day > 28) {
			printf("�������-�����µĹ�ϵ�Ƿ�");
			a = 0;
		}
	}
	if (a == 1) {
		if (month == 1)
			x = day;
		else if (month == 2)
			x = 31 + day;
		else if (month == 3)
			x = 31 + r + day;
		else if (month == 4)
			x = 31 + r + 31 + day;
		else if (month == 5)
			x = 31 + r + 31 + 30 + day;
		else if (month == 6)
			x = 31 + r + 31 + 30 + +31 + day;
		else if (month == 7)
			x = 31 + r + 31 + 30 + +31 + 30 + day;
		else if (month == 8)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + day;
		else if (month == 9)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + day;
		else if (month == 10)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + day;
		else if (month == 11)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + 31 + day;
		else if (month == 12)
			x = 31 + r + 31 + 30 + +31 + 30 + 31 + 31 + 30 + 31 + +30 + day;
		printf("%d-%d-%d��%d��ĵ�%d��", year, month, day, year, x);
	}

	return 0;
}