//Justin Gou
//jyg2qhc
//3/1/2020
//hashTable.h

#include <string>
#include <vector>
#include <list>

using namespace std;

class HashTable{
	public:
		HashTable();

		HashTable(int s);
		
		~HashTable();
		
		void insert(string s);

		bool find(string s);

	private:
		vector<list<string>> table;
		
		int size;

		int hashString(string s);
};
