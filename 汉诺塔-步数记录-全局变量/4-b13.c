/* 2151299 �ռ��� ��16 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
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

int i = 1;

void hanoi(int n, char src, char tmp, char dst);
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
		printf("%5d: ", i++);
        printf("%2d# %c-->%c\n",n,src,dst);
    }
    else if (n > 1) {
        hanoi(n - 1, src, dst, tmp);
		printf("%5d: ", i++);
		printf("%2d# %c-->%c\n", n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

void input()
{
	int c,ret;
	char qs, zj = 0, mb;
	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		ret=scanf("%d",&c);
		while (ret != 1) {
			while (getchar() != '\n');
			
			printf("�����뺺ŵ���Ĳ���(1-16)\n");
			ret=scanf("%d",&c);
		}
		if (c <= 0 || c >= 17) {
			while (getchar() != '\n');
			
		}
		if (c >= 1 && c <= 16) {
			while (getchar() != '\n');
			
			break;
		}
	}
	while (1) {
		printf("��������ʼ��(A-C)\n");
		scanf("%c",&qs);
		if (qs == 'a' || qs == 'b' || qs == 'c' || qs == 'A' || qs == 'B' || qs == 'C') {
			while (getchar() != '\n');
			
			break;
		}
		if (qs != 'a' && qs != 'b' && qs != 'c' && qs != 'A' && qs != 'B' && qs != 'C') {
			while (getchar() != '\n');
			
		}
	}
	while (1) {
		printf("������Ŀ����(A-C)\n");;
		scanf("%c",&mb);
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb != qs) {
			while (getchar() != '\n');
			
			break;
		}
		if (mb != 'a' && mb != 'b' && mb != 'c' && mb != 'A' && mb != 'B' && mb != 'C') {
			while (getchar() != '\n');
			
		}
		if ((mb == 'a' || mb == 'b' || mb == 'c' || mb == 'A' || mb == 'B' || mb == 'C') && mb == qs) {
			if (mb == 97 || mb == 65) {
				printf("Ŀ����(A)��������ʼ��(A)��ͬ\n");
				while (getchar() != '\n');
				
			}
			if (mb == 98 || mb == 66) {
				printf("Ŀ����(B)��������ʼ��(B)��ͬ\n");
				while (getchar() != '\n');
				
			}
			if (mb == 99 || mb == 67) {
				printf("Ŀ����(C)��������ʼ��(C)��ͬ\n");
				while (getchar() != '\n');
				
			}
		}
	}
	if ((qs == 'a' || qs == 'A') && (mb == 'b' || mb == 'B')) {
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

	printf("�ƶ�����Ϊ:\n");
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