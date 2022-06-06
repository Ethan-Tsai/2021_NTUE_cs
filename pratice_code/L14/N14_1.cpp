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
	int _ix, _iy;
	int *_pcolor; // �ѹ����C��A��ƫ����ܼ�
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int;  *_pcolor = color;
		_ix = x; _iy = y;
	}
	~CMouse() {
		delete _pcolor;
	};
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-1 �ʺA�O����t�m");
	CMouse mx(0, 100, 3); // �إ߮ɴN�|�۰ʩI�sCMouse �غc��
	CMouse my(mx);
	//mx.draw(); 
	my.draw();
	while (!kbhit()) { delay(200); } return 0;
}