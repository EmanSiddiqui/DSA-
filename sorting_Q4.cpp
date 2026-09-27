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

    void sortDescending() {
        if (head == NULL)
            return;

        for (Node* i = head; i != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->data < j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};

int main() {
    DoublyLinkedList N;

    for (int i = 2; i <= 10; i += 2) {
        N.insertEnd(i);
    }

    for (int i = 1; i <= 9; i += 2) {
        N.insertEnd(i);
    }

    cout << "Before sorting: ";
    N.display();

    N.sortDescending();

    cout << "After sorting: ";
    N.display();

    return 0;
}

