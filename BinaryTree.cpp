#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

BinaryTree::BinaryTree() {
    nodeCount = 0;
    root = NULL;
}

BinaryTree::~BinaryTree() {
    destructorHelper(root);
}

void BinaryTree::destructorHelper(Node* node) {
    if (node) {
        destructorHelper(node->left);
        destructorHelper(node->right);
        delete node;
    }
}

void BinaryTree::searchWord(string word) {
    Node* temp = getNode(word);
    if (temp)
        cout << word << " found, count = "
                    << temp->counter << endl;
    else
        cout << word << " not found" << endl;
}

bool BinaryTree::exists(string word) {
    Node* temp = getNode(word);
    if (temp) {
        temp = NULL;
        delete temp;
        return true;
    }
    else
        return false;
}

Node* BinaryTree::getNode(string word) {
    Node* temp = new Node;
    temp = root;
    while (temp) {
        if (word.compare(temp->data) < 0)
            temp = temp->left;
        else if (word.compare(temp->data) > 0)
            temp = temp->right;
        else if (word.compare(temp->data) == 0) {
            return temp;
        }
    }
    return NULL;
}

void BinaryTree::insertWord(string word) {
    if (root == NULL) {
        root = new Node(word);
        nodeCount = 1;
        cout << word << " inserted, new count = 1" << endl;
        return;
    }
    Node* temp = getNode(word);
    if ( temp ) {
        temp->counter++;
        cout << word << " inserted, new count = " << 
                    temp->counter << endl;
        temp = NULL;
        delete temp;
        return;
    }
    temp = root;
    while (temp) {
        if (word.compare(temp->data) < 0) {
            if (temp->left) {
                temp = temp->left;
            }
            else {
                temp->left = new Node(word);
                temp->left->parent = temp;
                break;
            }
        }
        else {
            if (temp->right) {
                temp = temp->right;
            }
            else {
                temp->right = new Node(word);
                temp->right->parent = temp;
                break;
            }
        }
    }
    temp = NULL;
    delete temp;
    cout << word << " inserted, new count = 1" << endl;
    nodeCount++;
}

void BinaryTree::deleteWord(string word) {
    //implement later with iteration
}

void BinaryTree::rangeSearch() {
    rangeSearchHelper(root);
}

void BinaryTree::rangeSearchHelper(Node* node) {
    if (node == NULL)
        return;
    rangeSearchHelper(node->left);
    cout << node->data << endl;
    rangeSearchHelper(node->right);
}