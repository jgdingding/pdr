//Justin Gou
//jyg2qhc
//1/31/2020
//testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream>

using namespace std;

int main() {
    PostfixCalculator p;
	string token;
	while (cin >> token) {
		// Do stuff with `token`!
		// For example, we can print each token back out on its own line:
		if(token == "+"){
			p.add();
		}else if(token == "-"){
			p.subtract();
		}else if(token == "*"){
			p.multiply();
		}else if(token == "/"){
			p.divide();
		}else if(token == "~"){
			p.negate();
		}else{
			p.pushNum(stoi(token));
		}
	}
    
	cout << "Result is: " << p.getTopValue() << endl;
    return 0;
}
