#include <iostream>
#include <climits>

class Node {
public:
    Node* next;
    int value;

    Node(int value) {
        next = nullptr;
        this->value = value;
    }
};

class Queue {
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int value) {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void printQueue() {
        Node* tmp = first;
        while (tmp)
        {
            std::cout <<  tmp->value << std::endl;
            tmp = tmp->next;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (length < 1) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        length++;
    }

    int dequeue() {
        if (length < 1) return INT_MIN;
        Node* tmp = first;
        int dequeuedValue = tmp->value;
        if (length < 2) {
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
        }

        delete tmp;
        length--;
        return dequeuedValue;
    }
};

#define SEP std::cout<<"------------"<<std::endl;

int main() {

    Queue* myQueue = new Queue(77);
    myQueue->printQueue();
    SEP;
    myQueue->enqueue(88);
    myQueue->enqueue(99);
    myQueue->enqueue(44);
    myQueue->printQueue();
    SEP;
    myQueue->dequeue();
    myQueue->printQueue();

    return 0;
}