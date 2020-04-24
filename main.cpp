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
	cout << argv << " arguments" << endl;	
	wordList.open("PA1_dataset.txt");
	if (!wordList) {
		cout << "could not open file";
		return 1;
	}

	HashTable ht;
	BinaryTree bt;
	while (getline (wordList, line) && (line.length() > 0)) {
		ht.insertWord(line, true);
		bt.insertWord(line, true);
	}

	bt.deleteWord("broadcasting", bt.getRoot(), false);
	bt.deleteWord("hospitalize", bt.getRoot(), false);
	bt.deleteWord("britts", bt.getRoot(), false);
	bt.deleteWord("runner", bt.getRoot(), false);
	bt.rangeSearch("hospitalization", "hot");
}
