// �{���]�p�G !! �Ĥ@���W���Ҹ� -- �ĤG�D (3��)
//
//  �b�D�{���ŧi int ���O�������ܼ�(pi)�A�ÿ�J�ݭn�[�`������ n
//  �Q�� malloc �� pi ���o n ���x�s int ���Ŷ�
//		���� : �����ܼ� = (��ƫ��O�W�� *)malloc(�줸�ռ�);
//  �Q�� for �j���J��ƭ�(���B�u���J�ƭȡA����P�ɰ���[�`���p��)
//  �A���Q�� for �j��N��J���ƭȥ[�`, �M��A��X�[�`���G
//  �̫�����t�m���O����  (���� : free)
//
//  �n�D: pi ���ϥγ��������Ъ�����
//
//  �ѦҥH�U����X
//
//  �ݭp��[�`���ƭ�: 3
//	�п�J�� 1 �Ӽƭ� : 30
//	�п�J�� 2 �Ӽƭ� : 40
//	�п�J�� 3 �Ӽƭ� : 50
//	�`�M����120
//

#define EX
#ifdef EX2
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
				// �ŧi��ƫ����ܼ� pi
	int *pi;
	int tot = 0, i, n; // tot �O�`�M, i �O�j���ܼ�, n ���ƭȭӼ�
	printf("�ݭp��[�`���ƭ�: "); scanf("%d", &n);
				// ���o n �� int ���O���x�s�Ŷ��� pi
	pi = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {  // ��J�ƭ�
		printf("�п�J��%2d �Ӽƭ�:", i + 1);
		scanf("%d",	pi+i	); // ��J�� i �����
	}
	for (i = 0; i < n; i++)
	{
		tot = tot + *(pi + i);
	}// �H for �p��[�`�� tot

	printf("�`�M����%d\n",tot );	// ��X
						// ����t�m���O����
	free(pi);
	system("pause"); return(0);
}

#endif

