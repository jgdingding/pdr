// Justin Gou
// jyg2qhc
// 4/10/2020
// huffmannode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>

using namespace std;

class huffmannode{
	public:
		huffmannode();
		huffmannode(char val);
		huffmannode* left;
		huffmannode* right;
		char value;
};

#endif
