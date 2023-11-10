/*2151299 �ռ��� ��16*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
#define COL 16

char change(char ch) {
	if (ch >= 65 && ch <= 90)
		ch += 32;
	return ch;
}
void change8(int n) {
	char b[8];
	for (int i = 0; i < 8; i++) {
		b[i] = '0';
	}
	for (int i = 7; n != 0; i--) {
		if (n % 16 == 10)b[i] = 'a';
		else if (n % 16 == 11)b[i] = 'b';
		else if (n % 16 == 12)b[i] = 'c';
		else if (n % 16 == 13)b[i] = 'd';
		else if (n % 16 == 14)b[i] = 'e';
		else if (n % 16 == 15)b[i] = 'f';
		else b[i] = (n % 16) + '0';
		n = n / 16;
	}
	for (int i = 0; i < 8; i++) {
		cout << b[i];
	}
	cout << "  ";
}
void change2(int n) {
	char a[2];
	for (int i = 0; i < 2; i++) {
		a[i] = '0';
	}
	if (n < 0 )
		n += 256;
	for (int i = 1; n != 0; i--) {
		if (n % 16 == 10)a[i] = 'A';
		else if (n % 16 == 11)a[i] = 'B';
		else if (n % 16 == 12)a[i] = 'C';
		else if (n % 16 == 13)a[i] = 'D';
		else if (n % 16 == 14)a[i] = 'E';
		else if (n % 16 == 15)a[i] = 'F';
		else a[i] = int((n % 16) + '0');
		n = n / 16;
	}
	for (int i = 0; i < 2; i++) {
		a[i]=change(a[i]);
		cout << a[i];
	}
	cout << " ";
}

int main()
{
	char way[100];
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.txt                    : ����·����ʽ" << endl;
	cerr << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	cerr << "�������ļ��� :";
	cin.getline(way, 100);
	int LEN = strlen(way);

	ifstream infile;
	infile.open(way, ios::in|ios::binary);
	if (!infile.is_open()) {
		cout << "�����ļ�";
		for (int i = 0; i < LEN; i++) {
			cout << way[i];
		}
		cout<< "��ʧ��!" << endl;
		return -1;
	}
	//��ʱ�����ļ��Ѿ��򿪳ɹ�
	char arr[COL] = { 0 }, ch;
	char* p;
	int row = 0;
	int sum=0;

	for (int r = 0; infile.peek()!=EOF; r++) {//r=row
		//��¼
		for (int c = 0; (c < COL) && (infile.peek() != EOF); c++) {//c=column
			arr[c] = infile.get();
			sum++;
		}
		//��һ����
		change8(row);
		//Ϊ������׼��
		if (sum == 16)
			row+=16;
		//�ڶ�����
		bool F = false, X = false;//Ϊ�˲���
		int now = 0;
		for (p=arr; p-arr<sum; p++) {//c=column
			int M = 0;		
			//"-"
			if (now == 8) {
					cout << "- ";
					X = true;
			}	
				change2(*p);
				now++;
		}//end of for
		if (X == false) {
			cout << "  ";
		}
		for (int i = 0; i < 16 - sum+F; i++) {//������
			cout << "   ";
		}
		//��������
		cout << "    ";
		for (p = arr; p - arr < sum; p++) {//c=column
			if (*p >= 33 && *p <= 126) {
				cout << char(*p);
			}
			else  {
				cout << ".";
			}
		}
		sum = 0;
		if (infile.peek() != EOF) {
			cout << endl;//������һ��
		}
		else
			break;

	}
	cout << endl;

	infile.close();             //�ر��ļ������� 

	return 0;
}
