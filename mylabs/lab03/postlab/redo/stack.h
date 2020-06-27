//Justin Gou
//jyg2qhc
//2/4/2020
//stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class myStack{
	public:
		myStack();

		~myStack();

		void push(int n);

		void pop();

		int top();

		bool empty();
	
	private:
		int numEl;
		int capacity;
		int *s;

		void sizeup();
};

#endif
