/* 2151299 ��16 �ռ��� */
#include<iostream>
#include <cmath>
using namespace std;

int main() {

	int x[10][10],error=0;

	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 1; i < 10; i++) {// line
		for (int j = 1; j < 10; j++) {//column
			while (1) {
				cin >> x[i][j];
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
					cout << "�����������"<<i<<"��"<<j<<"��(���о���1��ʼ����)��ֵ" << endl;
					cin >> x[i][j];
				}
				if (x[i][j] >= 1 && x[i][j] <= 9)
					break;
				else if (x[i][j] < 1 || x[i][j] > 9) {
					cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ" << endl;
				}
			}
		}
	}

	for (int i = 1; i < 10; i++) {// �����ظ�������
		for (int j = 1; j < 9; j++) {
			for (int k = j+1; k < 10; k++) {
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
		}
	}

	for (int i = 1; i < 10; i++) {// �����ظ�������
		for (int j = 1; j < 9; j++) {
			for (int k = j + 1; k < 10; k++) {
				if (x[j][i] == x[k][i]) {
					error++;
					break;
				}
			}
		}
	}


	for (int i = 1; i < 4; i++) {// �Ź���1���ظ�������
		for (int j = 1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4; m++) {//��������бȽ�
				for (int l=i+1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}	
		}
	}

	for (int i = 1; i < 4; i++) {// �Ź���2���ظ�������
		for (int j = 1+3; j < 4+3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4+3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1; i < 4; i++) {// �Ź���3���ظ�������
		for (int j = 1 + 3+3; j < 4 + 3 + 3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3 + 3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1+3; i < 4 + 3; i++) {// �Ź���4���ظ�������
		for (int j = 1 ; j < 4 ; j++) {
			for (int k = j + 1; k < 4; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4 ; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1+3; i < 4 + 3; i++) {// �Ź���5���ظ�������
		for (int j = 1 + 3; j < 4 + 3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4 + 3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3; i < 4 + 3; i++) {// �Ź���6���ظ�������
		for (int j = 1 + 3 + 3; j < 4 + 3 + 3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3 + 3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4+3 ; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// �Ź���7���ظ�������
		for (int j = 1; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1; m < 4; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// �Ź���8���ظ�������
		for (int j = 1 + 3; j < 4+3; j++) {
			for (int k = j + 1; k < 4 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3; m < 4 + 3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	for (int i = 1 + 3 + 3; i < 4 + 3 + 3; i++) {// �Ź���9���ظ�������
		for (int j = 1 + 3 + 3; j < 4 + 3+3; j++) {
			for (int k = j + 1; k < 4 + 3 + 3; k++) {//���бȽ�
				if (x[i][j] == x[i][k]) {
					error++;
					break;
				}
			}
			for (int m = 1 + 3 + 3; m < 4 + 3+3; m++) {//��������бȽ� m���� l����
				for (int l = i + 1; l < 4 + 3 + 3; l++) {
					if (x[i][j] == x[l][m]) {
						error++;
						break;
					}
				}
			}
		}
	}

	if (error == 0)
		cout << "�������Ľ�" << endl;
	else if (error != 0)
		cout << "���������Ľ�" << endl;


	return 0;
}