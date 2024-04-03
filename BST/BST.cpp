#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }

        Node* tmp = root;
        while (true)
        {
            if(value == tmp->value) return false;
            if(value > tmp->value) {
                if(tmp->right == nullptr) {
                    tmp->right = newNode;
                    return true;
                } else {
                    tmp = tmp->right;
                }
            } else {
                if(tmp->left == nullptr) {
                    tmp->left = newNode;
                    return true;
                } else {
                    tmp = tmp->left;
                }
            }
        }
    }

    Node* getRoot() {
        return root;
    }

    bool contains(int value) {
        if (root == nullptr) return false;

        Node* tmp = root;
        while (true)
        {
            if(value == tmp->value) {
                return true;
            }

            if(value > tmp->value) {
                if(tmp->right == nullptr) {
                    return false;
                }
                tmp = tmp->right;
            } else {
                if(tmp->left == nullptr) {
                    return false;
                }
                tmp = tmp->left;
            }
        }
        
    }
};

int main() {

    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(10);
    myBST->insert(2);
    myBST->insert(30);
    myBST->insert(4);
    myBST->insert(40);

    std::cout << myBST->getRoot()->right->right->value << std::endl;
    std::cout << myBST->contains(30) << std::endl;

    return 0;
}