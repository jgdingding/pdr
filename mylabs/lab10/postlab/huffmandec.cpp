// Justin Gou
// jyg2qhc
// 4/13/2020
// huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffmannode.h"

using namespace std;

void showTree(huffmannode* n);
void deleteTree(huffmannode* n);

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
	huffmannode root;
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
		huffmannode* temp = new huffmannode(character[0]);
		huffmannode* curNode = &root;
		for(int i=0;i<prefix.length();i++){
			if(prefix[i]=='0'){
				if(i==prefix.length()-1){
					curNode->left = temp;
				}
				if(curNode->left==NULL){
					curNode->left = new huffmannode;
				}
				curNode = curNode->left;
			}else{
				if(i==prefix.length()-1){
					curNode->right = temp;
				}
				if(curNode->right==NULL){
					curNode->right = new huffmannode;
				}
				curNode = curNode->right;
			}
		}
		//showTree(&root);
		//cout << endl;
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
	huffmannode* curpointer = &root;
	string decoded = "";
	for(int i=0;i<allbits.length();i++){
		//cout << allbits[i] << endl;
		//cout << "currently checking: " << curpointer->value << endl;
		if(allbits[i]=='0'){
			curpointer = curpointer->left;
		}else{
			curpointer = curpointer->right;
		}
		if(curpointer->value != 13){
			decoded += curpointer->value;
			curpointer = &root;
		} 
	}

    //cout << "All the bits: " << allbits << endl;
	cout << decoded << endl;

	deleteTree(&root);
    // close the file before exiting
    file.close();
}

// LEVEL ORDER TREE PRINTING FOR DEBUGGING
// adapted from https://www.geeksforgeeks.org/level-order-tree-traversal/
void printGivenLevel(huffmannode* root, int level);  
int height(huffmannode* node);  

void showTree(huffmannode* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++){ 
		cout << endl;
        printGivenLevel(root, i);
	}
}  
  
/* Print nodes at a given level */
void printGivenLevel(huffmannode* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->value << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  
  
/* Compute the "height" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int height(huffmannode* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}

void deleteTree(huffmannode* n){
	if(n==NULL){
		return;
	}

	deleteTree(n->left);
	deleteTree(n->right);

	delete n->left;
	delete n->right;
}
