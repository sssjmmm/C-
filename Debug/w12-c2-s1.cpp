/* 2151299 ��16 �ռ��� */
#include<iostream>
using namespace std;

int panduan(int n,int base) {
	if (n == 1) 
		return 1;
	else if (n % base==0) 
		return panduan(n / base,base);
	else
	    return 0;
}


int main() {
	int num, base, shu[10000],x=0,count=0;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> num;
	cout << "������3��������" << endl;
	for (int i=0; i < num; i++) {
		cin >> shu[i];
	}
	cout << "���������[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < num; i++) {
		x = panduan(shu[i], base);
		if (x == 1) {
			count++;
		}

	}
	cout << num << "�����л���" << base << "���ݵĸ��� : " << count<< endl;
	return 0;
}
