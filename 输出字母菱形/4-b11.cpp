/* 2151299 ��16 �ռ��� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_zmkg1(int j, int n);
void print_zmkg2(int i,int j, int n);
void print_diamond2(char start_ch,int b, char end_ch);
void print_diamond(char start_ch, char end_ch)
{
	static int n,i=1;
	int j=1;
	n = end_ch - 'A';
	if (i <= n + 1) {//������
		print_zmkg1(i, n);
		print_zmkg2(i,j, n);
		++i;
		cout << endl;
		print_diamond('A', end_ch);

	}	
	if (i > n + 1) {//����diamond2Ū������
		i--;
		i--;
		print_diamond2('A',i, end_ch);
	}
}

void print_diamond2(char start_ch,int b, char end_ch)
{
	static int n, i=b ;
	int j = 1;
	n = end_ch - 'A';
	if (i >= 1) {
		print_zmkg1(i, n);
		print_zmkg2(i, j, n);
		--i;
		cout << endl;
		print_diamond2('A',i, end_ch);
	}
	
}

void print_zmkg1(int a, int n) {//�ո�
	int j=a;
	if (j < n + 1) {
		printf(" ");
		j++;
		print_zmkg1(j,n);
	}
}
void print_zmkg2 (int i,int j, int n) {//i�ǵ�i�� j�ǵ�j����ĸ 

	if (j <= 2*i-1) {
		if (i == j) {
			cout << char(65);
		}
		else if (i > j) {
			cout << char(65 + (i-j));
		}
		else if (i < j) {
			cout << char(65 + (j-i));
		}
		j++;
		print_zmkg2(i,j, n);
	}
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout <<setfill('=')<< setw(2*(double(end_ch)-64)-1) << '=' << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(2 * (double(end_ch) - 64) - 1) << '=' << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}