#include <iostream>
using namespace std;

class OrderQueue {
    class Order {
    public:
        string item;
        int quantity;
        Order* next;
        Order(string i, int q) {
            item = i;
            quantity = q;
            next = nullptr;
        }
    };

    Order* front;
    Order* rear;

public:
    OrderQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool empty() {
        return front == nullptr;
    }

    void enqueue(string item, int quantity) {
        Order* newOrder = new Order(item, quantity);
        if (rear == nullptr) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order added: " << item << " x" << quantity << endl;
    }

    void dequeue() {
        if (empty()) {
            cout << "No orders to process!" << endl;
            return;
        }
        Order* temp = front;
        cout << "Processing order: " << front->item << " x" << front->quantity << endl;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void displayOrders() {
        if (empty()) {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Current orders in queue:" << endl;
        Order* temp = front;
        int count = 1;
        while (temp != nullptr) {
            cout << count << ". " << temp->item << " x" << temp->quantity << endl;
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    OrderQueue orders;
    int choice;
    string item;
    int quantity;

    do {
        cout << "\n1. Add Order\n2. Process Order\n3. Display Orders\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter quantity: ";
                cin >> quantity;
                orders.enqueue(item, quantity);
                break;
            case 2:
                orders.dequeue();
                break;
            case 3:
                orders.displayOrders();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
