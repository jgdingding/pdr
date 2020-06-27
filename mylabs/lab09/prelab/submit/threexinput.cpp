// Justin Gou
// jyg2qhc
// 4/6/2020
// threexinput.cpp

#include <iostream>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int main(){
	int x,n;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter n: ";
	cin >> n;

	cout << threexplusone(x) << endl;

	timer t;
	t.start();
	for(int i=0;i<n;i++){
		threexplusone(x);
	}
	t.stop();
	cout << t.getTime()*1e9/n << " nanoseconds" <<  endl;

	return 0;
}
