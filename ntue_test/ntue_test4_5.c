//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�Ĥ��D (2��)
// 
//  �ŧi���c  StuScores�A�]�t�H�U�������ܼ� �m�W(char:10)
//      �x�s ���(int) �^��(int) �P�ƾ�(int) ���T�즨�Z
//      �x�s �T�쪺�������Z(float)
//
//  �D�{���ŧi��, �ŧi���c�ܼ� stu, ��J���Z��A�p��䥭�����Z�A��X
//
//  �ѦҥH�U����X���G
//
//  ��J�m�W: xyz
//	��妨�Z : 70
//	�^�妨�Z : 80
//	�ƾǦ��Z : 90
//	xyz ���������Z�� 80.00
//

#define EX
#ifdef EX5
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
			// �ŧi���c StuScores
struct StuScores {
	char name[10];
	int chi;
	int eng;
	int mat;
	float ave;
};

int main(void)
{
	struct	StuScores stu;	// �ŧi���c�ܼ� stu
	float i;
	printf("��J�m�W: "); scanf("%s", &stu.name );	// ��J�m�W
	printf("��妨�Z: "); scanf("%d", &stu.chi);	// ��J��妨�Z
	printf("�^�妨�Z: "); scanf("%d", &stu.eng);	// ��J�^�妨�Z
	printf("�ƾǦ��Z: "); scanf("%d",&stu.mat );	// ��J�ƾǦ��Z
	i = ((stu.chi) + (stu.eng) + (stu.mat)) / 3.0f;								// �p�⥭��
	printf("%s ���������Z�� %5.2f\n",stu.name,i);
	system("pause"); return(0);
}

#endif
