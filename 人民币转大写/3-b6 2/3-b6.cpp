/*2151299 ��16 �ռ���*/
#include <iostream>
using namespace std;
int main()
{
	double a, sy, y, qw, bw, sw, h, w, q, b, s, g, j, o, f;

	cout << "������[0..100 ��)֮�������:" << endl;
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
	//ʮ�ڵ��ڣ�
	if (sy == 1)
		cout << "Ҽʰ";
	else if (sy == 2)
		cout << "��ʰ";
	else if (sy == 3)
		cout << "��ʰ";
	else if (sy == 4)
		cout << "��ʰ";
	else if (sy == 5)
		cout << "��ʰ";
	else if (sy == 6)
		cout << "½ʰ";
	else if (sy == 7)
		cout << "��ʰ";
	else if (sy == 8)
		cout << "��ʰ";
	else if (sy == 9)
		cout << "��ʰ";
	else if (sy == 0) {
		if (y == 1)
			cout << "Ҽ��";
		else if (y == 2)
			cout << "����";
		else if (y == 3)
			cout << "����";
		else if (y == 4)
			cout << "����";
		else if (y == 5)
			cout << "����";
		else if (y == 6)
			cout << "½��";
		else if (y == 7)
			cout << "����";
		else if (y == 8)
			cout << "����";
		else if (y == 9)
			cout << "����";
	}
	if (y == 1 && sy != 0)
		cout << "Ҽ��";
	else if (y == 2 && sy != 0)
		cout << "����";
	else if (y == 3 && sy != 0)
		cout << "����";
	else if (y == 4 && sy != 0)
		cout << "����";
	else if (y == 5 && sy != 0)
		cout << "����";
	else if (y == 6 && sy != 0)
		cout << "½��";
	else if (y == 7 && sy != 0)
		cout << "����";
	else if (y == 8 && sy != 0)
		cout << "����";
	else if (y == 9 && sy != 0)
		cout << "����";
	else if (y == 0 && sy != 0)
		cout << "��";

	//ʮ��-�ڽ�������ʼ
    
    if (qw == 0 && bw == 0 && sw == 0 && w != 0) {  //000* 1
        if (sy != 0 || y != 0)
            cout << "��";
        if (w == 1)
            cout << "Ҽ";
        else if (w == 2)
            cout << "��";
        else if (w == 3)
            cout << "��";
        else if (w == 4)
            cout << "��";
        else if (w == 5)
            cout << "��";
        else if (w == 6)
            cout << "½";
        else if (w == 7)
            cout << "��";
        else if (w == 8)
            cout << "��";
        else if (w == 9)
            cout << "��";
        cout << "��";
       
    }
    if (qw == 0 && bw == 0 && sw != 0 && w == 0) {  //00*0 2
        if (sy != 0 || y != 0)
            cout << "��";
        if (sw == 1)
            cout << "Ҽ";
        else if (sw == 2)
            cout << "��";
        else if (sw == 3)
            cout << "��";
        else if (sw == 4)
            cout << "��";
        else if (sw == 5)
            cout << "��";
        else if (sw == 6)
            cout << "½";
        else if (sw == 7)
            cout << "��";
        else if (sw == 8)
            cout << "��";
        else if (sw == 9)
            cout << "��";
        cout << "ʰ��";

    }
    if (qw == 0 && bw != 0 && sw == 0 && w == 0) {  //0*00 3 
        if (sy != 0 || y != 0)
            cout << "��";
        if (bw == 1)
            cout << "Ҽ";
        else if (bw == 2)
            cout << "��";
        else if (bw == 3)
            cout << "��";
        else if (bw == 4)
            cout << "��";
        else if (bw == 5)
            cout << "��";
        else if (bw == 6)
            cout << "½";
        else if (bw == 7)
            cout << "��";
        else if (bw == 8)
            cout << "��";
        else if (bw == 9)
            cout << "��";
        cout << "����";

    }        
    if (qw != 0 && bw == 0 && sw == 0 && w == 0) {  //*000 4 
        if (qw == 1)
            cout << "Ҽ";
        else if (qw == 2)
            cout << "��";
        else if (qw == 3)
            cout << "��";
        else if (qw == 4)
            cout << "��";
        else if (qw == 5)
            cout << "��";
        else if (qw == 6)
            cout << "½";
        else if (qw == 7)
            cout << "��";
        else if (qw == 8)
            cout << "��";
        else if (qw == 9)
            cout << "��";
        cout << "Ǫ��";

    }        
    if (qw == 0 && bw == 0 && sw != 0 && w != 0) {  //00** 5 
        if (sy != 0 || y != 0)
            cout << "��";
        if (sw == 1)
            cout << "Ҽ";
        else if (sw == 2)
            cout << "��";
        else if (sw == 3)
            cout << "��";
        else if (sw == 4)
            cout << "��";
        else if (sw == 5)
            cout << "��";
        else if (sw == 6)
            cout << "½";
        else if (sw == 7)
            cout << "��";
        else if (sw == 8)
            cout << "��";
        else if (sw == 9)
            cout << "��";
        cout << "ʰ";

        if (w == 1)
            cout << "Ҽ";
        else if (w == 2)
            cout << "��";
        else if (w == 3)
            cout << "��";
        else if (w == 4)
            cout << "��";
        else if (w == 5)
            cout << "��";
        else if (w == 6)
            cout << "½";
        else if (w == 7)
            cout << "��";
        else if (w == 8)
            cout << "��";
        else if (w == 9)
            cout << "��";
        cout << "��";

    }
    if (qw == 0 && bw != 0 && sw == 0 && w != 0) {  //0*0* 6 
        if (sy != 0 || y != 0)
            cout << "��";
        if (bw == 1)
            cout << "Ҽ";
        else if (bw == 2)
            cout << "��";
        else if (bw == 3)
            cout << "��";
        else if (bw == 4)
            cout << "��";
        else if (bw == 5)
            cout << "��";
        else if (bw == 6)
            cout << "½";
        else if (bw == 7)
            cout << "��";
        else if (bw == 8)
            cout << "��";
        else if (bw == 9)
            cout << "��";
        cout << "����";

        if (w == 1)
            cout << "Ҽ";
        else if (w == 2)
            cout << "��";
        else if (w == 3)
            cout << "��";
        else if (w == 4)
            cout << "��";
        else if (w == 5)
            cout << "��";
        else if (w == 6)
            cout << "½";
        else if (w == 7)
            cout << "��";
        else if (w == 8)
            cout << "��";
        else if (w == 9)
            cout << "��";
        cout << "��";

    }
    if (qw != 0 && bw == 0 && sw == 0 && w != 0) {  //*00* 7 

        if (qw == 1)
            cout << "Ҽ";
        else if (qw == 2)
            cout << "��";
        else if (qw == 3)
            cout << "��";
        else if (qw == 4)
            cout << "��";
        else if (qw == 5)
            cout << "��";
        else if (qw == 6)
            cout << "½";
        else if (qw == 7)
            cout << "��";
        else if (qw == 8)
            cout << "��";
        else if (qw == 9)
            cout << "��";
        cout << "Ǫ��";

        if (w == 1)
            cout << "Ҽ";
        else if (w == 2)
            cout << "��";
        else if (w == 3)
            cout << "��";
        else if (w == 4)
            cout << "��";
        else if (w == 5)
            cout << "��";
        else if (w == 6)
            cout << "½";
        else if (w == 7)
            cout << "��";
        else if (w == 8)
            cout << "��";
        else if (w == 9)
            cout << "��";
        cout << "��";

    }
    if (qw == 0 && bw != 0 && sw != 0 && w == 0) {  //0**0 8 
         if (sy != 0 || y != 0)
             cout << "��";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ��";

    }
    if (qw != 0 && bw == 0 && sw != 0 && w == 0) {  //80*0 9 

         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ��";

    }
    if (qw != 0 && bw != 0 && sw == 0 && w == 0) {  //**00 10

         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "����";

    }
    if (qw != 0 && bw != 0 && sw != 0 && w == 0) {  //***0 11

         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ��";
    }
    if (qw != 0 && bw != 0 && sw == 0 && w != 0) {  //**0* 12
         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "����";
         if (w == 1)
             cout << "Ҽ";
         else if (w == 2)
             cout << "��";
         else if (w == 3)
             cout << "��";
         else if (w == 4)
             cout << "��";
         else if (w == 5)
             cout << "��";
         else if (w == 6)
             cout << "½";
         else if (w == 7)
             cout << "��";
         else if (w == 8)
             cout << "��";
         else if (w == 9)
             cout << "��";
         cout << "��";
    }
    if (qw != 0 && bw == 0 && sw != 0 && w != 0) {  //*0** 13
         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ";
         if (w == 1)
             cout << "Ҽ";
         else if (w == 2)
             cout << "��";
         else if (w == 3)
             cout << "��";
         else if (w == 4)
             cout << "��";
         else if (w == 5)
             cout << "��";
         else if (w == 6)
             cout << "½";
         else if (w == 7)
             cout << "��";
         else if (w == 8)
             cout << "��";
         else if (w == 9)
             cout << "��";
         cout << "��";
    }
    if (qw == 0 && bw != 0 && sw != 0 && w != 0) {  //0*** 14
         if (sy != 0 || y != 0)
             cout << "��";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ";
         if (w == 1)
             cout << "Ҽ";
         else if (w == 2)
             cout << "��";
         else if (w == 3)
             cout << "��";
         else if (w == 4)
             cout << "��";
         else if (w == 5)
             cout << "��";
         else if (w == 6)
             cout << "½";
         else if (w == 7)
             cout << "��";
         else if (w == 8)
             cout << "��";
         else if (w == 9)
             cout << "��";
         cout << "��";
    }
    if (qw != 0 && bw != 0 && sw != 0 && w != 0) {  //**** 15
         if (qw == 1)
             cout << "Ҽ";
         else if (qw == 2)
             cout << "��";
         else if (qw == 3)
             cout << "��";
         else if (qw == 4)
             cout << "��";
         else if (qw == 5)
             cout << "��";
         else if (qw == 6)
             cout << "½";
         else if (qw == 7)
             cout << "��";
         else if (qw == 8)
             cout << "��";
         else if (qw == 9)
             cout << "��";
         cout << "Ǫ";
         if (bw == 1)
             cout << "Ҽ";
         else if (bw == 2)
             cout << "��";
         else if (bw == 3)
             cout << "��";
         else if (bw == 4)
             cout << "��";
         else if (bw == 5)
             cout << "��";
         else if (bw == 6)
             cout << "½";
         else if (bw == 7)
             cout << "��";
         else if (bw == 8)
             cout << "��";
         else if (bw == 9)
             cout << "��";
         cout << "��";
         if (sw == 1)
             cout << "Ҽ";
         else if (sw == 2)
             cout << "��";
         else if (sw == 3)
             cout << "��";
         else if (sw == 4)
             cout << "��";
         else if (sw == 5)
             cout << "��";
         else if (sw == 6)
             cout << "½";
         else if (sw == 7)
             cout << "��";
         else if (sw == 8)
             cout << "��";
         else if (sw == 9)
             cout << "��";
         cout << "ʰ";
         if (w == 1)
             cout << "Ҽ";
         else if (w == 2)
             cout << "��";
         else if (w == 3)
             cout << "��";
         else if (w == 4)
             cout << "��";
         else if (w == 5)
             cout << "��";
         else if (w == 6)
             cout << "½";
         else if (w == 7)
             cout << "��";
         else if (w == 8)
             cout << "��";
         else if (w == 9)
             cout << "��";
         cout << "��";
    }
    




     //����� ��ʼǧ
    if (q != 0 && b != 0 && s != 0 && g != 0) {  //**** 15
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q != 0 && b != 0 && s != 0 && g == 0) {  //***0 14
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
    }
    if (q != 0 && b != 0 && s == 0 && g == 0) {  //**00 13
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
    }
    if (q != 0 && b == 0 && s == 0 && g == 0) {  //*000 12
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ";
    }
    if (q != 0 && b == 0 && s != 0 && g == 0) {  //*0*0 11
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
    }

    if (q != 0 && b != 0 && s == 0 && g != 0) {  //**0* 10
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "����";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }

    if (q != 0 && b == 0 && s != 0 && g != 0) {  //*0** 9
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q == 0 && b != 0 && s != 0 && g != 0) {  //0*** 8
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q != 0 && b == 0 && s == 0 && g != 0) {  //*00* 7
        if (q == 1)
            cout << "Ҽ";
        else if (q == 2)
            cout << "��";
        else if (q == 3)
            cout << "��";
        else if (q == 4)
            cout << "��";
        else if (q == 5)
            cout << "��";
        else if (q == 6)
            cout << "½";
        else if (q == 7)
            cout << "��";
        else if (q == 8)
            cout << "��";
        else if (q == 9)
            cout << "��";
        cout << "Ǫ��";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q == 0 && b == 0 && s == 0 && g != 0) {  //000* 6
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q == 0 && b != 0 && s != 0 && g == 0) {  //0**0 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
    }
    if (q == 0 && b != 0 && s == 0 && g == 0) {  //0*00 5
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "��";
    }
    if (q == 0 && b != 0 && s == 0 && g != 0) {  //0*0* 4
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (b == 1)
            cout << "Ҽ";
        else if (b == 2)
            cout << "��";
        else if (b == 3)
            cout << "��";
        else if (b == 4)
            cout << "��";
        else if (b == 5)
            cout << "��";
        else if (b == 6)
            cout << "½";
        else if (b == 7)
            cout << "��";
        else if (b == 8)
            cout << "��";
        else if (b == 9)
            cout << "��";
        cout << "����";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";
    }
    if (q == 0 && b == 0 && s != 0 && g == 0) {  //00*0 2
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
    }
    if (q == 0 && b == 0 && s != 0 && g != 0) {  //00** 1
        if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0)
            cout << "��";
        if (s == 1)
            cout << "Ҽ";
        else if (s == 2)
            cout << "��";
        else if (s == 3)
            cout << "��";
        else if (s == 4)
            cout << "��";
        else if (s == 5)
            cout << "��";
        else if (s == 6)
            cout << "½";
        else if (s == 7)
            cout << "��";
        else if (s == 8)
            cout << "��";
        else if (s == 9)
            cout << "��";
        cout << "ʰ";
        if (g == 1)
            cout << "Ҽ";
        else if (g == 2)
            cout << "��";
        else if (g == 3)
            cout << "��";
        else if (g == 4)
            cout << "��";
        else if (g == 5)
            cout << "��";
        else if (g == 6)
            cout << "½";
        else if (g == 7)
            cout << "��";
        else if (g == 8)
            cout << "��";
        else if (g == 9)
            cout << "��";     
    }

    if (!sy&&!y&& !qw && !bw&&!w&&!sw &&! q &&! b &&! s &&! g&&!j&&!f)
        cout << "��Բ";


    //ǧ�������Ƿֿ�ʼ
    if (sy != 0 || y != 0 || qw != 0 || sw != 0 || bw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || g != 0) {
        cout << "Բ";
    }
    if (sy&&y&&qw&&bw&&w&&sw&&q&&b&&s&&g&&j == 0 && f != 0)
        cout << "��";
    if (j == 1)
        cout << "Ҽ��";
    else if (j == 2)
        cout << "����";
    else if (j == 3)
        cout << "����";
    else if (j == 4)
        cout << "����";
    else if (j == 5)
        cout << "���";
    else if (j == 6)
        cout << "½��";
    else if (j == 7)
        cout << "���";
    else if (j == 8)
        cout << "�ƽ�";
    else if (j == 9)
        cout << "����";
    else if (j == 0){
        if (f == 1)
            cout << "Ҽ��";
        else if (f == 2)
            cout << "����";
        else if (f == 3)
            cout << "����";
        else if (f == 4)
            cout << "����";
        else if (f == 5)
            cout << "���";
        else if (f == 6)
            cout << "½��";
        else if (f == 7)
            cout << "���";
        else if (f == 8)
            cout << "�Ʒ�";
        else if (f == 9)
            cout << "����";
        else if (f == 0)
            cout << "��";
    }

    if (f == 1 && j != 0)
        cout << "Ҽ��";
    else if (f == 2 && j != 0)
        cout << "����";
    else if (f == 3 && j != 0)
        cout << "����";
    else if (f == 4 && j != 0)
        cout << "����";
    else if (f == 5 && j != 0)
        cout << "���";
    else if (f == 6 && j != 0)
        cout << "½��";
    else if (f == 7 && j != 0)
        cout << "���";
    else if (f == 8 && j != 0)
        cout << "�Ʒ�";
    else if (f == 9 && j != 0)
        cout << "����";
    else if (f == 0 && j != 0)
        cout << "��";
    cout << endl;
    
	return 0;
}