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
	CMouse(const CMouse &m) {	// �غc��
		_ix = m._ix; _iy = m._iy; // �ѹ����_�l��m
		_pcolor = new int; // ���o�Ŷ�
		*_pcolor = *(m._pcolor); // �N�ǤJ���ѹ��ϥܶ�J
		outtextxy(X(-60), Y(0), "�����غc���Q�I�s");
	}
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-4 �ʺA�O����t�m �귽�����wĵ����");
	CMouse mx(0, 100, 12); // �إ߮ɴN�|�۰ʩI�sCMouse �غc��
	CMouse my(mx);
	my.draw(); // ���ѹ��ۤv�e�X�ۤv����m
	while (!kbhit()) { delay(200); } return 0;
}