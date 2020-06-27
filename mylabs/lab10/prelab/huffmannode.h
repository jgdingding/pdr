// Justin Gou
// jyg2qhc
// 4/10/2020
// huffmannode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include <vector>

using namespace std;

class huffmannode{
	public:
		huffmannode();
		huffmannode(char val);
		huffmannode getLeft();
		huffmannode getRight();
		void setLeft(huffmannode n);
		void setRight(huffmannode n);
		char value;
		int frequency;
	private:
		vector<huffmannode> v;

};

#endif
