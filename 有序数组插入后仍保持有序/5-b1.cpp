/* ��16 2151299 �ռ��� */
#include <iostream>
using namespace std;
#define n 21
int main() {
	cout << "��������������������������20��������-1����" << endl;
	int a[n] = {0}, k,sum=0;
	for (int i = 0; i < n-1; i++) {
		cin >> k;
		if (k <0)
			break;
		else {
			a[i] = k;
			sum++;
		}
	}
	cin.clear();
	cin.ignore(65535, '\n');
	if (a[0] <= 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
	else {
		cout << "ԭ����Ϊ��" << endl;
		for (int i = 0; i < sum; i++) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
	cout << "������Ҫ�����������" << endl;
	cin >> a[n-1];
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - (i+1); j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	cout << "����������Ϊ��" << endl;
	for (int i = n-sum-1; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}