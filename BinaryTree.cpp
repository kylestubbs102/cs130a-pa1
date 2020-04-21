#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

BinaryTree::BinaryTree() {
    nodeCount = 0;
    root = NULL;
}

BinaryTree::~BinaryTree() {
    //implement later with helper
}

void BinaryTree::destructorHelper() {

}

bool BinaryTree::searchWord(string word) {
    //implement later with iteration
}

Node* BinaryTree::exists(string word) {

}

void BinaryTree::insertWord(string word) {
    //implement later with iteration
}

void BinaryTree::deleteWord(string word) {
    //implement later with iteration
}

void BinaryTree::rangeSearch() {
    rangeSearchHelper(root);
}

void BinaryTree::rangeSearchHelper(Node* root) {
    rangeSearchHelper(root->left);
    cout << root->data << endl;
    rangeSearchHelper(root->right);
}