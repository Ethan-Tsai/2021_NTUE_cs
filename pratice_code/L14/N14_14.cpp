#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// 定義可活動的範圍
#define Y_MAX 200	// 定義可活動的範圍
using namespace std;
void drawFence();

class CSticker {
private:
	int  _ix, _iy, _icolor;	// 圖示的位置與顏色
public:
	CSticker() {
		_ix = rand() % 600 - 300; // 以亂數產生座標
		_iy = rand() % 600 - 300;
		_icolor = rand() % 15 + 1;  // 顏色隨機選擇 1 到 15
	}
	void draw() { drawColorBox(_ix, _iy, _icolor); }
};

class CPainter {
private:
	CSticker *psticker; // 指標變數
public:
	CPainter() { psticker = new CSticker[20]; }
	~CPainter() { delete[] psticker; }
	void draw() {
		for (int i = 0; i < 20; i++) (psticker + i)->draw(); // 每一個 sticker 都呼叫 draw
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-14 類別的組合");
	srand((unsigned)time(NULL)); // 設定亂數產生器的初始值
	cleardevice();
	CPainter pic;
	pic.draw();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}