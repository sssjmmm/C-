/* 2151299 �ռ��� ��16 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}


void menu();
void move_by_ijkl(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);

	/*��ʼ���λ��*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}

		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}

		}

		else if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}

	}

	while (i == 2) {
		ch = _getch();
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}
			else if (y == 1) {
				y = 17;
				gotoxy(hout, x, y);
				continue;
			}
		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}
			else if (x == 1) {
				x = 69;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}
			else if (y == 17) {
				y = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}
			else if (x == 69) {
				x = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}

	}

	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("��Ϸ���������س������ز˵�.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//�س� ���ز˵�
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}



void move_by_ijkl2(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);

	/*��ʼ���λ��*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			ch = 12345;
		}
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}

		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}

		}

		else if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}


	}

	while (i == 2) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			ch = 12345;
		}
		if (ch == 73 || ch == 105) {//I i
			if (y > 1) {
				gotoxy(hout, x, --y);
				continue;
			}
			else if (y == 1) {
				y = 17;
				gotoxy(hout, x, y);
				continue;
			}
		}

		else if (ch == 74 || ch == 106) {//J j
			if (x > 1) {
				gotoxy(hout, --x, y);
				continue;
			}
			else if (x == 1) {
				x = 69;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 75 || ch == 107) {//K k
			if (y < 17) {
				gotoxy(hout, x, ++y);
				continue;
			}
			else if (y == 17) {
				y = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 76 || ch == 108) {//L l
			if (x < 69) {
				gotoxy(hout, ++x, y);
				continue;
			}
			else if (x == 69) {
				x = 1;
				gotoxy(hout, x, y);
				continue;
			}

		}

		else if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		else if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}

	}

	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("��Ϸ���������س������ز˵�.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//�س� ���ز˵�
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}






void move_by_arrow(int i) {
	int ch;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);

	/*��ʼ���λ��*/
	int x, y;
	x = 35;
	y = 9;
	gotoxy(hout, x, y);

	while (i == 1) {
		ch = _getch();
		while (ch == 224) {
			ch = _getch();
			if (ch == 72) {//��
				if (y > 1) {
					gotoxy(hout, x, --y);
					continue;
				}
			}

			else if (ch == 75) {//��
				if (x > 1) {
					gotoxy(hout, --x, y);
					continue;
				}
			}

			else if (ch == 80) {//��
				if (y < 17) {
					gotoxy(hout, x, ++y);
					continue;
				}
			}
			else if (ch == 77) {//��
				if (x < 69) {
					gotoxy(hout, ++x, y);
					continue;
				}
			}
		}
		if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}

		if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}
	}

	while (i == 2) {
		ch = _getch();
		while (ch == 224) {
			ch = _getch();
			if (ch == 72) {//��
				if (y > 1) {
					gotoxy(hout, x, --y);
					continue;
				}
				else if (y == 1) {
					y = 17;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 75) {//��
				if (x > 1) {
					gotoxy(hout, --x, y);
					continue;
				}
				else if (x == 1) {
					x = 69;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 80) {//��
				if (y < 17) {
					gotoxy(hout, x, ++y);
					continue;
				}
				else if (y == 17) {
					y = 1;
					gotoxy(hout, x, y);
					continue;
				}
			}
			else if (ch == 77) {//��
				if (x < 69) {
					gotoxy(hout, ++x, y);
					continue;
				}
				else if (x == 69) {
					x = 1;
					gotoxy(hout, x, y);
					continue;
				}
			}
		}
		if (ch == 32) {//�ո�
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 113 || ch == 81) {//q Q �˳�
			break;
		}
	}


	x = 0; y = 23;
	gotoxy(hout, x, y);
	printf("��Ϸ���������س������ز˵�.");
	x = 27;
	gotoxy(hout, x, y);

	while (1) {//�س� ���ز˵�
		char k;
		k = _getch();
		if (k == '\r') {
			cls(hout);
			break;
		}
	}
}

void menu() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	char ch;
	while (1) {
		printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ\n");
		printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����\n");
		printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
		printf("4.�ü�ͷ�������������ң��߽����\n");
		printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ��׼�����ƶ�\n");
		printf("6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ��׼�����ƶ�\n");
		printf("0.�˳�\n");
		printf("[��ѡ��0 - 6] \n");
		ch = _getch();
		cls(hout);
		if (ch == '1')
			move_by_ijkl(1);
		else if (ch == '2')
			move_by_ijkl(2);
		else if (ch == '3')
			move_by_arrow(1);
		else if (ch == '4')
			move_by_arrow(2);
		else if (ch == '5')
			move_by_ijkl2(1);
		else if (ch == '6')
			move_by_ijkl2(2);
		else if (ch == '0')
			break;
	}
}
/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	menu();

	return 0;
}
/*˼��1���ҵĳ����������������⣬ֻҪ������
if (ch == 224) {
	ch = _getch();
	ch = 12345;
}
��ʡȥ�ͻ���ְ����ͷ���µ��������Ϊ���������������ֵ���ȷ���224�󷵻ط������Ӧ�ļ��룬
�������ͷ�ļ����k��ASCII��һ�£����Գ��ְ����ͷ�����µ������

˼��2���п��ܴﲻ��20����ĸ
*/