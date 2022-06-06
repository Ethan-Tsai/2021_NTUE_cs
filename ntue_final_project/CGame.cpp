#include <iostream>
#include "CGame.h"
extern bool g_bBoss;
CGame::CGame() { m_cIcon = '#';}
void CGame::Update() {
	if( g_bBoss ) m_cIcon = '*';
	else m_cIcon = '#';
}