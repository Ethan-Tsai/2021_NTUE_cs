// �{���]�p�@�A�ĤT���W���g�D�ĥ|�D (3 ��)
//    
// ��J�@�ӼƤj�� 2 ���ơA�çP�_�L�O�_�O 2 ������
// �p���覡 1 �� : �P�_��J�O�_���ƭȥB�j�� 2 
//          2 �� : ��X�p�U�����G 
// 
// �ѦҥH�U����X
//
// �п�J�@�Ӿ��: a
// �п�J�@�Ӿ�� : 1
// �п�J�@�Ӿ�� : 64
// �A��J���ƭ� 64 �O 2 �� 6 ����
//
// �п�J�@�Ӿ��: 7
// �A��J���ƭ� 7 ���O�O 2 ������
//

#define p
#ifdef p1

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int n, m = 0;
		int s,istatues;
		int flag = 1;
		do 
		{
			printf("��J�@�Ӿ��:");
			istatues=scanf("%d", &n);
			rewind(stdin);
		} while (n < 2 || istatues == 0);

		s = n; //�x�s��J����
		while (n != 1 && flag == 1)
		{
			if (n % 2 == 0)
			{
				m++;
			}
			else
			{
				flag = 0;
			}
			n = n / 2;
		}
		if (flag == 1)
		{
			printf("�A��J���ƭ�%d�O2��%d����\n", s, m);
		}
		else
		{
			printf("�A��J���ƭ�%d���O2������\n", s);
		}
		system("pause");
		return(0);
}

#endif


