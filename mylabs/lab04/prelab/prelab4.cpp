//Justin Gou
//jyg2qhc
//2/6/2020
//prelab4.cpp

#include <iostream>
#include <climits>

using namespace std;

void sizeOfTest(){
	cout << "Size of int is " << sizeof(int) << " bytes" << endl;
	cout << "Size of unsigned int is " << sizeof(unsigned int) << " bytes" << endl;
	cout << "Size of float is " << sizeof(float) << " bytes" << endl;
	cout << "Size of double is " << sizeof(double) << " bytes" << endl;
	cout << "Size of char is " << sizeof(char) << " bytes" << endl;
	cout << "Size of int* is " << sizeof(int*) << " bytes" << endl;
	cout << "Size of char* is " << sizeof(char*) << " bytes" << endl;
	cout << "Size of double* is " << sizeof(double*) << " bytes" << endl;
}

void outputBinary(unsigned int n){
	string result;
	for(int i=0;i<32;i++){
		if(n==0){
			result = "0" + result;
		}else{
			result = to_string(n%2) + result;
			n = n/2;
		}
	}
	for(int i=0;i<8;i++){
		cout << result.substr(i*4,4) << " ";
	}
	cout << endl;
}

void overflow(){
	unsigned int max = UINT_MAX;
	cout << "Max num ("<< max << ") + 1 is " << max+1 << endl;
	cout << "The wrapping occurs because the way unsigned numbers perform arithmetic is that it always performs modulo with 2^n, where n is the number of bits allocated. So when 1 is added to the max, the number is modded with itself, which resets to 0." << endl;
}


int main(){
	string tmp;
	unsigned int x;
	cout << "Enter a positive integer: ";
	cin >> tmp;
	x = stoi(tmp);

	sizeOfTest();
	outputBinary(x);
	overflow();

	return 0;
}
