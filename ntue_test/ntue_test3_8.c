// �{���]�p�@�A�ĤT���W���g�D�ĤK�D (3 ��)
//
// �ŧi�@�Ӥ@���}�C�i�H�x�s 12 �Ӿ��(int)
// �Q�ζüƲ��� 1 �� 99 �����ƭȡA�x�s��o�Ӱ}�C��
// ��X�o12�Ӽƪ��̤j�ȻP�̤p��
//
// 1  74  59  55  73  64  15  78  42  24  89  22
// �̤j�� = 89
// �̤p�� = 1
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


		printf("�̤j�� = %d\n�̤p�� = %d\n", fmax, fmin);
		system("pause");
		return(0);
}

#endif
