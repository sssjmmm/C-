/* 2151299 ��16 �ռ���*/
#include<iostream>
#include <time.h> 
using namespace std;
#define len 10
#define max 16
static const char other[] = "~!@#$%^&*()-_=+[],.?";

int main() {
	int code, LETTER, letter, digit, othern;
	char mycode[len][max+1];
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> code;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (code <= 11 || code >max) {
		cout << "���볤��[" << code << "]����ȷ" << endl;
		return 0;
	}
	cin >> LETTER;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (LETTER <= 1 || LETTER > code) {
		cout << "��д��ĸ����[" << LETTER << "]����ȷ" << endl;
		return 0;
	}
	cin >> letter;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (letter <= 1 || letter > code) {
		cout << "Сд��ĸ����[" << letter << "]����ȷ" << endl;
		return 0;
	}
	cin >> digit;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (digit <= 1 || digit > code) {
		cout << "���ָ���[" << digit << "]����ȷ" << endl;
		return 0;
	}
	cin >> othern;
	if (cin.fail()) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (othern <= 1 || othern > code) {
		cout << "�������Ÿ���[" << othern << "]����ȷ" << endl;
		return 0;
	}
	if (LETTER + letter + digit + othern > code) {
		cout << "�����ַ�����֮��[" << LETTER << "+" << letter << "+" << digit << "+" << othern << "]���������볤��[" << code << "]" << endl;
		return 0;
	}
	cout << code << " " << LETTER << " " << letter << " " << digit << " " << othern << endl;
	srand((unsigned int)time(NULL));//48-57digit big65-90 small 97-122
	int random1, random2, random3;
	for (int i = 0; i < len; i++){//LETTER
		for (int k=0; k < LETTER;) {
			random1 = rand() % 26;//����ַ�
			random2 = rand() % 16;//���λ��
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + 'A';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//letter
		for (int k = 0; k < letter;) {
			random1 = rand() % 26;//����ַ�[0,26)
			random2 = rand() % 16;//���λ��[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + 'a';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//digit
		for (int k = 0; k < digit;) {
			random1 = rand() % 10;//����ַ�[0,10)
			random2 = rand() % 16;//���λ��[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = random1 + '0';
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//othern
		for (int k = 0; k < othern;) {
			random1 = rand() % 20;//����ַ�[0,20)
			random2 = rand() % 16;//���λ��[0,16)
			if (mycode[i][random2] == -52) {
				mycode[i][random2] = other[random1];
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {//����
		for (int k = LETTER+letter+othern+digit; k < code;) {
			random2 = rand() % 16;//���λ��[0,16)
			random3 = rand() % 4;//�����[0,4)
			if (random3 == 0) {
				random1 = rand() % 20;//����ַ�[0,20)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = other[random1];
					k++;
				}
			}
			else if (random3 == 1) {
				random1 = rand() % 26;//����ַ�[0,26)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + 'a';
					k++;
				}
			}
			else if (random3 == 2) {
				random1 = rand() % 26;//����ַ�[0,26)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + 'A';
					k++;
				}
			}
			else if (random3 == 3) {
				random1 = rand() % 10;//����ַ�[0,10)
				if (mycode[i][random2] == -52) {
					mycode[i][random2] = random1 + '0';
					k++;
				}
			}
		}
	}
	
	for (int i = 0; i < len; i++) {//cout
		for (int k = 0; k < max;k++) {
			if (mycode[i][k] != -52) {
				cout << mycode[i][k];
			}
		}
		cout << endl;
	}
	return 0;
}
