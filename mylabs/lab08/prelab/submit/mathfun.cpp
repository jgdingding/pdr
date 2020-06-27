// Justin Gou
// jyg2qhc
// 3/30/2020
// mathfun.cpp

#include <iostream>

using namespace std;

extern "C" int product(int, int);

int main(){
	int x,y;

	cout << "Enter first num: ";
	cin >> x;

	cout << "Enter second num: ";
	cin >> y;

	cout << product(x,y) << endl;

	return 0;
}
