/* 2151299 ��16 �ռ��� */
#include<iostream>
#include <cmath>
using namespace std;


double calculatethree(double x1, double x2, double x3, double y1, double y2, double y3);
//���׹�ʽ
double calculatethree(double x1, double x2, double x3, double y1, double y2, double y3) {
	double a, b, c, p;
	double area;
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	p = (a + b + c) / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	return area;
}
int main() {
	double mj = 0.0;
	int num, s;
	double x[10], y[10];


	while (1) {
		cout << "���������εĶ�������(4-7)" << endl;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "���������εĶ�������(4-7)" << endl;
			cin >> num;
		}
		if (num >= 4 && num <= 7)
			break;
	}
	cout << "�밴˳ʱ��/��ʱ�뷽������4�������x,y���꣺" << endl;
	for (s = 0; s < num; s++) {
		cout << "�������" << s + 1 << "����������꣺" << endl;
		cin >> x[s] >> y[s];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "�������" << s + 1 << "����������꣺" << endl;
			cin >> x[s] >> y[s];
		}
	}

	x[s] = x[0];
	y[s] = y[0];
	x[s+1] = x[1];
	y[s+1] = y[1];

	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < s; i++) {//������� �÷����ж�
		if ((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                 (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]) > 0) {
			num1++;
		}
		else if (fabs((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                 (y[i + 1] - y[i]) * (x[i + 2] - x[i + 1])) < 1e-8) {
			cout << "����͹" << num << "����" << endl;
			break;
		}
		else if((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) -
			                  (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]) < 0) {
			num2++;
		}
	}

	for (int i = 1; i < num - 1; i++) {
		mj = mj + calculatethree(x[0], x[i], x[i + 1], y[0], y[i], y[i + 1]);
	}

	if (num1 == num || num2 == num) {
		cout << "͹" << num << "���ε����=" << mj << endl;
	}

	return 0;
}