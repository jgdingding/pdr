// Justin Gou
// jyg2qhc
// 4/10/2020
// huffmanenc.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include "huffmannode.h"
#include "heap.h"

using namespace std;


void encode(huffmannode n, char c, string curStr);
void getCodes(huffmannode n, vector<char> chars);

int compressedBits = 0;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

	map<char,int> freqtable;

    char g;
    while (file.get(g)) {
		if(freqtable.find(g) != freqtable.end()){
			freqtable[g] += 1;
		}else{
			freqtable[g] = 1;
		}
    }

	heap h;
	vector<char> chars;
	for (map<char, int>::iterator it = freqtable.begin(); it != freqtable.end(); it++){
		if(it->first==10){
			continue;
		}
		huffmannode temp(it->first);
		temp.frequency = it->second;
		h.insert(temp);
		chars.push_back(it->first);
		//cout << it->first << it->second << endl;
	}

	while (h.size > 1){
		huffmannode l,r;
		l = h.deleteMin();
		r = h.deleteMin();
		huffmannode newnode;
		newnode.setLeft(l);
		newnode.setRight(r);
		newnode.frequency = l.frequency + r.frequency;
		h.insert(newnode);
	}

	getCodes(h.findMin(), chars);

    cout << "----------------------------------------" << endl;

    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    while (file.get(g)) {
		encode(h.findMin(),g,"");
    }
	cout << endl;

    cout << "----------------------------------------" << endl;

	cout << "There are a total of " << h.findMin().frequency << " symbols that are encoded." << endl;
	cout << "There are " << chars.size() << " distinct symbols used." << endl;
	cout << "There were " << h.findMin().frequency*8 << " bits in the original file." << endl;
	cout << "There were " << compressedBits << " bits in the compressed file." << endl;
	cout << "This gives a compression ratio of " << h.findMin().frequency*8.0/compressedBits << "." << endl;
	cout << "The cost of the Huffman tree is " << (double)compressedBits/h.findMin().frequency << " bits per character." << endl;

    file.close();
}

void traverse(huffmannode n, char c, string curStr){
	if(n.value == c){
		if(n.value==' ')
			cout << "space " << curStr << endl;
		else
			cout << n.value << " " << curStr << endl;
		return;
	}
	if(n.value==0){
		return;
	}
	traverse(n.getLeft(), c, curStr+"0");
	traverse(n.getRight(), c, curStr+"1");
}

void getCodes(huffmannode n, vector<char> chars){
	for (int i=0;i<chars.size();i++){
		traverse(n, chars[i], "");
	}
}

void encode(huffmannode n, char c, string curStr){
	if(n.value == c && curStr.length()>0){
		cout << curStr << " ";
		compressedBits += curStr.length();
		return;
	}
	if(n.value==0){
		return;
	}
	encode(n.getLeft(), c, curStr+"0");
	encode(n.getRight(), c, curStr+"1");
}
