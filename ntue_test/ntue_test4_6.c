//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�Ĥ��D (4��)
//
//  �ŧi�@�ӥ]�t����򥻸�T�����c genInfo�A�䦨���ܼƬ� �W��(char:10)�P�y�� x(float) y(float)
//  �ŧi�@�ӥ]�t�H�U�����ܼƪ����c gameChar
//       �H genInfo �ŧi�������ܼ� gi
//       ��q hp(int)�B�����O atk(int)
//
//  �D�{���H gameChar �ŧi�@�����c�}�C npc �i�x�s 3 �Ө���
//  ���ϥΪ̿�J�Ĥ@�� npc ���⪺��T�A�N�Ө��⪺���e�]�w���ĤG�P�T�ӭӨ���
//  ���ϥΪ̿�J�ĤG�P�ĤT���⪺�W�ٻP�����O atk(int)
//  �p��T�Ө��⪺�`�����O�ÿ�X
// 
//  ���O�Ѧ�
//  ���c�ŧi�Gstruct
//
//  �ѦҥH�U����X���G
//  
//  ��J�W��: x
//  ��J�y�� : 1 2
//  ��J��q : 10
//  ��J�����O : 10
//  ��J�W�� : y
//  ��J�����O : 20
//  ��J�W�� : z
//  ��J�����O : 30
//  x �b(1, 2)��q  10 �����O  10
//  y �b(1, 2)��q  10 �����O  20
//  z �b(1, 2)��q  10 �����O  30
//  �����O  60
//

#define EX
#ifdef EX6

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// �ŧi  genInfo
struct genInfo {
	char name[10];
	float posx;
	float posy;
};

// �ŧi  gameChar
struct gameChar {
	struct genInfo gi;
	int hp;
	int atk;
};

int main(void)
{
	int i, tot=0;
	struct gameChar npc[3];						// �ŧi�@�����c�}�C�� npc
	printf("��J�W��: "); gets(npc[0].gi.name);  // ��J�W��
	printf("��J�y��: "); scanf("%f%f", &npc[0].gi.posx, &npc[0].gi.posy);
	printf("��J��q : "); scanf("%d",&npc[0].hp );
	printf("��J�����O : "); scanf("%d", &npc[0].atk);
	rewind(stdin);
							// �N�Ө��⪺���e�]�w���ĤG�P�T�ӭӨ���
	npc[1] = npc[0];
	npc[2] = npc[0];

	// ��X��Ө����T
	for ( i = 1; i < 3; i++) // �o�Ӥ����
	{
		printf("��J�W��: "); gets(npc[i].gi.name);  // ��J�W��
		printf("��J�����O : "); scanf("%d",&npc[i].atk); //��J�����O
		rewind(stdin);
	}
	// ��X�����T
	for (i = 0; i < 3; i++) // �o�Ӥ����
	{
		printf("%s �b(%2.0f,%2.0f)", npc[i].gi.name, npc[i].gi.posx, npc[i].gi.posy);
		printf("��q %3d �����O %3d\n", npc[i].hp, npc[i].atk);
	}
	// �p���`�����O
	for (i = 0; i < 3; i++) // �o�Ӥ����
	{
		tot += npc[i].atk;
	}
	printf("�����O %3d\n", tot);

	system("pause"); return(0);
}
#endif