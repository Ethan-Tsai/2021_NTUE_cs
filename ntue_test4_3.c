//  程式設計二，第一次上機考試 ，第三題 (3分)
//  
//  完成 add product 與 swap_cal 函式的功能
//  三個函式都有兩個引數(假設名稱為 a b ) 都是傳指標的型式 
//  根據以下的註解說明，完成所需要的程式碼，並輸出以下的內容
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
// add 函式功能
// 傳回 a + b 的結果
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

// product 函式功能
// 傳回 a * b 的結果


// swap_cal 函式功能
// 先交換傳入的變數，然後在執行 a*b +(a - b) 的計算
// 回傳值為 a*b +(a - b) 的計算結果
// 


int main()
{
	int a = 3, b = 5;
	int ret;
					// 宣告可以指向 add 、 product 與  swap_cal 的函式指標變數 pfun
					// 設定指向 product 函式
					// 呼叫 pfun 回傳值給 ret
	int(*pfun)(int *, int *);
	pfun = product;
	ret = pfun(&a, &b);
	printf("product(%d,%d) = %d\n", a, b, ret);

					// 設定指向 swap_cal 函式
					// 呼叫 pfun 回傳值給 ret
	pfun = swap_cal;
	ret = pfun(&a, &b);
	printf("swap_cal(%d,%d) = %d\n", a, b, ret);

					// 設定指向 add 函式
					// 呼叫 pfun 回傳值給 ret
	pfun = add;
	ret = pfun(&a, &b);
	printf("add(%d,%d) = %d\n", a, b, ret);

	system("pause"); return(0);
}


#endif
//
//void swap(int *, int *); // 交換兩個引數的內容
//void swap(int *x, int *y)
//{
//	int temp;
//	temp = *x; *x = *y; *y = temp; // 等同於 temp = a; a = b; b = temp;
//	printf("In swap...\n");
//	printf("x=%d,y=%d\n", *x, *y);  /* 輸出在函式中交*/
//	printf("x 的右值: %p, y 的右值: %p\n", x, y);
//	printf("x 的左值: %p, y 的左值: %p\n", &x, &y);
//}
//int main()
//{
//	int a = 5, b = 10;
//	printf("In main... Before Swap\n");
//	printf("a=%d,b=%d\n", a, b); printf("a 的位址: %p, b 的位址: %p\n", &a, &b);
//	swap(&a, &b);  // 以傳指標的方式傳遞 a, b 的位址
//	printf("In main... After Swap\n");
//	printf("a=%d,b=%d\n", a, b); printf("a 的位址: %p, b 的位址: %p\n", &a, &b);
//	system("pause"); return(0);
//}

