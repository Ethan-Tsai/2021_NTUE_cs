//  程式設計二，第一次上機考試 ，第四題 (3分)
//
//  A B C 三個都是 3X3 陣列，執行 C = A + B 的計算,
//  本題的指標變數都只能用指標型式，不能使用陣列型式
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
//
// 參考以下的輸出結果
//
// 5   1   7
// 9  -3   3
// 1   4   6

#define EX
#ifdef EX4

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j;
	int A[3][3] = { { 3,2,4 },{ 6,1,5 },{ 2,1,4 } };	// 宣告陣列 A 並設定初值
	int B[3][3] = { { 2,-1,3 },{ 3,-4,-2 },{ -1,3,2 } };  	// 宣告陣列 B 並設定初值 
	int C[3][3] = { 0 };  		// 宣告陣列 C 並設定初值為 0
						// 宣告 pa pb pc 為指標變數
	int *pa, *pb, *pc;
	for ( i = 0; i < 3; i++)  // 這個不能改
	{
								//pa 指向 A 第 i row 起點， pb 指向 B 第 i row 起點， pc 指向 C 第 i row 起點
		pa = A+i; pb = B+i; pc = C+i;
		for (j = 0; j < 3; j++) // 這個不能改
								// 以 pa pb pc 執行 C = A + B 計算
			*(pc + j) = *(pa + j) + *(pb + j);
	}

			// pc 指向 C 的起始位置
	pc = C;
	for ( i = 0; i < 9; i++)  // 這個不能改
	{
		printf("%3d ", *(pc + i));
		if ((i + 1) % 3 == 0) {
			printf("\n");
		}
	}
		  // 以 pc 印出 C 的內容
		printf("\n");					// 每三個換一行
	system("pause"); return(0);
}
#endif

