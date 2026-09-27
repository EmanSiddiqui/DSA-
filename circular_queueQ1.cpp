//Eman Siddiqui CT-25072
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularQueue {
    Node* rear;

public:
    CircularQueue() {
        rear = NULL;
    }

    bool isEmpty() {
        return rear == NULL;
    }

    void enqueue(int x) {
        Node* n = new Node;
        n->data = x;

        if (rear == NULL) {
            rear = n;
            rear->next = rear;
        }
        else {
            n->next = rear->next;
            rear->next = n;
            rear = n;
        }
    }

    void dequeue() {
        if (rear == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = rear->next;

        if (rear == temp) {
            rear = NULL;
        }
        else {
            rear->next = temp->next;
        }

        delete temp;
    }

    int getFront() {
        if (rear == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return rear->next->data;
    }

    void display() {
        if (rear == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = rear->next;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "After dequeue: ";
    q.display();

    cout << "Front: " << q.getFront() << endl;

    return 0;
}
