/* 2151299 ��16 �ռ��� */
#include <iostream>
using namespace std;

int max(int a, int b);
int max(int a, int b,int c);
int max(int a, int b,int c,int d);
int max(int a, int b) {
	int e = (a > b ? a : b);
	return e;
}
int max(int a, int b, int c) {
	int e = (a > b ? a : b);
	int f = (e > c ? e : c);
	return f;
}
int max(int a, int b, int c,int d) {
	int e = (a > b ? a : b);
	int f = (e > c ? e : c);
	int g = (f > d ? f : d);
	return g;
}
int main() {
	int num, a, b, c,d,m;
	m = 0;
	while (1) {
		cout << "���������num��num����������"<<endl;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "���������num��num����������"<<endl;
			cin >> num;
		}
		if (num == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			cout << "max=" << max(a, b) << endl;
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			cout << "max=" <<max(a, b, c) << endl;
		}
		else if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				while (cin.fail()) {
					cin.clear();
					cin.ignore(65535, '\n');
				}
				continue;
			}
			cout << "max=" << max(a, b, c, d) << endl;
		}	
		else
			cout << "�����������" << endl;
		break;
	}

	return 0;
}