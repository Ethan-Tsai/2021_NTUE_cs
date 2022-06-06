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
	~CMouse() {
		delete _pcolor;
	};
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	friend void drawM(CMouse m) {
		drawBoxMan(m._ix, m._iy, *(m._pcolor));
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-3 �ʺA�O����t�m �귽�����wĵ����");
	CMouse mx(0, 100, 3); // �إ߮ɴN�|�۰ʩI�sCMouse �غc��
	drawM(mx);
	while (!kbhit()) { delay(200); } return 0;
}