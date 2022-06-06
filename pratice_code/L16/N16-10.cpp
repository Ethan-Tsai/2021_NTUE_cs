#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
using namespace std;
class CCharacter {
protected:
	int  _ix, _iy, _icolor;;	// �y�лP�C��
public:
	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTGREEN) { _ix = ix; _iy = iy; _icolor = icolor; }
	void setPos(int ix, int iy) { _ix = ix; _iy = iy; }
	virtual void draw() = 0; //�µ����禡
};
class CVillager : public  CCharacter {
protected:
	int _isex;
public:
	CVillager(int icolor = 2, int isex = 1) :CCharacter(0,0, icolor) { _isex = isex; }
	void draw() {
		char str[20]; sprintf(str, "Sex = %2d", _isex); outtextxy(X(_ix + 60), Y(_iy), str);
		drawBoxMan(_ix, _iy, _icolor); }
};
class CAnimal : public  CCharacter {
protected:
	int _ihp;
public:
	CAnimal(int ihp, int icolor = 15) : CCharacter(0, 0, icolor) { _ihp = ihp; }
	virtual void Attack() { outtextxy(X(_ix + 60), Y(_iy), "�������a"); }
};
class CMouse : public CAnimal {
public:
	CMouse(int ihp = 10, int icolor = 3) : CAnimal(ihp, icolor) {}
	void Attack() { outtextxy(X(_ix + 60), Y(_iy), "�S��覡�������a"); }
	void draw() {
		drawSizeBox(_ix, _iy + 60, COLOR_WHITE, 30); // �Y�v
		drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);
	}
};
class CRabbit : public CAnimal {
public:
	CRabbit(int ihp = 10, int icolor = 3) : CAnimal(ihp, icolor) {}
	void draw() {
		char str[20]; sprintf(str, "hp = %2d", _ihp); outtextxy(X(_ix + 60), Y(_iy), str);
		drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N16-10 �h�h���~��");
	CVillager v(4, 2); v.setPos(0, 200); v.draw();
	CAnimal *pa2m = new CMouse;
	pa2m->setPos(0,50); pa2m->draw(); pa2m->Attack();
	CAnimal *pa2r = new CRabbit;
	pa2r->setPos(0, -70); pa2r->draw(); pa2r->Attack();
	delete pa2m; delete pa2r;
	while (!kbhit()) { delay(200); } return 0;
}