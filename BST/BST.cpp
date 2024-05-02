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

    Node* rInsert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);
        
        if (value < currentNode->value) {
            currentNode->left = rInsert(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = rInsert(currentNode->right, value);
        }

        return currentNode;
    }

    void rInsert(int value) {
        if (root == nullptr) root = new Node(value);
        rInsert(root, value);
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

    bool rContains(Node* currentNode, int value) {
        if (currentNode == nullptr) return false;

        if (currentNode->value == value) return true;

        if (value < currentNode->value) {
            return rContains(currentNode->left, value);
        } else {
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value) {
        return rContains(root, value);
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

    int minValue(Node* currentNode) {
        while(currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }

        return currentNode->value;
    }

    Node* deleteNode(Node* currentNode, int value) {
        if (currentNode == nullptr) return nullptr;

        if(value < currentNode->value) {
            currentNode->left = deleteNode(currentNode->left, value);
        } else if (value > currentNode->value) {
            currentNode->right = deleteNode(currentNode->right, value);
        } else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete(currentNode);
                return nullptr;
            } else if (currentNode->left == nullptr) {
                Node* tmp = currentNode->right;
                delete(currentNode);
                return tmp;
            } else if (currentNode->right == nullptr) {
                Node* tmp = currentNode->left;
                delete(currentNode);
                return tmp;
            } else {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }

        return currentNode;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
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
    std::cout << myBST->rContains(1) << std::endl; 
    myBST->rInsert(3);
    std::cout << myBST->minValue(myBST->getRoot()) << std::endl; 
    myBST->deleteNode(2);
    std::cout << myBST->minValue(myBST->getRoot()) << std::endl; 

    return 0;
}