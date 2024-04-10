#include <iostream>
#include <vector>

class Node{
public:
    std::string key;
    int value;
    Node* next;

    Node(std::string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable{
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

public:
    ~HashTable() {
        for(int i = 0; i < SIZE; i++) {
            Node* head = dataMap[i];
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                    temp = head;
            }
        }
    }
    void printTable() {
        for(int i = 0; i < SIZE; i++) {
            std::cout << i << ":" << std::endl;
            if(dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    std::cout << "   {" << temp->key << ", " << temp->value << "}" << std::endl;
                    temp = temp->next;
                }
            }
        }
    }

    int hash(std::string key) {
        int hash = 0;
        for(int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }

        return hash;
    }

    void set(std::string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* tmp = dataMap[index];
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    int get(std::string key) {
        int index = hash(key);
        Node* tmp = dataMap[index];
        while (tmp != nullptr)
        {
            if(tmp->key == key) return tmp->value;
            tmp = tmp->next;
        }
        
        return 0;
    }

    std::vector<std::string> keys() {
        std::vector<std::string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node* tmp = dataMap[i];
            while (tmp != NULL) {
                allKeys.push_back(tmp->key);
                tmp = tmp->next;
            }
        }

        return allKeys;
    }

};

#define SEP std::cout << "-----------------------------------" << std::endl;

int main() {

    HashTable* myHashTable = new HashTable();
    myHashTable->set("one", 100);
    myHashTable->set("two", 101);
    myHashTable->set("three", 102);
    myHashTable->set("four", 103);
    myHashTable->set("five", 104);
    myHashTable->printTable();
    SEP
    std::cout << myHashTable->get("one") << std::endl;
    SEP
    std::vector<std::string> myKeys = myHashTable->keys();

    for (std::string key: myKeys) {
        std::cout << key << std::endl;
    }

    return 0;
}