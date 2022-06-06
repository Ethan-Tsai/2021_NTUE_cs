//  程式設計二，第一次上機考試 ，第七題 (3分)
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
//  本題不可使用全域變數
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
#ifdef EX7
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// 宣告  genInfo
struct genInfo {
	char name[20];
	int hp;
	int atk;
	
};
//  函式 gen, 兩個引數，第一個為傳入的 gmaeChar 一維結構陣列，第二個陣列的大小 (int)
void gen(struct genInfo genChar[], int n) {
	int i;
	//  功能是輸入角色的名稱、血量 與 攻擊力
	for (i = 0; i < n; i++) {
		printf("輸入名稱: "); gets(genChar[i].name);  // 輸入名稱
		printf("輸入血量 : "); scanf("%d",&genChar[i].hp);
		printf("輸入攻擊力 : "); scanf("%d", &genChar[i].atk);
		rewind(stdin);
	}
}


//for
//  函式 prn, 兩個引數，第一個為傳入的 gmaeChar 一維結構陣列，第二個陣列的大小 (int)
//  功能是輸出角色的名稱、血量 與 攻擊力
void prn(struct genInfo genChar[],int n){
	int i;
	for (i = 0; i < n; i++) // 這個不能改
	{
		printf("%s 的血量 %3d 攻擊力 %3d\n", genChar[i].name,genChar[i].hp,genChar[i].atk);
	}
}

int main(void)
{
	struct genInfo npc[2];				// 宣告一維結構陣列變 npc
	gen(&npc[0], 2);// 呼叫 gen
	prn(&npc[0], 2);			// 呼叫 prn
	system("pause"); return(0);
}

#endif




