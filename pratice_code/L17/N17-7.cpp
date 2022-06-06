#include <iostream>
#include <iomanip>
using namespace std;
#define LEVEL -1
#if LEVEL == 1
#define NUM_ENEMY 50
#elif LEVEL == 2
#define NUM_ENEMY 100
#elif LEVEL > 0 && LEVEL < 5 
#define NUM_ENEMY 200
#else
#define NUM_ENEMY 400
#endif

int main(void) {
	cout << "敵人的數量 = " << NUM_ENEMY << endl;
	system("pause"); return(0);
}
