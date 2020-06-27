// Justin Gou
// jyg2qhc
// 4/2/2020
// mathfun.cpp

#include <iostream>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main(){
	int x,y;

	cout << "Enter first num: ";
	cin >> x;

	cout << "Enter second num: ";
	cin >> y;

	cout << product(x,y) << endl;
	cout << power(x,y) << endl;

	return 0;
}
