// Justin Gou
// jyg2qhc
// 04/17/20
// vertex.h

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <string>
	
using namespace std;

class vertex{
	public:
		vertex();
		vertex(string n);
		~vertex();
		vector<vertex> edges;

		bool isAdjacent(vertex v);
		string getName();

	private:
		string name;
				
};

#endif 
