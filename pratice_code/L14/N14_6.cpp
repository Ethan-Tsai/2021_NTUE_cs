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
	int _ix, _iy;		// �ѹ����_�l��m
	int *_pcolor;		// �ѹ����C��A��ƫ����ܼ�
	CMouse(int x = 0, int y = 0, int color = COLOR_WHITE) { 
		_pcolor = new int; 	*_pcolor = color; _ix = x; _iy = y;
	}
	~CMouse() { delete _pcolor; };
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N14-6 �������");
	CMouse *pmx = new CMouse; // �ŧi��������ܼơA�P�ɨ��o�Ŷ�
	pmx->_ix = 0; pmx->_iy = 100; 
	*(pmx->_pcolor) = 14; // �]�w������
	pmx->draw(); // ���ѹ��ۤv�e�X�ۤv����m
	delete pmx;
	while (!kbhit()) { delay(200); } return 0;
}