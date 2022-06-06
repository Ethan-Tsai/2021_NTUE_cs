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

class CSticker {
private:
	int  _ix, _iy, _icolor;	// �ϥܪ���m�P�C��
public:
	CSticker() {
		_ix = rand() % 600 - 300; // �H�üƲ��ͮy��
		_iy = rand() % 600 - 300;
		_icolor = rand() % 15 + 1;  // �C���H����� 1 �� 15
	}
	void draw() { drawColorBox(_ix, _iy, _icolor); }
};

class CPainter {
private:
	CSticker *psticker; // �����ܼ�
public:
	CPainter() { psticker = new CSticker[20]; }
	~CPainter() { delete[] psticker; }
	void draw() {
		for (int i = 0; i < 20; i++) (psticker + i)->draw(); // �C�@�� sticker ���I�s draw
	}
};

int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-14 ���O���զX");
	srand((unsigned)time(NULL)); // �]�w�üƲ��;�����l��
	cleardevice();
	CPainter pic;
	pic.draw();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}