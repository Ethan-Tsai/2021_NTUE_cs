#include <iostream>
#include <conio.h>
#include "CGame.h"
extern void Show(CGame);
using namespace std;
bool g_bBoss = false; // 老闆來了
int  g_iCounter = 0;  // 輸入的按鍵次數
int main(void) {
	char cIn;
	CGame gx;
	while ( (cIn = getch()) != 'q' ) {
		if( cIn == 'b' ) g_bBoss = !g_bBoss;
		g_iCounter++;
		gx.Update();
		Show(gx); 
	}
	system("pause"); return(0);
}