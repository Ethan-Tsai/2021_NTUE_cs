// �{���]�p�@�A�ĤT���W���g�D�ĤC�D (2 ��)
//
// �r�����
// �Q�Τ@�Ӱj�餣�_�������ϥΪ̿�J�@�Ӧr��A�M���X�Ӧr�����᪺���G�A
// ��ϥΪ̿�J���r����׬�1 (�u���@�Ӧr����) �N����{��������C
// 
//  ����: �A�|�ϥΨ� strlen �o�Ө禡
//
//  ��X�Ѧ�
//  ��J�@�Ӧr��: Apple
//	�Ӧr�ꪺ�ϦV : elppA
//	��J�@�Ӧr�� : Cat
//	�Ӧr�ꪺ�ϦV : taC
//	��J�@�Ӧr�� : q
//	�Ӧr�ꪺ�ϦV : q

#define p1
#ifdef p

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
		int i, ilength; /* ilength: ��J�r�ꪺ���� */
		char str1[20];char str2[20]; /* ������J���r�� */
		do 
		{
			printf("��J�@�Ӧr��:"); scanf("%s", str1);
			ilength = strlen(str1);
			for (i = 0; i < ilength; i++)
			{
				str2[ilength - i - 1] = str1[i];
				str2[ilength] = NULL;
			}
			printf("�Ӧr�ꪺ�ϦV:%s\n", str2);
		} while (ilength>1);
		
system("pause"); return(0);
}

#endif
