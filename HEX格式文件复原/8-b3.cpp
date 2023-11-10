/* 2151299 �ռ��� ��16 */
/* 2152503 ���ٳ� 2153167 ������ 2153686 ������ 2151773 ����� 2153410 ����˶ 2154301 ������ */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	char from[100];
	char to[100];
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.hex                    : ����·����ʽ" << endl;
	cerr << "    ..\\data\\b.txt          : ���·����ʽ" << endl;
	cerr << "    C:\\Windows\\System32\\c.hex : �������·����ʽ" << endl;
	cerr << "������Ҫת����hex��ʽ�ļ��� : ";
	cin.getline(from, 100);
	cerr << "������ת������ļ���        :";
	cin.getline(to, 100);

	int LEN = strlen(from);
	int LEN2 = strlen(to);

	ifstream infile;
	ofstream outfile;
	infile.open(from, ios::in | ios::binary);   
	if (!infile.is_open()) {
		cout << "�����ļ�";
		for (int i = 0; i < LEN; i++) {
			cout << from[i];
		}
		cout << "��ʧ��!" << endl;
		return -1;
	}
	//��ʱ�����ļ��Ѿ��򿪳ɹ�
	outfile.open(to, ios::out | ios::binary);
	if (!outfile.is_open()) {
		cout << "����ļ�";
		for (int i = 0; i < LEN2; i++) {
			cout << to[i];
		}
		cout << "��ʧ��!" << endl;
		infile.close();
		return -1;
	}
	//��ʱ���롢����ļ����Ѿ��򿪳ɹ�



	int n = 0;
	int nx = 0;
	for (int r = 0; infile.peek() != EOF; r++) {//r=row
		//��¼
		char arr[82] = { 0 };
		for (int c = 0; (c < 82) && (infile.peek() != EOF);c++) {//c=column
			arr[c] = infile.get();
		}
		char b[9],c[9];
		for (int i = 0; i < 8; i++) {
			b[i] = '0';
		}
		for (int i = 0; i < 8; i++) {
			c[i] = arr[i];
		}
		b[8] = '\0';
		c[8] = '\0';
		n = nx;
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
		nx += 16;
		int x=strcmp(b, c);
		if (x != 0) {
			cout << "������ƫ����0x" << c << "��������ֵ0x" << b << endl;
			break;
		}
		//���
		for (int c = 10; arr[c]!=-52&&c<=58;) {//c=column
	        int sum = 0;
			if ((arr[c] >= '0' && arr[c] <= '9') || (arr[c] >= 'a' && arr[c] <= 'f')) {
				if (arr[c] >= '0' && arr[c] <= '9')
					sum = sum + (arr[c] - '0') * 16;
				else if (arr[c] >= 'a' && arr[c] <= 'f')
					sum = sum + (arr[c] - 'a' + 10) * 16;
				if (arr[c + 1] >= '0' && arr[c + 1] <= '9')
					sum = sum + (arr[c + 1] - '0');
				else if (arr[c + 1] >= 'a' && arr[c + 1] <= 'f')
					sum = sum + (arr[c + 1] - 'a' + 10);
				if (sum > 127) {
					sum -= 256;		
					outfile << char(sum);
				}
				else
				    outfile << char(sum);
				c += 3;
			}
			else
				c += 2;
		}
	}//end of for



	infile.close();             //�ر��ļ������� 
	outfile.close();             //�ر��ļ������ 

	return 0;
}
