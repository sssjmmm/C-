/* 2151299 ��16 �ռ���*/
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	char str[3][128];
	int i,k;
	int letter=0, LETTER=0, digit=0, blank=0, other=0;
	for (i = 0; i < 3; i++) {
		cout << "�������" << i + 1 << "��" << endl;

		cin.getline(str[i],128);

		for (k=0; str[i][k]!='\0'; k++){
			if (str[i][k] >= '0' && str[i][k] <= '9')
				digit++;
			else if (str[i][k] >= 'A' && str[i][k] <= 'Z') 
				LETTER++;
			else if (str[i][k]>= 'a' && str[i][k]<= 'z')
				letter++;
			else if (str[i][k]== ' ') 
				blank++;
			else
				other++;
		}
	}
	cout << "��д : " << LETTER << endl;
	cout << "Сд : " << letter << endl;
	cout << "���� : " << digit << endl;
	cout << "�ո� : " << blank << endl;
	cout << "���� : " << other << endl;
	return 0;
}
