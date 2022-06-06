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
public:
	int _ix, _iy;		// �ѹ����_�l��m
	int *_pcolor;		// �ѹ����C��A��ƫ����ܼ�
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &m) {	// �����غc��
		_ix = m._ix; _iy = m._iy; _pcolor = new int; // �ѹ����_�l��m�P���o�Ŷ�
		*_pcolor = *(m._pcolor);
	}
	~CMouse() { delete _pcolor; }; // �Ѻc��, ����귽
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-7 ��������ܼ�");
	CMouse mx(0, 0, 14); // �إ߮ɴN�|�۰ʩI�sCMouse �غc��
	CMouse *pmy = new CMouse(mx);
	pmy->draw(); // ���ѹ��ۤv�e�X�ۤv����m
	delete pmy;
	while (!kbhit()) { delay(200); } return 0;
}