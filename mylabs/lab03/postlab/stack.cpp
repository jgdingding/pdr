//Justin Gou
//jyg2qhc
//1/31/2020
//stack.cpp

#include <iostream>
#include <vector>
#include "stack.h"

using namespace std;

myStack::myStack(){}

myStack::~myStack(){}

void myStack::push(int n){
	s.push_back(n);
}

void myStack::pop(){
	s.pop_back();
}

int myStack::top(){
	return s.back();
}

bool myStack::empty(){
	return s.size()==0;
}
