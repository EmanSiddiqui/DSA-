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

Node* mergeLists(Node* list1, Node* list2) {
    // Allocate dummy node on heap to avoid stack destruction issues
    Node* dummy = new Node(0);
    Node* current = dummy;

    while(list1 != NULL && list2 != NULL) {
        if(list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    if(list1 != NULL) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    Node* resultHead = dummy->next;
    delete dummy; // Clean up the dummy node memory
    return resultHead;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* answer = mergeLists(list1, list2);

    cout << "Merged List: ";
    printList(answer);

    return 0;
}
