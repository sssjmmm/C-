/* 2151299 ��16 �ռ��� */
/* 2052750 ��Ī֮ 2153410 ����˶ 2151792 ���� 2153686 ������ 2154301 ������ 2150267 ���Ӻ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

# define row 10
# define column 26
int main()
{

	int leishu = 50;

	int x = 0, y = 0, sjm[row][column];
	char c;

	for (int i = 0; i < row; i++) {//���ļ�����sjm[][]
		for (int j = 0; j < column; j++) {
			while (!(sjm[i][j] == 42 ||
				(sjm[i][j] >= 0 && sjm[i][j] <= 8) ||
				(sjm[i][j] >= 48 && sjm[i][j] <= 56))) {
				scanf("%c", &c);
				if ((int)c == 42 ||
					((int)c >= 0 && (int)c <= 8) ||
					((int)c >= 48 && (int)c <= 56)) {//���˿ո�������ַ�
					sjm[i][j] = (int)c;
				}
			}
		}
	}

	int num = 0;
	for (int i = 0; i < row; i++) {//��鹻����50����
		for (int j = 0; j < column; j++) {
			if (sjm[i][j] == 42)
				num++;
		}
	}
	if (num != 50) {
		printf("����1\n");
		return 0;
	}

	int sum = 0;//��Χ8��λ�õ�����
	for (int i = 0; i < row; i++) {//�����
		for (int j = 0; j < column; j++) {
			if (sjm[i][j] !=42) {
				if (i - 1 >= 0) {
					if (sjm[i - 1][j] == '*')
						sum++;
					if ((j + 1) < column) {
						if (sjm[i - 1][j + 1] == '*')
							sum++;
					}
				}
				if (j - 1 >= 0) {
					if (sjm[i][j - 1] == '*')
						sum++;
					if ((i + 1) < row) {
						if (sjm[i + 1][j - 1] == '*')
							sum++;
					}
				}
				if (j - 1 >= 0 && i - 1 >= 0) {
					if (sjm[i - 1][j - 1] == '*')
						sum++;
				}
				if ((j + 1) < column) {
					if (sjm[i][j + 1] == '*')
						sum++;
					if ((i + 1) < row) {
						if (sjm[i + 1][j + 1] == '*')
							sum++;
					}
				}
				if ((i + 1) < row) {
					if (sjm[i + 1][j] == '*')
						sum++;
				}
				if (sjm[i][j] != sum+48) {
					printf("����2\n");
					return 0;
				}
				sum = 0;
			}
		}
	}

	printf("��ȷ\n");
	return 0;
}
