/*2151299 �ռ��� ��16*/
/*���������˵����ֺ���*/
#include <iostream>
#include <iomanip>
#include<conio.h>
#include"cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include"90-b2.h"
#include <Windows.h>
using namespace std;
#define ROW 8
#define COL 10
#define		MAX_ROW_NUM		8
#define		MAX_COL_NUM		10
void find_A_row_and_col(int map0[8][10], char* row, int* col, int what_row, int what_col);
int menu() 
{
	char ch;
	cout << "---------------------------------------" << endl;
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������(֧�����)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "A.�����н��棨�����Զ���-�����棩" << endl;
	cout << "B.αͼ�ν��棨�����Զ���-�����棩" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:]";
	while (1) {
		ch = _getch();
		if (ch >= '0' && ch <= '9') {
			cout << ch - '0';
			cout << endl;
			cout << endl;
			cout << endl;
			break;
		}
		else if (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (ch == 65||ch==97) {
			if (ch == 97)
				ch = 65;
			cout << ch;
			cout << endl;
			cout << endl;
			cout << endl;
			return ch;
		}
		else if (ch == 66||ch==98) {
			if (ch == 98)
				ch = 66;
			cout << ch ;
			cout << endl;
			cout << endl;
			cout << endl;
			return ch;
		}
	}//end of while
	return (ch - '0');



}
int game_progress(mto10_net_tools& client,int what_row,int what_col,int choice)
{
	char svrpack[RECVBUF_LEN];	//��Ŵ�Server���յ�������
	char row='Z';
	int col=11;
	int all=0;
	char mark[ROW][COL];
	const char *p;//8 row 10 col
	int map0[8][10];
	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* ���ݷ���˷����ĵ�ͼ������һ�������꣨ĿǰΪ�ֹ�������ʽ����Ҫ��Ϊ�Զ�����ѽ����꣩
			  ��ʾ�����Խ�client.get_map()�ķ���ֵ���Ƶ��ַ������У��ٻ�ԭΪ���Լ��Ķ�ά��������
		   */
		if(choice==65)
		client.print_map(); //��������Ϊʾ�⣬ͼ�ν����в��ܵ��ã�Ҫ�Լ�дת������
		else if (choice == 66) {
			//��������������Ҫ��Ҫ�ź���
			if (row != 'Z' && col != 11) {
				//��¼��map0��
				p = client.get_map();
				for (int i = 0; i < what_row; i++) {
					for (int j = 0; j < what_col; j++) {
						map0[i][j] = *p - '0';
						p++;
					}
				}
				for (int i = 0; i < what_row; i++) {
					for (int j = 0; j < what_col; j++) {
						if (mark[i][j] == '*') {
							int X = 8 * j + 4;
							int Y = 4 * (i + 1) - 1;
							paint_9_num(map0[i][j], &X, &Y, COLOR_BLACK);
							Sleep(1);
						}
					}
				}
				cct_setcolor();
				cct_showstr(0, 4 * what_row + 4, " ", COLOR_BLACK, COLOR_WHITE, 28);
				cct_gotoxy(0, 4 * what_row + 4);
			}
			//��ʱ�ǿհ׵ģ������µĲ�ͬ���������Ӧ��ֵ
		}

		/* ��Ϸ�ѽ������ٶ���*/
		if (client.is_gameover())
			break;

		cout << "��(A-J)��(0-9)���� : ";
		//��¼��map0��
		p = client.get_map();
		for (int i = 0; i < what_row; i++) {
			for (int j = 0; j < what_col; j++) {
				map0[i][j] = *p-'0';
				p++;
			}
		}
		//��map0����row��col
		//����
		find_A_row_and_col(map0, &row, &col, what_row, what_col);
		cout << row << col << endl;
		//cin >> row >> col; //�˴�δ�ж���ȷ�ԣ���Ҫ���д���

		/* ��պ����Ļ����� */
		//cin.clear();
		//cin.ignore(INT_MAX, '\n');

		if (row >= 'a' && row <= 'j')
			row -= 32; //�����Сд��תΪ��д
		//����row��col��͸߹⡢��������ʧ��հ�
		if (choice == 66) {
			find_same_num_and_mark(what_row, what_col, map0, mark, row, char(col + '0'), choice);
			mark_highlight(map0, mark, what_row, what_col);
			thelast_paint_colour_aftermix(map0, mark, what_row, what_col, row, char(col + '0'), choice, 0, &all);
		}
		client.send_coordinate(row, col);

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* �ȴ�Server�˵�gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* ��ӡ�� svrpack �����ݣ����д�������Server�˼�������
		   ���� Content �����ݣ��������£�
			"InvalidCoordinate" : �Ƿ�����
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeFailed" : ѡ���������Χ�޿ɺϳ���
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeSucceeded" : ���κϳɳɹ�
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
				OldMap		������ѡ�������ĵ�ͼ
				NewMap		������ѡ��������ٴ����ĵ�ͼ
			"GameOver" : ��ͼ�����������Ϸ����
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ
			"GameFinished" : �Ѻϳɵ��������ޣ�16������Ϸ���
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ */


				/* ��ӡ�յ���ԭʼ�ַ��� */
		if(choice==65)
		cout << "ServerӦ�� : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}
void find_A_row_and_col(int map0[8][10],char *row,int *col,int what_row,int what_col) {
	
	for (int i = 0; i < what_row; i++) {
		for (int j = 0; j < what_col; j++) {
			if (judge_neighbor(map0, i, j, what_row, what_col)) {//��Χ����ֵͬ
				*row = i + 'A';
				*col = j;
				return;
			}
		}
	}
}
int main()
{
	while (1) {
		int choice;
		int row, col, goal;
		int map[ROW][COL];
		char mark[ROW][COL];
		char map_x = '0', map_y = '0';
		int all = 0;
		choice = menu();
		cct_cls();
		if (choice == 1) {
			char map_x, map_y;
			input_row_col(&row, &col, &goal, 1);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			renew_mark(row, col, mark);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 2) {
			char map_x, map_y;
			input_row_col(&row, &col, &goal, 1);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			renew_mark(row, col, mark);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 3) {
			input_row_col(&row, &col, &goal, 3);
			create_begin_arr(map, row, col);
			paint_now(map, mark, row, col);
			cin1(row, col, &map_x, &map_y, map);
			find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
			paint_find_arr(mark, row, col);
			paint_colour_now(map, mark, row, col);
			if (wait_for_mix_enter(map_x, map_y) == 'Y') {
				paint_colour_aftermix(map, mark, row, col, map_x, map_y);
				add_score(row, col, map, mark, map_x, map_y, goal, &all);
				wait_for_enter_eliminate_zero();
				paint_colour_after_eliminate_zero(map, mark, row, col, map_x, map_y);
				wait_for_enter_fill_new_value();
				paint_colour_fill_new_value(map, mark, row, col);
				renew_mark(row, col, mark);
				wait_for_end_enter();
			}
			else {
				renew_mark(row, col, mark);
				wait_for_end_enter();
			}
			cct_cls();
		}
		else if (choice == 4) {
			input_row_col(&row, &col, &goal, 4);
			create_begin_arr(map, row, col);
			while (1) {
				paint_now(map, mark, row, col);
				cin1(row, col, &map_x, &map_y, map);
				find_same_num_and_mark(row, col, map, mark, map_x, map_y, choice);
				paint_find_arr(mark, row, col);
				paint_colour_now(map, mark, row, col);
				char ch = wait_for_mix_enter(map_x, map_y);
				if (ch == 'Y') {
					paint_colour_aftermix(map, mark, row, col, map_x, map_y);
					add_score(row, col, map, mark, map_x, map_y, goal, &all);
					wait_for_enter_eliminate_zero();
					paint_colour_after_eliminate_zero(map, mark, row, col, map_x, map_y);
					wait_for_enter_fill_new_value();
					paint_colour_fill_new_value(map, mark, row, col);
					renew_mark(row, col, mark);
					wait_for_mix_again();
				}
				else if (ch == 'N') {
					renew_mark(row, col, mark);
					continue;
				}
				else {
					renew_mark(row, col, mark);
					wait_for_end_enter();
					break;
				}
			}
			cct_cls();
		}
		else if (choice == 5) {
			input_row_col(&row, &col, &goal, 5);
			create_begin_arr(map, row, col);
			paint_background_5(map, row, col);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 6) {
			input_row_col(&row, &col, &goal, 6);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 7) {
			input_row_col(&row, &col, &goal, 7);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 7, &goal);
			wait_for_end_enter7();
			cct_cls();
		}
		else if (choice == 8) {
			input_row_col(&row, &col, &goal, 8);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 8, &goal);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 9) {
			input_row_col(&row, &col, &goal, 9);
			create_begin_arr(map, row, col);
			paint_background_6(map, row, col);
			select_7(map, mark, row, col, 9, &goal);
			wait_for_end_enter();
			cct_cls();
		}
		else if (choice == 0) {
			break;
		}
		else if (choice == 65||choice==66) {
		const char* my_no = "2151299";		//����ѧ��
		const char* my_pwd = "sujiaming.123";	//��������

		int wanted_row, wanted_col, wanted_id, wanted_delay;

#if 0//�������룬�˴���Ϊ #if 0 ���ʾ�������� #else �е����
		input_row_col(&wanted_row, &wanted_col, &goal,65);
		//wanted_row = 8;			//�˴������޸�Ϊ�����������ʽ
		//wanted_col = 10;			//�˴������޸�Ϊ�����������ʽ
		wanted_id = 22345;		//idΪ�����������Ϸ��ţ������-1����ʾ���������������[0..2^31-1]���ʾ��̶���ţ���Ź̶�����ÿ�θ����ĳ�ʼ���󼰺���������ͬ��������ԣ�
		wanted_delay = 60 * 1000;	//delayΪ�����ÿ��Ӧ����ʱ�ӣ���λms
#else
		//wanted_row = 5;
		//wanted_col = 7;
		input_row_col(&wanted_row, &wanted_col, &goal, 65);
		wanted_id = -1;
		wanted_delay = 60 * 1000;
#endif
		mto10_net_tools client;

		/* ��client������е�debug���أ�����ʱ�ɴ򿪣���ͼ�ν���ʱ��رգ� */
		if(choice==65)
		client.set_debug_switch(true);
		else if(choice==66)
			client.set_debug_switch(false);


		/* ���ӷ����� */
		if (client.connect() < 0) {
			/* ����ʧ����Ϣ����û��debug_switch����ӡ */
			cout << "���ӷ�����ʧ��!" << endl;
			return -1;
		}

		/* ��Server�˷�����֤��Ϣ������ */
		if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
			cout << "������֤��������Ϣʧ��!" << endl;
			return -1;
		}

		/* �ȴ�Server���·���������Ϸ��ʼ��*/
		if (client.wait_for_game_start() < 0) {
			cout << "�ȴ�GameStartʧ��!" << endl;
			return -1;
		}

		/* ��ӡ�ӷ������յ��Ĳ�����������Ϸ�Դ˲���Ϊ׼����������6��6�У�����8��10�У��򱾴���Ϸ��8��10��Ϊ׼��
		�����ӡ����Ϣ��ͼ�λ������������ȥ�� */
		if (choice == 65) {
			cout << "������������Ϣ : " << endl;
			cout << "  ���� : " << client.get_row() << endl;
			cout << "  ���� : " << client.get_col() << endl;
			cout << "  ID�� : " << client.get_gameid() << endl;
			cout << "  ��ʱ : " << client.get_delay() / 1000.0 << "(��)" << endl;
			cout << "  ��ͼ : " << client.get_map() << endl;
		}
		else if (choice == 66) {
			int map1[8][10];
			const char* p;
			p = client.get_map();
			for (int i = 0; i < client.get_row(); i++) {
				for (int j = 0; j < client.get_col(); j++) {
					map1[i][j] = *p-'0';
					p++;
				}
			}
			paint_background_66(map1, client.get_row(), client.get_col());
		}
		/* ��ͼ���е�ֵΪ1-9��A-F���ֱ��ʾ1-15��ֵ��
			   ���磺
				 ������������=3
				 ������������=4
				 ���������ص�ͼ=123A85CF2123
			   ���ʾ��ǰ��ͼΪ(����������ʾ��)
				 1 2 3  10
				 8 5 12 15
				 2 1 2  3
				��Ϸ����������Ϊ���ϳɵ�16�����κοɺϳ�Ԫ�� */

				/* ������Ϸ��������
				   1���յ�Server��GameOver�򷵻�0����Ϸ����
				   2���������������-1��������Ϣ����ȷ�ȴ��󣩣��������ٴ��ظ�	*/
		if (game_progress(client,wanted_row,wanted_col,choice) < 0) {
			client.close();
			return -1;
		}

		client.close();
		cout << "��Ϸ����" << endl;
		wait_for_end_enter();
		cct_cls();
		
}//if choice==65 66
	}//end of while
	return 0;
}