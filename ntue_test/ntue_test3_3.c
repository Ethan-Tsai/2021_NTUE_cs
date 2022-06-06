// 程式設計一，第三次上機寫題第三題 (3 分)
//
// 讓使用者輸入一段英文句子，統計並輸出超過(含)3次以上的字母，之後再輸出每一個母音各出現幾次。
//   計分方式 2 分 : 統計並輸出超過(含)3次以上的字母
//            1 分 : 輸出每一個母音各出現幾次(此部分必須以 for 搭配陣列索引的方式才給分)
//
// 輸入一段英文句子, 以#代表結尾
// Whatever our souls are made of, his and mine are the same.#
// a 出現  6 次
// e 出現  8 次
// h 出現  3 次
// m 出現  3 次
// o 出現  3 次
// r 出現  4 次
// s 出現  4 次
//
// 每一個母音各出現
// a 出現   6次
// e 出現   8次
// i 出現   2次
// o 出現   3次
// u 出現   2次
//


#define p31
#ifdef p3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int iAtoZ[26] = { 0 };
	char ch; 
	printf("輸入一段英文句子,以#代表結尾\n");
	while ((ch = getchar()) != '#')
	{
		if (ch >= 'a' && ch <= 'z') 
			iAtoZ[ch - 97]++;
		else if (ch >= 'A' && ch <= 'Z')
			iAtoZ[ch - 65]++;
	}
	for (i = 0; i < 26; i++) 
		if((iAtoZ[i] != 0)&& (iAtoZ[i]>=3))
			printf("%c 出現 %2d 次\n", i + 97, iAtoZ[i]);

	printf("每個母音各出現:\n");
	printf("a出現 %4d 次\n", iAtoZ[0]);
	printf("e出現 %4d 次\n", iAtoZ[4]);
	printf("i出現 %4d 次\n", iAtoZ[8]);
	printf("o出現 %4d 次\n", iAtoZ[14]);
	printf("u出現 %4d 次\n", iAtoZ[20]);
	system("pause");
	return(0);
}
#endif

