// 程式設計一，第三次上機寫題第二題 (4 分)
//
// 寫兩個函式，並完成各自指定的部分，每一個部分 2 分
// 要求:  一定要用函式完成，且函式的迴圈都只能使用 for
//  
// sum   函式 : 兩個引數 n 與 m  都是 int 型別，回傳值型別也是 int，功能是計算 n+...+m 的總和
// pchar 函式 : 兩個引數 n (int) 與 ch (char)，水平輸出 n 個 ch 字元 (不需要換行)
// 
// 輸出參考
// 
// 輸入 n = 2
// 輸入 m = 99
// 2 + ... + 99 = 4949
//
//
// 輸入層數 n = 6
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//

#define p
#ifdef p1


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void pchar(int n, char ch)
{
	int a;
	for (a = 0; a < n; a++)
	{
		printf("%c", ch);
	}

}

int sum(int f, int l)
{
	int a; 
	int total=0;
	for (a=f ;  a<= l; a++)
	{
		total += a;
	}
	return (total);
}

int main(void)
{


	int r, s;
	int total;
	printf("輸入f:");
	scanf("%d", &r);
	printf("輸入l:");
	scanf("%d", &s);
	total=sum(r, s);
	printf("2 + ... + 99 = %d", total);
	int n = 0;
	int a;
	printf("輸入要輸出的層 :\n");
	scanf("%d", &n);

	for (a = 1; a <= n; a++)
	{
		pchar((n - a), ' ');
		pchar((2 * a - 1), '*');
		pchar(1, '\n');
	}

	system("pause"); return(0);
}

#endif