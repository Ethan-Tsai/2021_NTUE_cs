// 程式設計一，第三次上機寫題第七題 (2 分)
//
// 字串反轉
// 利用一個迴圈不斷的接收使用者輸入一個字串，然後輸出該字串反轉後的結果，
// 當使用者輸入的字串長度為1 (只有一個字元時) 就停止程式的執行。
// 
//  提示: 你會使用到 strlen 這個函式
//
//  輸出參考
//  輸入一個字串: Apple
//	該字串的反向 : elppA
//	輸入一個字串 : Cat
//	該字串的反向 : taC
//	輸入一個字串 : q
//	該字串的反向 : q

#define p1
#ifdef p

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
		int i, ilength; /* ilength: 輸入字串的長度 */
		char str1[20];char str2[20]; /* 接收輸入的字串 */
		do 
		{
			printf("輸入一個字串:"); scanf("%s", str1);
			ilength = strlen(str1);
			for (i = 0; i < ilength; i++)
			{
				str2[ilength - i - 1] = str1[i];
				str2[ilength] = NULL;
			}
			printf("該字串的反向:%s\n", str2);
		} while (ilength>1);
		
system("pause"); return(0);
}

#endif
