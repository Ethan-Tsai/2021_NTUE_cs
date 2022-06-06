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
	CCharacter(int ix, int iy, int icolor) { // �غc��	
		_ix = ix; _iy = iy; _icolor = icolor; // �]�w��m�P�ϥ�
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
public:
	CMouse(int ix = 0, int iy = 0, int icolor = 14, int ivalue = 10) :
	CCharacter(ix, iy, icolor) {
		_iattack = ivalue;
		cout << "CMouse �غc���Q�I�s" << endl;
	}
	void showAttack() { cout << "�����O=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-2 ��¦���O�غc�������w");
	CMouse mx1, mx2(0, 100, 13, 5);
	mx1.draw();
	mx2.draw(); mx2.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}