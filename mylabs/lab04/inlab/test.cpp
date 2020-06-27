#include <iostream>
#include <limits>

using namespace std;

union foo{
	float x;
	int *p;
} bar;

int main(){
	//cout << sizeof(bool) << endl;
	//cout << numeric_limits<int*>::min() << endl;
	//int* test{0};
	//cout << test << endl;
	bar.x = 1.0;
	cout << bar.p << endl;
	return 0;
}
