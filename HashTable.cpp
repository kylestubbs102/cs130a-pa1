#include <iostream>
#include "HashTable.h"
#include <string>
using namespace std;

HashTable::HashTable() {
	tableSize = 10000;
	table = new arrayOfVectors[tableSize];
	counter = 0;
}

HashTable::~HashTable() {
	delete [] table;
}

void HashTable::searchWord(string word) {
	int hash = hashFunction((char)word);
	for ( arrayOfVectors::iterator it = table[hash].begin(); it != table[hash].end(); it++ ) {
		if ( it->first == word ) {
			cout << word << " found, count = " << it->second << endl;
			return;
		}
	}
	cout << word << " not found" << endl;
}

void HashTable::insertWord(string word, bool start) {
	int hash = hashFunction((char)word);
	bool found = false;
	int count = 0;
	for ( arrayOfVectors::iterator it = table[hash].begin(); it != table[hash].end(); it++ ) {
		if ( it->first == word ) {
			count = ++it->second;
			found = true;
		}
	}
	if (!found) {
		table[hash].push_back( make_pair(word, 1) );
		counter++;
		count = 1;
		cout << counter << endl;
	}
	if (!start)
		cout << word << " inserted, new count = " << count << endl;
}

void HashTable::deleteWord(string word) {
	int hash = hashFunction((char)word);
	int count = 0;
	for ( arrayOfVectors::iterator it = table[hash].begin(); it != table[hash].end(); it++ ) {
		if ( it->first == word ) {
			if ( it->second > 1 ) {
				it->second--;
				count = it->second;
			}
			else {
				table[hash].erase(it);
			}
			break;
		}
	}
	if ( count > 0 )
		cout << word << " deleted, new count = " << count << endl;
	else
		cout << word << " deleted" << endl;
}

void HashTable::rangeSearch() {
	int count = 0;
	int count2 = 0;
	for ( int i = 0; i < tableSize; i++ ) {
		if (table[i].size() > 0)
			count2++;
	}
	cout << count << endl;
	cout << count2 << endl;
}

int HashTable::hashFunction(const char str) {
	int hash = 0;
	for ( int i = 0; i < word.length(); i++ ) {
		hash += (i+1)*(int)word[i];
	}
	hash %= tableSize;
	return hash;
}
