#include <iostream>
#include <time.h>
using namespace std;
int main(void)
{
	double i, total = 0;
	double duration; // 計算經過的時間
	clock_t start, finish;
	start = clock();
	for (i = 1; i < 1000000000; i++) total += i;
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "1+2+...+1000000000 = " << total << endl;
	cout << "需時: " << duration << "秒" << endl;
	system("pause"); return(0);
}