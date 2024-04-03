#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    char* value;
}node;

node* node_new(char* value) {
    node* newNode = malloc(sizeof(node));
    newNode->value = malloc(sizeof(value));
    
    for(int i = 0; i <= (sizeof(value)/sizeof(char)); i++) {
        *(newNode->value+i) = *(value+i);
    }
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

typedef struct DLL
{
    node* head;
    node* tail;
    int length;
}dll;

dll* dll_new(char* value) {
    dll* newDLL = malloc(sizeof(dll));
    node* newNode = node_new(value);
    newDLL->head = newNode;
    newDLL->tail = newNode;
    newDLL->length = 1;
}

void append(dll* myDLL, char* value) {
    node* newNode = node_new(value);
    if(myDLL->length < 1) {
        myDLL->head = newNode;
        myDLL->tail = newNode;
    } else {
        myDLL->tail->next = newNode;
        newNode->prev = myDLL->tail;
        myDLL->tail = newNode;
    }

    myDLL->length++;
}

void deleteLast(dll* myDLL) {
    if (myDLL->length < 1) return;

    node* tmp = myDLL->tail;
    if (myDLL->length < 2) {
        myDLL->head = NULL;
        myDLL->tail = NULL;
    } else {
        myDLL->tail = myDLL->tail->prev;
        myDLL->tail->next = NULL;
    }
    
    free(tmp);
    myDLL->length--;
}

node* get(dll* myDLL, int index) {
    if (index >= myDLL->length || index < 0) return NULL;

    int i = 0;
    node* tmp = myDLL->head;
    while (i < index)
    {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void printList(dll* myDLL) {
    node* tmp = myDLL->head;
    while (tmp)
    {
        printf("->%s", tmp->value);
        tmp = tmp->next;
    }
}

int main() {
    printf("Doubly linked list of heap-allocated strings\n");
    dll* myDLL = dll_new("jaja");
    append(myDLL, "hola");
    append(myDLL, "jeje");
    printList(myDLL);
    printf("\n");
    deleteLast(myDLL);
    printList(myDLL);
    printf("\n->%s", get(myDLL, 0)->value);

    return 0;
}