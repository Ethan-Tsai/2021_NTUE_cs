#include <iostream>
#include "CGame.h"
using namespace std;
extern int g_iCounter; 
void Show(CGame iGx) {
	cout << "m_cIcon =  " << iGx.m_cIcon << endl;
	if( g_iCounter >= 10 ) cout << "按下 q 鍵可結束程式" << endl;
}