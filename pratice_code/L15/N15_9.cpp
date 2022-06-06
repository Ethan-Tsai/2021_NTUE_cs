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
	int  _ix, _iy, *_pcolor;	// 座標與顏色
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _pcolor = new int; *_pcolor = icolor;
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	CCharacter(const CCharacter &ca) {	// 拷貝建構元
		_ix = ca._ix; _iy = ca._iy; // 設定老鼠的起始位置
		_pcolor = new int;  *_pcolor = *(ca._pcolor); // 取得空間與設定圖示
		cout << "CCharacter 拷貝建構元被呼叫" << endl; // 顯示訊息
	}
	~CCharacter() { delete _pcolor;  }
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	void setPos(int ix, int iy) { _ix = ix;  _iy = iy; };
};
class CMouse : public CCharacter {
private:
	int _iattack;	// 設定攻擊力
public:
	CMouse(int x, int y, int color, int ivalue = 10) : CCharacter(x,y,color) { _iattack = ivalue; }
	void showAttack() { cout << "攻擊力=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-9 拷貝宣告的處理");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0,120); my.draw(); my.showAttack();
	mz.setPos(0, -120); mz.draw(); mz.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}