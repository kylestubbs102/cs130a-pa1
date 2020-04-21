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
    Node(int data1) {
        data = data1;
        counter = 1;
        left = right = parent = NULL;
    }
};

class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        bool searchWord(string word);
        void insertWord(string word);
        void deleteWord(string word);
        void rangeSearch();
    private:
        int nodeCount;
        Node* root;
        Node* exists(string word);
        void rangeSearchHelper(Node* root);
        void destructorHelper();
};

#endif