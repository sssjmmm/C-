/* 2151299 �ռ��� ��16 */
#include <iostream>
#include<cmath>
using namespace std;
#define N 32
int main() {
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	char bin[N + 1], * p1=bin;
	unsigned int oct=0;

	cin >> p1;
	while (*p1 != '\0')
		p1++;
	p1 -= 1;//��pbָ�����һ���ַ�
	for (int k=0; p1>=bin; p1--,k++) {
		oct = (*p1 - 48) *int (pow(2, k)) + oct;
	}
	cout << oct << endl;
	return 0;
}
