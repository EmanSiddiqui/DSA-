// Eman Siddiqui CT-25072
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

Node* deleteDuplicates(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            Node* duplicateNode = temp->next; 
            temp->next = temp->next->next;    
            delete duplicateNode;             
        } else {
            temp = temp->next;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    head = deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
