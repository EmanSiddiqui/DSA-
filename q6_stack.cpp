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

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;
    }

    void printStack() {
        Node* temp = top;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.printStack();

    s.pop();

    cout << endl << "After Pop: ";
    s.printStack();

    return 0;
}
