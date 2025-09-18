#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    double price;
    Node* prev;
    Node* next;

    Node(int ID, string n, double p) : id(ID), name(n), price(p) {
        next = nullptr;
        prev = nullptr;
    }
};

class Cart {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Cart() {
        head = nullptr; 
        tail = nullptr;
        count = 0; 
    } 

    void insertEnd(int id, string name, double price) {
        Node* newNode = new Node(id, name, price);
        if (tail == nullptr) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    void insertFront(int id, string name, double price) {
        Node* newNode = new Node(id, name, price);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void removeFirst() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        count--;
    }

    void removeLast() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; 
        delete temp;
        count--;
    }

    Node* search(int id) {
        Node* current = head;
        while (current != NULL) {
            if (current->id == id) {
                return current;
            } 
            current = current->next;
        }
        return nullptr;
    }

    void updatePrice(int id, double newPrice) {
        Node* item = search(id);
        if (item) item->price = newPrice;
    }

    void displayForward() {
        Node* current = head;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name
                 << ", Price: $" << current->price << endl;
            current = current->next;
        }
    }

    void displayBackward() {
        Node* current = tail;
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name
                 << ", Price: $" << current->price << endl;
            current = current->prev;
        }
    }

    int totalItems() {
        return count;
    }

    Node* findMostExpensive() {
        if (!head) return nullptr;
        Node* current = head;
        Node* mostExpensive = head;
        while (current != NULL) {
            if (current->price > mostExpensive->price) {
                mostExpensive = current;
            }
            current = current->next;
        }
        return mostExpensive;
    }

    ~Cart() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Cart cart;
    cart.insertEnd(1, "Laptop", 999.99);
    cart.insertEnd(2, "Mouse", 25.50);
    cart.insertFront(3, "Headphones", 79.99);

    cout << "Cart forward:" << endl;
    cart.displayForward();

    cout << "Cart backward:" << endl;
    cart.displayBackward();

    cout << "Total items: " << cart.totalItems() << endl;

    Node* expensive = cart.findMostExpensive();
    if (expensive) {
        cout << "Most expensive item: " << expensive->name
             << " ($" << expensive->price << ")" << endl;
    }

    cart.updatePrice(2, 19.99);
    cout << "After updating mouse price:" << endl;
    cart.displayForward();

    cart.removeFirst();
    cout << "After removing first item:" << endl;
    cart.displayForward();

    cart.removeLast();
    cout << "After removing last item:" << endl;
    cart.displayForward();

    return 0;
}
