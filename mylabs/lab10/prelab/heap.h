// Justin Gou
// jyg2qhc
// 4/10/2020
// heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "huffmannode.h"

using namespace std;

class heap{
	public:
		heap();
		void insert(huffmannode x);
		huffmannode findMin();
		huffmannode deleteMin();
		unsigned int size;
		void print();
	
	private:
   		vector<huffmannode> heapvec;

    	void bubbleUp(int hole);
    	void bubbleDown(int hole);
};



#endif
