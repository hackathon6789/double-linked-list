#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    // Insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int data, int pos) {
        if (pos <= 1) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        int count = 1;
        while (temp && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (!temp) {  // If position is out of bounds, insert at the end
            insertAtEnd(data);
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            if (!newNode->next) tail = newNode;
        }
    }
}