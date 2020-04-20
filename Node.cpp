#include <iostream>
using namespace std;
class Node {
    string data;
    Node* left;
    Node* right;
    Node* parent;

    Node() {
        data = 0;
        left = right = parent = null;
    }

    Node(string data) {
        this.data = data;
        left = right = parent = null;
    }

    string GetData() const {
        return data;
    }

    void SetData(string data) {
        this.data = data;
    }

    Node* GetLeft() const {
        return left;
    }

    void SetLeft(Node* left) {
        this.left = left;
    }

    Node* GetRight() const {
        return right;
    }

    void SetRight(Node* right) {
        this.right = right;
    }

    Node* GetParent() const {
        return parent;
    }

    void SetParent(Node* parent) {
        this.parent = parent;
    }
}