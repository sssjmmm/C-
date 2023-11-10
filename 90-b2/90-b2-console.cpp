/*2151299 �ռ��� ��16*/
/*��cmdαͼ�ν��淽ʽʵ�ֵĸ�������*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include<conio.h>
#include <time.h> 
#include"cmd_console_tools.h"
#include"90-b2.h"
using namespace std;

#define ROW 8
#define COL 10


/*���Ʋ��ҽ������*/
void paint_find_arr(char mark[ROW][COL], int row, int col) {
	cout << endl << endl << "���ҽ�����飺" << endl;
	cout << "  |";
	for (int i = 0; i < col; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (int i = 0; i < col; i++) {
		cout << "---";
	}
	cout << endl;
	for (int i = 0; i < row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			cout << "  " << mark[i][j];
		}
		cout << endl;
	}
	cout << endl;

}
/*���Ƶ�ǰ����(��ͬɫ��ʶ)*/
void paint_colour_now(int map[ROW][COL], char mark[ROW][COL], int row, int col) {
	cout << endl << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	paint_arr(row, col, map, mark);
}
/*������ֵͬ�鲢�������(��ͬɫ��ʶ)*/
void paint_colour_aftermix(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y) {
	cout << endl << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
	map[map_x - 'A'][map_y - '0']++;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*' && !(i == map_x - 'A' && j == map_y - '0')) {
				map[i][j] = 0;
			}
		}
	}
	paint_arr(row, col, map, mark);
}
/*paint����*/
void paint_arr(int row, int col, int map[ROW][COL], char mark[ROW][COL]) {
	cout << "  |";
	for (int i = 0; i < col; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (int i = 0; i < col; i++) {
		cout << "---";
	}
	cout << endl;
	for (int i = 0; i < row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*') {
				int X, Y;
				cct_getxy(X, Y);
				cct_showch(X + 2, Y, char('0' + map[i][j]), COLOR_RED, COLOR_HYELLOW, 1);
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			}
			else
				cout << "  " << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
/*���Ƴ�0�������(��ͬɫ��ʶ)��*/
void paint_colour_after_eliminate_zero(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y) {
	cout << endl << "��0�������(��ͬɫ��ʶ)��" << endl;
	bool BREAK2 = true;
	while (BREAK2) {
		BREAK2 = false;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 0) {
					if (i - 1 >= 0) {
						if (map[i - 1][j] != 0) {
							map[i][j] = map[i - 1][j];
							map[i - 1][j] = 0;
							BREAK2 = true;
						}
					}
				}
			}//end of for
		}//end of for
	}//end of while
	//��markȫ�ó�'0'
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mark[i][j] = '0';
		}
	}
	//��map'0'ȫ�ó�mark'*'
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				mark[i][j] = '*';
			}
		}
	}
	paint_arr(row, col, map, mark);
}
/*������ֵ���������(��ͬɫ��ʶ)*/
void paint_colour_fill_new_value(int map[ROW][COL], char mark[ROW][COL], int row, int col) {
	cout << endl << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	int max;
	max = find_max_num(map, row, col);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				map[i][j] = create_random(max);
			}
		}
	}
	paint_arr(row, col, map, mark);
}
/*ѡ��5�����޿򱳾�*/
void paint_background_5(int map[ROW][COL], int row, int col) {
	//int cols, lines, buffer_cols, buffer_lines;
	int X = 0, Y = 0;
	cct_setconsoleborder(6 * col + 7, 3 * row + 8);
	//cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
	cout << "��Ļ��ǰ����Ϊ��" << 6 * col + 7 << "��" << 3 * row + 8 << "��" << endl;
	cout << " ";
	for (int i = 0; i < col; i++)
		cout << setw(6) << i;
	cout << endl;
	for (int i = 0; i < 3 * row + 2; i++) {
		if (i % 3 == 2)
			cout << char((i + 1) / 3 + 'A' - 1);
		else
			cout << " ";
		cout << " ";
		for (int j = 0; j < 4 + 6 * col; j += 2) {
			cct_getxy(X, Y);
			Sleep(0);
			if (i == 0) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 2 + 6 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else if (i == 3 * row + 1) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 2 + 6 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else {
				if (j == 0 || j == 2 + 6 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
		cout << endl;
	}//end of for
	cct_gotoxy(4, 3);//��ʼŪ����
	cct_getxy(X, Y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			paint_9_num(map[i][j], &X, &Y, COLOR_BLACK);
		}
		X -= 6 * col;
		Y += 3;
	}
	cout << endl << endl << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/*ѡ��6�����п򱳾�*/
void paint_background_6(int map[ROW][COL], int row, int col) {
	int X = 0, Y = 0;
	cct_setconsoleborder(8 * col + 5, 4 * row + 7);
	cout << "��Ļ��ǰ����Ϊ��" << 8 * col + 5 << "��" << 4 * row + 7 << "��" << endl;
	cout << "      0";
	for (int i = 1; i < col; i++)
		cout << setw(8) << i;
	cout << endl;
	for (int i = 0; i < 4 * row + 1; i++) {
		if (i % 4 == 2)
			cout << char((i + 2) / 4 + 'A' - 1);
		else
			cout << " ";
		cout << " ";
		for (int j = 0; j < 2 + 8 * col; j += 2) {
			cct_getxy(X, Y);
			Sleep(0);
			if (i == 0) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else if (i == 4 * row) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else if (i % 4 == 0) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else {
				if (j == 0 || j == 8 * col || j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
		cout << endl;
	}//end of for
	cct_gotoxy(4, 3);//��ʼŪ����
	cct_getxy(X, Y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			paint_9_num(map[i][j], &X, &Y, COLOR_BLACK);
			X += 2;
		}
		X = X - 8 * col;
		Y += 4;
	}
	cout << endl << endl << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
/*���ƾŹ�����ɫ����*/
void paint_9_num(int num, int* X, int* Y, int highlight) {
	if (num > 16)
		num -= 16;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*Y += 1;
	*X -= 4;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	if (num >= 10) {
		cct_showint(*X, *Y, num, num, highlight, 1);
		*X += 2;
	}
	else {
		cct_showint(*X, *Y, num, num, highlight, 1);
		*X += 1;
		cct_showch(*X, *Y, ' ', num, highlight, 1);
		*X += 1;
	}
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*Y += 1;
	*X -= 4;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	cct_showstr(*X, *Y, "��", num, highlight, 1);
	*X += 2;
	*Y -= 2;
}
void paint_background_66(int map[ROW][COL], int row, int col) {
	int X = 0, Y = 0;
	cct_setconsoleborder(8 * col + 5, 4 * row + 12);
	cout << "��Ļ��ǰ����Ϊ��" << 8 * col + 5 << "��" << 4 * row + 12 << "��" << endl;
	cout << "      0";
	for (int i = 1; i < col; i++)
		cout << setw(8) << i;
	cout << endl;
	for (int i = 0; i < 4 * row + 1; i++) {
		if (i % 4 == 2)
			cout << char((i + 2) / 4 + 'A' - 1);
		else
			cout << " ";
		cout << " ";
		for (int j = 0; j < 2 + 8 * col; j += 2) {
			cct_getxy(X, Y);
			Sleep(0);
			if (i == 0) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else if (i == 4 * row) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else if (i % 4 == 0) {
				if (j == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j == 8 * col)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else if (j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			else {
				if (j == 0 || j == 8 * col || j % 8 == 0)
					cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				else
					cct_showstr(X, Y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		}
		cout << endl;
	}//end of for
	cct_gotoxy(4, 3);//��ʼŪ����
	cct_getxy(X, Y);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			paint_9_num(map[i][j], &X, &Y, COLOR_BLACK);
			X += 2;
		}
		X = X - 8 * col;
		Y += 4;
	}
	cout << endl << endl << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}