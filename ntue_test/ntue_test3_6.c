// 程式設計一，第三次上機寫題第六題 (2 分)
//
// 計算100 到 1000 中的所有數其以下的總和
// 1. 是 5 的倍數，且能被3整除的和，不能被3整除但能被2整除的和 (此處必須使用 if...else)
// 2. 被 5 除餘 1，且能被 3 整除，但不能被 6 整除和
// 2. 被 5 除餘 3，且能被 4 整除，或不能被 7 整除的和
// 要求 : 5 整除與否的分類必須使用 switch-case，各 case 中則必須使用 if...else 

// 輸出參考
//
// 5 的倍數，且能被 3 整除的和 32850
// 5 的倍數，不能被 3 整除但能被 2 整除的和 32400
// 除 5 餘 1，且能被 3 整除，但不能被 6 整除和 16380
// 除 5 餘 3，且能被 4 整除，或不能被 7 整除的和 88373
//
   
#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int a, b, c, d;
	a = b = c = d = 0;
	for (n = 100; n < 1000; n++)
	{
		switch (n%5)
		{
		case 0:
			if (n % 3 == 0)
			{
				a = a + n;
			}
			else if(n%2==0)
			{
				b = b + n;
			}
			break;
		case 1:
			if ((n % 3 == 0) && (n % 6 != 0))
			{
				c = c + n;
			}
			break;
		case 3:
			if ((n % 4 == 0) || (n % 7 != 0)) 
			{
				d = d + n;
			}
			break;
		}

	}

	printf(" 5 的倍數，且能被 3 整除的和 %5d\n",a);
	printf(" 5 的倍數，不能被 3 整除但能被 2 整除的和 %5d\n",b);
	printf("除 5 餘 1，且能被 3 整除，但不能被 6 整除和 %5d\n",c);
	printf("除 5 餘 3，且能被 4 整除，或不能被 7 整除的和 %5d\n",d);

	
	system("pause"); return(0);
}

#endif




