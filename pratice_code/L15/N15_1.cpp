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
	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) { // �غc��	
		_ix = ix; _iy = iy; _icolor = icolor; // �]�w��m�P�C��
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	void draw() { drawBoxMan(_ix, _iy, _icolor); }
	void setColor(int icolor) { _icolor = icolor; }
};
class CMouse : public CCharacter {
private:
	int _iattack;	// �]�w�����O
public:
	CMouse(int ivalue = 10) {
		_iattack = ivalue;
		cout << "CMouse �غc���Q�I�s" << endl;
	}
	void showAttack() { cout << "�����O=" << _iattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-1 �~�Ӫ��w�q�P�ϥ�");
	CCharacter npc(0, 100);
	CMouse mx;
	npc.draw();
	mx.setColor(14);
	mx.draw();
	mx.showAttack();
	cout << "sizeof(npc) = " << sizeof(npc) << endl;
	cout << "sizeof(mx)  = " << sizeof(mx) << endl;
	while (!kbhit()) { delay(200); } return 0;
}