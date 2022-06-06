//  程式設計二，第一次上機考試 ，第一題 (2分)
//
//  根據以下的註解 完成指定的程式碼與輸出，以下所有的程式碼都必須使用 指標的形式
//  完成以下的輸出結果
// ------------------------------
//	n = 11
//	n = 14
//	f = 31.40
//

#define EX1
#ifdef EX

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	int n = 10,*pi;
	float f = 3.14f;
				// 宣告 pv 為 void 型別指標變數
				// 宣告 pi 為 int 型別指標變數
	void *pv;
				// 將 pi 指向變數 n
				//實現 n++ 的功能,但必須是用 pi 且使用 ++ 運算子
	pi = &n;
	*pi = *pi + 1;
	printf("n = %d\n",*pi);  // 必須以 pi 當成輸出的變數

				// 將 pv 指向 n
				// 實現 n = n + 3 的功能,但必須是用 pv 變數
	pv = &n;
	*(int *)pv = *(int *)pv + 3;
	printf("n = %d\n", *(int *)pv);  // 必須以 pv 當成輸出的變數

				// 將 pv 指向 f
				// 實現 f = f * 10.0f 的功能,但必須是用 pv 變數
	pv = &f;
	*(float *)pv = (*(float *)pv)*10.0f;
	printf("f = %5.2f\n", *(float *)pv);     // 必須以 pv 當成輸出的變數

	system("pause"); return(0);
}

#endif