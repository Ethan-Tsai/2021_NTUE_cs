// �{���]�p�@�A�ĤT���W���g�D�Ĥ@�D (2 ��)
//    
// �@�ӳ��� 1 ��
//
// �H for ���_���j���X�E�E���k��
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
// �H for �p��ÿ�X 1+ 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) ���M�C
// n �ѨϥΪ̿�J
//
// ��J n : 6
// 1 + 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) = 40.56250000
//
// ����: 3^3 �N�� 3*3*3 , ��ĳ�ŧi�� float �B�I�ƫ��O����n�p����X
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
		printf("��Jn=");
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







//printf("\n\n��J n : "); scanf("%d");

//	printf("1+ 3/1 + 3^2/2 + 3^3/2^2 + ... + 3^n/2^(n-1) = %2.8f \n");
//	system("pause"); return(0);
//}

