/* 2151299 �ռ��� ��16 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;

	gets_s(str);
	for (p = str,pa = a,is_num=false; *p != '\0'; p++){

		if (*p >= '0' && *p <= '9')
			is_num = true;		
		else
			is_num = false;

		if (is_num) {//����ַ�������
			*pa = *pa * 10 + *p - '0';			
		}	
		//������һ���ַ��ǲ�������
		p++;
		if (!(*p >= '0' && *p <= '9')) {
			pa++;
		}
		p--;//������		
	}

	cout << "����" << pa - a  << "������" << endl;
	pnum = a;
	while (pa > pnum)
		cout << *pnum++ << " ";
	cout << endl;
	return 0;
}
