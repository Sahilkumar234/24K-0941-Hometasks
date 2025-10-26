#include <iostream>
using namespace std;

class CallHistory {
    struct Call {
        string name;
        string number;
        int duration;
    };

    static const int MAX = 100;
    Call stack[MAX];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    void push() {
        if (topIndex >= MAX - 1) {
            cout << "Call history full" << endl;
            return;
        }
        Call c;
        cout << "Enter Name: ";
        cin >> c.name;
        cout << "Enter Number: ";
        cin >> c.number;
        cout << "Enter Duration (in seconds): ";
        cin >> c.duration;
        stack[++topIndex] = c;
        cout << "Call added" << endl;
        display();
    }

    void pop() {
        if (empty()) {
            cout << "No calls to delete" << endl;
            return;
        }
        cout << "Deleted call: " << stack[topIndex].name << endl;
        topIndex--;
        display();
    }

    void top() {
        if (empty()) {
            cout << "No recent call" << endl;
            return;
        }
        Call c = stack[topIndex];
        cout << "Most Recent Call:" << endl;
        cout << "Name: " << c.name << endl;
        cout << "Number: " << c.number << endl;
        cout << "Duration: " << c.duration << " seconds" << endl;
    }

    void display() {
        if (empty()) {
            cout << "Call history empty" << endl;
            return;
        }
        cout << "Current Call History:" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << topIndex - i + 1 << ". "
                 << stack[i].name << " | "
                 << stack[i].number << " | "
                 << stack[i].duration << " sec" << endl;
        }
        cout << endl;
    }
};

int main() {
    CallHistory history;
    int choice;

    do {
        cout << "--- Call History Management ---" << endl;
        cout << "1. Add New Call" << endl;
        cout << "2. Delete Most Recent Call" << endl;
        cout << "3. Show Most Recent Call" << endl;
        cout << "4. Check if History is Empty" << endl;
        cout << "5. Display All Calls" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) history.push();
        else if (choice == 2) history.pop();
        else if (choice == 3) history.top();
        else if (choice == 4) cout << (history.empty() ? "Empty" : "Not empty") << endl;
        else if (choice == 5) history.display();
        else if (choice != 0) cout << "Invalid choice" << endl;

    } while (choice != 0);

    cout << "Goodbye" << endl;
    return 0;
}
