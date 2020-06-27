//Justin Gou
//jyg2qhc
//2/11/2020
//inlab4.cpp

#include <iostream>

using namespace std;

int main(){
	bool a = true;
	char b = 'b';
	int c = 123;
	double d = 1234.567;
	int* e = new int(321);

	cout << "bool is " << a << endl;
	cout << "char is " << b << endl;
	cout << "int is " << c << endl;
	cout << "double is " << d << endl;
	cout << "int* is " << e << endl;

	cout << "Primitive Arrays" << endl;

	int IntArray[10];
	char CharArray[10];

	int IntArray2D[6][5];
	char CharArray2D[6][5];

	for(int i=0;i<10;i++){
		IntArray[i] = i;
	}

	for(int i=0;i<10;i++){
		CharArray[i] = 'a';
	}

	for(int i=1;i<=6;i++){
		for(int j=1;j<=5;j++){
			IntArray2D[i][j] = i*j;
		}
	}

	for(int i=1;i<=6;i++){
		for(int j=1;j<=5;j++){
			CharArray2D[i][j] = 'a';
		}
	}


	return 0;
}
