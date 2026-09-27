//Eman Siddiqui CT-25072
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int x) {
        Node* n = new Node;
        n->data = x;
        n->prev = NULL;
        n->next = NULL;

        if (isEmpty()) {
            front = rear = n;
        }
        else {
            n->next = front;
            front->prev = n;
            front = n;
        }
    }

    void insertRear(int x) {
        Node* n = new Node;
        n->data = x;
        n->prev = NULL;
        n->next = NULL;

        if (isEmpty()) {
            front = rear = n;
        }
        else {
            n->prev = rear;
            rear->next = n;
            rear = n;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = NULL;
        }
        else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(20);
    dq.insertRear(30);
    dq.insertFront(10);
    dq.insertFront(5);

    cout << "Deque: ";
    dq.display();

    dq.deleteFront();

    cout << "After deleting front: ";
    dq.display();

    dq.deleteRear();

    cout << "After deleting rear: ";
    dq.display();

    return 0;
}
