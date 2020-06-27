// Justin Gou
// jyg2qhc
// 04/17/20
// vertex.cpp

#include <iostream>
#include "vertex.h"

using namespace std;

vertex::vertex(){
	name = "noname";
}

vertex::vertex(string n){
	name = n;
}

vertex::~vertex(){	
}

bool vertex::isAdjacent(vertex v){
	for (int i=0; i<edges.size(); i++) {
		if ( edges[i].name == v.name ){
			return true;
		}
	}
	return false;
}

string vertex::getName(){
	return name;
}
