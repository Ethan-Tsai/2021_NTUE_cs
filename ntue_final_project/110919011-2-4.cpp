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

class CMouse
{
private:
	int x, y;
	int status; // 1:正常狀態, 2:在邊界上, 0: 死亡
	int color;
	int dcolor, ncolor;
public:
	CMouse();
	void draw(int x, int y, int color);
	void setColor(int ncol, int dcol) { color = ncolor = ncol; dcolor = dcol; }
	void setPos(int ix, int iy) { x = ix; y = iy; }
	int update(char cIn);
	int getStatus() { return (status); }
};

CMouse::CMouse() {
	x = 0; y = 0;	// 老鼠的起始位置
	status = 1;		// 1 : 正常狀態, 2: 離開邊界0: 死亡狀態
	color = ncolor = NORMAL_COLOR; dcolor = DANGER_COLOR;// 設定老鼠的初始顏色為 mcolor[0]

}

void CMouse::draw(int x = 100, int y = 100, int color = 12)
{
	drawBoxMan(x, y, color); // 畫出老鼠
}
int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		y = y + 20; break;
	case 's': // 往下
		y = y - 20; break;
	case 'a': // 往左
		x = x - 20; break;
	case 'd': // 往右
		x = x + 20; break;
	}
	if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // 安全區域內
		status = 1; color = ncolor;
	}
	else if (x < -X_MAX || x > X_MAX || y < -Y_MAX || y > Y_MAX) {
		status = 0; // 移除邊界 老鼠死亡 遊戲結束			
	}
	else {	// 在邊界上
		status = 2;  color = dcolor;
	}
	return (status);
}


int main()
{
	CMouse mx;
	CMouse m1, m2, m3;
	m1.draw();
	m2.draw(50, 100, 9);
	m3.draw(150, 100, 4);
	int in;
	cin >> in;
	if (in == 1)
	{
		CMouse mx = m1;
	}
	else if (in == 2)
	{
		CMouse mx = m2;
	}
	else CMouse mx = m3;
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-11 使用建構元");
	//CMouse mx; // 建立時就會自動呼叫 CMouse 建構
	status = mx.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // 畫出範圍
		mx.draw();	// 畫出老鼠
		swapbuffers();
		cIn = getch();
		status = mx.update(cIn); // 讓老鼠自己更新狀態
		fflush(stdin);
	}
	cleardevice();
	drawFence();
	setcolor(COLOR_WHITE);
	outtextxy(X(-100), Y(0), "!! 老鼠死了 GG 按任意鍵結束!! ");
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

void drawFence()
{
	for (int i = -200; i <= 200; i += 20) {
		drawColorBox(i, 200, COLOR_LIGHTGREEN);
		drawColorBox(i, -200, COLOR_LIGHTGREEN);
	}
	for (int i = -180; i <= 180; i += 20) {
		drawColorBox(-200, i, COLOR_LIGHTGREEN);
		drawColorBox(200, i, COLOR_LIGHTGREEN);
	}
}