//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�ĤC�D (3��)
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
//  ���D���i�ϥΥ����ܼ�
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
#ifdef EX7
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// �ŧi  genInfo
struct genInfo {
	char name[20];
	int hp;
	int atk;
	
};
//  �禡 gen, ��Ӥ޼ơA�Ĥ@�Ӭ��ǤJ�� gmaeChar �@�����c�}�C�A�ĤG�Ӱ}�C���j�p (int)
void gen(struct genInfo genChar[], int n) {
	int i;
	//  �\��O��J���⪺�W�١B��q �P �����O
	for (i = 0; i < n; i++) {
		printf("��J�W��: "); gets(genChar[i].name);  // ��J�W��
		printf("��J��q : "); scanf("%d",&genChar[i].hp);
		printf("��J�����O : "); scanf("%d", &genChar[i].atk);
		rewind(stdin);
	}
}


//for
//  �禡 prn, ��Ӥ޼ơA�Ĥ@�Ӭ��ǤJ�� gmaeChar �@�����c�}�C�A�ĤG�Ӱ}�C���j�p (int)
//  �\��O��X���⪺�W�١B��q �P �����O
void prn(struct genInfo genChar[],int n){
	int i;
	for (i = 0; i < n; i++) // �o�Ӥ����
	{
		printf("%s ����q %3d �����O %3d\n", genChar[i].name,genChar[i].hp,genChar[i].atk);
	}
}

int main(void)
{
	struct genInfo npc[2];				// �ŧi�@�����c�}�C�� npc
	gen(&npc[0], 2);// �I�s gen
	prn(&npc[0], 2);			// �I�s prn
	system("pause"); return(0);
}

#endif




