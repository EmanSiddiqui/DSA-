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

Node* merge(Node* first, Node* second) {
    
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    if (first != NULL) {
        temp->next = first;
    } else {
        temp->next = second;
    }

    Node* result = dummy->next;
    delete dummy; 
    return result;
}

Node* sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = NULL; // Break the list into two halves


    Node* left = sortList(head);
    Node* right = sortList(second);

    
    return merge(left, right);
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
