/* ��16 2151299 �ռ��� */
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

int main()
{
	const int row = 10;
	const int column = 26;
	int leishu = 50;

	int x = 0, y = 0;
	int sjm[row][column];

	for (int i=0; i < row; i++) {//��ÿ�����Ϊ1
		for (int j=0; j < column; j++) {
			sjm[i][j] = 1;
		}
	}

	srand((unsigned int)time(NULL));  //�������
	while (leishu>0) {//if leishu==0 ����ѭ�� else ����
		x = rand() % row + 1;
		y = rand() % column + 1;
		if (sjm[x-1][y-1] == 1){
			sjm[x-1][y-1] = '*';
			leishu--;
		}
	}
	int sum = 0;//��Χ8��λ�õ�����
	for (int i=0; i < row; i++) {//��¼��
		for (int j=0; j < column; j++) {
			if (sjm[i][j] == 1) {
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
				sjm[i][j] = sum;
				sum = 0;
			}
		}
	}
	
	for (int i=0; i < row; i++) {//�����
		for (int j=0; j < column; j++) {
			if (sjm[i][j] == 42) {
				cout << char(sjm[i][j]) << " ";
			}
			else
				cout << sjm[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
