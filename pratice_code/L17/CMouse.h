#pragma once
class CMouse
{
private:
	int _ix, _iy, _icolor, _mcolor[2];
	int _istatus; // 1:���`���A, 2:�b��ɤW, 0: ���`
	bool _btracer; //true ���l�ܪ̡Afalse ���Q�l�ܪ�
	int _itx, _ity; // �Q���H��H���y��
public:
	CMouse();
	void draw();
	void setColor(int ncolor, int dcolor);
	int update(char cIn);
	int getStatus() { return (_istatus); }
	void getPos(int *ix, int *iy);
	void setTracer(bool bT);
	void setTrackedPos(int ix, int iy);
};