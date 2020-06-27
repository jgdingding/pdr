#include <iostream>

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


