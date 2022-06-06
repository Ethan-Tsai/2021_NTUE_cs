#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCharacter {
private:
	int  _ix, _iy;	// �y�лP�C��
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
public:
	int _icolor;
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _icolor = icolor; // �]�w��m�P�C��
	}
	void setColor(int icolor) { _icolor = icolor; }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};

class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
	void setPosColor(int ix, int iy, int icolor) {
		setColor(icolor);
//		setPos(ix, iy); 
	}
public:
	CMouse(int ivalue = 10) { _iattack = ivalue; }
	void showAttack() { cout << "�����O=" << _iattack << endl; }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-4 �~�ӫ᪺�s������(�鷺�P��~)");
	CMouse mx1;
//	mx1.setPosColor(0, 100, 14);
	mx1.draw();	
	while (!kbhit()) { delay(200); } return 0;
}