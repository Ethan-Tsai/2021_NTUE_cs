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
	int  _ix, _iy, _icolor;	// 座標與顏色
public:
	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) { // 建構元	
		_ix = ix; _iy = iy; _icolor = icolor; // 設定位置與顏色
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// 設定攻擊力
public:
	CMouse(int ivalue = 10) {
		_iattack = ivalue;
		cout << "CMouse 建構元被呼叫" << endl;
	}
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-1 繼承的定義與使用");
	CCharacter npc(0, 100);
	CMouse mx;
	npc.draw();
	mx.setColor(14);
	mx.draw();
	mx.showAttack();
	cout << "sizeof(npc) = " << sizeof(npc) << endl;
	cout << "sizeof(mx)  = " << sizeof(mx) << endl;
	while (!kbhit()) { delay(200); } return 0;
}