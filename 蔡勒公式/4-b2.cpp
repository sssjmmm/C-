/* ��16 2151299 �ռ��� */
#include <iostream>
#include <limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int c, w;
	if (m != 1 && m != 2) {
		c = y / 100;
	y = y - c * 100;
	}
	if (m == 1) {
		m = 13;
	    y = y - 1;
	    c = y / 100;
	    y = y - c * 100;
	}		
	if (m == 2) {
		m = 14;
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
	}		
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	if (w < 0)
		w = w%7+7;
	else if (w > 0)
		w = w % 7;
	return w;
}

void daxie(int w)
{
	switch (w) {
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "һ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "��";
			break;
	}
}

int main()
{
	int year, month, day,a,k;
 	while (1) {
		a = 1;
		cout << "��������[1900-2100]���¡��գ�"<<endl;
		cin >> year >> month >> day;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "�����������������" << endl;
			cout << "��������[1900-2100]���¡��գ�"<<endl;
			cin >> year >> month >> day;
		}
		if (year < 1900 || year>2100) {//year
			cout << "��ݲ���ȷ������������" << endl;
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month < 1 || month > 12)) {//month
			cout << "�·ݲ���ȷ������������" << endl;
			a = 0;
		}
		else if ((year >= 1900 && year <= 2100) && (month >= 1 || month <= 12)) {//day
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				if (month == 2 && day > 29) {
					cout << "�ղ���ȷ������������" << endl;
					a = 0;
				}				
			}		
			if (month == 1 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 2 && !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (day <= 0 || day > 28)) {
                cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 3 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 4 && (day <= 0 || day > 30)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}			
			else if (month == 5 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 6 && (day <= 0 || day > 30)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 7 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 8 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 9 && (day <= 0 || day > 30)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 10 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 11 && (day <= 0 || day > 30)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}				
			else if (month == 12 && (day <= 0 || day > 31)) {
				cout << "�ղ���ȷ������������" << endl;
				a = 0;
			}
		}
	    if(a == 1&& (year >= 1900 && year <= 2100) && (month >= 1 && month <= 12))
		    break;
	}
	k = zeller(year, month, day);
	cout << "����";
	daxie(k);
	cout << endl;
	return 0;
}