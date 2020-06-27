//Justin Gou
//jyg2qhc
//1/31/2020
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"

using namespace std;

class PostfixCalculator{
	public:
		PostfixCalculator();
		
		~PostfixCalculator();

		void add();

		void subtract();

		void divide();

		void multiply();

		void negate();

		void pushNum(int n);

		int getTopValue();

	private:
		myStack s;
};

#endif
