#include <iostream>
using namespace std;

class LibraryQueue {
    class Patron {
    public:
        string name;
        int numBooks; 
        Patron* next;
        Patron(string n, int b) {
            name = n;
            numBooks = b;
            next = nullptr;
        }
    };

    Patron* front;
    Patron* rear;

public:
    LibraryQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool empty() {
        return front == nullptr;
    }

    void addPatron(string name, int numBooks) {
        Patron* newPatron = new Patron(name, numBooks);
        if (rear == nullptr) {
            front = rear = newPatron;
        } else {
            rear->next = newPatron;
            rear = newPatron;
        }
        cout << name << " added to the queue with " << numBooks << " book(s)." << endl;
    }

    void servePatron() {
        if (empty()) {
            cout << "No patrons in the queue to serve!" << endl;
            return;
        }
        Patron* temp = front;
        cout << "Serving " << front->name << " who has " << front->numBooks << " book(s)." << endl;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void displayQueue() {
        if (empty()) {
            cout << "No patrons are currently waiting in the queue." << endl;
            return;
        }
        cout << "Current queue of patrons:" << endl;
        Patron* temp = front;
        int count = 1;
        while (temp != nullptr) {
            cout << count << ". " << temp->name << " - " << temp->numBooks << " book(s)" << endl;
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    LibraryQueue library;
    int choice;
    string name;
    int books;

    do {
        cout << "\n1. Add Patron to Queue\n2. Serve Patron\n3. Display Queue\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patron name: ";
                cin >> name;
                cout << "Enter number of books: ";
                cin >> books;
                library.addPatron(name, books);
                break;
            case 2:
                library.servePatron();
                break;
            case 3:
                library.displayQueue();
                break;
            case 4:
                cout << "Exiting simulation..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
