#include "CMouse.h"
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED
#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍

CMouse::CMouse() {
	_ix = 0; _iy = 0;	// 老鼠的起始位置
	_istatus = 1;		// 1 : 正常狀態, 2: 離開邊界0: 死亡狀態
	_icolor = _mcolor[0] = NORMAL_COLOR; _mcolor[1] = DANGER_COLOR;	// 設定老鼠的初始顏色為 mcolor[0]
	_btracer = false; // 預設為【被】追蹤者
}

void CMouse::draw() {
	if (_btracer) 	drawBoxMan(_itx, _ity - 100, _icolor); // 追蹤者在 Y 軸往下 100 單位的地方
	else drawColorBox(_ix, _iy, _icolor);
}

void CMouse::setColor(int ncolor, int dcolor) { _icolor = _mcolor[0] = ncolor; _mcolor[1] = dcolor; };
void CMouse::getPos(int *ix, int *iy) { *ix = _ix;  *iy = _iy; }
void CMouse::setTracer(bool bT) { _btracer = bT; }
void CMouse::setTrackedPos(int ix, int iy) { _itx = ix; _ity = iy; }

int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_iy = _iy + 20; break;
	case 's': // 往下
		_iy = _iy - 20; break;
	case 'a': // 往左
		_ix = _ix - 20; break;
	case 'd': // 往右
		_ix = _ix + 20; break;
	}
	if (_ix > -X_MAX && _ix < X_MAX && _iy > -Y_MAX && _iy < Y_MAX) { // 安全區域內
		_istatus = 1; _icolor = _mcolor[0];
	}
	else if (_ix < -X_MAX || _ix > X_MAX || _iy < -Y_MAX || _iy > Y_MAX) {
		_istatus = 0; // 移除邊界 老鼠死亡 遊戲結束			
	}
	else {	// 在邊界上
		_istatus = 2; _icolor = _mcolor[1];
	}
	return (_istatus);
}
