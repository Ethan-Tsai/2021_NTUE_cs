#pragma once
class CMouse
{
private:
	int _ix, _iy, _icolor, _mcolor[2];
	int _istatus; // 1:正常狀態, 2:在邊界上, 0: 死亡
	bool _btracer; //true 為追蹤者，false 為被追蹤者
	int _itx, _ity; // 被跟隨對象的座標
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