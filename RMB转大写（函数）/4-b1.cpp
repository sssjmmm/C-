/* 2151299 �ռ��� ��16 */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double a, o, h,sy, y, qw, bw, sw, w, q, b, s, g, j, f;

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
	if(sy!=0)
	    cout << "ʰ";
	daxie(int(y),0);
	if(sy!=0||y!=0)
	    cout << "��";
	//�ڽ�������ʼ
	if (qw == 0 && bw == 0 && sw == 0 && w != 0) { //000* 1
		if (sy != 0 || y != 0)
			daxie(int(qw), 1);
		daxie(int(w), 0);
        cout << "��";
	}
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        cout << "ʰ��";
    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "����";
    }
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        daxie(int(qw), 0);
        cout << "Ǫ��";
    }
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(sw), 0);
        cout << "ʰ";
        daxie(int(w), 0);
        cout << "��";
    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 1);
        daxie(int(w), 0);
        cout << "��";

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 1);
        daxie(int(w), 0);
        cout << "��";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 0);
        cout << "ʰ��";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //*0*0 9 
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        cout << "ʰ��";

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 0);
        cout << "����";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 0);
        cout << "ʰ��";
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 1);
        daxie(int(w), 0);
        cout << "��";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 1);
        daxie(int(sw), 0);
        cout << "ʰ";
        daxie(int(w), 0);
        cout << "��";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
        if (sy != 0 || y != 0)
            daxie(int(qw), 1);
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 0);
        cout << "ʰ";
        daxie(int(w), 0);
        cout << "��";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
        daxie(int(qw), 0);
        cout << "Ǫ";
        daxie(int(bw), 0);
        cout << "��";
        daxie(int(sw), 0);
        cout << "ʰ";
        daxie(int(w), 0);
        cout << "��";
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
        cout << "ʰ";
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 3 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "��";
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 4 
        daxie(int(q), 0);
        cout << "Ǫ";
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 5 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(s), 0);
        cout << "ʰ";
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 6 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7 
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 1);
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 8 
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 0);
        cout << "ʰ";
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 9 
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 1);
        daxie(int(s), 0);
        cout << "ʰ";

    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 10
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 0);
        cout << "��";
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 11
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 0);
        cout << "ʰ";
    }
    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 12
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 1);
        daxie(int(g), 0);
    }
    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 13
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 1);
        daxie(int(s), 0);
        cout << "ʰ";
        daxie(int(g), 0);
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 14
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            daxie(int(q), 1);
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 0);
        cout << "ʰ";
        daxie(int(g), 0);
    }
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        daxie(int(q), 0);
        cout << "Ǫ";
        daxie(int(b), 0);
        cout << "��";
        daxie(int(s), 0);
        cout << "ʰ";
        daxie(int(g), 0);
    }
    if (!sy && !y && !qw && !bw && !w && !sw && !q && !b && !s && !g && !j && !f) {
        daxie(int(g), 1);
        cout << "Բ";
    }
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) 
        cout << "Բ";
    //  ǧ��Բ�������Ƿֿ�ʼ
    if ((sy || y || qw || bw || w || sw || q || b || s || g) && !j && f)
        daxie(int(j), 1);
    if (!j && !f)
        cout << "��";
    if (!j && f) {
        daxie(int(f), 0);
        cout << "��";
    }
    if (j && !f) {
        daxie(int(j), 0);
        cout << "����";
    }
    if (j && f) {
        daxie(int(j), 0);
        cout << "��";
        daxie(int(f), 0);
        cout << "��";
    }
    cout << endl;

	/* ������� */
	return 0;
}