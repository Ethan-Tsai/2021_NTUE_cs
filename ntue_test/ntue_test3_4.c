// 程式設計一，第三次上機寫題第四題 (3 分)
//    
// 輸入一個數大於 2 的數，並判斷他是否是 2 的次方
// 計分方式 1 分 : 判斷輸入是否為數值且大於 2 
//          2 分 : 輸出如下的結果 
// 
// 參考以下的輸出
//
// 請輸入一個整數: a
// 請輸入一個整數 : 1
// 請輸入一個整數 : 64
// 你輸入的數值 64 是 2 的 6 次方
//
// 請輸入一個整數: 7
// 你輸入的數值 7 不是是 2 的次方
//

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int n, m = 0;
		int s,istatues;
		int flag = 1;
		do 
		{
			printf("輸入一個整數:");
			istatues=scanf("%d", &n);
			rewind(stdin);
		} while (n < 2 || istatues == 0);

		s = n; //儲存輸入的數
		while (n != 1 && flag == 1)
		{
			if (n % 2 == 0)
			{
				m++;
			}
			else
			{
				flag = 0;
			}
			n = n / 2;
		}
		if (flag == 1)
		{
			printf("你輸入的數值%d是2的%d次方\n", s, m);
		}
		else
		{
			printf("你輸入的數值%d不是2的次方\n", s);
		}
		system("pause");
		return(0);
}

#endif


