#include "CMouse.h"
#include "functions.h"

#define NORMAL_COLOR COLOR_YELLOW
#define DANGER_COLOR COLOR_RED
#define X_MAX 200	// �w�q�i���ʪ��d��
#define Y_MAX 200	// �w�q�i���ʪ��d��

CMouse::CMouse() {
	_ix = 0; _iy = 0;	// �ѹ����_�l��m
	_istatus = 1;		// 1 : ���`���A, 2: ���}���0: ���`���A
	_icolor = _mcolor[0] = NORMAL_COLOR; _mcolor[1] = DANGER_COLOR;	// �]�w�ѹ�����l�C�⬰ mcolor[0]
	_btracer = false; // �w�]���i�Q�j�l�ܪ�
}

void CMouse::draw() {
	if (_btracer) 	drawBoxMan(_itx, _ity - 100, _icolor); // �l�ܪ̦b Y �b���U 100 ��쪺�a��
	else drawColorBox(_ix, _iy, _icolor);
}

void CMouse::setColor(int ncolor, int dcolor) { _icolor = _mcolor[0] = ncolor; _mcolor[1] = dcolor; };
void CMouse::getPos(int *ix, int *iy) { *ix = _ix;  *iy = _iy; }
void CMouse::setTracer(bool bT) { _btracer = bT; }
void CMouse::setTrackedPos(int ix, int iy) { _itx = ix; _ity = iy; }

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
		_istatus = 1; _icolor = _mcolor[0];
	}
	else if (_ix < -X_MAX || _ix > X_MAX || _iy < -Y_MAX || _iy > Y_MAX) {
		_istatus = 0; // ������� �ѹ����` �C������			
	}
	else {	// �b��ɤW
		_istatus = 2; _icolor = _mcolor[1];
	}
	return (_istatus);
}
