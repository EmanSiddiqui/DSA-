//Eman Siddiqui CT-25072
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int x) {
        Node* n = new Node;
        n->data = x;
        n->prev = NULL;
        n->next = NULL;

        if (head == NULL) {
            head = tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    Node* getHead() {
        return head;
    }
};

int main() {
    DoublyLinkedList L;
    DoublyLinkedList M;
    DoublyLinkedList N;

    for (int i = 2; i <= 10; i += 2) {
        L.insertEnd(i);
    }

    for (int i = 1; i <= 9; i += 2) {
        M.insertEnd(i);
    }

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();

    Node* temp = L.getHead();

    while (temp != NULL) {
        N.insertEnd(temp->data);
        temp = temp->next;
    }

    temp = M.getHead();

    while (temp != NULL) {
        N.insertEnd(temp->data);
        temp = temp->next;
    }

    cout << "List N: ";
    N.display();

    return 0;
}

