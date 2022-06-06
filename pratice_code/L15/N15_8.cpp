#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include "functions.h"

using namespace std;

class CCharacter {
protected:
	int  _ix, _iy, _icolor;;	// �y�лP�C��
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _icolor = icolor; 
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setPos(int ix, int iy) { _ix = ix;  _iy = iy; };
};
class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
public:
	CMouse(int x, int y, int color, int ivalue = 10) : CCharacter(x,y,color) { _iattack = ivalue; }
	void showAttack() { cout << "�����O=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-8 �����ŧi���B�z");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0,120); my.draw(); my.showAttack();
	mz.setPos(0, -120); mz.draw(); mz.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}