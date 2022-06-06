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
	int status, ix, iy;  // ix iy ���Q�l�H�̪��y��
	initwindow(SCREENWIDTH, SCREENWIDTH, "N17-1 �{���ɪ�����");
	CMouse m1, m2;
	m1.setColor(COLOR_CYAN, COLOR_LIGHTBLUE); // �]�w�s���C��
	m1.getPos(&ix, &iy);
	m2.setTrackedPos(ix,iy);
	m2.setTracer(true);
	status = m1.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // �e�X�d��
		m1.draw();	// �e�X�ѹ�
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
	outtextxy(X(-100), Y(0), "!! �ѹ����F GG �����N�䵲��!! ");
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