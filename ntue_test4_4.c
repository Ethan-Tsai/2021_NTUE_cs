//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�ĥ|�D (3��)
//
//  A B C �T�ӳ��O 3X3 �}�C�A���� C = A + B ���p��,
//  ���D�������ܼƳ��u��Ϋ��Ы����A����ϥΰ}�C����
//  �ھڥH�U�����ѻ����A�����һݭn���{���X�A�ÿ�X�H�U�����e
//
// �ѦҥH�U����X���G
//
// 5   1   7
// 9  -3   3
// 1   4   6

#define EX
#ifdef EX4

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j;
	int A[3][3] = { { 3,2,4 },{ 6,1,5 },{ 2,1,4 } };	// �ŧi�}�C A �ó]�w���
	int B[3][3] = { { 2,-1,3 },{ 3,-4,-2 },{ -1,3,2 } };  	// �ŧi�}�C B �ó]�w��� 
	int C[3][3] = { 0 };  		// �ŧi�}�C C �ó]�w��Ȭ� 0
						// �ŧi pa pb pc �������ܼ�
	int *pa, *pb, *pc;
	for ( i = 0; i < 3; i++)  // �o�Ӥ����
	{
								//pa ���V A �� i row �_�I�A pb ���V B �� i row �_�I�A pc ���V C �� i row �_�I
		pa = A+i; pb = B+i; pc = C+i;
		for (j = 0; j < 3; j++) // �o�Ӥ����
								// �H pa pb pc ���� C = A + B �p��
			*(pc + j) = *(pa + j) + *(pb + j);
	}

			// pc ���V C ���_�l��m
	pc = C;
	for ( i = 0; i < 9; i++)  // �o�Ӥ����
	{
		printf("%3d ", *(pc + i));
		if ((i + 1) % 3 == 0) {
			printf("\n");
		}
	}
		  // �H pc �L�X C �����e
		printf("\n");					// �C�T�Ӵ��@��
	system("pause"); return(0);
}
#endif

