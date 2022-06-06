#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCharacter {
private:
	int  _ix, _iy, _icolor;	// �y�лP�C��
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { // �غc��	
		_ix = ix; _iy = iy; _icolor = icolor; // �]�w��m�P�C��
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
public:
	CMouse(int ivalue = 10) { _iattack = ivalue; }
	CMouse(int icolor, int ivalue = 10) : CCharacter( 0, 0, icolor) {
		_iattack = ivalue; 
		cout << "CMouse �I�s�����C��غc��" << endl;
	}
	void showAttack() { cout << "�����O=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-3 ��¦���O�غc�������w");
	CMouse mx1, mx2(13, 6);
	mx1.draw();	mx1.showAttack();
	mx2.setPos(0, 100);
	mx2.draw();	mx2.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}