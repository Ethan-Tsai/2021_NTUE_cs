//  程式設計二，第一次上機考試 ，第八題 (3分)
//
//  宣告一個包含遊戲角色結構 gmaeChar，包含以下的成員
//      名稱(char:10)、血量 hp(int)、攻擊力 atk(int)
//
//  完成  gen 與 prn 函式(參考以下的註解)
//  主程式中
//		宣告一維陣列 npc 可儲存三個角色 
//   	呼叫 gen 將 npc 與 3 傳入，建立陣列的內容
//      呼叫 prn 顯示傳入的 npc 的內容
//
//  本題不可使用全域變數，gen 與 prn 函式中都必須使用指標的型式來完成，不能使用陣列
//
// 參考以下的輸出
//
//  輸入名稱: x
//	輸入血量 : 10
//	輸入攻擊力 : 10
//	輸入名稱 : y
//	輸入血量 : 20
//	輸入攻擊力 : 20
//	x 的血量  10 攻擊力  10
//	y 的血量  20 攻擊力  20

#define EX
#ifdef EX8
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// 宣告  genInfo
struct genInfo {
	char name[10];
	int hp;
	int atk;
	
};

//  函式 gen, 兩個引數，第一個為傳入的 gmaeChar 的指標變數，第二個陣列的大小 (int)
//  功能是輸入角色的名稱、血量 與 攻擊力
void gen(struct genInfo* genchar, int n) {
	int i;
	for (i=0; i < n; i++) {
		printf("輸入名稱: "); gets((genchar + i)->name);  // 輸入名稱
		printf("輸入血量 : "); scanf("%d", &(genchar + i)->hp);
		printf("輸入攻擊力 : "); scanf("%d", &(genchar + i)->atk);
		rewind(stdin);
	}
}

//  函式 prn, 兩個引數，第一個為傳入的 g                       ameChar 的指標變數，第二個陣列的大小 (int)
void prn(struct genInfo genChar[], int n) {
	int i;
	for (i = 0; i < n; i++) // 這個不能改
	{
		printf("%s 的血量 %3d 攻擊力 %3d\n", genChar[i].name, genChar[i].hp, genChar[i].atk);
	}
}
//  功能是輸出角色的名稱、血量 與 攻擊力

int main(void)
{
	struct genInfo* npc;						// 宣告結構指標變數 npc
	if ((npc = (struct genInfo*)malloc(sizeof(struct genInfo) * 2)) == NULL) {
		return 0;
	}// 以 malloc 取得兩個儲存空間給 npc

	gen(npc, 2);		// 呼叫 gen
	prn(npc, 2);				// 呼叫 prn
	free(npc);				// 釋放 npc 所取得的空間
	system("pause"); return(0);
}

#endif