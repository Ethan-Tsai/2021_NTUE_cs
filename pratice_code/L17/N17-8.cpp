#include <iostream>
#include "area.h"
#include "volume.h"
using namespace std;
int main(void) {
	float r, l;
	cout << "請輸入半徑: " ; cin >> r;
	cout << "請輸入邊長: " ; cin >> l;
	cout << "半徑為 " << r << " 的圓," << "面積為 " << CIRCLE(r) << endl;
	cout << "半徑為 " << r << " 的球," << "體積為 " << SPHERE(r) << endl;
	cout << "邊長為 " << l << " 的正方形," << "面積為 " << SQUARE(l) << endl;
	cout << "邊長為 " << l << " 的立方體," << "體積為 " << CUBIC(l) << endl;
	system("pause"); return(0);
}