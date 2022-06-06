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
	int  _ix, _iy;	// 座標與顏色
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
public:
	int _icolor;
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _icolor = icolor; // 設定位置與顏色
	}
	void setColor(int icolor) { _icolor = icolor; }
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};

class CMouse : public CCharacter {
private:
	int _iattack;	// 設定攻擊力
public:
	void setPosColor(int ix, int iy, int icolor) {
		setColor(icolor);
		setPos(ix, iy);
	}
	CMouse(int ivalue = 10) { _iattack = ivalue; }
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-5 被保護的成員");
	CMouse mx1;
	mx1.setPosColor(0, 100, 14);
	mx1.draw();	
	while (!kbhit()) { delay(200); } return 0;
}