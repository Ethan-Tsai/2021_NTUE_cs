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
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-6 物件指標");
	CMouse *pmx = new CMouse; // 宣告物件指標變數，同時取得空間
	pmx->_ix = 0; pmx->_iy = 100; 
	*(pmx->_pcolor) = 14; // 設定為黃色
	pmx->draw(); // 讓老鼠自己畫出自己的位置
	delete pmx;
	while (!kbhit()) { delay(200); } return 0;
}