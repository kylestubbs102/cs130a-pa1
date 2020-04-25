all: prog1.out

prog1.out: BinaryTree.cpp HashTable.cpp prog1.cpp
	g++ -g BinaryTree.cpp HashTable.cpp prog1.cpp -o prog1.out

clean:
	rm prog1.out
