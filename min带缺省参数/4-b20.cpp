/* 2151299 ��16 �ռ��� */
#include <iostream>
using namespace std;

int min();
int main() {
	min();
	return 0;
}
int min() {
	int num, a, b, c, d, m;
	m = 0;
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "���������num��num����������" << endl;
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
			int e = (a < b ? a : b);
			cout << "min=" << e << endl;
			return e;
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
			int e = (a < b ? a : b);
			int f = (e < c ? e : c);
			cout << "min=" << f << endl;
			return f;
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
			int e = (a < b ? a : b);
			int f = (e < c ? e : c);
			int g = (f < d ? f : d);
			cout << "min=" << g << endl;
			return g;
		}
		else
			cout << "�����������" << endl;
		return 0;
	}

}

