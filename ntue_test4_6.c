//  程式設計二，第一次上機考試 ，第六題 (4分)
//
//  宣告一個包含角色基本資訊的結構 genInfo，其成員變數為 名稱(char:10)與座標 x(float) y(float)
//  宣告一個包含以下成員變數的結構 gameChar
//       以 genInfo 宣告的成員變數 gi
//       血量 hp(int)、攻擊力 atk(int)
//
//  主程式以 gameChar 宣告一維結構陣列 npc 可儲存 3 個角色
//  讓使用者輸入第一個 npc 角色的資訊，將該角色的內容設定給第二與三個個角色
//  讓使用者輸入第二與第三角色的名稱與攻擊力 atk(int)
//  計算三個角色的總攻擊力並輸出
// 
//  指令參考
//  結構宣告：struct
//
//  參考以下的輸出結果
//  
//  輸入名稱: x
//  輸入座標 : 1 2
//  輸入血量 : 10
//  輸入攻擊力 : 10
//  輸入名稱 : y
//  輸入攻擊力 : 20
//  輸入名稱 : z
//  輸入攻擊力 : 30
//  x 在(1, 2)血量  10 攻擊力  10
//  y 在(1, 2)血量  10 攻擊力  20
//  z 在(1, 2)血量  10 攻擊力  30
//  攻擊力  60
//

#define EX
#ifdef EX6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// 宣告  genInfo
struct genInfo {
	char name[10];
	float posx;
	float posy;
};

// 宣告  gameChar
struct gameChar {
	struct genInfo gi;
	int hp;
	int atk;
};

int main(void)
{
	int i, tot=0;
	struct gameChar npc[3];						// 宣告一維結構陣列變 npc
	printf("輸入名稱: "); gets(npc[0].gi.name);  // 輸入名稱
	printf("輸入座標: "); scanf("%f%f", &npc[0].gi.posx, &npc[0].gi.posy);
	printf("輸入血量 : "); scanf("%d",&npc[0].hp );
	printf("輸入攻擊力 : "); scanf("%d", &npc[0].atk);
	rewind(stdin);
							// 將該角色的內容設定給第二與三個個角色
	npc[1] = npc[0];
	npc[2] = npc[0];

	// 輸出兩個角色資訊
	for ( i = 1; i < 3; i++) // 這個不能改
	{
		printf("輸入名稱: "); gets(npc[i].gi.name);  // 輸入名稱
		printf("輸入攻擊力 : "); scanf("%d",&npc[i].atk); //輸入攻擊力
		rewind(stdin);
	}
	// 輸出角色資訊
	for (i = 0; i < 3; i++) // 這個不能改
	{
		printf("%s 在(%2.0f,%2.0f)", npc[i].gi.name, npc[i].gi.posx, npc[i].gi.posy);
		printf("血量 %3d 攻擊力 %3d\n", npc[i].hp, npc[i].atk);
	}
	// 計算總攻擊力
	for (i = 0; i < 3; i++) // 這個不能改
	{
		tot += npc[i].atk;
	}
	printf("攻擊力 %3d\n", tot);

	system("pause"); return(0);
}
#endif