/* ��16 2151299 �ռ��� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	while (1) {
		int n = 0, choice;
		char qs = 0, zj = 0, mb = 0;
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_cls();
		choice = hanoi_menu();
		cct_gotoxy(0, 14);
		cout << endl;
		if (choice == 1) {
			input(&n, &qs, &zj, &mb, choice);
			no_1(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 2) {
			input(&n, &qs, &zj, &mb, choice);
			no_2(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 3) {
			input(&n, &qs, &zj, &mb, choice);
			no_3(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 4) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_4(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 5) {
			cct_cls();
			no_5();
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 6) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_6(n, qs, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 7) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_7(n, qs, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 8) {
			input(&n, &qs, &zj, &mb, choice);

			cct_cls();
			no_8(n, qs, zj, mb, choice);
			cct_gotoxy(0, 36);
			continue1();
		}
		else if (choice == 9) {
			input(&n, &qs, &zj, &mb, choice);
			cct_cls();
			no_9(n, qs, zj, mb, choice);
			continue1();
		}
		else if (choice == 0) {
			break;
		}
	}

	return 0;
}
