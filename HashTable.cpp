#include <iostream>
#include "HashTable.h"
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

HashTable::HashTable() {
	tableSize = 13627;
	table = new arrayOfVectors[tableSize];
}

HashTable::~HashTable() {
	delete [] table;
}

void HashTable::searchWord(string word) {
	char* str = strcpy(new char[word.length() + 1], word.c_str());
	int hash = hashFunction(str);
	for ( arrayOfVectors::iterator it = table[hash].begin(); it != table[hash].end(); it++ ) {
		if ( it->first == word ) {
			cout << word << " found, count = " << it->second << endl;
			return;
		}
	}
	cout << word << " not found" << endl;
}

void HashTable::insertWord(string word, bool start) {
	char* str = strcpy(new char[word.length() + 1], word.c_str());
	int hash = hashFunction(str);
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
		count = 1;
	}
	if (!start)
		cout << word << " inserted, new count = " << count << endl;
}

void HashTable::deleteWord(string word) {
	char* str = strcpy(new char[word.length() + 1], word.c_str());
	int hash = hashFunction(str);
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

void HashTable::rangeSearch(string start, string end) {
	vector<string> wordList;
	for ( int i = 0; i < tableSize; i++ ) {
		for ( arrayOfVectors::iterator it = table[i].begin(); it != table[i].end(); it++ ) {
			wordList.push_back(it->first);
		}
	}
	sort(wordList.begin(), wordList.end());
	for ( vector<string>::iterator it = wordList.begin(); it->compare(end) <= 0; it++ ) {
		if (it->compare(start) >= 0)
			cout << *it << endl;
	}
}

unsigned HashTable::hashFunction(const char* str) {
	unsigned hash = 41;
	unsigned prime = 36277;
	unsigned prime2 = 25889;
	for ( int i = 0; i < strlen(str); i++ ) {
		hash += (i+1)*(int)str[i];
		hash = (hash*prime) ^ (prime2*(int)str[i]); 
	}
	hash %= tableSize;
	return hash;
}
