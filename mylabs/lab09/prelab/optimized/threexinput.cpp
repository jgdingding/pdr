// Justin Gou
// jyg2qhc
// 4/5/2020
// threexinput.cpp

#include <iostream>
#include "timer.h"

using namespace std;

int threexplusone(int n){
	if (n==1){
		return 0;
	}
	if (n%2==0){
		return 1+threexplusone(n/2);
	}else{
		return 1+threexplusone(3*n+1);
	}
	return 0;
}

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
	cout << t.getTime()*1e9/n << " Nanoseconds" <<  endl;

	return 0;
}
