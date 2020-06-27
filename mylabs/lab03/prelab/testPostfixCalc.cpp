//Justin Gou
//jyg2qhc
//1/31/2020
//testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream>

using namespace std;

int main() {
    PostfixCalculator p;
    p.pushNum(1);
    p.pushNum(2);
    p.pushNum(3);
    p.pushNum(4);
    p.pushNum(5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "Result is: " << p.getTopValue() << endl;
    return 0;
}
