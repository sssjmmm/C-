/* ��16 2151299 �ռ��� */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
    /* ������Ա��������κ��޸� */
    switch (num) {
    case 0:
        if (flag_of_zero) 	//�˱��ʲô��˼������˼��
            result = result + chnstr[0]+ chnstr[1];
        break;
    case 1:
        result = result + chnstr[2] + chnstr[3];
        break;
    case 2:
        result = result + chnstr[4] + chnstr[5];
        break;
    case 3:
        result = result + chnstr[6] + chnstr[7];
        break;
    case 4:
        result = result + chnstr[8] + chnstr[9];
        break;
    case 5:
        result = result + chnstr[10] + chnstr[11];
        break;
    case 6:
        result = result + chnstr[12] + chnstr[13];
        break;
    case 7:
        result = result + chnstr[14] + chnstr[15];
        break;
    case 8:
        result = result + chnstr[16] + chnstr[17];
        break;
    case 9:
        result = result + chnstr[18] + chnstr[19];
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
    cout << "������[0-100��)֮�������:" << endl;
    cin >> a;
    cout << "��д�����:" << endl;
    sy = int(a / 1000000000);
    y = int((a - sy * 1000000000) / 100000000);
    qw = int((a - sy * 1000000000 - y * 100000000) / 10000000);
    bw = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000) / 1000000);
    sw = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000) / 100000);
    w = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000) / 10000);
    q = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000) / 1000);
    b = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000) / 100);
    s = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100) / 10);
    g = int((a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10) / 1);
    h = a - sy * 1000000000 - y * 100000000 - qw * 10000000 - bw * 1000000 - sw * 100000 - w * 10000 - q * 1000 - b * 100 - s * 10 - g * 1;
    o = h * 100.001;
    j = int(o / 10);
    f = int(o - j * 10);

    //ʮ��-��
    daxie(int(sy), 0);
    if (sy != 0)
        result=result+shi;
    daxie(int(y), 0);
    if (sy != 0 || y != 0)
        result=result+yi;
    //�ڽ�������ʼ
    if (qw == 0 && bw == 0 && sw == 0 && w != 0) { //000* 1
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        result=result+shi; 
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        daxie(int(qw), 0);
        result=result+qian;
        result=result+wan;
    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 1);
        daxie(int(w), 0);
        result=result+wan;

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi; 
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //*0*0 9 
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        result=result+wan;

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 1);
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        daxie(int(qw), 0);
        result=result+qian;
        daxie(int(bw), 0);
        result=result+bai;
        daxie(int(sw), 0);
        result=result+shi;
        daxie(int(w), 0);
        result=result+wan;
    }
    //�������ǧ��ʼ
    if (q == 0 && b == 0 && s == 0 && g != 0) { //000* 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 3 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 4 
        daxie(int(q), 0);
        result=result+qian;
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 5 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 6 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7 
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 8 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 9 
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(s), 0);
        result=result+shi;

    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 10
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 11
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
    }
    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 12
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 13
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 1);
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 14
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        daxie(int(q), 0);
        result=result+qian;
        daxie(int(b), 0);
        result=result+bai;
        daxie(int(s), 0);
        result=result+shi;
        daxie(int(g), 0);
    }
    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f) {
        daxie(int(g), 1);
        result=result+yuan;
    }
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0)
        result=result+yuan;
    //  ǧ��Բ�������Ƿֿ�ʼ
    if ((sy || y || qw || bw || w || sw || q || b || s || g) && !j && f)
        daxie(int(j), 1);
    if (!j && !f)
        result=result+zheng;
    if (!j && f) {
        daxie(int(f), 0);
        result=result+fen;
    }
    if (j && !f) {
        daxie(int(j), 0);
        result=result+jiao; 
        result=result+zheng;
    }
    if (j && f) {
        daxie(int(j), 0);
        result=result+jiao;
        daxie(int(f), 0);
        result=result+fen;
    }

    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}