// Justin Gou
// jyg2qhc
// 4/13/2020
// huffmannode.cpp

#include "huffmannode.h"

huffmannode::huffmannode(){
	value = 13;
	frequency = 0;
}

huffmannode::huffmannode(char val){
	value = val;
	frequency = 1;
}

huffmannode huffmannode::getLeft(){
	if(v.size()>0)	
		return v[0];
	huffmannode temp(0);
	return temp;
}

huffmannode huffmannode::getRight(){
	if(v.size()>1)	
		return v[1];
	huffmannode temp(0);
	return temp;
}

void huffmannode::setLeft(huffmannode n){
	if(v.size()>0)
		v[0] = n;
	else
		v.push_back(n);
}

void huffmannode::setRight(huffmannode n){
	if(v.size()>1)
		v[1] = n;
	else
		v.push_back(n);
}


