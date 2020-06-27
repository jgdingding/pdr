//Justin Gou
//jyg2qhc
//1/20/2020
//xToN.cpp

#include <iostream>
using namespace std;

int xton (int x, int n) {
	return n==0 ? 1 : x * xton(x,n-1);
}

int main () {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = xton (x, y);
    cout << x << " ^ " << y << " = " << z << endl;
    return 0;
}
