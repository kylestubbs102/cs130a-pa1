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
    Node* temp = new Node; //memory problem somewhere here
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

Node* BinaryTree::getSuccessorNode(string word) { //can probably remove this later
	Node* node = getNode(word);
	if (!node)
		return NULL;
	if (node->right == NULL) {
		while (node->data != root->data) {
			if (node->parent->data.compare(node->data) > 0)
				return node->parent;
			node = node->parent;
		}
		node = NULL;
		delete node;
		return NULL;
	}
	else {
		node = node->right;
		if (!node)
			return node;
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	node = NULL;
	delete node;
}

void BinaryTree::insertWord(string word, bool start) { //maybe combine to one print statement later
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

void BinaryTree::deleteWord(string word, Node*& node) {
	if (!node || !exists(word))
		return;
	if (word.compare(node->data) > 0)
		deleteWord(word, node->right);
	else if (word.compare(node->data) < 0)
		deleteWord(word, node->left);
	else {
		if (node->counter > 1) {
			node->counter--;
			//cout << word << 
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
			//node = NULL;
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
			deleteWord(successor->data, successor);
			/*if (successor->right) {
				node->right = successor->right;
				node->parent = successor->parent;
			}
			else {
				node->left = successor->left;
				node->parent = successor->parent;
			}*/
			successor = NULL;
			delete successor;
		}
		else if (!node->left && node->right) {
			if (node == root) {
				//if (node->parent->data.compare(node->data) > 0) {
					node->right->parent = NULL;
					root = node->right;
				//}
				/*else {
					node->left->parent = NULL;
					root = node->left;
				}*/
			}
			else {
				if (node->parent->data.compare(node->data) > 0) {
					node->right->parent = node->parent;
				}
				else {
					node->left->parent = node->parent;
				}
				node->parent->left = node->right;
			}
			//node = NULL;
			delete node;
		}
		else {
			if (node == root) {
				//if (node->parent->data.compare(node->data) > 0) {
					node->left->parent = NULL;
					root = node->left;
				//}
				/*else {
					node->left->parent = NULL;
					root = node->left;
				}*/
			}
			else {
				if (node->parent->data.compare(node->data) > 0) {
					node->parent->left = node->left;
					node->left->parent = node->parent;
				}
				else {
					node->parent->left = node->right;
					node->left->parent = node->parent;
				}
			}
			//node = NULL;
			delete node;
		}
	}

}

Node*& BinaryTree::getRoot() {
	return root;
}

void BinaryTree::rangeSearch() {
    rangeSearchHelper(root);
}

void BinaryTree::rangeSearchHelper(Node* node) { //fix this to take parameters later
    if (node == NULL)
        return;
    rangeSearchHelper(node->left);
    cout << node->data << endl;
    rangeSearchHelper(node->right);
}
