/* 2151299 ��16 �ռ���*/
#include<iostream>
using namespace std;
#define len 10
#define max 16
static const char other[] = "~!@#$%^&*()-_=+[],.?";

int main() {
	int num[5];
	char checkcode[len][max + 1] = {" "}, sentence[5][18];
	for (int i = 0; i < 5; i++) {//���һ��
		cin >> sentence[i];
	}
	for (int i = 0; i < 5; i++) {//��5������
		cin >> num[i];
	}
	for (int i = 0; i < len; i++) {//������
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] == '\0'|| checkcode[i][k] == ' ') {
				cin>> checkcode[i][k];
			}
		}
	}
	//�����ܳ��Ƿ����Ҫ��

	for (int i = 0; i < len; i++) {
		if (strlen(checkcode[i]) != num[0]) {
			cout << "����" << endl;
			return 0;
		}
	}

	//�������͵��ַ������Ƿ���ϸ��Ե���СҪ��
	
	for (int i = 0, sum = 0; i < len; i++) {//LETTER
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= 'A' && checkcode[i][k] <= 'Z') {
				sum++;
			}
		}
		if (sum < num[1]) {
			cout << "����" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//letter
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= 'a' && checkcode[i][k] <= 'z') {
				sum++;
			}
		}
		if (sum < num[2]) {
			cout << "����" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//digit
		for (int k = 0; k < num[0]; k++) {
			if (checkcode[i][k] >= '0' && checkcode[i][k] <= '9') {
				sum++;
			}
		}
		if (sum < num[3]) {
			cout << "����" << endl;
			return 0;
		}
		else
			sum = 0;
	}
	for (int i = 0, sum = 0; i < len; i++) {//other
		for (int k = 0; k < num[0]; k++) {
			for (int j = 0; j < 20; j++) {
				if (checkcode[i][k] ==other[j]) {
					sum++;
				}
			}
		}
		if (sum < num[4]) {
			cout << "����" << endl;
			return 0;
		}
		else
			sum = 0;
	}

	//���������ַ��������ܺ��Ƿ�����ܳ�

	int sumx;
	sumx = num[0];
	for (int i = 0, sum = 0; i < len; i++) {//��
		for (int k = 0; k < num[0]; k++) {
			for (int j = 0; j < 20; j++) {
				if (checkcode[i][k] == other[j]) {
					sum++;
				}
			}
			if (checkcode[i][k] >= '0' && checkcode[i][k] <= '9') {
				sum++;
			}
			else if(checkcode[i][k] >= 'a' && checkcode[i][k] <= 'z') {
				sum++;
			}
			else if (checkcode[i][k] >= 'A' && checkcode[i][k] <= 'Z') {
				sum++;
			}
		}
		if (sum != sumx) {
			cout << "����" << endl;
			return 0;
		}
		else
			sum=0;
	}


	cout << "��ȷ" << endl;
	return 0;
}