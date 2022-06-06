#include <iostream>
using namespace std;
#define MAX_SIZE 10
int main(void) {
	int n;
#ifdef MAX_SIZE 
	int iX[MAX_SIZE];
	n = MAX_SIZE;
#else
	int *iX;
	cout << "請輸入建立的陣列大小: ";
	cin >> n;
	iX = new int[n];
#endif
	cout << "陣列 iX 共有 " << n << " 個元素" << endl;
	system("pause"); return(0);
}
