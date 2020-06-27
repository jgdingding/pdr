//Justin Gou
//jyg2qhc
//3/5/2020
//hashTable.cpp

#include "hashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(){
	size = 1009;
	list<string> newList;
	for(int i=0;i<size;i++){
		table.push_back(newList);
	}
}

HashTable::HashTable(int s){
	size = s;
	list<string> newList;
	for(int i=0;i<size;i++){
		table.push_back(newList);
	}
}

HashTable::~HashTable(){
	
}

void HashTable::insert(string s){
	table[hashString(s)].push_back(s);
}

bool HashTable::find(string s){
	list<string> thelist = table[hashString(s)];
	for (list<string>::iterator it = thelist.begin(); it != thelist.end(); ++it){
		if(*it == s){
			return true;
		}
	}
	return false;
}

//int HashTable::hashString(string s){
//	unsigned long long hash = 0;
//	for(int i=0;i<s.length();i++){
//		hash += ((int)s[i])<<i;
//	}
//	return hash%size;
//}
//int HashTable::hashString(string s){
//
//	unsigned long hash = 0;
//
//    for(int i=0;i<s.size();i++)
//    {
//        hash += (int)s[i];
//        hash += (hash << 10);
//        hash ^= (hash >> 6);
//    }
//
//    hash += (hash << 3);
//    hash ^= (hash >> 11);
//    hash += (hash << 15);
//
//    return hash%size;
//}

int HashTable::hashString(string s){
	unsigned int hash = 2166136261;
	for(int i=0;i<s.size();i++){
		hash = hash^s[i];
		hash = hash*16777619;
	}
	return hash%size;
}

//int HashTable::hashString(string s){
//	unsigned int hash = 0;
//	for(int i=0;i<s.size();i++){
//		hash += s[i];
//	}
//	return hash%size;
//}
