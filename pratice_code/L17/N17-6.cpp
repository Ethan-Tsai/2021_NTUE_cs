#include <iostream>
using namespace std;
//#define MAX_SIZE 10
#ifndef MAX_SIZE	// MAX_SIZE 沒有定義時, 展開以下的程式區塊
#define  MAX_SIZE 10
#endif
int main(void) {
	int n;
	int iX[MAX_SIZE];
	n = MAX_SIZE;
	cout << "陣列 iX 共有 " << n << " 個元素" << endl;
	system("pause"); return(0);
}
