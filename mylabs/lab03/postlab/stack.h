//Justin Gou
//jyg2qhc
//1/31/2020
//stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

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
		vector<int> s;
};

#endif
