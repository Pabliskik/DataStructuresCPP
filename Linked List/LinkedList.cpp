#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }

    ~Node() {

    }

};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int value) {
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head) {
            cout << "Head: " << head->value <<endl;
        }
    }

    void getTail() {
        if (tail) {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (0 == length) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        this->length++;
    }

    void deleteLast() {
        if (0 == length) return;
        Node* tmp = head;
        if (1 == length) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* pre = head;
            while (tmp->next)
            {
                pre = tmp;
                tmp = tmp->next;
            }
            pre->next = nullptr;
            tail = pre;
        }
        delete tmp;

        this->length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (0 == length) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        
        this->length++;
    }

    void deleteFirst() {
        if (length == 0) return;

        Node* tmp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }

        delete tmp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        Node* tmp = head;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }

        return tmp;
    }

    bool set(int index, int value) {
        Node* tmp = get(index);
        if (tmp) {
            tmp->value = value;
            return true;
        }

        return false;
    }

    bool insert(int index, int value) {
        if(index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
        }
        Node* newNode = new Node(value);
        Node* tmp = get(index-1);
        newNode->next = tmp->next;
        tmp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        if (index == length-1) {
            deleteLast();
            return;
        }

        if (0 == index) {
            deleteFirst();
            return;
        }

        Node* pre = get(index-1);
        Node* tmp = get(index);

        pre->next = tmp->next;
        delete tmp;
        length--;
    }

    void reverse() {
        Node* tmp = head;
        head = tail;
        tail = tmp;
        Node* after = tmp->next;
        Node* before = nullptr;
        while(tmp) {
            after = tmp->next;
            tmp->next = before;
            before = tmp;
            tmp = after;
        }
    }
};

#define SEP cout<<"-------------------------"<<endl;

int main() {
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << "-------------------------" << endl;

    myLinkedList->append(8);
    myLinkedList->append(7);
    myLinkedList->append(9);
    myLinkedList->printList();
    myLinkedList->getLength();

    cout << "-------------------------" << endl;
    
    myLinkedList->deleteLast();
    myLinkedList->printList();
    myLinkedList->getLength();

    cout << "-------------------------" << endl;

    myLinkedList->prepend(5);
    myLinkedList->printList();
    myLinkedList->getLength();

    cout << "-------------------------" << endl;
    
    cout << myLinkedList->get(0)->value << endl;

    cout << "-------------------------" << endl;

    myLinkedList->set(0, 99);
    myLinkedList->printList();

    cout << "-------------------------" << endl;

    myLinkedList->insert(1, 98);
    myLinkedList->printList();

    SEP

    myLinkedList->deleteNode(2);
    myLinkedList->printList();

    SEP
    
    myLinkedList->reverse();
    myLinkedList->printList();
    
    return 0;
}