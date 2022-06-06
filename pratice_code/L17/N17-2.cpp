#include <iostream>
using namespace std;
namespace name1 { int iX = 1; }
namespace name2 { int iX = 5; }
int main()
{
	int iX = 10;
	cout << "      iX = " << iX << endl;
	cout << "name1:iX = " << name1::iX << endl;
	cout << "name2:iX = " << name2::iX << endl;
	system("pause");
}