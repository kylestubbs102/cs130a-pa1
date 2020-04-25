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
    if (temp) {
        cout << word << " found, count = "
                << temp->counter << endl;
	temp = NULL;
        delete temp;
    }
    else {
        cout << word << " not found" << endl;
    }
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

void BinaryTree::insertWord(string word, bool start) {
    if (root == NULL) {
        root = new Node(word);
        nodeCount = 1;
	if (!start)
      		  cout << word << " inserted, new count = 1" << endl;
        return;
    }
    Node* temp = getNode(word);
    if ( temp ) {
        temp->counter++;
	if (!start)
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
    if (!start)
    	cout << word << " inserted, new count = 1" << endl;
    nodeCount++;
}

void BinaryTree::deleteWord(string word, Node* node, bool isSwitched) {
	if (!node || !exists(word))
		return;
	if (word.compare(node->data) > 0)
		deleteWord(word, node->right, false);
	else if (word.compare(node->data) < 0)
		deleteWord(word, node->left, false);
	else {
		if (node->counter > 1 && !isSwitched) {
			node->counter--;
			cout << word << " deleted, new count = " << node->counter << endl;
			return;
		}
		if (!node->left && !node->right) {
			if (node == root)
				root = NULL;
			else {
				if (node->parent->left == node)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
			}
			delete node;
		}
		else if (node->left && node->right) {
			Node* successor = new Node;
			successor = node;
			successor = successor->right;
			while (successor->left) {
				successor = successor->left;
			}
			node->data = successor->data;
			node->counter = successor->counter;
			deleteWord(successor->data, successor, true);
			successor = NULL;
			delete successor;
		}
		else if (!node->left && node->right) {
			if (node == root) {
					node->right->parent = NULL;
					root = node->right;
			}
			else {
				if (node->parent->data.compare(node->data) > 0) {
					node->parent->left = node->right;
				}
				else {
					node->parent->right = node->right;
				}
				node->right->parent = node->parent;
			}
			delete node;
		}
		else {
			if (node == root) {
				node->left->parent = NULL;
				root = node->left;
			}
			else {
				if (node->parent->data.compare(node->data) > 0) {
					node->parent->left = node->left;
				}
				else {
					node->parent->right = node->left;
				}
				node->left->parent = node->parent;
			}
			delete node;
		}
		if (!isSwitched)
			cout << word << " deleted" << endl;
	}

}

Node*& BinaryTree::getRoot() {
	return root;
}

void BinaryTree::rangeSearch(string start, string end) {
    rangeSearchHelper(root, start, end);
}

void BinaryTree::rangeSearchHelper(Node* node, string start, string end) {
    if (node == NULL)
        return;
    rangeSearchHelper(node->left, start, end);
    if ( node->data.compare(start) >= 0 && node->data.compare(end) <= 0 ) 
        cout << node->data << endl;
    rangeSearchHelper(node->right, start, end);
}
