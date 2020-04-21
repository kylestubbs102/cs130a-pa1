all: prog1.out

prog1.out: BinaryTree.cpp main.cpp
	g++ -g BinaryTree.cpp main.cpp -o prog1.out
