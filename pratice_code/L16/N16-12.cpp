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
	CCharacter(int ix=0, int iy=0, int icolor= 3) {_ix = ix; _iy = iy; _icolor = icolor; }
	virtual ~CCharacter() { cout << "CCharacter �Ѻc���Q�I�s" << endl; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() = 0; //�����禡
};
class CAnimal : public CCharacter {
protected:
	int _ihp;
public:
	CAnimal(int ihp, int icolor = 15) : CCharacter(0,0,icolor) { _ihp = ihp; }
	~CAnimal() { cout << "CAnimal �Ѻc���Q�I�s" << endl; }

};
class CMouse : public CAnimal {
public:
	CMouse(int icolor= 10, int ihp = 10) : CAnimal(ihp, icolor) {}
	~CMouse() { cout << "CMouse �Ѻc���Q�I�s" << endl; }
	void draw() {
		char str[20]; sprintf(str, "HP = %2d", _ihp); outtextxy(X(_ix + 60), Y(_iy), str);
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-12 �h�h���~�ӤU���������c��");
	CMouse mx( 2, 50); mx.setPos(0, 100); mx.draw();
	CCharacter *pChar = new CMouse;
	pChar->draw();
	delete pChar;
	while (!kbhit()) { delay(200); } return 0;
}