//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�ĤE�D (2/6/1/2��)
// 

//  ���]�@���쵲��C�]�t�T�Ӹ`�I�A�q�Y�}�l�̧ǩ�m�����e�� 5 8 3
//  �Ыإ߳o���쵲��C�A�ÿ�X�䤺�e
//  �`�I�����c�W�ٺ� TNode�A�̭���Ӧ����ܼơA�x�s�ƭȪ� int ���O��ƻP���V TNode �������ܼ�
//  �p���覡 (1 �� 2 �ФG�ܤ@���g)
//      1.(2 ��) ��¥H TNode �ŧi�T�ӵ��c�ܼơA�ä�u���覡�@�Ӧ�@�ӡA�������쵲��C
//      2.(6 ��) �H�߰ݪ��覡�A���ݭn�إߪ��`�I�ӼơA�H malloc ���o�@�Ӹ`�I�A
// 				 �ëإߤ@�Ӹ`�I���쵲��C�A���� head�Btail ���]�w
//               �M��H for �j��A�Q�� malloc ���o��L���`�I�A��J�ç����s�쵲��C
//      �H�W��ӳ������̧ǿ�X�`�I�����e�A�L�קA�Φ�ؤ覡�A
//   	3.(1 ��) ���p�G�H while �j��A�̧Ǫ��g�L�C�@�Ӹ`�I�ÿ�X�䤺�e�h�A�h�@��
//   	4.(2 ��) ��H while �j��A�̧Ǧa����C�@�Ӹ`�I
//   

// �߰ݭn�إߴX�Ӹ`�I�A�ÿ�J�C�@�Ӹ`�I�n�x�s�����e
// �ѦҥH�U����X�����쵲��C�C
//
// �p���覡�G4 �� : �����`�I���إ߻P��X�A�ӥB�`�I�����o�O�ϥ� malloc�A����ϥΤ@�몺���c�ܼ� 
//           2 �� : �`�I������A�����ϥΰj������񤣱o�ϥμɤO�k
// -------�H�U�� 2 ������X�Ѧ�  --------
// �� 1 �� node �����e : 5
// �� 2 �� node �����e : 8
// �� 3 �� node �����e : 4

// -------�H�U�� 6 + 1 + 2 ������X�Ѧ�  --------
// �п�J�ݭn�X�� node : 3
// �п�J�� 1 �� node �����e : 5
// �п�J��  2 �� node �����e : 8
// �п�J��  3 �� node �����e : 4
// ��  1 �� node �����e�O   5
// ��  2 �� node �����e�O   8
// ��  3 �� node �����e�O   4
//
// ����`�I�����e�O  5
// ����`�I�����e�O  8
// ����`�I�����e�O  4
// �@����F  3 �� node
//

#define EX9
#ifdef EX


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// �ŧi TNode
typedef struct TNode {
	int num;
	struct TNode *Link;
} NODE, *PNODE;

int main(void)
{

	printf("��k�G:\n");
	int i, num, in;
	PNODE pHead, pTail, pGet;
	pHead = pTail = NULL;
	printf("�п�J�ݭn�X�� node : "); scanf("%d", &num);
	if ((pHead = (PNODE)malloc(sizeof(NODE))) == NULL) { 
		printf("�O���餣��\n"); exit(0);
	}
	printf("�п�J��1��node �����e: "); scanf("%d", &in);
	pHead->num = in; pHead->Link = NULL;
	pTail = pHead;
	for (i = 1; i < num; i++) { 
		if ((pGet = (PNODE)malloc(sizeof(NODE))) == NULL) {
			printf("�O���餣��\n"); exit(0);
		}
		printf("�п�J��%d��node �����e: ", i + 1); scanf("%d", &in);
		pGet->num = in; pGet->Link = NULL;	
		pTail->Link = pGet; pTail = pGet;	
	}
	pGet = pHead; i = 1;
	int tot = 0;
	while (pGet != NULL) { 
		printf("��%d��node �����e�O %d\n", i, pGet->num);
		pGet = pGet->Link; i++;
		tot++;
	}
	printf("�@����F%d��node\n", tot);
	system("pause"); return(0);
}
#endif



