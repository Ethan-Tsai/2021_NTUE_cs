// �{���]�p�@�A�ĤT���W���g�D�ĤE�D (2 ��)
//
// ��X�O���Y�ƫe 10 �������e
// �n�D :  1. �ŧi�@�� int ���O�i�x�s10�Ӥ������@���}�C fn , �O���Y���x�s�b�o�ح�
//         2. �O���Y�ƪ��Ĥ@���P�ĤG���� 1�A�������ϥΪ̿�J�A���x�s�� fn ��
//         3. �̫��X�o 10 �ӫY�ƪ��M
// ��X�Ѧ�
//
//  ��J�Ĥ@�� : 1
//	��J�ĤG�� : 1
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
//  �M = 143
// 

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
			int i, ifib[11],itotal=0;
			printf("��J�Ĥ@�� : "); 
			scanf("%2d",&ifib[0]);
			printf("��J�ĤG�� : ");
			scanf("%2d",&ifib[1]);
			for (i = 2; i < 11; i++)
			{
				ifib[i] = ifib[i-1] + ifib[i - 2]; 

			}
			for (i = 1; i < 11; i++)
			{
				printf("f%-2d = %2d\n", i-1, ifib[i-1]); itotal += ifib[i - 1];
			}
			printf("�M=%2d", itotal);
			printf("\n");
			system("pause");
			return(0);

	}
#endif

















