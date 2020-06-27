//Justin Gou
//jyg2qhc
//2/4/2020
//stack.cpp

#include <iostream>
#include "stack.h"

using namespace std;

myStack::myStack(){
	numEl = 0;
	capacity = 10;
	s = new int[capacity];
}

myStack::~myStack(){
	delete s;
}

void myStack::push(int n){
	if(numEl == capacity){
		sizeup();
	}
	s[numEl] = n;
	numEl++;
}

void myStack::pop(){
	numEl--;
}

int myStack::top(){
	return s[numEl-1];
}

bool myStack::empty(){
	return numEl==0;
}

void myStack::sizeup(){
	int *temp = new int[capacity*2];
	for(int i=0;i<capacity;i++){
		temp[i] = s[i];
	}
	s = temp;
	capacity *= 2;
}
