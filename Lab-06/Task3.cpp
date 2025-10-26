#include <iostream>
using namespace std;

class WebHistory {
    class Node {
    public:
        string url;
        Node* next;
        Node(string u) {
            url = u;
            next = nullptr;
        }
    };

    Node* head;
    string stack[100];
    int topIndex;

public:
    WebHistory() {
        head = nullptr;
        topIndex = -1;
    }

    bool emptyStack() {
        return topIndex == -1;
    }

    void push(string site) {
        if (topIndex >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++topIndex] = site;
    }

    string pop() {
        if (emptyStack()) {
            cout << "Stack underflow" << endl;
            return "";
        }
        return stack[topIndex--];
    }

    void visit(string site) {
        Node* newNode = new Node(site);
        newNode->next = head;
        head = newNode;
        push(site);
        cout << "Visited: " << site << endl;
    }

    void back(int steps) {
        cout << "Going back " << steps << " pages..." << endl;
        for (int i = 0; i < steps; i++) {
            if (head == nullptr || emptyStack()) {
                cout << "No more history to go back." << endl;
                return;
            }
            cout << "Removing: " << pop() << endl;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        if (head != nullptr)
            cout << "Now on page: " << head->url << endl;
        else
            cout << "No pages left in history." << endl;
    }

    void displayHistory() {
        cout << "Current browsing history:" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->url << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    WebHistory history;
    history.visit("Google");
    history.visit("Facebook");
    history.visit("Twitter");
    history.visit("LinkedIn");
    history.visit("Instagram");

    cout << endl;
    history.displayHistory();

    history.back(2);

    cout << endl;
    history.displayHistory();

    return 0;
}
