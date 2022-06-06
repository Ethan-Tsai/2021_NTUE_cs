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

bool g_bBoss = false; // �����ܼơCfalse: ���`���A�Atrue: ���ê��A

class CMouse
{
private:
	int _ix, _iy, _icolor;
	int _istatus; // 1:���`���A, 2:�b��ɤW, 0: ���`
	int _ncolor, _dcolor;
public:
	CMouse() {  
		_ix = 0; _iy = 0;	// �ѹ����_�l��m
		_istatus = 1;		// 1 : ���`���A, 2: ���}���0: ���`���A
		_icolor = _ncolor = NORMAL_COLOR; _dcolor = DANGER_COLOR;	// �]�w�ѹ�����l�C�⬰ mcolor[0]
	}
	void draw();
	void setColor(int ncolor, int dcolor) { _icolor = _ncolor = ncolor; _dcolor = dcolor; };
	int update(char cIn);
	int getStatus() { return (_istatus); }
};

void CMouse::draw() {
	if ( g_bBoss) {
		drawBoxMan(0, 0, COLOR_WHITE);
	}
	else drawColorBox(_ix, _iy, _icolor); 
}

int CMouse::update(char cIn)
{
	switch (cIn) {
	case 'w': // ���W. ���ѹ���m,�îھڷs����m,��s�ѹ������A
		_iy = _iy + 20; break;
	case 's': // ���U
		_iy = _iy - 20; break;
	case 'a': // ����
		_ix = _ix - 20; break;
	case 'd': // ���k
		_ix = _ix + 20; break;
	}
	if (_ix > -X_MAX && _ix < X_MAX && _iy > -Y_MAX && _iy < Y_MAX) { // �w���ϰ줺
		_istatus = 1; _icolor = _ncolor;
	}
	else if (_ix < -X_MAX || _ix > X_MAX || _iy < -Y_MAX || _iy > Y_MAX) {
		_istatus = 0; // ������� �ѹ����` �C������			
	}
	else {	// �b��ɤW
		_istatus = 2; _icolor = _dcolor;
	}
	return (_istatus);
}

int main()
{
	char cIn;
	int status;
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-11 �����ܼƪ��ϥ�");
	CMouse mx;
	mx.setColor(COLOR_CYAN, COLOR_LIGHTBLUE); // �]�w�s���C��
	status = mx.getStatus();
	while (status != 0)
	{
		cleardevice();
		drawFence(); // �e�X�d��
		mx.draw();	// �e�X�ѹ�
		swapbuffers();
		cIn = getch();
		if (cIn == 'b') g_bBoss = !g_bBoss;  //�P�_�O�_���U���� b
		status = mx.update(cIn);
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