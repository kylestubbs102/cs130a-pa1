all: prog1.out

prog1.out: BinaryTree.cpp HashTable.cpp main.cpp
	g++ -g BinaryTree.cpp HashTable.cpp main.cpp -o prog1.out
