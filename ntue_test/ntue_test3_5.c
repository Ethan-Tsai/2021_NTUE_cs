// �{���]�p�@�A�ĤT���W���g�D�Ĥ��D (4 ��)
//
//
// ��X 60 �� 500 �����Ҧ���ơA�åB�C 6 �Ӵ��@��
// �p���覡 3 �� : ��X�Ҧ������
//    	    1 �� : �C 6 �Ӵ��@�� 
//           
//  61  67  71  73  79
//  83  89  97 101 103
// 107 109 113 127 131
// 137 139 149 151 157
// 163 167 173 179 181
// 191 193 197 199 211
// 223 227 229 233 239
// 241 251 257 263 269
// 271 277 281 283 293
//

#define p
#ifdef p1


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int prime(int n)
{
	int ix=2; int flag = 0;
		while(( ix*ix<= n) && (flag==0))
		{
			if (!(n % ix)) 
			{ 
				flag =1;
			}
			ix++;
		}
		return(flag);
}
int main(void)
{
	int a=60, b=0, c;
	while (a<500)
	{
		if (prime(a)== 0)
		{
			printf(" %4d", a); b++;
			if (b == 5)
			{
				b = 0; printf("\n");
			}
		}
		a++;
	}
	printf("\n");
		system("pause");
		return(0);
}

#endif