/*2151299 �ռ��� ��16*/
/*���ڲ����鷽ʽʵ�ֵĸ�������*/
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
void thelast_paint_colour_fall(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y, int choice) {
	bool BREAK2 = true;
	while (BREAK2) {
		BREAK2 = false;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 0) {
					if (i - 1 >= 0) {
						if (map[i - 1][j] != 0) {
							fall_move(map, char('A' + i - 1), char(j + '0'));
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
	
	if (choice == 8)
		wait_for_what(row, 2);
	if(choice!=66)//b�͵���Ϊֹ
	thelast_paint_colour_fill(map, mark, row, col, map_x, map_y, choice);
}
void fall_move(int map[ROW][COL], char map_x, char map_y) {
	int X = 8 * (map_y - '0') + 4;
	int Y = 4 * (map_x - 'A' + 1) - 1;
	//�Ź������Ͻ�
	for (int i = 0; i < 4; i++) {//����ƽ��һ��


			/* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */

		cct_showstr(X, Y, " ", COLOR_HWHITE, COLOR_BLACK, 6);
		Y++;

		paint_9_num(map[map_x - 'A'][map_y - '0'], &X, &Y, COLOR_BLACK);
		X -= 6;
		Sleep(1);
	} //end of for
	Y--;
	cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK, 3);
}
void thelast_paint_colour_fill(int map[ROW][COL], char mark[ROW][COL], int row, int col, char map_x, char map_y, int choice) {
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*') {
				int X = 8 * j + 4;
				int Y = 4 * (i + 1) - 1;
				paint_9_num(map[i][j], &X, &Y, COLOR_BLACK);
				Sleep(1);
			}
		}
	}
	if (choice == 8)
		wait_for_what(row, 3);

}
void thelast_add_score(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int goal, int* all) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*')
				sum++;
		}
	}
	int now_num = 0, score = 0;
	now_num = map[map_x - 'A'][map_y - '0'] - 1;
	score = now_num * sum * 3;
	*all = *all + score;
	cct_gotoxy(0, 0);
	cout << " ���ε÷֣�" << score << " �ܵ÷֣�" << *all << " �ϳ�Ŀ�꣺" << goal << endl;

}
void add_score2(int row, int col, int map[ROW][COL], char mark[ROW][COL], char map_x, char map_y, int* goal, int* all) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == '*')
				sum++;
		}
	}
	int now_num = 0, score = 0;
	now_num = map[map_x - 'A'][map_y - '0'] - 1;
	score = now_num * sum * 3;
	*all = *all + score;
	cct_gotoxy(0, 0);
	cct_setcolor();
	cout << setiosflags(ios::left);
	cout << "���ε÷�:" << setw(4) << score << " �ܵ÷�:" << setw(5) << *all << " �ϳ�Ŀ��:" << setw(2) << *goal << endl;
	cout << resetiosflags(ios::left);
}