#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
#include "HashTable.h"
using namespace std;

int main(int argv, char** argc) {
	/*if(argv < 2){
		cout << "Please provide 1 file name" << endl;
		return 1; 
	}*/ //eventually uss array to read input commands

	ifstream wordList;
	string line;
	
	wordList.open("PA1_dataset.txt");
	if (!wordList) {
		cout << "could not open file";
		return 1;
	}

	HashTable ht;
	while (getline (wordList, line) && (line.length() > 0)) {
		ht.insertWord(line, true);
	}

	ht.searchWord("intimidation");
	ht.searchWord("zoo");
	ht.searchWord("asdfasdf");
	ht.insertWord("intimidation", false);
	ht.insertWord("zoo", false);
	ht.insertWord("asdfadfadf", false);
	ht.deleteWord("intimidation");
	ht.deleteWord("zoo");
	ht.deleteWord("asdfasdf");
	ht.searchWord("intimidation");
	ht.searchWord("zoo");
	ht.searchWord("asdfasdf");
	ht.rangeSearch();

	/*BinaryTree bt;
	while (getline (wordList, line) && (line.length() > 0)) {
		bt.insertWord(line, true);
	}

	bt.rangeSearch();
	bt.deleteWord("broadcasting", bt.getRoot());
	bt.deleteWord("hospitalize", bt.getRoot());
	bt.deleteWord("britts", bt.getRoot());
	bt.deleteWord("runner", bt.getRoot());*/
}
