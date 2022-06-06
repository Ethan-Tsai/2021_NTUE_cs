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
	int  _ix, _iy, _icolor;;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor= COLOR_LIGHTGREEN) { _ix = ix; _iy = iy; _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() = 0; //純虛擬函式
};
class CCat : public  CCharacter {
public:
	CCat(int x = 0, int y = 0, int color = COLOR_LIGHTRED) : CCharacter(x, y, color) {}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
};

class CMouse : public CCharacter {
public:
	CMouse(int x=0, int y = 0, int color= COLOR_LIGHTRED) : CCharacter(x, y, color) {}
	void draw() { 
		drawSizeBox(_ix , _iy + 60, COLOR_WHITE, 30); // 頭髮
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
class CRabbit : public CCharacter {
public:
	CRabbit(int x = 0, int y = 0, int color = COLOR_YELLOW) : CCharacter(x, y, color) {  }
	void draw() {
		drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
		drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
		drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};
int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-6 抽象類別");
	CCharacter *pChar[5];
	pChar[0] = new CCat(-150, 50);  // 建立貓的角色
	pChar[1] = new CMouse(0, 50);
	pChar[2] = new CMouse(150, 50, COLOR_GREEN); // 老鼠
	pChar[3] = new CRabbit(-150, -100); //兔子
	pChar[4] = new CRabbit(0, -100, COLOR_LIGHTCYAN);
	for (i = 0; i < 5; i++) pChar[i]->draw();
	for (i = 0; i < 5; i++) delete pChar[i]; // 釋放取得的物件空間
	while (!kbhit()) { delay(200); } return 0;
}
