/* 2151299 �ռ��� ��16 */
#include <iostream>
#include <cstdio>
using namespace std;
#define N 80

bool judge(char *a) {
	char *pa=a,*pb=a;
	while (*pb != '\0')
		pb++;
	pb -= 2;//��pbָ�����һ���ǻس��ַ�
	for (int k=0;k<(int(strlen(a))/2); k++) {
		if (*pa != *pb) {
			return false;
		}
		else {
			pa++;
			pb--;
		}
	}
	return true;

}
int main() {
	char str[N+2];
	bool out;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, N, stdin);
	out=judge(str);
	if (out)
		cout << "yes" << endl;
	else if (!out)
		cout << "no" << endl;
	return 0;
}