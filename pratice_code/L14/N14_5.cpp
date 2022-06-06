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
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &ma) {	// �غc��
		_ix = ma._ix; _iy = ma._iy; // �ѹ����_�l��m
		_pcolor = new int; // ���o�Ŷ�
		*_pcolor = *(ma._pcolor); // �N�ǤJ���ѹ��ϥܶ�J
		outtextxy(X(-60), Y(0), "�����غc���Q�I�s");
	}
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	friend void drawM(CMouse m) { drawBoxMan(m._ix, m._iy, *(m._pcolor)); }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-5 �ʺA�O����t�m �귽�����wĵ����");
	CMouse mx(0, 100, 12); // �إ߮ɴN�|�۰ʩI�sCMouse �غc��
	mx.draw(); // ���ѹ��ۤv�e�X�ۤv����m
	while (!kbhit()) { delay(200); } return 0;
}