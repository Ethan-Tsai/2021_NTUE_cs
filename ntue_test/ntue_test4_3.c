//  �{���]�p�G�A�Ĥ@���W���Ҹ� �A�ĤT�D (3��)
//  
//  ���� add product �P swap_cal �禡���\��
//  �T�Ө禡������Ӥ޼�(���]�W�٬� a b ) ���O�ǫ��Ъ����� 
//  �ھڥH�U�����ѻ����A�����һݭn���{���X�A�ÿ�X�H�U�����e
//
//  product(3, 5) = 15
//  swap_cal(5, 3) = 17
//  add(5, 3) = 8
//

#define EX
#ifdef EX
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
// add �禡�\��
// �Ǧ^ a + b �����G
int add(int *,int *);
int product(int *, int *);
int swap(int *, int *);
int add(int* x, int* y) {
	return((*x) + (*y));
}
int product(int* x, int* y) {
	return((*x)*(*y));
}
int swap_cal(int* x, int* y) {
	int temp;
	int i;
	temp = x; x = y; y = temp;
	i = ((*x)*(*y)) + ((*x) - (*y));
	return(i);
}

// product �禡�\��
// �Ǧ^ a * b �����G


// swap_cal �禡�\��
// ���洫�ǤJ���ܼơA�M��b���� a*b +(a - b) ���p��
// �^�ǭȬ� a*b +(a - b) ���p�⵲�G
// 


int main()
{
	int a = 3, b = 5;
	int ret;
					// �ŧi�i�H���V add �B product �P  swap_cal ���禡�����ܼ� pfun
					// �]�w���V product �禡
					// �I�s pfun �^�ǭȵ� ret
	int(*pfun)(int *, int *);
	pfun = product;
	ret = pfun(&a, &b);
	printf("product(%d,%d) = %d\n", a, b, ret);

					// �]�w���V swap_cal �禡
					// �I�s pfun �^�ǭȵ� ret
	pfun = swap_cal;
	ret = pfun(&a, &b);
	printf("swap_cal(%d,%d) = %d\n", a, b, ret);

					// �]�w���V add �禡
					// �I�s pfun �^�ǭȵ� ret
	pfun = add;
	ret = pfun(&a, &b);
	printf("add(%d,%d) = %d\n", a, b, ret);

	system("pause"); return(0);
}


#endif
//
//void swap(int *, int *); // �洫��Ӥ޼ƪ����e
//void swap(int *x, int *y)
//{
//	int temp;
//	temp = *x; *x = *y; *y = temp; // ���P�� temp = a; a = b; b = temp;
//	printf("In swap...\n");
//	printf("x=%d,y=%d\n", *x, *y);  /* ��X�b�禡����*/
//	printf("x ���k��: %p, y ���k��: %p\n", x, y);
//	printf("x ������: %p, y ������: %p\n", &x, &y);
//}
//int main()
//{
//	int a = 5, b = 10;
//	printf("In main... Before Swap\n");
//	printf("a=%d,b=%d\n", a, b); printf("a ����}: %p, b ����}: %p\n", &a, &b);
//	swap(&a, &b);  // �H�ǫ��Ъ��覡�ǻ� a, b ����}
//	printf("In main... After Swap\n");
//	printf("a=%d,b=%d\n", a, b); printf("a ����}: %p, b ����}: %p\n", &a, &b);
//	system("pause"); return(0);
//}

