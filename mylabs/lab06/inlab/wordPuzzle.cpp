//Justin Gou
//jyg2qhc
//3/1/2020
//wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "timer.h"
#include "hashTable.h"

using namespace std;

HashTable dictionary;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

void readDict(string filename);
int countDict(string filename);
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
string getString(string output,int r, int c, int dir);
int getNextPrime (unsigned int n);
bool checkprime(unsigned int p);

int main(int argc, char** argv){
	timer myTimer;
	myTimer.start();

	if(argc < 3){
		cout << "Not Enough Arguments" << endl;
		return 0;
	}

	int dictSize = countDict(argv[1]);
	dictionary = HashTable(getNextPrime(dictSize*2));
	readDict(argv[1]);
	int rows,cols;
	bool result = readInGrid(argv[2], rows, cols);
	if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }

	string foundWord;
	int wordCount = 0;
	for(int r=0;r<rows;r++){
		for(int c=0;c<cols;c++){
			for(int d=0;d<8;d++){
				for(int l=3;l<22;l++){
					foundWord = getWordInGrid(r,c,d,l,rows,cols); 
					int wordlen = foundWord.size();
					if(wordlen==0){
						break;
					}
					if(wordlen >=3 && dictionary.find(foundWord)){
						//cout << getString(foundWord,r,c,d) << endl;
						wordCount++;
					}
				}
			}
		}
	}

	//cout << to_string(wordCount) << " words found" << endl;
	
	myTimer.stop();
	//cout << "Found all words in " << myTimer.toString() << " seconds" << endl;
	cout << round(myTimer.getTime()*1000) << endl;

	return 0;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


int countDict(string filename){
	int count = 0;
	ifstream file(filename);
	if (!file.is_open()) {
        cout << "invalid dictionary file" << endl;
		return 1009;
    }

	string useless;
	while(file.peek()!=EOF){
		count++;
		file >> useless;
	}

	file.close();

	return count;
}

void readDict(string filename){
	ifstream file(filename);
	if (!file.is_open()) {
        cout << "invalid dictionary file" << endl;
		return;
    }

	while(file.peek()!=EOF){
		string temp;
		file >> temp;
		dictionary.insert(temp);	
	}

	file.close();
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
			output.clear();
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

string getString(string output,int r, int c, int dir){
    static string result;
    result.clear(); // Since it's static we need to clear it
    result.reserve(256); // Can't set capacity in the constructor so do it the first time here
	
	switch (dir) { // assumes grid[0][0] is in the upper-left
		case 0:
			result += "N ";
			break; // north
		case 1:
			result += "NE";
			break; // north-east
		case 2:
			result += "E ";
			break; // east
		case 3:
			result += "SE";
			break; // south-east
		case 4:
			result += "S ";
			break; // south
		case 5:
			result += "SW";
			break; // south-west
		case 6:
			result += "W ";
			break; // west
		case 7:
			result += "NW";
			break; // north-west
	}
	result += "("+to_string(r)+", "+to_string(c)+"):\t"+output;
	return result;
}

