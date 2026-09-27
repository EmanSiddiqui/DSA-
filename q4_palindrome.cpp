// Eman Siddiqui CT-25072
#include <iostream>
#include <vector>
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

bool isPalindrome(Node* head) {
    vector<int> arr;

    
    Node* temp = head;
    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if (isPalindrome(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
