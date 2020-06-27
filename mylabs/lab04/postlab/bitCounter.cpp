//Justin Gou
//jyg2qhc
//2/11/2020
//bitCounter.cpp

#include <iostream>

using namespace std;

int countBits(int n){
	if(n==0){
		return 0;
	}else if(n%2==0){
		return countBits(n/2);
	}else{
		return 1+countBits(n/2); 
	}
	return 0;
}

int main(int argc, char **argv){
	if(argc>1)
		cout << countBits(stoi(argv[1])) << endl;
	else
		cout << "No input entered" << endl;
	return 0;
}
