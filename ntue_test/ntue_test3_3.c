// �{���]�p�@�A�ĤT���W���g�D�ĤT�D (3 ��)
//
// ���ϥΪ̿�J�@�q�^��y�l�A�έp�ÿ�X�W�L(�t)3���H�W���r���A����A��X�C�@�ӥ����U�X�{�X���C
//   �p���覡 2 �� : �έp�ÿ�X�W�L(�t)3���H�W���r��
//            1 �� : ��X�C�@�ӥ����U�X�{�X��(�����������H for �f�t�}�C���ު��覡�~����)
//
// ��J�@�q�^��y�l, �H#�N����
// Whatever our souls are made of, his and mine are the same.#
// a �X�{  6 ��
// e �X�{  8 ��
// h �X�{  3 ��
// m �X�{  3 ��
// o �X�{  3 ��
// r �X�{  4 ��
// s �X�{  4 ��
//
// �C�@�ӥ����U�X�{
// a �X�{   6��
// e �X�{   8��
// i �X�{   2��
// o �X�{   3��
// u �X�{   2��
//


#define p31
#ifdef p3

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int iAtoZ[26] = { 0 };
	char ch; 
	printf("��J�@�q�^��y�l,�H#�N����\n");
	while ((ch = getchar()) != '#')
	{
		if (ch >= 'a' && ch <= 'z') 
			iAtoZ[ch - 97]++;
		else if (ch >= 'A' && ch <= 'Z')
			iAtoZ[ch - 65]++;
	}
	for (i = 0; i < 26; i++) 
		if((iAtoZ[i] != 0)&& (iAtoZ[i]>=3))
			printf("%c �X�{ %2d ��\n", i + 97, iAtoZ[i]);

	printf("�C�ӥ����U�X�{:\n");
	printf("a�X�{ %4d ��\n", iAtoZ[0]);
	printf("e�X�{ %4d ��\n", iAtoZ[4]);
	printf("i�X�{ %4d ��\n", iAtoZ[8]);
	printf("o�X�{ %4d ��\n", iAtoZ[14]);
	printf("u�X�{ %4d ��\n", iAtoZ[20]);
	system("pause");
	return(0);
}
#endif

