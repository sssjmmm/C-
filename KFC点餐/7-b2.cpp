/*2151299 �ռ��� ��16*/
#include <cstdio> 
#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

int jishuqi(char a[], char ch, int len);
int jishuqi2(const char a[], char ch, int len);
struct KFC {
	const char zimu;
	const char name[20];
	double pay;
};
struct SPECIAL {
	const char mix[27];
	const char name[30];
	double pay2;
};
const struct KFC list[] = {
	{'A', "��԰���ȱ�",         18.5},
	{'B', "���ռ��ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "��������",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ƽ���ǹ����(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "ƻ����",         9.0},
	{'U', "��̢",           8.0},
	{'V', "�ɿڿ���(С)",       7.0},
	{'W', "�ɿڿ���(��)",       9.5},
	{'X', "�ɿڿ���(��)",       11.5},
	{'Y', "��֭",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};

const struct SPECIAL special[] = {
	//	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};
void menu() {
	cout << "=============================================================" << endl;
	cout << "                      KFC 2021�＾�˵�" << endl;
	cout << "=============================================================" << endl;
	cout << setiosflags(ios::left);
	for (int i = 0; i < 26; i+=2) {
		cout << " " << list[i].zimu << " " << setw(20) << list[i].name << setw(5) << list[i].pay ;
		cout << " | ";
		cout << " " << list[i+1].zimu << " " << setw(20) << list[i+1].name << setw(5) << list[i+1].pay<<endl ;
	}
	cout << endl;
	cout << "���Ż���Ϣ����" << endl;
	for (int i = 0; special[i].pay2 != 0; i++) {
		cout << special[i].name<<"=" ;
		for (int j = 0; j < 26; j++) {
			if ((jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix)) >= 2)) {
				cout << list[j].name << "*" << (jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix))) << " ";
			}
			else if ((jishuqi2(special[i].mix, list[j].zimu, strlen(special[i].mix))) == 1) {
				cout << list[j].name << " ";
			}
		}
		cout << "ֻ��" << special[i].pay2 << "Ԫ��" <<endl;
	}
	cout << endl;
	cout << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl << endl;;
	cout << "��㵥:";
}
bool input_order (char a[]) {
	char ch;
	cin.getline(a,100);
	for (int i = 0; a[i]!=0; i++) {
		if (a[i] >= 97 && a[i] <= 122)
			a[i] -= 32;
		else if(!(a[i] >= 97 && a[i] <= 122)&&!(a[i] >= 65 && a[i] <= 97)) {
			if (!(a[1] == '\0' && a[0] == '0')) {
				cout << "������󣬰����������." << endl;
				ch = _getch();
			}
			return false;
		}
	}
	return true;
}
void count(char a[],double *sum,int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] >= 65 && a[i] <= 97) {
			for (int j = 0; j < 26; j++) {
				if (a[i] == list[j].zimu) {
					*sum = *sum + list[j].pay;
					a[i] = 0;
					break;
				}
			}
		}
	}
}

void count0(char a[], double* sum, int len) {
	char temp[100] = { -1 };
	for (int i = 0; i < 100; i++) {
		temp[i] = -1;
	}
	int lenth = 0;
	for (int i = 0; special[i].pay2!=0;i++) {//Ѱ����ͬ�ַ���mix
		bool P=true;
		while (P) {
			for (int j = 0; special[i].mix[j] != '\0'; j++) {//mix�е�Ӣ����ĸ

				for (int k = 0; k < len; k++) {//a[k]
					if (a[k] == special[i].mix[j]) {
						lenth++;
						temp[k] = a[k];//a��i
						a[k] = i;
						break;
					}
				}
			}
			/*111111111111111111111111111111*/
			if (lenth == strlen(special[i].mix)) {//�������Ż���Ĵ��ھ�
				*sum = *sum + special[i].pay2;//sumҪ�ӣ���Ҫ���Żݷ�������ĸ��1
			}//��1����
			else if (lenth != strlen(special[i].mix)) {//������Ҫ�ҵ��Żݣ��Ͱ���ĸ����ȥ
				for (int m = 0; m < 100; m++) {
					if (a[m] == i) {
						a[m] = temp[m];
					}
				}
			}
			/*111111111111111111111111111111*/
			lenth = 0;
			//ѭ����������˵�����û�ж����Ż�
			char b[100];
			for (int i = 0; i < len; i++) {
				b[i] = a[i];
			}
			for (int j = 0; special[i].mix[j] != '\0'; j++) {//mix�е�Ӣ����ĸ

				for (int k = 0; k < len; k++) {//a[k]
					if (b[k] == special[i].mix[j]) {
						lenth++;
						b[k] = 0;
						break;
					}
				}
			}
			/*111111111111111111111111111111*/
			if (lenth != strlen(special[i].mix)) {//�������Ż���Ĵ��ھ�
				lenth = 0;
				break;
			}
			lenth = 0;

		}
		
	}

}
void output1(char a[], int len) {
	cout << "���ĵ��=";
	for (int j = 0; j < 26; j++) {
		if ((jishuqi(a, list[j].zimu, len)) >= 2) {
			cout << list[j].name << "*" << (jishuqi(a, list[j].zimu, len))<<" ";
		}
		else if ((jishuqi(a, list[j].zimu, len)) == 1) {
			cout << list[j].name<<" ";
		}
	}
	cout << endl;
}
int jishuqi(char a[],char ch, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == ch) {
			count++;
		}
	}
	return count;
}
int jishuqi2(const char a[], char ch, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == ch) {
			count++;
		}
	}
	return count;
}
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}
int main() {
	while (1) {
		bool T;
		double sum = 0;
		char order[100] = {0};
		int len = 0;
		system("cls");
		system("mode con cols=120 lines=35");//35�� 120��
		menu();
		T=input_order(order);
		len = strlen(order);
		if (len == 1 && order[0] == '0')
			return 0;
		if (T) {
			output1(order, len);
			//ok
			count0(order, &sum, len);//�Żݷ�������
			count(order, &sum, len);
			cout << "���ƣ�" << sum << "Ԫ" << endl;
			wait_for_enter();
		}
	}
	return 0;
}