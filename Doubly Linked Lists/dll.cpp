#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList() {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
        
    }

    void getHead() {
        std::cout << head->value << std::endl;
    }

    void getTail() {
        std::cout << tail->value << std::endl;
    }

    void getLength() {
        std::cout << length << std::endl;
    }

    bool append(int value) {
        Node* newNode = new Node(value);
        if (length < 1) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        length++;
        return true;
    }

    bool deleteLast() {
        if (length < 1) return false;

        Node* tmp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tmp->prev;
            tail->next = nullptr;
        }

        delete tmp;
        length--;
        return true;
    }

    bool prepend(int value) {
        Node* newNode = new Node(value);
        if (length < 1) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        length++;
        return true;
    }

    bool deleteFirst() {
        if (length < 1) return false;

        Node* tmp = head;
        if (length < 2) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = tmp->next;
            head->prev = nullptr;
        }

        delete tmp;
        length--;
        return true;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;

        Node* tmp = head;
        if (index < length/2) {
            for(int i = 0; i < index; i++) {
                tmp = tmp->next;
            }
        } else {
            tmp = tail;
            for(int i = length-1; i > index; i--) {
                tmp = tmp->prev;
            }
        }

        return tmp;
    }

    bool set(int index, int value) {
        Node* tmp = get(index);
        if (tmp) {
            tmp->value = value;
            return true;
        } else {
            return false;
        }
    }

    bool insert(int index, int value) {
        if (index > length || index < 0) return false;

        if (index == 0) return prepend(value);
        if (index == length) return append(value);

        Node* newNode = new Node(value);
        Node* next = get(index);
        Node* pre = next->prev;
        pre->next = newNode;
        next->prev = newNode;
        newNode->next = next;
        newNode->prev = pre;

        length++;
        return true;
    }

    bool deleteNode(int index) {
        if(index >= length || index < 0) return false;
        if(index == 0) return deleteFirst();
        if(index == length-1) return deleteLast();
        
        Node* tmp = get(index);
        Node* prev = tmp->prev;
        Node* after = tmp->next;
        prev->next = after;
        after->prev = prev;

        delete tmp;
        return true;
    }
};

#define SEP std::cout << "-------------------------" << std::endl;

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->printList();
    SEP;
    myDLL->append(3);
    myDLL->append(1);
    myDLL->printList();
    SEP;
    myDLL->deleteLast();
    myDLL->printList();
    SEP;
    myDLL->prepend(55);
    myDLL->printList();
    SEP;
    myDLL->deleteFirst();
    myDLL->append(7);
    myDLL->append(9);
    myDLL->printList();
    SEP;
    std::cout << myDLL->get(2)->value << std::endl;
    SEP;
    myDLL->printList();
    SEP;
    myDLL->set(1, 7);
    myDLL->printList();
    SEP;
    myDLL->insert(0, 10);
    myDLL->printList();
    SEP;
    myDLL->deleteNode(2);
    myDLL->printList();
}