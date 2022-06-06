#include <iostream>
using namespace std;
namespace name1 {
	int iX = 1;
	void print_n1() { iX++; cout << iX << endl; }
}
namespace name2 {
	int iX = 5;
	void print_n2() { iX += 2; cout << iX << endl; }
}
int main(void) {
	int iX = 10;
	using namespace name1;  // 使用 name1 空間
	cout << "iX = " << iX << endl;
	print_n1();  // 宣告在 name1 空間的函式
	using namespace name2; // 使用 name2 空間
	cout << "iX = " << iX << endl;
	print_n2();  // 宣告在 name2 空間的函式
	system("pause"); return(0);
}
