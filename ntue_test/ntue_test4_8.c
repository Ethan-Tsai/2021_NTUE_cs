//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�ĤK�D (3��)
//
//  �ŧi�@�ӥ]�t�C�����⵲�c gmaeChar�A�]�t�H�U������
//      �W��(char:10)�B��q hp(int)�B�����O atk(int)
//
//  ����  gen �P prn �禡(�ѦҥH�U������)
//  �D�{����
//		�ŧi�@���}�C npc �i�x�s�T�Ө��� 
//   	�I�s gen �N npc �P 3 �ǤJ�A�إ߰}�C�����e
//      �I�s prn ��ܶǤJ�� npc �����e
//
//  ���D���i�ϥΥ����ܼơAgen �P prn �禡���������ϥΫ��Ъ������ӧ����A����ϥΰ}�C
//
// �ѦҥH�U����X
//
//  ��J�W��: x
//	��J��q : 10
//	��J�����O : 10
//	��J�W�� : y
//	��J��q : 20
//	��J�����O : 20
//	x ����q  10 �����O  10
//	y ����q  20 �����O  20

#define EX
#ifdef EX8
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// �ŧi  genInfo
struct genInfo {
	char name[10];
	int hp;
	int atk;
	
};

//  �禡 gen, ��Ӥ޼ơA�Ĥ@�Ӭ��ǤJ�� gmaeChar �������ܼơA�ĤG�Ӱ}�C���j�p (int)
//  �\��O��J���⪺�W�١B��q �P �����O
void gen(struct genInfo* genchar, int n) {
	int i;
	for (i=0; i < n; i++) {
		printf("��J�W��: "); gets((genchar + i)->name);  // ��J�W��
		printf("��J��q : "); scanf("%d", &(genchar + i)->hp);
		printf("��J�����O : "); scanf("%d", &(genchar + i)->atk);
		rewind(stdin);
	}
}

//  �禡 prn, ��Ӥ޼ơA�Ĥ@�Ӭ��ǤJ�� g                       ameChar �������ܼơA�ĤG�Ӱ}�C���j�p (int)
void prn(struct genInfo genChar[], int n) {
	int i;
	for (i = 0; i < n; i++) // �o�Ӥ����
	{
		printf("%s ����q %3d �����O %3d\n", genChar[i].name, genChar[i].hp, genChar[i].atk);
	}
}
//  �\��O��X���⪺�W�١B��q �P �����O

int main(void)
{
	struct genInfo* npc;						// �ŧi���c�����ܼ� npc
	if ((npc = (struct genInfo*)malloc(sizeof(struct genInfo) * 2)) == NULL) {
		return 0;
	}// �H malloc ���o����x�s�Ŷ��� npc

	gen(npc, 2);		// �I�s gen
	prn(npc, 2);				// �I�s prn
	free(npc);				// ���� npc �Ҩ��o���Ŷ�
	system("pause"); return(0);
}

#endif