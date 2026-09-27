//Eman Siddiqui CT-25072
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
public:
    Node* rear;

    CircularQueue() {
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if(rear == NULL) {
            rear = newNode;
            rear->next = rear;
        }
        else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(rear == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* front = rear->next;

        if(front == rear) {
            rear = NULL;
        }
        else {
            rear->next = front->next;
        }

        delete front;
    }

    void printQueue() {
        if(rear == NULL) {
            cout << "Queue is empty";
            return;
        }

        Node* temp = rear->next;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != rear->next);
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.printQueue();

    q.dequeue();

    cout << endl << "After Dequeue: ";
    q.printQueue();

    return 0;
}
