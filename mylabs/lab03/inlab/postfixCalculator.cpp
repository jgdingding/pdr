//Justin Gou
//jyg2qhc
//1/31/2020
//postfixCalculator.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"

using namespace std;

PostfixCalculator::PostfixCalculator(){
	
}

PostfixCalculator::~PostfixCalculator(){
}

void PostfixCalculator::add(){
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num1+num2);
}

void PostfixCalculator::subtract(){
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num2-num1);
}

void PostfixCalculator::multiply(){
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num1*num2);
}

void PostfixCalculator::divide(){
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num2/num1);
}

void PostfixCalculator::negate(){
	int num1 = s.top();
	s.pop();
	s.push(0-num1);
}

void PostfixCalculator::pushNum(int n){
	s.push(n);
}

int PostfixCalculator::getTopValue(){
	return s.top();
}
