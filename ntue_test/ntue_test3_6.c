// �{���]�p�@�A�ĤT���W���g�D�Ĥ��D (2 ��)
//
// �p��100 �� 1000 �����Ҧ��ƨ�H�U���`�M
// 1. �O 5 �����ơA�B��Q3�㰣���M�A����Q3�㰣����Q2�㰣���M (���B�����ϥ� if...else)
// 2. �Q 5 ���l 1�A�B��Q 3 �㰣�A������Q 6 �㰣�M
// 2. �Q 5 ���l 3�A�B��Q 4 �㰣�A�Τ���Q 7 �㰣���M
// �n�D : 5 �㰣�P�_�����������ϥ� switch-case�A�U case ���h�����ϥ� if...else 

// ��X�Ѧ�
//
// 5 �����ơA�B��Q 3 �㰣���M 32850
// 5 �����ơA����Q 3 �㰣����Q 2 �㰣���M 32400
// �� 5 �l 1�A�B��Q 3 �㰣�A������Q 6 �㰣�M 16380
// �� 5 �l 3�A�B��Q 4 �㰣�A�Τ���Q 7 �㰣���M 88373
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

	printf(" 5 �����ơA�B��Q 3 �㰣���M %5d\n",a);
	printf(" 5 �����ơA����Q 3 �㰣����Q 2 �㰣���M %5d\n",b);
	printf("�� 5 �l 1�A�B��Q 3 �㰣�A������Q 6 �㰣�M %5d\n",c);
	printf("�� 5 �l 3�A�B��Q 4 �㰣�A�Τ���Q 7 �㰣���M %5d\n",d);

	
	system("pause"); return(0);
}

#endif




