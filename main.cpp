#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
using namespace std;

int main(int argv, char** argc) {
	if(argv < 2){
		cout << "Please provide 1 file name" << endl;
		return 1;
	}

	ifstream wordList(argc[1]);
	string line;
	
	if (wordList.fail()) {
		cout << "could not open file";
		return 1;
	}

	BinaryTree bt;
	while (getline (wordList, line) && (line.length() > 0)) {
		bt.insertWord(line);
	}

}
