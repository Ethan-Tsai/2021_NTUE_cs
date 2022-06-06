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
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
public:
	CMouse(int x, int y, int color, int ivalue = 10):CCharacter(x,y,color) { _iattack = ivalue; }
	void showAttack() { cout << "�����O=" << _iattack << endl; }
	void draw() {
		drawSizeBox(_ix - 62, _iy + 20, COLOR_LIGHTBLUE, 20); // ���զ�
		drawSizeBox(_ix + 62, _iy + 20, COLOR_LIGHTBLUE, 20); // �k�զ�	
		drawBoxMan(_ix, _iy, _icolor, COLOR_YELLOW, COLOR_LIGHTMAGENTA);
	}
};
class CTiger : public CCharacter {
private:
	int _ishape;	// �]�w���P���~��
public:
	CTiger(int x, int y, int color, int ishape = 1) : CCharacter(x, y, color) { _ishape = ishape; }
	void draw() { 
		if( _ishape == 1)  drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
		else {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // ���զ�
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-7 �����禡����g");
	CMouse mx(0, -50, COLOR_BROWN);
	CTiger tx(0, 100, 2,2);
	mx.draw(); // ��¦���O���� draw() 
	tx.draw(); // �l�����O CTiger ���� draw() 
	while (!kbhit()) { delay(200); } return 0;
}