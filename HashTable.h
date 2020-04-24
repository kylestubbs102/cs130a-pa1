#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef vector< pair<string, int> > arrayOfVectors;

class HashTable {
	public:
		HashTable();
		~HashTable();
		void searchWord(string word);
		void insertWord(string word, bool start);
		void deleteWord(string word);
		void rangeSearch(); //add parameters to all of these later if needed
	private:
		arrayOfVectors* table;
		int tableSize;
		int counter; //used for testing
		int hashFunction(const char* str);
	//array of list(pair)
	
};

#endif
