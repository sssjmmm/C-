/* ��16 2151299 �ռ��� */
#define _CRT_SECURE_NO_WARNINGS  //VS2019��Ҫ
#include <string.h>
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
    char temp[] = " ";
    /* ������Ա��������κ��޸� */
    switch (num) {
    case 0:
        if (flag_of_zero)	//�˱��ʲô��˼������˼��
            strncat(result, chnstr,2);
        break;
    case 1:
        temp[0] = chnstr[2];
        temp[1] = chnstr[3];
        strncat(result, temp, 2);
        break;
    case 2:
        temp[0] = chnstr[4];
        temp[1] = chnstr[5];
        strncat(result, temp, 2);
        break;
    case 3:
        temp[0] = chnstr[6];
        temp[1] = chnstr[7];
        strncat(result, temp, 2);
        break;
    case 4:
        temp[0] = chnstr[8];
        temp[1] = chnstr[9];
        strncat(result, temp, 2);
        break;
    case 5:
        temp[0] = chnstr[10];
        temp[1] = chnstr[11];
        strncat(result, temp, 2);
        break;
    case 6:
        temp[0] = chnstr[12];
        temp[1] = chnstr[13];
        strncat(result, temp, 2);
        break;
    case 7:
        temp[0] = chnstr[14];
        temp[1] = chnstr[15];
        strncat(result, temp, 2);
        break;
    case 8:
        temp[0] = chnstr[16];
        temp[1] = chnstr[17];
        strncat(result, temp, 2);
        break;
    case 9:
        temp[0] = chnstr[18];
        temp[1] = chnstr[19];
        strncat(result, temp, 2);
        break;
    default:
        break;
    }
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
    double a, o, h, sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    char shi[] = { "ʰ" };
    char bai[] = { "��" };
    char qian[] = { "Ǫ" };
    char wan[] = { "��" };
    char yi[] = { "��" };
    char yuan[] = { "Բ" };
    char jiao[] = { "��" };
    char fen[] = { "��" };
    char zheng[] = { "��" };
    printf("������[0-100��)֮�������:\n");
    scanf("%lf",&a);
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

    //ʮ��-��
    daxie((int)(sy), 0);
    if (sy != 0)
        strcat(result,shi);
    daxie((int)(y), 0);
    if (sy != 0 || y != 0)
        strcat(result,yi);
    //�ڽ�������ʼ
    if (qw == 0 && bw == 0 && sw == 0 && w != 0) { //000* 1
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(sw), 0);
        strcat(result,shi);
        strcat(result,wan);
    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(bw), 0);
        strcat(result,bai);
        strcat(result,wan);
    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        daxie((int)(qw), 0);
        strcat(result,qian);
        strcat(result,wan);
    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(sw), 0);
        strcat(result,shi);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 1);
        daxie((int)(w), 0);
        strcat(result,wan);

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 1);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 0);
        strcat(result,shi);
        strcat(result,wan);
    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //*0*0 9 
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 1);
        daxie((int)(sw), 0);
        strcat(result,shi);
        strcat(result,wan);

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 0);
        strcat(result,bai);
        strcat(result,wan);
    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 0);
        strcat(result,shi);
        strcat(result,wan);
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 1);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 1);
        daxie((int)(sw), 0);
        strcat(result,shi);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            daxie((int)(qw), 1);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 0);
        strcat(result,shi);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        daxie((int)(qw), 0);
        strcat(result,qian);
        daxie((int)(bw), 0);
        strcat(result,bai);
        daxie((int)(sw), 0);
        strcat(result,shi);
        daxie((int)(w), 0);
        strcat(result,wan);
    }
    //�������ǧ��ʼ
    if (q == 0 && b == 0 && s == 0 && g != 0) { //000* 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(g), 0);
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(s), 0);
        strcat(result,shi);
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 3 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(b), 0);
        strcat(result,bai);
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 4 
        daxie((int)(q), 0);
        strcat(result,qian);
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 5 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(s), 0);
        strcat(result,shi);
        daxie((int)(g), 0);
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 6 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 1);
        daxie((int)(g), 0);
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7 
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 1);
        daxie((int)(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 8 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 0);
        strcat(result,shi);
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 9 
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 1);
        daxie((int)(s), 0);
        strcat(result,shi);

    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 10
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 0);
        strcat(result,bai);
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 11
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 0);
        strcat(result,shi);
    }
    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 12
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 1);
        daxie((int)(g), 0);
    }
    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 13
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 1);
        daxie((int)(s), 0);
        strcat(result,shi);
        daxie((int)(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 14
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie((int)(q), 1);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 0);
        strcat(result,shi);
        daxie((int)(g), 0);
    }
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        daxie((int)(q), 0);
        strcat(result,qian);
        daxie((int)(b), 0);
        strcat(result,bai);
        daxie((int)(s), 0);
        strcat(result,shi);
        daxie((int)(g), 0);
    }
    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f) {
        daxie((int)(g), 1);
        strcat(result,yuan);
    }
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0)
        strcat(result,yuan);
    //  ǧ��Բ�������Ƿֿ�ʼ
    if ((sy || y || qw || bw || w || sw || q || b || s || g) && !j && f)
        daxie((int)(j), 1);
    if (!j && !f)
        strcat(result,zheng);
    if (!j && f) {
        daxie((int)(f), 0);
        strcat(result,fen);
    }
    if (j && !f) {
        daxie((int)(j), 0);
        strcat(result,jiao);
        strcat(result,zheng);
    }
    if (j && f) {
        daxie((int)(j), 0);
        strcat(result,jiao);
        daxie((int)(f), 0);
        strcat(result,fen);
    }

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}