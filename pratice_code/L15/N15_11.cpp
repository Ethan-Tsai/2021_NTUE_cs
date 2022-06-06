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
	int  _ix, _iy, *_pcolor;	// �y�лP�C��
public:
	CCharacter(int ix=0, int iy=0, int icolor=COLOR_WHITE) { 
		_ix = ix; _iy = iy; _pcolor = new int; *_pcolor = icolor;
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	CCharacter(const CCharacter &ca) {	// �����غc��
		_ix = ca._ix; _iy = ca._iy; // �]�w�ѹ����_�l��m
		_pcolor = new int;  *_pcolor = *(ca._pcolor); // ���o�Ŷ��P�]�w�ϥ�
		cout << "CCharacter �����غc���Q�I�s" << endl; // ��ܰT��
	}
	~CCharacter() {
		delete _pcolor;  
		cout << "CCharacter �Ѻc���Q����" << endl;
		system("pause");
	}
	void draw() { drawBoxMan(_ix, _iy, *_pcolor); }
	void setPos(int ix, int iy) { _ix = ix;  _iy = iy; };
};
class CMouse : public CCharacter {
private:
	int *_pattack;	// �]�w�����O
public:
	CMouse(int x, int y, int color, int ivalue = 10) : CCharacter(x,y,color) {
		_pattack = new int;  *_pattack = ivalue;
	}
	CMouse(const CMouse &ma) : CCharacter(ma) {	// �����غc��
		_pattack = new int;  *_pattack = *(ma._pattack); //���o�Ŷ��P�]�w�ϥ�
		cout << "CMouse �����غc���Q�I�s" << endl; // ��ܰT��
	}
	~CMouse() { 
		delete _pattack; 
		cout << "CMouse �Ѻc���Q����" << endl;
		system("pause");
	}  // �Ѻc��, ����귽
	void showAttack() { cout << "�����O=" << *_pattack << endl; }
};
int main()
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "N15-11 �Ѻc�������涶��");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	mx.draw();
	my.setPos(0,120); my.draw(); my.showAttack();
	while (!kbhit()) { delay(200); } return 0;
}