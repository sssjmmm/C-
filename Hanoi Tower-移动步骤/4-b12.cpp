/* 2151299 �ռ��� ��16 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cout << setw(2) << n << "# " << src << "-->" << dst << endl; 
	}
	else if(n>1){
		hanoi(n - 1, src, dst, tmp); 
		cout << setw(2) << n << "# " << src << "-->" << dst << endl;
		hanoi(n - 1, tmp, src, dst);
	}

}

void input()
{
	int c;
	char qs,zj=0, mb;
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-16)"<<endl;
		cin >> c;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
			cin >>c;
		}
		if (c<=0||c>=17) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if (c >= 1 && c <= 16) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;	
		}
	}
	while (1) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> qs;
		if (qs == 'a' || qs == 'b' || qs == 'c' || qs == 'A' || qs == 'B' || qs == 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (qs != 'a' && qs != 'b' && qs != 'c' && qs != 'A' && qs != 'B' && qs != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
	}
	while (1) {
		cout << "������Ŀ����(A-C)" << endl;;
		cin >> mb;
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C')&&mb!=qs) {
			cin.clear();
			cin.ignore(65535, '\n');
			break;
		}
		if (mb != 'a' && mb != 'b' && mb != 'c' && mb != 'A' && mb != 'B' && mb != 'C') {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb == qs) {
			if (mb == 97 || mb == 65) {
				cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (mb == 98 || mb == 66) {
				cout << "Ŀ����(B)��������ʼ��(B)��ͬ" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
			if (mb == 99 || mb == 67) {
				cout << "Ŀ����(C)��������ʼ��(C)��ͬ" << endl;
				cin.clear();
				cin.ignore(65535, '\n');
			}
		}
	}
	if ((qs == 'a' || qs == 'A') &&( mb == 'b' || mb == 'B')) {
		qs = 'A';
		zj = 'C';
		mb = 'B';
	}
	else if ((qs == 'a' || qs == 'A') && (mb == 'c' || mb == 'C')) {
		qs = 'A';
		zj = 'B';
		mb = 'C';
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'c' || mb == 'C')) {
		qs = 'B';
		zj = 'A';
		mb = 'C';
	}
	else if ((qs == 'b' || qs == 'B') && (mb == 'a' || mb == 'A')) {
		qs = 'B';
		zj = 'C';
		mb = 'A';
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'b' || mb == 'B')) {
		qs = 'C';
		zj = 'A';
		mb = 'B';
	}
	else if ((qs == 'c' || qs == 'C') && (mb == 'a' || mb == 'A')) {
		qs = 'C';
		zj = 'B';
		mb = 'A';
	}
		
	cout << "�ƶ�����Ϊ:" << endl;
	hanoi(c, qs, zj, mb);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	input();

	return 0;
}