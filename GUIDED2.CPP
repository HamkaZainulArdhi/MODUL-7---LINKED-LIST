#include <iostream>

using namespace std;

struct Node {
    Node* prev;
    int data;
    char info;
    Node* next;
};

int main() {Node* newNode = (Node*) malloc(sizeof(Node));

    
    newNode->prev = NULL;
    newNode->data = 1;
    newNode->info = 'I';
    newNode->next = NULL;

    
    cout << "Node: " << endl;
    cout << "prev: " << (newNode->prev ? "not NULL" : "NULL") << endl;
    cout << "data: " << newNode->data << endl;
    cout << "info: " << newNode->info << endl;
    cout << "next: " << (newNode->next ? "not NULL" : "NULL") << endl;

    return 0;
}