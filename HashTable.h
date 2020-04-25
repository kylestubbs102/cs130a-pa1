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
		void rangeSearch(string start, string end);
	private:
		arrayOfVectors* table;
		int tableSize;
		unsigned hashFunction(const char* str);
};

#endif
