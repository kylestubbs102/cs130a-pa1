#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
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

	BinaryTree bt;
	while (getline (wordList, line) && (line.length() > 0)) {
		bt.insertWord(line);
	}

	bt.rangeSearch();
	bt.searchWord("pose");
	bt.searchWord("zymes");
	bt.insertWord("zymet");
	bt.insertWord("zymer");
	bt.insertWord("zymes");
}
