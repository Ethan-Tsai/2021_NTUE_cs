// �{���]�p�@�A�ĤT���W���g�D�ĤG�D (4 ��)
//
// �g��Ө禡�A�ç����U�۫��w�������A�C�@�ӳ��� 2 ��
// �n�D:  �@�w�n�Ψ禡�����A�B�禡���j�鳣�u��ϥ� for
//  
// sum   �禡 : ��Ӥ޼� n �P m  ���O int ���O�A�^�ǭȫ��O�]�O int�A�\��O�p�� n+...+m ���`�M
// pchar �禡 : ��Ӥ޼� n (int) �P ch (char)�A������X n �� ch �r�� (���ݭn����)
// 
// ��X�Ѧ�
// 
// ��J n = 2
// ��J m = 99
// 2 + ... + 99 = 4949
//
//
// ��J�h�� n = 6
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//

#define p
#ifdef p1


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void pchar(int n, char ch)
{
	int a;
	for (a = 0; a < n; a++)
	{
		printf("%c", ch);
	}

}

int sum(int f, int l)
{
	int a; 
	int total=0;
	for (a=f ;  a<= l; a++)
	{
		total += a;
	}
	return (total);
}

int main(void)
{


	int r, s;
	int total;
	printf("��Jf:");
	scanf("%d", &r);
	printf("��Jl:");
	scanf("%d", &s);
	total=sum(r, s);
	printf("2 + ... + 99 = %d", total);
	int n = 0;
	int a;
	printf("��J�n��X���h :\n");
	scanf("%d", &n);

	for (a = 1; a <= n; a++)
	{
		pchar((n - a), ' ');
		pchar((2 * a - 1), '*');
		pchar(1, '\n');
	}

	system("pause"); return(0);
}

#endif