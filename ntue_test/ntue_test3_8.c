// 祘Α砞璸材Ω诀糶肈材肈 (3 だ)
//
// 蝴皚纗 12 俱计(int)
// ノ睹计玻ネ 1  99 丁计纗硂皚い
// т硂12计程籔程
//
// 1  74  59  55  73  64  15  78  42  24  89  22
// 程 = 89
// 程 = 1
//

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int i;
		int fnum[12];
		srand((unsigned)time(NULL));
		for(i=0;i<12;i++)
		{
			fnum[i] = rand() % 99+1;
		}
		for (i = 0; i < 12; i++) 
		{
			printf("%3d", fnum[i]);
		}
		int fmax, fmin;
		fmax = -1; fmin = 101;
		for (i = 0; i < 12; i++)
		{
			if (fnum[i] < fmin) fmin=fnum[i];
			if (fnum[i] > fmax) fmax=fnum[i];
		}


		printf("程 = %d\n程 = %d\n", fmax, fmin);
		system("pause");
		return(0);
}

#endif
