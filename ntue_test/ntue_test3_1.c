// 程式設計一，第三次上機寫題第一題 (2 分)
//    
// 一個部分 1 分
//
// 以 for 的巢狀迴圈輸出九九乘法表
//
// 1   2   3   4   5   6   7   8   9
// 2   4   6   8  10  12  14  16  18
// 3   6   9  12  15  18  21  24  27
// 4   8  12  16  20  24  28  32  36
// 5  10  15  20  25  30  35  40  45
// 6  12  18  24  30  36  42  48  54
// 7  14  21  28  35  42  49  56  63
// 8  16  24  32  40  48  56  64  72
// 9  18  27  36  45  54  63  72  81 
// 
// 以 for 計算並輸出 1+ 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) 的和。
// n 由使用者輸入
//
// 輸入 n : 6
// 1 + 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) = 40.56250000
//
// 提示: 3^3 代表 3*3*3 , 建議宣告成 float 浮點數型別比較好計算跟輸出
//

#define p
#ifdef p

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int i, j;
		printf("\n");
		for (i = 1; i <= 9; i++) {
			printf("%3d", i);
			for (j = 2; j <= 9; j++) {
				printf("%3d", i*j);
			}
			printf("\n");
		}
	int n;

		float dtotal=0, dx,dy;
		printf("輸入n=");
		scanf("%d", &n);
		float s = 1;
		for (int i = 1,dx=3, dy = 1; i < n; i++,dx*=3, dy *= 2)
		{
			s += ((float)dx / (float)dy);
		}
		printf("1+ 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) = %2.8f \n",s);
		system("pause");
		return(0);
}

#endif







//printf("\n\n輸入 n : "); scanf("%d");

//	printf("1+ 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) = %2.8f \n");
//	system("pause"); return(0);
//}

