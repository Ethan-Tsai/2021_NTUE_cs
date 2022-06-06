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
	int _ix, _iy, _icolor, _ncolor, _dcolor;
	int _istatus; // 1:���`���A, 2:�b��ɤW, 0: ���`
	bool _btracer; //true ���l�ܪ̡Afalse ���Q�l�ܪ�
	int _itx, _ity; // �Q���H��H���y��
public:
	CMouse() {  
		_ix = 0; _iy = 0; 	// �ѹ����_�l��m
		_istatus = 1;		// 1 : ���`���A, 2: ���}���0: ���`���A
		_icolor= _ncolor = NORMAL_COLOR; _dcolor = DANGER_COLOR;	// �]�w�ѹ�����l�C�⬰ mcolor[0]
		_btracer = false; // �w�]���i�Q�j�l�ܪ�
		_itx = _ity = 0;
	}
	void draw();
	void setColor(int ncolor, int dcolor) { _icolor = _ncolor = ncolor;  _dcolor = dcolor; };
	int update(char cIn);
	int getStatus() { return (_istatus); }
	void getPos(int *ix, int *iy) {
		*ix = _ix;  *iy = _iy; 
	}
	void setTracer(bool bT) { _btracer = bT; }
	void setTrackedPos(int ix, int iy) { _itx = ix; _ity = iy;  }
};

void CMouse::draw() {
	if( _btracer ) 	drawBoxMan(_itx, _ity -100, _icolor); // �l�ܪ̦b Y �b���U 100 ��쪺�a��
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
	int status, ix, iy;  // ix iy ���Q�l�H�̪��y��
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-12 ���󤧶��ǻ���T");
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
		rewind(stdin);
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