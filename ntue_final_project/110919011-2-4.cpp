#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED

#define X_MAX 200	// �w�q�i���ʪ��d��
#define Y_MAX 200	// �w�q�i���ʪ��d��
using namespace std;
void drawFence();

class CMouse
{
private:
	int x, y;
	int status; // 1:���`���A, 2:�b��ɤW, 0: ���`
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
	x = 0; y = 0;	// �ѹ����_�l��m
	status = 1;		// 1 : ���`���A, 2: ���}���0: ���`���A
	color = ncolor = NORMAL_COLOR; dcolor = DANGER_COLOR;// �]�w�ѹ�����l�C�⬰ mcolor[0]

}

void CMouse::draw(int x = 100, int y = 100, int color = 12)
{
	drawBoxMan(x, y, color); // �e�X�ѹ�
}
int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // ���W. ���ѹ���m,�îھڷs����m,��s�ѹ������A
		y = y + 20; break;
	case 's': // ���U
		y = y - 20; break;
	case 'a': // ����
		x = x - 20; break;
	case 'd': // ���k
		x = x + 20; break;
	}
	if (x > -X_MAX && x < X_MAX && y > -Y_MAX && y < Y_MAX) { // �w���ϰ줺
		status = 1; color = ncolor;
	}
	else if (x < -X_MAX || x > X_MAX || y < -Y_MAX || y > Y_MAX) {
		status = 0; // ������� �ѹ����` �C������			
	}
	else {	// �b��ɤW
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
	initwindow(SCREENWIDTH, SCREENWIDTH, "N12-11 �ϥΫغc��");
	//CMouse mx; // �إ߮ɴN�|�۰ʩI�s CMouse �غc
	status = mx.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // �e�X�d��
		mx.draw();	// �e�X�ѹ�
		swapbuffers();
		cIn = getch();
		status = mx.update(cIn); // ���ѹ��ۤv��s���A
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