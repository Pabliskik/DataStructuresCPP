#include <iostream>
#include <climits>

class Node
{
public:
    Node* next;
    int value;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;
    int height;
public:
    Stack(int value){
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack() {
        Node* tmp = top;
        while (tmp)
        {
            std::cout << tmp->value << std::endl;
            tmp = tmp->next;
        }
        
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if (height < 1) return INT_MIN;
        Node* tmp = top;
        int popValue = tmp->value;
        top = top->next;
        delete tmp;
        height--;

        return popValue;
    }
};

#define SEP std::cout<<"------------"<<std::endl;

int main() {
    Stack* myStack = new Stack(1);
    myStack->push(2);
    myStack->push(3);
    myStack->printStack();
    SEP;
    myStack->pop();
    myStack->printStack();
    SEP;
    return 0;
}

