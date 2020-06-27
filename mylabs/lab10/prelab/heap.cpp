// Justin Gou
// jyg2qhc
// 4/13/2020
// heap.cpp

#include <iostream>
#include <cmath>
#include "heap.h"

using namespace std;

heap::heap(){
	size=0;
	huffmannode temp;
	heapvec.push_back(temp); //dummy 0th element
}

void heap::insert(huffmannode x){
	heapvec.push_back(x);
	size++;
	bubbleUp(size);
}

huffmannode heap::findMin(){
	return heapvec[1];
}

huffmannode heap::deleteMin(){
	if (size<=0){
		throw "cannot remove element from empty list";
	}
	huffmannode temp = heapvec[1];
	heapvec[1] = heapvec[size];
	size--;
	heapvec.pop_back();
	bubbleDown(1);
	return temp;
}

void heap::bubbleUp(int hole){
	huffmannode temp = heapvec[hole];
	while(hole > 1 && heapvec[hole/2].frequency > temp.frequency){
		heapvec[hole] = heapvec[hole/2];
		if(hole > 1)
			hole/=2;
	}
	heapvec[hole] = temp;
}

void heap::bubbleDown(int hole){
	if(hole > size){
		return;
	}
	huffmannode temp = heapvec[hole];
	while(hole*2 <= size && hole>0){
		int lesschild;
		if(hole*2+1 <= size && heapvec[hole*2].frequency > heapvec[hole*2+1].frequency){
			lesschild = hole*2 + 1;	
		}else{
			lesschild = hole*2;
		}
		if(temp.frequency >= heapvec[lesschild].frequency){
			heapvec[hole] = heapvec[lesschild];
			hole = lesschild;
		}else
			break;
	}
	heapvec[hole] = temp;
}

//print method adapted from Aaron Bloomfield's Binary Heap
void heap::print() {
    cout << "(" << heapvec[0].frequency << ") \t";
    for ( int i = 1; i <= size; i++ ) {
        cout << "(" << heapvec[i].value << ", " << heapvec[i].frequency << ") ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}


