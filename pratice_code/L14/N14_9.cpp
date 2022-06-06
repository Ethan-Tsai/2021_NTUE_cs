#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"
using namespace std;
class CMouse
{
private:
	int _ix, _iy, *_pcolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) {  // �غc��
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &m) {	// �����غc��
		_ix = m._ix; _iy = m._iy; _pcolor = new int; // �ѹ����_�l��m�P���o�Ŷ�
		*_pcolor = *(m._pcolor);
	}
	~CMouse() { delete _pcolor; }; // �Ѻc��, ����귽
	void operator= (const CMouse &m) { // �]�w�B��l
		_ix = m._ix; _iy = m._iy;
		*_pcolor = *(m._pcolor); // �N�ǤJ���󪺬۹������r����J�Y�i
	}
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-9 ���w�B��l =");
	CMouse m1(0, 100, 14); // �إ߮ɴN�|�۰ʩI�s CMouse �غc��
	CMouse m2 = m1;	// �I�s�����غc���ӫإߪ��� mouse2
	CMouse m3;
	m3 = m1;		// ������w�B��l
	m3.draw();
	while (!kbhit()) { delay(200); } return 0;
}