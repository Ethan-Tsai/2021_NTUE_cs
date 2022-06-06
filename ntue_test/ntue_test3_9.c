// 程式設計一，第三次上機寫題第九題 (2 分)
//
// 輸出費式係數前 10 項的內容
// 要求 :  1. 宣告一個 int 型別可儲存10個元素的一維陣列 fn , 費式係數儲存在這裏面
//         2. 費式係數的第一項與第二項的 1，必須讓使用者輸入，並儲存到 fn 中
//         3. 最後輸出這 10 個係數的和
// 輸出參考
//
//  輸入第一項 : 1
//	輸入第二項 : 1
//	f1  =  1
//	f2  =  1
//	f3  =  2
//	f4  =  3
//	f5  =  5
//	f6  =  8
//	f7  = 13
//	f8  = 21
//	f9  = 34
//	f10 = 55
//  和 = 143
// 

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
			int i, ifib[11],itotal=0;
			printf("輸入第一項 : "); 
			scanf("%2d",&ifib[0]);
			printf("輸入第二項 : ");
			scanf("%2d",&ifib[1]);
			for (i = 2; i < 11; i++)
			{
				ifib[i] = ifib[i-1] + ifib[i - 2]; 

			}
			for (i = 1; i < 11; i++)
			{
				printf("f%-2d = %2d\n", i-1, ifib[i-1]); itotal += ifib[i - 1];
			}
			printf("和=%2d", itotal);
			printf("\n");
			system("pause");
			return(0);

	}
#endif

















