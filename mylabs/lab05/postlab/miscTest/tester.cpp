//Justin Gou
//jyg2qhc
//2/23/2020
//AVLPathTest.cpp

#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
			avl.printTree();
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
	avl.printTree();
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
