/* 2151299 �ռ��� ��16 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3�������������������
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	float fen;                    //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����10��ѧ������Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* �����������ͱ����⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;
	for (i = 0; i < 10; i++) {
		cout << "������� " << i+1 << "��ѧ������Ϣ : ";
		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < 3; j++) {
			cin >> stu[i].score[j].value;
			cin >> stu[i].score[j].weight;
		}
	}
	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����10��ѧ���Ļ�����Ϣ
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* ��������ָ������⣬�����������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* ps;
	struct course* pc;
	cout << "10��ѧ���ĳɼ�Ϊ" << endl;
	cout << "��� ѧ��    ����     �ɼ�1 Ȩ��1 �ɼ�2 Ȩ��2 �ɼ�3 Ȩ��3 ��Ȩƽ���ɼ�" << endl;
	cout << "======================================================================" << endl;
	for (ps = stu; ps - stu < num; ps++) {//һ��ʼΪstudent�ṹ����׵�ַ
		cout << setw(4) << setiosflags(ios::left) << ps - stu + 1 << " ";//���
		cout << setw(7) << ps->no << " ";
		cout << setw(8) << ps->name << " ";
		ps->fen = 0;
		for (pc = ps->score; pc - ps->score < 3; pc++) {//һ��ʼΪstudent�ṹ���е�score�ṹ����׵�ַ
			cout << setw(5) << pc->value << " ";
			cout << setw(5) << pc->weight << " ";
			ps->fen += (pc->value * pc->weight);
		}
		pc = ps->score;

		ps->fen /= (pc->weight + (pc+1)->weight + (pc+2)->weight);
		cout << setw(5) << ps->fen;
		cout << endl;

	}
	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����������ߵ�ѧ���������в��У�
  ���������
  �� �� ֵ��
  ˵    ������������ֺ궨��N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* ��������������������͵ļ򵥱������������������� */
	cout << "�ɼ���ߵ�ѧ��Ϊ" << endl;
	cout << "��� ѧ��    ����     �ɼ�1 Ȩ��1 �ɼ�2 Ȩ��2 �ɼ�3 Ȩ��3 ��Ȩƽ���ɼ�" << endl;
	cout << "======================================================================" << endl;

	int a = 0, c = 0, d, e, f = 0;
	double y = 0, x = 0;
	for (d = 0; d < num; d++) {
		x = (stu[d].score[0].value * stu[d].score[0].weight + stu[d].score[1].value * stu[d].score[1].weight + stu[d].score[2].value * stu[d].score[2].weight) / (stu[d].score[0].weight + stu[d].score[1].weight + stu[d].score[2].weight) + 0.001;
		for (e = 0; e < num; e++) {
			y = (stu[e].score[0].value * stu[e].score[0].weight + stu[e].score[1].value * stu[e].score[1].weight + stu[e].score[2].value * stu[e].score[2].weight) / (stu[e].score[0].weight + stu[e].score[1].weight + stu[e].score[2].weight) + 0.001;
			if (y > x)
				break;
		}
		if (e == num) {
			a = d + 1;
			break;
		}
	}
	e = a - 1;
	cout << setiosflags(ios::left)<< setw(4) << a;
	cout << setw(7) << stu[e].no;
	cout << setw(8) << stu[e].name;
	cout << setw(5) << stu[e].score[0].value;
	cout << setw(5) << stu[e].score[0].weight;
	cout << setw(5) << stu[e].score[1].value;
	cout << setw(5) << stu[e].score[1].weight;
	cout << setw(5) << stu[e].score[2].value;
	cout << setw(5) << stu[e].score[2].weight;
	cout << setprecision(2) << x << endl;
	for (d = a; d < num; d++) {
		x = (stu[d].score[0].value * stu[d].score[0].weight + stu[d].score[1].value * stu[d].score[1].weight + stu[d].score[2].value * stu[d].score[2].weight) / (stu[d].score[0].weight + stu[d].score[1].weight + stu[d].score[2].weight) + 0.001;
		y = (stu[e].score[0].value * stu[e].score[0].weight + stu[e].score[1].value * stu[e].score[1].weight + stu[e].score[2].value * stu[e].score[2].weight) / (stu[e].score[0].weight + stu[e].score[1].weight + stu[e].score[2].weight) + 0.001;
		if (x == y)
			f = d;
		if (f > 0) {
			cout << setw(4) << f + 1;
			cout << setw(7) << stu[f].no;
			cout << setw(8) << stu[f].name;
			cout << setw(5) << stu[f].score[0].value;
			cout << setw(5) << stu[f].score[0].weight;
			cout << setw(5) << stu[f].score[1].value;
			cout << setw(5) << stu[f].score[1].weight;
			cout << setw(5) << stu[f].score[2].value;
			cout << setw(5) << stu[f].score[2].weight;
			cout << setprecision(2) << x << endl;
		}
		f = 0;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//����10��ѧ������Ϣ
	output_base(stu, 10);	//���10��ѧ���Ļ�����Ϣ
	output_max(stu, 10);	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2052708 ������ 76.5 4 82 5 52 2
2053177 ��ѧ�� 63 4 49 1 87 6
2054176 ����� 56 3 76 4 69 5
2051973 ����� 44.5 2 83.5 4 87 6
2053641 ������ 91 4 43.5 1 66 3
2053385 ������ 79 6 85.5 3 62 2
2052931 ��һ�� 86 3 63 3 77.5 4
2052312 ��־�� 49.5 3 86 6 93.5 3
2054363 ��Ƴ� 68 2 74.5 3 60 5
2053287 ������ 73 3 62 2 85 5

*/