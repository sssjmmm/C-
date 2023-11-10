/* 2151299 ��16 �ռ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�
class stu_list;
/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no=0;			//ѧ��
	char stu_name[MAX_NAME_LEN]="";	//����
	char no1 ='/';
	char no2 = '/';
	friend stu_list;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	
	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	void print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append ) 
{
	int LEN = strlen(filename);

	ifstream infile;
	infile.open(filename, ios::in | ios::binary);
	if (!infile.is_open()) {
		cout << "�ļ�[";
		for (int i = 0; i < LEN; i++) {
			cout << filename[i];
		}
		cout << "]��ʧ��" << endl;
		return -1;
	}
	//��ʱ�Ѿ��򿪳ɹ�
	if (append == 0) {
		int i;
		for (i = 0; infile.peek() != EOF; i++) {//��һ��
			infile >> stu[i].stu_no >> stu[i].stu_name;
			stu[i].no1 = 'Y';
		}
		if(i-1>=0)
		stu[i - 1].no1 = '/';
	}
	else if (append == 1) {
		int a = 0;
		while (1) {
			if (stu[a].stu_no > 0)
				a++;
			else if (stu[a].stu_no == 0)
				break;
		}
		int  stu_no2;			//ѧ��
		char stu_name2[MAX_NAME_LEN];	//����
		bool U = false;
		for (int i = 0; infile.peek() != EOF;) {//�ڶ��μ�¼
			U = false;
			infile >> stu_no2 >> stu_name2;
			for (int j = 0; j < MAX_STU_NUM; j++) {
				if (stu_no2 == stu[j].stu_no) {//��������ͬѧ��
					stu[j].no2 = 'Y';
					U = true;
				}
			}
			if (U == false) {//ֻ�еڶ�����
				stu[i + a].stu_no= stu_no2;
				strncpy(stu[i + a].stu_name, stu_name2, MAX_NAME_LEN);
				stu[i + a].no2 = 'Y';
				i++;
			}
		}

		//�����������ͬѧ�ţ���һ��YY���ڶ���ѧ����0�����ֻ��һ��ѧ�ţ���һ����Y���ڶ��α���˿Σ�
		//��һ����\�ڶ�����Y����ڶ��α�ɲ�ѡ
		
		//ʣ�µ�ѧ�ſ϶�û����ͬ����
		//����
		int  stu_no;			//ѧ��
		char stu_name[MAX_NAME_LEN];	//����
		char no;
		for (int j = 0; j < MAX_STU_NUM - 1; j++) {
			for (int i = 0; i < MAX_STU_NUM - (j + 1); i++) {
				if (stu[i].stu_no > stu[i + 1].stu_no) {
					stu_no = stu[i].stu_no;
					stu[i].stu_no = stu[i + 1].stu_no;
					stu[i + 1].stu_no = stu_no;

					strncpy(stu_name, stu[i].stu_name, MAX_NAME_LEN);
					strncpy(stu[i].stu_name, stu[i + 1].stu_name, MAX_NAME_LEN);
					strncpy(stu[i + 1].stu_name, stu_name, MAX_NAME_LEN);

					no = stu[i].no1;
					stu[i].no1 = stu[i + 1].no1;
					stu[i + 1].no1 = no;

					no = stu[i].no2;
					stu[i].no2 = stu[i + 1].no2;
					stu[i + 1].no2 = no;

				}
			}
		}
	}
	return 0;
}
void stu_list::print(const char* prompt) 
{
	cout << "����ѡ������" << endl;
	cout << "===========================================" << endl;
	cout << "��� ѧ��    ����             ��һ�� �ڶ���" << endl;
	cout << "===========================================" << endl;
	int a = 1;
	for (int i = 0; i < MAX_STU_NUM; i++) {
		if (stu[i].stu_no > 0) {
			cout << setiosflags(ios::left) << setw(5) << a << setw(8) << stu[i].stu_no << setw(17) << stu[i].stu_name;
			if (stu[i].no1 == 'Y' && stu[i].no2 == 'Y')
				cout << setw(7) << stu[i].no1 << stu[i].no2;
			else if (stu[i].no1 == 'Y' && stu[i].no2 == '/')
				cout << setw(7) << stu[i].no1 << "�˿�";
			else if (stu[i].no1 == '/' && stu[i].no2 == 'Y')
				cout << setw(7) << stu[i].no1 << "��ѡ";
			a++;
			cout << endl;
		}

	}
	cout << "===========================================" << endl;

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
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}