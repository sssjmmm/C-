/*2151299 ��16 �ռ���*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
 int main()
{
     double a, sy, y, qw, bw, sw, h, w, q, b, s, g, j, o, f;

     printf("������[0..100 ��)֮�������:\n");
     scanf("%lf", &a);
     printf("��д�����:\n");
     sy = (int)(a / 1000000000);
     y = (int)((a - sy * 1000000000) / 100000000);
     qw = (int)((a - sy * 1000000000 - y * 100000000) / 10000000);
     bw = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000) / 1000000);
     sw = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000) / 100000);
     w = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000) / 10000);
     q = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000) / 1000);
     b = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000) / 100);
     s = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100) / 10);
     g = (int)((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10) / 1);
     h = a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10 - g * 1;
     o = h * 100.001;
     j = (int)(o / 10);
     f = (int)(o - j * 10);
    //ʮ�ڵ��ڣ�
    if (sy == 1)
        printf("Ҽʰ");
    else if (sy == 2)
        printf("��ʰ");
    else if (sy == 3)
        printf("��ʰ");
    else if (sy == 4)
        printf("��ʰ");
    else if (sy == 5)
        printf("��ʰ");
    else if (sy == 6)
        printf("½ʰ");
    else if (sy == 7)
        printf("��ʰ");
    else if (sy == 8)
        printf("��ʰ");
    else if (sy == 9)
        printf("��ʰ");
    else if (sy == 0) {
        if (y == 1)
            printf("Ҽ��");
        else if (y == 2)
            printf("����");
        else if (y == 3)
            printf("����");
        else if (y == 4)
            printf("����");
        else if (y == 5)
            printf("����");
        else if (y == 6)
            printf("½��");
        else if (y == 7)
            printf("����");
        else if (y == 8)
            printf("����");
        else if (y == 9)
            printf("����");
    }
    if (y == 1 && sy != 0)
        printf("Ҽ��");
    else if (y == 2 && sy != 0)
        printf("����");
    else if (y == 3 && sy != 0)
        printf("����");
    else if (y == 4 && sy != 0)
        printf("����");
    else if (y == 5 && sy != 0)
        printf("����");
    else if (y == 6 && sy != 0)
        printf("½��");
    else if (y == 7 && sy != 0)
        printf("����");
    else if (y == 8 && sy != 0)
        printf("����");
    else if (y == 9 && sy != 0)
        printf("����");
    else if (y == 0 && sy != 0)
        printf("��");

    //ʮ��-�ڽ�������ʼ

    if (qw == 0 && bw == 0 && sw == 0 && w != 0) {  //000* 1
        if (sy != 0 || y != 0)
            printf("��");
        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");

    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ��");

    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            printf("��");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("����");

    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ��");

    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ");

        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");

    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            printf("��");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("����");

        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 

        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ��");

        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");

    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            printf("��");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ��");

    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //80*0 9 

        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ��");

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10

        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("����");

    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11

        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ��");
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("����");
        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ");
        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            printf("��");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ");
        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        if (qw == 1)
            printf("Ҽ");
        else if (qw == 2)
            printf("��");
        else if (qw == 3)
            printf("��");
        else if (qw == 4)
            printf("��");
        else if (qw == 5)
            printf("��");
        else if (qw == 6)
            printf("½");
        else if (qw == 7)
            printf("��");
        else if (qw == 8)
            printf("��");
        else if (qw == 9)
            printf("��");
        printf("Ǫ");
        if (bw == 1)
            printf("Ҽ");
        else if (bw == 2)
            printf("��");
        else if (bw == 3)
            printf("��");
        else if (bw == 4)
            printf("��");
        else if (bw == 5)
            printf("��");
        else if (bw == 6)
            printf("½");
        else if (bw == 7)
            printf("��");
        else if (bw == 8)
            printf("��");
        else if (bw == 9)
            printf("��");
        printf("��");
        if (sw == 1)
            printf("Ҽ");
        else if (sw == 2)
            printf("��");
        else if (sw == 3)
            printf("��");
        else if (sw == 4)
            printf("��");
        else if (sw == 5)
            printf("��");
        else if (sw == 6)
            printf("½");
        else if (sw == 7)
            printf("��");
        else if (sw == 8)
            printf("��");
        else if (sw == 9)
            printf("��");
        printf("ʰ");
        if (w == 1)
            printf("Ҽ");
        else if (w == 2)
            printf("��");
        else if (w == 3)
            printf("��");
        else if (w == 4)
            printf("��");
        else if (w == 5)
            printf("��");
        else if (w == 6)
            printf("½");
        else if (w == 7)
            printf("��");
        else if (w == 8)
            printf("��");
        else if (w == 9)
            printf("��");
        printf("��");
    }





    //����� ��ʼǧ
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 14
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 13
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 12
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ");
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 11
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
    }

    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 10
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("����");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }

    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 9
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 8
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7
        if (q == 1)
            printf("Ҽ");
        else if (q == 2)
            printf("��");
        else if (q == 3)
            printf("��");
        else if (q == 4)
            printf("��");
        else if (q == 5)
            printf("��");
        else if (q == 6)
            printf("½");
        else if (q == 7)
            printf("��");
        else if (q == 8)
            printf("��");
        else if (q == 9)
            printf("��");
        printf("Ǫ��");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q == 0 && b == 0 && s == 0 && g != 0) {  //000* 6
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 4
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("����");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            printf("��");
        if (s == 1)
            printf("Ҽ");
        else if (s == 2)
            printf("��");
        else if (s == 3)
            printf("��");
        else if (s == 4)
            printf("��");
        else if (s == 5)
            printf("��");
        else if (s == 6)
            printf("½");
        else if (s == 7)
            printf("��");
        else if (s == 8)
            printf("��");
        else if (s == 9)
            printf("��");
        printf("ʰ");
        if (g == 1)
            printf("Ҽ");
        else if (g == 2)
            printf("��");
        else if (g == 3)
            printf("��");
        else if (g == 4)
            printf("��");
        else if (g == 5)
            printf("��");
        else if (g == 6)
            printf("½");
        else if (g == 7)
            printf("��");
        else if (g == 8)
            printf("��");
        else if (g == 9)
            printf("��");
    }

    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f)
        printf("��Բ");


    //ǧ�������Ƿֿ�ʼ
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) {
        printf("Բ");
    }
    if (sy && y && qw && bw && w && sw && q && b && s && g && j == 0 && f != 0)
        printf("��");
    if (j == 1)
        printf("Ҽ��");
    else if (j == 2)
        printf("����");
    else if (j == 3)
        printf("����");
    else if (j == 4)
        printf("����");
    else if (j == 5)
        printf("���");
    else if (j == 6)
        printf("½��");
    else if (j == 7)
        printf("���");
    else if (j == 8)
        printf("�ƽ�");
    else if (j == 9)
        printf("����");
    else if (j == 0) {
        if (f == 1)
            printf("Ҽ��");
        else if (f == 2)
            printf("����");
        else if (f == 3)
            printf("����");
        else if (f == 4)
            printf("����");
        else if (f == 5)
            printf("���");
        else if (f == 6)
            printf("½��");
        else if (f == 7)
            printf("���");
        else if (f == 8)
            printf("�Ʒ�");
        else if (f == 9)
            printf("����");
        else if (f == 0)
            printf("��");
    }

    if (f == 1 && j != 0)
        printf("Ҽ��");
    else if (f == 2 && j != 0)
        printf("����");
    else if (f == 3 && j != 0)
        printf("����");
    else if (f == 4 && j != 0)
        printf("����");
    else if (f == 5 && j != 0)
        printf("���");
    else if (f == 6 && j != 0)
        printf("½��");
    else if (f == 7 && j != 0)
        printf("���");
    else if (f == 8 && j != 0)
        printf("�Ʒ�");
    else if (f == 9 && j != 0)
        printf("����");
    else if (f == 0 && j != 0)
        printf("��");

    return 0;
}