// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "heap.h"
#include "huffmannode.h"

heap bh;

int main() {
    srand(time(NULL));
    cout << "inserting a value into the heap..." << endl;
	huffmannode n('g');
    bh.insert(n);
    try {
        cout << bh.findMin().value << endl;
    } catch (const char *e) {
        cout << "Exception thrown: " << e << endl;
    }
    for ( int i = 0; i < 40; i++ ){
		char temp = (char)(97+rand()%26);
		cout << temp << endl;
		huffmannode n(temp);
		n.frequency = rand()%1000;
        bh.insert(n);
	}
    cout << bh.findMin().value << endl;
    cout << "size: " << bh.size << endl;
    bh.print();
    cout << "deleting min..." << endl;
    int min = bh.deleteMin().value;
    cout << "\t" << min << endl;
    cout << "size: " << bh.size << endl;
    bh.print();
    cout << "inserting a value into the heap..." << endl;
    bh.insert(100);
    cout << "size: " << bh.size << endl;
    cout << "deleting min..." << endl;
    bh.deleteMin();
    cout << "size: " << bh.size << endl;
	bh.print();
    return 0;
}
