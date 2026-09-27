//Eman Siddiqui CT-25072
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;
};

class BrowserHistory {
    Node* curr;

public:
    BrowserHistory(string homepage) {
        curr = new Node;
        curr->url = homepage;
        curr->prev = NULL;
        curr->next = NULL;
    }

    void visit(string url) {
        Node* temp = curr->next;

        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        Node* n = new Node;
        n->url = url;
        n->prev = curr;
        n->next = NULL;

        curr->next = n;
        curr = n;
    }

    string back(int steps) {
        while (steps > 0 && curr->prev != NULL) {
            curr = curr->prev;
            steps--;
        }

        return curr->url;
    }

    string forward(int steps) {
        while (steps > 0 && curr->next != NULL) {
            curr = curr->next;
            steps--;
        }

        return curr->url;
    }
};

int main() {
    BrowserHistory browser("leetcode.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;
    cout << browser.back(1) << endl;
    cout << browser.forward(1) << endl;

    browser.visit("linkedin.com");

    cout << browser.forward(2) << endl;
    cout << browser.back(2) << endl;
    cout << browser.back(7) << endl;

    return 0;
}
