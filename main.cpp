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
}
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
// Delete from the beginning
    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Delete from a specific position
    void deleteFromPosition(int pos) {
        if (pos <= 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp && count < pos) {
            temp = temp->next;
            count++;
        }
        if (!temp) return;  // Position out of bounds
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;
        delete temp;
    }
}
    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };
