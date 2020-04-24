#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
#include "HashTable.h"
using namespace std;

int main(int argv, char** argc) {

	ifstream wordList;
	string line;
	wordList.open("/autograder/submission/PA1_dataset.txt");
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

	int i = 0; 
	while ( (int)argc[1][i] != 78 ) {
		if ( argc[1][i] == 's' ) {
			i += 7;
			string str = "";
			while ( (int)argc[1][i] > 96 )
				str += argc[1][i++];
			ht.searchWord(str);
			bt.searchWord(str);
		}
		else if ( argc[1][i] == 'i' ) {
			i += 7;
			string str = "";
			while ( (int)argc[1][i] > 96 )
				str += argc[1][i++];
			ht.insertWord(str, false);
			bt.insertWord(str, false);
		}
		else if ( argc[1][i] == 'd' ) {
			i += 7;
			string str = "";
			while ( (int)argc[1][i] > 96 )
				str += argc[1][i++];
			ht.deleteWord(str);
			bt.deleteWord(str, bt.getRoot(), false);
		}
		else if ( argc[1][i] == 'r' ) {
			i += 13;
			string start = "";
			while ( (int)argc[1][i] > 96 )
				start += argc[1][i++];
			i += 4;
			string end = "";
			while ( (int)argc[1][i] > 96 )
				end += argc[1][i++];
			ht.rangeSearch(start, end);
			bt.rangeSearch(start, end);
		}
		if ( argc[1][i] == ',' )
			i++;
		i++;
	}
}
