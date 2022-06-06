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
public:
	int _ix, _iy;		// 老鼠的起始位置
	int *_pcolor;		// 老鼠的顏色，整數指標變數
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	CMouse(const CMouse &m) {	// 拷貝建構元
		_ix = m._ix; _iy = m._iy; _pcolor = new int; // 老鼠的起始位置與取得空間
		*_pcolor = *(m._pcolor);
	}
	~CMouse() { delete _pcolor; }; // 解構元, 釋放資源
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-7 物件指標變數");
	CMouse mx(0, 0, 14); // 建立時就會自動呼叫CMouse 建構元
	CMouse *pmy = new CMouse(mx);
	pmy->draw(); // 讓老鼠自己畫出自己的位置
	delete pmy;
	while (!kbhit()) { delay(200); } return 0;
}