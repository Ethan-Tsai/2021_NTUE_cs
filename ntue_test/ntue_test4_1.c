//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�Ĥ@�D (2��)
//
//  �ھڥH�U������ �������w���{���X�P��X�A�H�U�Ҧ����{���X�������ϥ� ���Ъ��Φ�
//  �����H�U����X���G
// ------------------------------
//	n = 11
//	n = 14
//	f = 31.40
//

#define EX1
#ifdef EX

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	int n = 10,*pi;
	float f = 3.14f;
				// �ŧi pv �� void ���O�����ܼ�
				// �ŧi pi �� int ���O�����ܼ�
	void *pv;
				// �N pi ���V�ܼ� n
				//��{ n++ ���\��,�������O�� pi �B�ϥ� ++ �B��l
	pi = &n;
	*pi = *pi + 1;
	printf("n = %d\n",*pi);  // �����H pi ����X���ܼ�

				// �N pv ���V n
				// ��{ n = n + 3 ���\��,�������O�� pv �ܼ�
	pv = &n;
	*(int *)pv = *(int *)pv + 3;
	printf("n = %d\n", *(int *)pv);  // �����H pv ����X���ܼ�

				// �N pv ���V f
				// ��{ f = f * 10.0f ���\��,�������O�� pv �ܼ�
	pv = &f;
	*(float *)pv = (*(float *)pv)*10.0f;
	printf("f = %5.2f\n", *(float *)pv);     // �����H pv ����X���ܼ�

	system("pause"); return(0);
}

#endif