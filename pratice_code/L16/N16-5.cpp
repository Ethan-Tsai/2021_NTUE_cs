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
	CCharacter(int ix=0, int iy=0, int icolor= COLOR_LIGHTGREEN) { _ix = ix; _iy = iy; _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() { drawBoxMan(_ix, _iy, _icolor); }
};
class CMouse : public CCharacter {
public:
	CMouse(int x=0, int y = 0, int color= COLOR_LIGHTRED) : CCharacter(x, y, color) {}
	void draw() { 
		drawSizeBox(_ix , _iy + 60, COLOR_WHITE, 30); // �Y�v
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
class CRabbit : public CCharacter {
public:
	CRabbit(int x = 0, int y = 0, int color = COLOR_YELLOW) : CCharacter(x, y, color) {  }
	void draw() {
		drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // ���զ�
		drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
		drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};
int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-5 �h��");
	CCharacter *pChar[7];
	pChar[0] = new CCharacter[3];  // �إߤ@�몺����
	pChar[1] = new CMouse(0, 50);
	pChar[2] = new CMouse(150, 50, COLOR_GREEN); // �ѹ�
	pChar[3] = new CRabbit(-150, -100); //�ߤl
	pChar[4] = new CRabbit(0, -100, COLOR_LIGHTCYAN);
	pChar[5] = new CRabbit(150, -100, COLOR_BROWN);
	pChar[6] = new CRabbit[3];
	for (i = 1; i < 6; i++) pChar[i]->draw();
	for (i = 0; i < 3; i++) pChar[6][i].draw();
	for (i = 1; i < 6; i++) delete pChar[i]; // ������o������Ŷ�
	delete[] pChar[0];
	delete[] pChar[6];

	while (!kbhit()) { delay(200); } return 0;
}
