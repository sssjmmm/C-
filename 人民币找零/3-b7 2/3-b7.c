/*2151299 ��16 �ռ���*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 int main() 
{
	double a, b, c, d, e, f, g, h, i, j, k;
	int x;
	printf( "����������ֵ��\n");
	scanf("%lf", &a);
	b = (int)(a / 50);
	c = (int)((a - b * 50) / 20);
	d = (int)((a - b * 50 - c * 20) / 10);
	e = (int)((a - b * 50 - c * 20 - d * 10) / 5);
	f = (int)((a - b * 50 - c * 20 - d * 10 - e * 5) / 1);
	g = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1) / 0.5);
	h = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5) / 0.1);
	i = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1) / 0.05);
	j = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1 - i * 0.05) / 0.02);
	k = (int)((a - b * 50 - c * 20 - d * 10 - e * 5 - f * 1 - g * 0.5 - h * 0.1 - i * 0.05 - j * 0.02) / 0.01);
	x = b + c + d + e + f + g + h + i + j + k;
	printf("��%d�����㣬�������£�\n",x);
	if (b)
		printf("50Ԫ : %d��\n" , (int)b);
	if (c)
		printf("20Ԫ : %d��\n" , (int)c);
	if (d)
		printf("10Ԫ : %d��\n" , (int)d);
	if (e)
		printf("5Ԫ  : %d��\n" , (int)e);
	if (f)
		printf("1Ԫ  : %d��\n" , (int)f);
	if (g)
		printf("5��  : %d��\n" , (int)g);
	if (h)
		printf("1��  : %d��\n" , (int)h);
	if (i)
		printf("5��  : %d��\n" , (int)i);
	if (j)
		printf("2��  : %d��\n" , (int)j);
	if (k)
		printf("1��  : %d��\n" , (int)k);

	return 0;
}
