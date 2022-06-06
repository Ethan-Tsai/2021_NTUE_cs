#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "CMouse.h"
#include "functions.h"

using namespace std;
void drawFence();

int main()
{
	char cIn;
	int status, ix, iy;  // ix iy 為被追隨者的座標
	initwindow(SCREENWIDTH, SCREENWIDTH, "N17-1 程式檔的分割");
	CMouse m1, m2;
	m1.setColor(COLOR_CYAN, COLOR_LIGHTBLUE); // 設定新的顏色
	m1.getPos(&ix, &iy);
	m2.setTrackedPos(ix,iy);
	m2.setTracer(true);
	status = m1.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // 畫出範圍
		m1.draw();	// 畫出老鼠
		m2.draw();
		swapbuffers();
		cIn = getch();
		status = m1.update(cIn);
		m1.getPos(&ix, &iy);
		m2.setTrackedPos(ix, iy);
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