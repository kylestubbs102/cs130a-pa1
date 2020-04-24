#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

struct Node {
    string data;
    int counter;
    Node* left;
    Node* right;
    Node* parent;
    Node(string data1 = "") {
        data = data1;
        counter = 1;
        left = right = parent = NULL;
    }
};

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void searchWord(string word);
        void insertWord(string word, bool start);
        void deleteWord(string word, Node*& node, bool isSwitched);
        void rangeSearch(string start, string end);
	Node*& getRoot();
    private:
        int nodeCount;
        Node* root;
        bool exists(string word);
        Node* getNode(string word);
//	Node* getSuccessorNode(string word);
        void rangeSearchHelper(Node* node, string start, string end);
        void destructorHelper(Node* node);
};

#endif
