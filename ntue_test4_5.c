//  程式設計二，第一次上機考試 ，第五題 (2分)
// 
//  宣告結構  StuScores，包含以下的成員變數 姓名(char:10)
//      儲存 國文(int) 英文(int) 與數學(int) 的三科成績
//      儲存 三科的平均成績(float)
//
//  主程式宣告中, 宣告結構變數 stu, 輸入成績後，計算其平均成績再輸出
//
//  參考以下的輸出結果
//
//  輸入姓名: xyz
//	國文成績 : 70
//	英文成績 : 80
//	數學成績 : 90
//	xyz 的平均成績為 80.00
//

#define EX
#ifdef EX5
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
			// 宣告結構 StuScores
struct StuScores {
	char name[10];
	int chi;
	int eng;
	int mat;
	float ave;
};

int main(void)
{
	struct	StuScores stu;	// 宣告結構變數 stu
	float i;
	printf("輸入姓名: "); scanf("%s", &stu.name );	// 輸入姓名
	printf("國文成績: "); scanf("%d", &stu.chi);	// 輸入國文成績
	printf("英文成績: "); scanf("%d", &stu.eng);	// 輸入英文成績
	printf("數學成績: "); scanf("%d",&stu.mat );	// 輸入數學成績
	i = ((stu.chi) + (stu.eng) + (stu.mat)) / 3.0f;								// 計算平均
	printf("%s 的平均成績為 %5.2f\n",stu.name,i);
	system("pause"); return(0);
}

#endif
