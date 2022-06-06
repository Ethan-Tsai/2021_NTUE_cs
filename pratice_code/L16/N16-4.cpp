#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCharacter {
protected:
	int  _ix, _iy, _icolor;;	// �y�лP�C��
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { _ix = ix; _iy = iy; _icolor = icolor; }
	virtual void draw() { drawBoxMan(_ix, _iy, _icolor); }
};
class CMouse : public CCharacter {
private:
	int _ishape;	// �]�w���P���~��
public:
	CMouse(int x, int y, int color, int ishape = 1) : CCharacter(x, y, color) { _ishape = ishape; }
	void draw() { 
		if( _ishape == 1)  drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
		else {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // ���զ�
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
	}
};


void drawCharacter(CCharacter *ch) { ch->draw(); } // �@��禡
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-4 �����禡(�ǫ���)");
	CCharacter npc1(-100, 100, 12), npc2(100, 100, 12);
	CMouse m1(-100, -50, 2, 2), m2(100, -50, 2, 2);
	npc1.draw(); m1.draw();
	drawCharacter(&npc2); drawCharacter(&m2); // ��ܨ���
	while (!kbhit()) { delay(200); } return 0;
}
