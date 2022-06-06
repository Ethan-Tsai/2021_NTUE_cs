// 程式設計二 !! 第一次上機考試 -- 第二題 (3分)
//
//  在主程式宣告 int 型別的指標變數(pi)，並輸入需要加總的筆數 n
//  利用 malloc 為 pi 取得 n 個儲存 int 的空間
//		提示 : 指標變數 = (資料型別名稱 *)malloc(位元組數);
//  利用 for 迴圈輸入對數值(此處只能輸入數值，不能同時執行加總的計算)
//  再次利用 for 迴圈將輸入的數值加總, 然後再輸出加總結果
//  最後釋放配置的記憶體  (提示 : free)
//
//  要求: pi 的使用都必須指標的型式
//
//  參考以下的輸出
//
//  需計算加總的數值: 3
//	請輸入第 1 個數值 : 30
//	請輸入第 2 個數值 : 40
//	請輸入第 3 個數值 : 50
//	總和等於120
//

#define EX
#ifdef EX2
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
				// 宣告整數指標變數 pi
	int *pi;
	int tot = 0, i, n; // tot 是總和, i 是迴圈變數, n 為數值個數
	printf("需計算加總的數值: "); scanf("%d", &n);
				// 取得 n 個 int 型別的儲存空間給 pi
	pi = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {  // 輸入數值
		printf("請輸入第%2d 個數值:", i + 1);
		scanf("%d",	pi+i	); // 輸入第 i 筆資料
	}
	for (i = 0; i < n; i++)
	{
		tot = tot + *(pi + i);
	}// 以 for 計算加總到 tot

	printf("總和等於%d\n",tot );	// 輸出
						// 釋放配置的記憶體
	free(pi);
	system("pause"); return(0);
}

#endif

